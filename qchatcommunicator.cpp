#include "qchatcommunicator.h"

QChatCommunicator::QChatCommunicator(QObject *parent) : QObject(parent)
{
    this->m_socket = std::make_unique<QUdpSocket>(this);
    this->m_socket->bind(QHostAddress::LocalHost);
}

int QChatCommunicator::set_mode(QString mode = "c"){

}
