#include<iostream>
#include<boost/asio.hpp>
#include<thread>
#include<vector>
#include<string>

using namespace std;
using namespace boost::asio;
using namespace ip;

string menu();
void help();

int main()
{
    io_service io;
    tcp::socket sock(io);
    sock.connect(tcp::endpoint(address::from_string("127.0.0.1"), 1234));

    help();
    string x = menu();
    write(sock, boost::asio::buffer(x));
    string x2;
    getline(cin, x2);

    while (1)
    {
        string msg;
        cout << "it's your turn: ";
        getline(cin, msg);
        msg += "\n";
        write(sock, boost::asio::buffer(msg));

        boost::asio::streambuf buff;
        read_until(sock, buff, "\n");
        cout << buffer_cast <const char*> (buff.data());
    }
}

string menu()
{
    cout << endl << "******************************************" << endl;
    cout << "1. Playground number 1" << endl;
    cout << "2. Playground number 2" << endl;
    cout << "3. Playground number 3" << endl;
    cout << "4. Help" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter a number: ";
    string x;
    cin >> x;
    x += "\n";
    return x;
}

void help() {
    string str = "\n==========================================\n";
    str += "Playground's name: 1\n";
    str += "The size of the ground : 9 Home\n";
    str += "The condition of winning: 3 ta???????????\n";
    str += "Earth shape: \n";
    str += "1---2---3\n|   |   |\n4---5---6\n|   |   |\n7---8---9\n";
    str += "\n==========================================\n";
    str += "Playground's name: 2\n";
    str += "The size of the ground : 17 Home\n";
    str += "The condition of winning: 3 ta ?????????/\n";
    str += "Earth shape: \n";
    str += "1 ---- 2 ---- 3\n|      |      |\n|      |      |\n|  4 - 5 - 6  |\n|  |   |   |  |\n7--8---9--1O--11\n|  |   |   |  |\n| 12 -13- 14  |\n|      |      |\n|      |      |\n15----16 ----17\n";
    str += "\n==========================================\n";
    str += "Playground's name: 3\n";
    str += "The size of the ground : 21 Home\n";
    str += "The condition of winning: 3 ta ????????/\n";
    str += "Earth shape: \n";
    str += " 1------2------3\n |      |      |\n |      |      |\n |  4---5---6  |\n |  |   |   |  |\n |  | 7-8-9 |  |\n |  | |   | |  |\n10-11-12 13-14-15\n |  | |   | |  |\n |  |16---17|  |\n |  |/     \\|  |\n | 18------19  |\n |/           \\|\n20-------------21\n";
    str += "\n==========================================\n";
    cout << str;
}

