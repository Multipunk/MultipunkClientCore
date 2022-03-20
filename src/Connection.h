#ifndef MULTIPUNK_CONNECTION_H
#define MULTIPUNK_CONNECTION_H

#include <iostream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <vector>

#pragma comment(lib, "ws2_32.lib")

using namespace std;

class Connection {
private:
	static bool isReady;
	SOCKET socketConnection = INVALID_SOCKET;
	vector<string> packets = {};

	static bool Init();

	static void ClientHandler(Connection *connection);

public:
	bool Connect(string ip, int port);

	bool Disconnect();

	bool IsConnected();

	bool Send(string message);

	string Receive();
};


#endif //MULTIPUNK_CONNECTION_H
