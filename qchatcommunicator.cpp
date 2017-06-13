#include "qchatcommunicator.h"

QChatCommunicator::QChatCommunicator(char *chatparam,QObject *parent) : QObject(parent){
    this->m_socketReceive = std::make_unique<QUdpSocket>(this);
    std::cout << this->m_socketReceive->bind(65000);
    //this->m_socketSend = std::make_unique<QUdpSocket>(this);
    connect(this->m_socketReceive.get(),
            &QUdpSocket::readyRead,
            this,
            &QChatCommunicator::receive_message,
            Qt::QueuedConnection
            );

    this->m_receivedMessages.push_back("10");
    this->m_receivedMessages.push_back("14");
    this->m_receivedMessages.push_back("15");
    this->m_receivedMessages.push_back("178");
    this->set_mode(chatparam);

}

int QChatCommunicator::set_mode(QString mode = "c"){
    if (mode == "s"){
        std::cout << "Server started\n";
        this->m_checkTimer = std::make_unique<QTimer>(this);
        connect(this->m_checkTimer.get(),
                SIGNAL(timeout()),
                this,
                SLOT(update_helper())
                );
        this->m_checkTimer->start(1000);
    } else {
        std::cout << "Client started\n";
        QByteArray datagram = "Multicast message";
        std::cout << "Sent> " << this->m_socketReceive->writeDatagram(datagram.data(), QHostAddress::LocalHost, 65000) << std::endl;
        this->m_socketReceive->flush();
    }
}

void QChatCommunicator::receive_message(){
    std::lock_guard<std::mutex> lock(this->m_vectorLock);

    std::cout << "Message received\n";
    QString data = "";
    while (this->m_socketReceive->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(this->m_socketReceive->pendingDatagramSize());
        this->m_socketReceive->readDatagram(datagram.data(), datagram.size());

        data += QString(datagram);
    }
    m_receivedMessages.push_back(data);
}

void QChatCommunicator::update_helper(){
    std::cout << "Timer Timeout \n";

    this->m_updateThread = std::make_unique<std::thread>(&QChatCommunicator::update_messages,this);
    this->m_updateThread->join();
}

void QChatCommunicator::update_messages(){
    std::lock_guard<std::mutex> lock(this->m_vectorLock);
    while (!this->m_receivedMessages.empty()){
        this->m_receivedMessages.back();
        this->m_receivedMessages.pop_back();
        std::cout << "Popped \n";
    }
    this->m_receivedMessages.push_back("10");
    this->m_receivedMessages.push_back("14");
    this->m_receivedMessages.push_back("15");
    this->m_receivedMessages.push_back("178");
}

QChatCommunicator::~QChatCommunicator(){
}


