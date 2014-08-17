#ifndef SERVER_H_
#define SERVER_H_

#include "constant.h"
#include "database.h"
#include "clientsocket.h"

class Server : public QTcpServer
{
	Q_OBJECT
private:
	int descriptor;	
	saveStruct temp;
	ServerDatabase data;
	QMap<QString, ClientSocket*> userMap;

public:
	Server(QObject *parent=0);
	~Server();

	void friendRequest(const saveStruct &save);
	void changeStatu(const QString &acc, qint32 status);

protected:
	void incomingConnection(int sockDescriptor);

	public slots:
		void clientDisconnected(const QString &acc);
		void sendMessage(const saveStruct &save); 
};

#endif
