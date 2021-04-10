#include<iostream>
#include<boost/asio.hpp>
#include<thread>
#include<vector>
#include<string>

using namespace std;
using namespace boost::asio;
using namespace ip;

string help();

int main()
{
    io_service io2;
    tcp::socket sock(io2);
    sock.connect(tcp::endpoint(address::from_string("127.0.0.1"), 1234));
    while (1)
    {
        boost::asio::streambuf buff2;
        read_until(sock, buff2, "\n");
        cout << buffer_cast <const char*> (buff2.data());

        string msg2;
        cout << "it's your turn: ";
        getline(cin, msg2);
        msg2 += "\n";
        write(sock, boost::asio::buffer(msg2));
    }
}


