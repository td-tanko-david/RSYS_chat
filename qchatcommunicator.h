#ifndef QCHATCOMMUNICATOR_H
#define QCHATCOMMUNICATOR_H

#include <QObject>

class QChatCommunicator : public QObject
{
    Q_OBJECT
public:
    explicit QChatCommunicator(QObject *parent = nullptr);

signals:

public slots:
};

#endif // QCHATCOMMUNICATOR_H