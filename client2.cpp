#include<stdio.h>
#include<winsock2.h>
#include <iostream>
#include<string>
#include<thread>
#include <windows.h>  

using namespace std;

#pragma comment(lib,"ws2_32.lib") 
#pragma warning(disable:4996)


void sendTo(SOCKET s)
{
    string msg;

    while (1)
    {
        getline(cin, msg);
        if (msg == "-h" || msg == "--help") {
            string str = "\n==========================================\n";
            str += "Playground's name: 1\n";
            str += "The size of the ground : 9 Homes\n";
            str += "The condition of winning: Selected 3 homes continuous\n";
            str += "Earth shape: \n";
            str += "1---2---3\n|   |   |\n4---5---6\n|   |   |\n7---8---9\n";
            str += "\n==========================================\n";
            str += "Playground's name: 2\n";
            str += "The size of the ground : 16 Homes\n";
            str += "The condition of winning: Selected 3 homes continuous\n";
            str += "Earth shape: \n";
            str += "1 ---- 2 ---- 3\n|      |      |\n|      |      |\n|  4 - 5 - 6  |\n|  |       |  |\n7--8       9--10\n|  |       |  |\n| 11 -12- 13  |\n|      |      |\n|      |      |\n14---- 15 ----16\n";
            str += "\n==========================================\n";
            str += "Playground's name: 3\n";
            str += "The size of the ground : 21 Homes\n";
            str += "The condition of winning: Selected 3 homes continuous\n";
            str += "Earth shape: \n";
            str += " 1------2------3\n |      |      |\n |      |      |\n |  4---5---6  |\n |  |   |   |  |\n |  | 7-8-9 |  |\n |  | |   | |  |\n10-11-12 13-14-15\n |  | |   | |  |\n |  |16---17|  |\n |  |/     \\|  |\n | 18------19  |\n |/           \\|\n20-------------21\n";
            str += "\n==========================================\n";
            cout << str;
        }
        else {
            if (send(s, msg.c_str(), msg.length(), 0) < 0)
            {
                puts("Send failed");
            }
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
    system("Color 71");
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
    cout << endl << "******************************************" << endl;
    cout << "Your Time is 20 seconds for press key and enter! =)" << endl;
    cout << endl << "******************************************" << endl;
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

    sThread.join();
    rThread.join();



    closesocket(s);
    WSACleanup();

    return 0;
}

