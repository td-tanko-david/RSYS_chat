#ifndef QCHATCOMMUNICATOR_H
#define QCHATCOMMUNICATOR_H

#include <QObject>
#include <QUdpSocket>
#include <memory>
#include <QString>
#include <QTimer>
#include <mutex>
#include <thread>
#include <QThread>
#include <iostream>

class QChatCommunicator : public QObject
{
    Q_OBJECT
public:
    explicit QChatCommunicator(char *chatparam,QObject *parent = nullptr);
    ~QChatCommunicator();
    int set_mode(QString mode);
    void check_messages();
    void update_messages();

private:
    std::vector<QString> m_receivedMessages;

    std::unique_ptr<QUdpSocket> m_socketReceive;
    std::unique_ptr<QUdpSocket> m_socketSend;
    std::unique_ptr<QTimer> m_checkTimer;
    std::mutex m_vectorLock;
    std::unique_ptr<std::thread> m_receiverThread;
    std::unique_ptr<std::thread> m_updateThread;
signals:

public slots:
    void update_helper();
    void receive_message();
};

#endif // QCHATCOMMUNICATOR_H
