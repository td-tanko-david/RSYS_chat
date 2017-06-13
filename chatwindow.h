#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QObject>
#include <qchatcommunicator.h>

class ChatWindow : public QObject
{
    Q_OBJECT
public:
    explicit ChatWindow(QObject *parent = nullptr);
private:
signals:

public slots:
};

#endif // CHATWINDOW_H
