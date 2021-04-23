#include<io.h>
#include<stdio.h>
#include<winsock2.h>
#include<iostream>
#include<thread>
#include<vector>
#include<cstdio>
#include <chrono>
#include<string>
#pragma comment(lib,"ws2_32.lib") 

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
void Timer();
class Client
{
private:
	SOCKET sock;
	string name;
public:
	Client(SOCKET _sock, string _name) { setSocket(_sock); setName(_name); }
	void setSocket(SOCKET _sock) { sock = _sock; }
	void setName(string _name) { name = _name; }
	SOCKET getSocket() { return sock; }
	string getName() { return name; }
};

vector<Client> clients;
vector<thread> threads;

void receiveFrom(Client client) {


	int recv_size;
	while (1) {
		char msg[2000];
		if ((recv_size = recv(client.getSocket(), msg, 2000, 0)) == SOCKET_ERROR)
		{
			puts("recv failed");
		}

		msg[recv_size] = '\0';
		string sendMsg = client.getName() + ": " + string(msg);
		for (int i = 0; i < clients.size(); ++i)
			if (clients[i].getName() != client.getName())
				send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
	}

}

int main(int argc, char* argv[])
{
	WSADATA wsa;
	SOCKET s, new_socket;
	int c;
	const char* message;

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}

	printf("Initialised.\n");

	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}

	printf("Socket created.\n");

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8080);

	if (bind(s, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
	{
		printf("Bind failed with error code : %d", WSAGetLastError());
	}

	puts("Bind done");
	puts("\n++++++++++++++++++++++++++\n");
	puts("Enter a word: ");
	string str2;
	cin >> str2;
	Timer();
	listen(s, 3);
	puts("Waiting for incoming connections...");

	struct sockaddr_in client;
	c = sizeof(struct sockaddr_in);
	while (1) {
		new_socket = accept(s, (struct sockaddr*)&client, &c);
		if (new_socket == INVALID_SOCKET)
		{
			printf("accept failed with error code : %d", WSAGetLastError());
		}
		puts("Connection accepted");

		char msg[2000];
		int recv_size;
		if ((recv_size = recv(new_socket, msg, 2000, 0)) == SOCKET_ERROR)
		{
			puts("recv failed");
		}
		msg[recv_size] = '\0';

		cout << msg << " is connected!!" << endl;

		Client client(new_socket, string(msg));
		clients.push_back(client);
		threads.push_back(thread(receiveFrom, client));
	}


	getchar();

	closesocket(s);
	WSACleanup();

	return 0;
}
void Timer() {
    for (int i = 20; i >= 0; i--) {
		string str = "|| ";
		str += to_string(i);
        str += " ||";
        sleep_until(system_clock::now() + seconds(5));
        i = i - 1;
		cout << str << endl;
    }
}