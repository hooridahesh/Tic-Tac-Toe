/*
Initialise Winsock
*/

#include<stdio.h>
#include<winsock2.h>
#include <iostream>
#include<string>
#include<thread>
#include <chrono>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

#pragma comment(lib,"ws2_32.lib") //Winsock Library
#pragma warning(disable:4996)

void timer();
string str;

void sendTo(SOCKET s)
{
    string msg;

    while (1)
    {
        getline(cin, msg);
        if (send(s, msg.c_str(), msg.length(), 0) < 0)
        {
            puts("Send failed");
        }
    }
}

void receiveFrom(SOCKET s)
{
    while (1)
    {
        int recv_size;
        char server_reply[2000];
        if ((recv_size = recv(s, server_reply, 2000, 0)) == SOCKET_ERROR)
        {
            puts("recv failed");
        }
        server_reply[recv_size] = '\0';
        str=string(server_reply);
        if (string(server_reply) == "--exit") {
            closesocket(s);
            WSACleanup();
        }
        cout << server_reply << endl;
    }
}

int main(int argc, char* argv[])
{
    WSADATA wsa;
    SOCKET s;
    struct sockaddr_in server;

    cout << "\nInitialising Winsock...";
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        cout << "Failed. Error Code " << WSAGetLastError();
        return 1;
    }

    cout << "Initialised.";

    if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        cout << "Could not create socket" << WSAGetLastError();
    }

    cout << "Socket created." << endl;

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    //Connect to remote server
    if (connect(s, (struct sockaddr*)&server, sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }

    puts("Connected");
    cout << endl << "******************************************" << endl;
    cout << "1. Playground number 1" << endl;
    cout << "2. Playground number 2" << endl;
    cout << "3. Playground number 3" << endl;
    cout << "4. Help => Enter --help or -h" << endl; 
    cout << "5. Exit => Enter --exit" << endl;
    //Send name
    cout << "Enter your name:" << endl;
    string name;
    cin >> name;
    cout << "Enter a number: " << endl;

    if (send(s, name.c_str(), name.length(), 0) < 0)
    {
        puts("Send failed");
        return 1;
    }

    thread sThread(sendTo, s);
    thread rThread(receiveFrom, s);
    thread Thread(timer);

    sThread.join();
    rThread.join();



    closesocket(s);
    WSACleanup();

    return 0;
}

void timer()
{
    for (int i = 20; i != 0; i--)
    {
        cout << str << endl;
        cout << i;
        sleep_until(system_clock::now() + seconds(1));
        system("cls");
    }
}

