#ifndef QCHATCOMMUNICATOR_H
#define QCHATCOMMUNICATOR_H

#include <QObject>
#include <QUdpSocket>
#include <memory>

class QChatCommunicator : public QObject
{
    Q_OBJECT
public:
    explicit QChatCommunicator(QObject *parent = nullptr);
    int set_mode(QString mode);
private:
    std::unique_ptr<QUdpSocket> m_socket;
signals:

public slots:
};

#endif // QCHATCOMMUNICATOR_H
