#ifndef CLIENTSOCKET_H_
#define CLIENTSOCKET_H_

#include "constant.h"

class ClientSocket : public QTcpSocket
{
	Q_OBJECT
private:
	saveStruct save;			//储存各种信息
	qint16 blockSize;

public:
	ClientSocket(QObject *parent = 0);
	~ClientSocket();

signals:
	void sendSignal(const saveStruct &temp);
	void userLoginSignal(const UserInformation &user);
	void deleteSignal(const QString &acc);

	public slots:
		void receiveMessage();
		void sendMessage(const saveStruct &temp);
		void deleteScoket();
};

#endif
