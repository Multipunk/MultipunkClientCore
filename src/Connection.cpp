#include "Connection.h"

bool Connection::isReady = false;

bool Connection::Init() {
	if (isReady) return false;
	WSAData wsaData;
	bool isSuccess = WSAStartup(MAKEWORD(2, 1), &wsaData) == 0;
	isReady = isSuccess;
	return isSuccess;
}

void Connection::ClientHandler(Connection *connection) {
	char msg[4096];
	while (true) {
		if (connection->socketConnection == INVALID_SOCKET) return;
		int result = recv(connection->socketConnection, msg, sizeof(msg), 0);
		if (result == SOCKET_ERROR) {
			connection->Disconnect();
			return;
		}
		connection->packets.emplace_back(msg);
	}
}

bool Connection::Connect(string ip, int port) {
	if (!this->isReady && !this->Init()) {
		cout << "Connection::Connect() > WSAStartup error" << endl;
		return false;
	}
	if (this->socketConnection != INVALID_SOCKET) {
		cout << "Connection::Connect() > already connected" << endl;
		return false;
	}

	SOCKADDR_IN sockaddrIn;
	InetPton(AF_INET, ip.c_str(), &sockaddrIn.sin_addr.s_addr);
	sockaddrIn.sin_port = htons(port);
	sockaddrIn.sin_family = AF_INET;

	this->socketConnection = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (connect(this->socketConnection, (SOCKADDR *) &sockaddrIn, sizeof(sockaddrIn)) != 0) {
		cout << "Connection::Connect() > server ne nayden" << endl;
		this->Disconnect();
		return false;
	}
	cout << "Connection::Connect() > connected to " << ip << ":" << port << endl;
	CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE) ClientHandler, (LPVOID)(this), 0, nullptr);
	return true;
}

bool Connection::Disconnect() {
	if (this->socketConnection == INVALID_SOCKET) return false;
	closesocket(this->socketConnection);
	this->socketConnection = INVALID_SOCKET;
	return true;
}

bool Connection::IsConnected() {
	return this->socketConnection != INVALID_SOCKET;
}

bool Connection::Send(string message) {
	cout << "MPSend() > msg: " << message << " len: " << message.length() << endl;

	int result = send(this->socketConnection, message.c_str(), message.length(), 0);
	if (result == SOCKET_ERROR) {
		this->Disconnect();
		return false;
	}
	return true;
}

string Connection::Receive() {
	if (!this->packets.empty()) {
		string result = packets[0].c_str();
		packets.erase(packets.begin());
		return result;
	}
	return "";
}