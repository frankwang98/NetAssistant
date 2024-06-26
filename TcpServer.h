﻿#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    TcpServer(QObject *parent = 0);
    QList<QTcpSocket *> tcpClientSocketList;
signals:
    void updateTcpServer(char *, int, int);
    void addClientLink(QString, int);
    void removeClientLink(QString, int);
public slots:
    void clientDisconnected();
    void sendDataToClient(char *msg, int length, int socketDescriptor, int socketDescriptorEx);
    void acceptNewClient();
    void clientDataReceived();

protected:
};

#endif // SERVER_H
