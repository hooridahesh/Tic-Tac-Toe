#include<iostream>
#include<boost/asio.hpp>
#include<thread>
#include<vector>
#include<string>

using namespace std;
using namespace boost::asio;
using namespace ip;

class TicTacToe {
private:
    vector<int> p1;
    vector<int> p2;
    string answer;
public:
    string playGround1(vector<int>& p1, vector<int>& p2);
    string playGround2(vector<int>& p1, vector<int>& p2);
    string playGround3(vector<int>& p1, vector<int>& p2);
    void play();
    bool checkWinningP1(int x);
    bool checkWinningP2(int x);
    bool checkEnding(int x);
    void setP1G1(int data, vector<int>& p1, vector<int>& p2);
    void setP1G2(int data, vector<int>& p1, vector<int>& p2);
    void setP1G3(int data, vector<int>& p1, vector<int>& p2);
    void setP2G1(int data, vector<int>& p1, vector<int>& p2);
    void setP2G2(int data, vector<int>& p1, vector<int>& p2);
    void setP2G3(int data, vector<int>& p1, vector<int>& p2);
};

int main()
{
    TicTacToe game;
    game.play();
}

void TicTacToe::play() {

    io_service io, io2;
    tcp::socket server_sock(io);
    tcp::socket server_sock2(io2);
    tcp::acceptor acc(io, tcp::endpoint(tcp::v4(), 1234));
    tcp::acceptor acc2(io2, tcp::endpoint(tcp::v4(), 1234));
    acc.accept(server_sock);
    acc.accept(server_sock2);

    boost::asio::streambuf buff;
    read_until(server_sock, buff, "\n");
    int x = atoi(buffer_cast<const char*>(buff.data()));

    while (1)
    {
        int flag = 0;
        boost::asio::streambuf buff;
        if (x == 1)
        {
            read_until(server_sock, buff, "\n");
            setP1G1(atoi(buffer_cast<const char*>(buff.data())), p1, p2);
        }
        if (x == 2)
        {
            read_until(server_sock, buff, "\n");
            setP1G2(atoi(buffer_cast<const char*>(buff.data())), p1, p2);
        }
        if (x == 3)
        {
            read_until(server_sock, buff, "\n");
            setP1G3(atoi(buffer_cast<const char*>(buff.data())), p1, p2);
        }
        if (checkWinningP1(x))
        {
            string s = "Player 1 won the match!\n";
            write(server_sock, boost::asio::buffer(s));
            write(server_sock2, boost::asio::buffer(s));
        }
        else if (checkEnding(x))
        {
            string s = "the match had no winners!\n";
            write(server_sock, boost::asio::buffer(s));
            write(server_sock2, boost::asio::buffer(s));

        }
        cout << "player1:" << buffer_cast<const char*>(buff.data());
        if (x == 1)
            write(server_sock2, boost::asio::buffer(playGround1(p1, p2)));
        if (x == 2)
            write(server_sock2, boost::asio::buffer(playGround2(p1, p2)));
        if (x == 3)
            write(server_sock2, boost::asio::buffer(playGround3(p1, p2)));

        boost::asio::streambuf buff2;
        if (x == 1)
        {
            read_until(server_sock2, buff2, "\n");
            setP2G1(atoi(buffer_cast<const char*>(buff2.data())), p1, p2);
        }
        if (x == 2)
        {
            read_until(server_sock2, buff2, "\n");
            setP2G2(atoi(buffer_cast<const char*>(buff2.data())), p1, p2);
        }
        if (x == 3)
        {
            read_until(server_sock2, buff2, "\n");
            setP2G3(atoi(buffer_cast<const char*>(buff2.data())), p1, p2);
        }
        if (checkWinningP2(x))
        {
            string s = "Player 1 won the match!\n";
            write(server_sock, boost::asio::buffer(s));
            write(server_sock2, boost::asio::buffer(s));
        }
        else if (checkEnding(x))
        {
            string s = "the match had no winners!\n";
            write(server_sock, boost::asio::buffer(s));
            write(server_sock2, boost::asio::buffer(s));
        }
        cout << "player2: " << buffer_cast<const char*>(buff2.data());

        if (x == 1)
            write(server_sock, boost::asio::buffer(playGround1(p1, p2)));
        if (x == 2)
            write(server_sock, boost::asio::buffer(playGround2(p1, p2)));
        if (x == 3)
            write(server_sock2, boost::asio::buffer(playGround3(p1, p2)));
    }
}

string TicTacToe::playGround1(vector<int>& p1, vector<int>& p2) {
    int p1Size = p1.size();
    int p2Size = p2.size();
    int flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 1) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 1) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer = "*";
    }
    else if (flag == 2) {
        answer = "+";
    }
    else {
        answer = "1";
    }
    answer += "---";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 2) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 2) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "2";
    }
    answer += "---";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 3) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 3) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "3";
    }
    answer += "\n";
    answer += "|   |   |\n";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 4) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 4) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "4";
    }
    answer += "---";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 5) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 5) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "5";
    }
    answer += "---";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 6) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 6) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "6";
    }
    answer += "\n";
    answer += "|   |   |\n";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 7) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 7) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "7";
    }
    answer += "---";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 8) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 8) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "8";
    }
    answer += "---";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 9) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 9) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "9";
    }
    flag = 0;
    answer += "\n\n==================================\n";
    return answer;
}

string TicTacToe::playGround2(vector<int>& p1, vector<int>& p2) {
    int p1Size = p1.size();
    int p2Size = p2.size();
    int flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 1) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 1) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer = "* ";
    }
    else if (flag == 2) {
        answer = "+ ";
    }
    else {
        answer = "1 ";
    }
    answer += "----";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 2) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 2) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += " * ";
    }
    else if (flag == 2) {
        answer += " + ";
    }
    else {
        answer += " 2 ";
    }
    answer += "----";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 3) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 3) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += " *";
    }
    else if (flag == 2) {
        answer += " +";
    }
    else {
        answer += " 3";
    }
    answer += "\n|      |      |\n";
    answer += "|      |      |\n";
    answer += "| ";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 4) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 4) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += " 4 ";
    }
    answer += "-";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 5) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 5) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += " 5 ";
    }
    answer += "-";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 6) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 6) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += " 6 ";
    }
    answer += " |\n";
    answer += "|  |   |   |  |\n";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 7) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 7) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "7";
    }
    answer += "--";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 8) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 8) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "8";
    }
    answer += "---";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 9) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 9) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "9";
    }
    answer += "--";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 10) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 10) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "-*";
    }
    else if (flag == 2) {
        answer += "-+";
    }
    else {
        answer += "1O";
    }
    answer += "--";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 11) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 11) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "11";
    }
    answer += "\n|  |   |   |  |\n";
    answer += "| ";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 12) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 12) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += " *";
    }
    else if (flag == 2) {
        answer += " +";
    }
    else {
        answer += "12";
    }
    answer += " -";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 13) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 13) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += " *";
    }
    else if (flag == 2) {
        answer += " +";
    }
    else {
        answer += "13";
    }
    answer += "-";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 14) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 14) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "  *";
    }
    else if (flag == 2) {
        answer += "  +";
    }
    else {
        answer += " 14";
    }
    answer += "  |";
    answer += "\n|      |      |\n";
    answer += "|      |      |\n";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 15) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 15) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "* ";
    }
    else if (flag == 2) {
        answer += "+ ";
    }
    else {
        answer += "15";
    }
    answer += "----";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 2) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 16) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += " * ";
    }
    else if (flag == 2) {
        answer += " + ";
    }
    else {
        answer += "16 ";
    }
    answer += "----";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 17) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 17) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += " *";
    }
    else if (flag == 2) {
        answer += " +";
    }
    else {
        answer += "17";
    }
    answer += "\n\n==================================\n";
    return answer;
}

string TicTacToe::playGround3(vector<int>& p1, vector<int>& p2) {
    int p1Size = p1.size();
    int p2Size = p2.size();
    int flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 1) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 1) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer = " *";
    }
    else if (flag == 2) {
        answer = " +";
    }
    else {
        answer = " 1";
    }
    answer += "------";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 2) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 2) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "2";
    }
    answer += "------";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 3) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 3) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "3";
    }
    answer += "\n |      |      |\n |      |      |\n |  ";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 4) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 4) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "4";
    }
    answer += "---";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 5) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 5) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "5";
    }
    answer += "---";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 6) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 6) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "6";
    }
    answer += "  |\n |  |   |   |  |\n |  | ";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 7) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 7) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "7";
    }
    answer += "-";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 8) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 8) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "8";
    }
    answer += "-";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 9) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 9) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "9";
    }
    answer += " |  |\n |  | |   | |  |\n";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 10) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 10) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += " *";
    }
    else if (flag == 2) {
        answer += " +";
    }
    else {
        answer += "10";
    }
    answer += "-";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 11) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 11) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += " *";
    }
    else if (flag == 2) {
        answer += " +";
    }
    else {
        answer += "11";
    }
    answer += "-";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 12) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 12) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "* ";
    }
    else if (flag == 2) {
        answer += "+ ";
    }
    else {
        answer += "12";
    }
    answer += " ";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 13) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 13) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "* ";
    }
    else if (flag == 2) {
        answer += "+ ";
    }
    else {
        answer += "13";
    }
    answer += "-";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 14) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 14) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "* ";
    }
    else if (flag == 2) {
        answer += "+ ";
    }
    else {
        answer += "14";
    }
    answer += "-";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 15) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 15) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "15";
    }
    answer += "\n |  | |   | |  |\n |  |";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 16) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 16) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += " *";
    }
    else if (flag == 2) {
        answer += " +";
    }
    else {
        answer += "16";
    }
    answer += "---";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 17) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 17) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "* ";
    }
    else if (flag == 2) {
        answer += "+ ";
    }
    else {
        answer += "17";
    }
    answer += "|  |\n |  |/     \\|  |\n | ";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 18) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 18) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += " *";
    }
    else if (flag == 2) {
        answer += " +";
    }
    else {
        answer += "18";
    }
    answer += "------";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 19) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 19) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "-*";
    }
    else if (flag == 2) {
        answer += "-+";
    }
    else {
        answer += "19";
    }
    answer += "  |\n |/           \\|\n";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 20) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 20) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += " *";
    }
    else if (flag == 2) {
        answer += " +";
    }
    else {
        answer += "20";
    }
    answer += "-------------";
    flag = 0;
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == 21) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == 21) {
                flag = 2;
                break;
            }
        }
    }
    if (flag == 1) {
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "21";
    }
    flag = 0;
    answer += "\n\n========================================\n";
    return answer;
}
bool TicTacToe::checkWinningP1(int x) {
    if (x == 1)
    {
        int flag = 0;
        int p1Size = p1.size();
        int arr[3] = { 1, 2, 3 };
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 4;
        arr[1] = 5;
        arr[2] = 6;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 7;
        arr[1] = 8;
        arr[2] = 9;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 1;
        arr[1] = 4;
        arr[2] = 7;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 2;
        arr[1] = 5;
        arr[2] = 8;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 3;
        arr[1] = 6;
        arr[2] = 9;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        return false;
    }
    else if (x == 2)
    {
        int flag = 0;
        int p1Size = p1.size();
        int arr[3] = { 1, 2, 3 };
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 4;
        arr[1] = 5;
        arr[2] = 6;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 7;
        arr[1] = 8;
        arr[2] = 9;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 8;
        arr[1] = 9;
        arr[2] = 10;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 9;
        arr[1] = 10;
        arr[2] = 11;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 12;
        arr[1] = 13;
        arr[2] = 14;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 15;
        arr[1] = 16;
        arr[2] = 17;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 1;
        arr[1] = 7;
        arr[2] = 15;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 4;
        arr[1] = 8;
        arr[2] = 12;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 2;
        arr[1] = 5;
        arr[2] = 9;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 5;
        arr[1] = 9;
        arr[2] = 13;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 9;
        arr[1] = 13;
        arr[2] = 16;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 6;
        arr[1] = 10;
        arr[2] = 14;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 3;
        arr[1] = 11;
        arr[2] = 17;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        return false;
    }
    else if (x == 3)
    {
        int flag = 0;
        int p1Size = p1.size();
        int arr[3] = { 1, 2, 3 };
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 4;
        arr[1] = 5;
        arr[2] = 6;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 7;
        arr[1] = 8;
        arr[2] = 9;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 10;
        arr[1] = 11;
        arr[2] = 12;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 13;
        arr[1] = 14;
        arr[2] = 15;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 16;
        arr[1] = 18;
        arr[2] = 20;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 17;
        arr[1] = 19;
        arr[2] = 21;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 1;
        arr[1] = 10;
        arr[2] = 20;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 4;
        arr[1] = 11;
        arr[2] = 18;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 7;
        arr[1] = 12;
        arr[2] = 16;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 2;
        arr[1] = 5;
        arr[2] = 8;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 9;
        arr[1] = 13;
        arr[2] = 17;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 6;
        arr[1] = 14;
        arr[2] = 19;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 3;
        arr[1] = 15;
        arr[2] = 21;
        for (int i = 0; i < p1Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p1[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        return false;
    }
}
bool TicTacToe::checkEnding(int x) {
    if (x == 1)
    {
        int total = p1.size() + p2.size();
        if (total == 9) {
            return true;
        }
        return false;
    }
    if (x == 2)
    {
        int total = p1.size() + p2.size();
        if (total == 17) {
            return true;
        }
        return false;
    }
    if (x == 3)
    {
        int total = p1.size() + p2.size();
        if (total == 21) {
            return true;
        }
        return false;
    }
}


bool TicTacToe::checkWinningP2(int x) {
    if (x == 1)
    {
        int flag = 0;
        int p2Size = p2.size();
        int arr[3] = { 1, 2, 3 };
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 4;
        arr[1] = 5;
        arr[2] = 6;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 7;
        arr[1] = 8;
        arr[2] = 9;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 1;
        arr[1] = 4;
        arr[2] = 7;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 2;
        arr[1] = 5;
        arr[2] = 8;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 3;
        arr[1] = 6;
        arr[2] = 9;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        return false;
    }

    else if (x == 2)
    {
        int flag = 0;
        int p2Size = p2.size();
        int arr[3] = { 1, 2, 3 };
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 4;
        arr[1] = 5;
        arr[2] = 6;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 7;
        arr[1] = 8;
        arr[2] = 9;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 8;
        arr[1] = 9;
        arr[2] = 10;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 9;
        arr[1] = 10;
        arr[2] = 11;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 12;
        arr[1] = 13;
        arr[2] = 14;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 15;
        arr[1] = 16;
        arr[2] = 17;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 1;
        arr[1] = 7;
        arr[2] = 15;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 4;
        arr[1] = 8;
        arr[2] = 12;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 2;
        arr[1] = 5;
        arr[2] = 9;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 5;
        arr[1] = 9;
        arr[2] = 13;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 9;
        arr[1] = 13;
        arr[2] = 16;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 6;
        arr[1] = 10;
        arr[2] = 14;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 3;
        arr[1] = 11;
        arr[2] = 17;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        return false;
    }
    else if (x == 3)
    {
        int flag = 0;
        int p2Size = p2.size();
        int arr[3] = { 1, 2, 3 };
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 4;
        arr[1] = 5;
        arr[2] = 6;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 7;
        arr[1] = 8;
        arr[2] = 9;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 10;
        arr[1] = 11;
        arr[2] = 12;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 13;
        arr[1] = 14;
        arr[2] = 15;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 16;
        arr[1] = 18;
        arr[2] = 20;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 17;
        arr[1] = 19;
        arr[2] = 21;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 1;
        arr[1] = 10;
        arr[2] = 20;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 4;
        arr[1] = 11;
        arr[2] = 18;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 7;
        arr[1] = 12;
        arr[2] = 16;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 2;
        arr[1] = 5;
        arr[2] = 8;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 9;
        arr[1] = 13;
        arr[2] = 17;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 6;
        arr[1] = 14;
        arr[2] = 19;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        arr[0] = 3;
        arr[1] = 15;
        arr[2] = 21;
        for (int i = 0; i < p2Size; i++) {
            for (int j = 0; j < 3; j++) {
                if (p2[i] == arr[j]) {
                    flag++;
                    break;
                }
            }
        }
        if (flag == 3) {
            return true;
        }
        flag = 0;
        return false;
    }
}

void TicTacToe::setP1G1(int data, vector<int>& p1, vector<int>& p2) {
    int flag = 0;
    int p1Size = p1.size();
    int p2Size = p2.size();
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == data) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == data) {
                flag = 1;
                break;
            }
        }
    }
    if (data >= 1 && data <= 9 && flag == 0) {
        p1.push_back(data);
    }
}

void TicTacToe::setP1G2(int data, vector<int>& p1, vector<int>& p2) {
    int flag = 0;
    int p1Size = p1.size();
    int p2Size = p2.size();
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == data) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == data) {
                flag = 1;
                break;
            }
        }
    }
    if (data >= 1 && data <= 17 && flag == 0) {
        p1.push_back(data);
    }
}

void TicTacToe::setP1G3(int data, vector<int>& p1, vector<int>& p2) {
    int flag = 0;
    int p1Size = p1.size();
    int p2Size = p2.size();
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == data) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == data) {
                flag = 1;
                break;
            }
        }
    }
    if (data >= 1 && data <= 21 && flag == 0) {
        p1.push_back(data);
    }
}

void TicTacToe::setP2G1(int data, vector<int>& p1, vector<int>& p2) {
    int flag = 0;
    int p1Size = p1.size();
    int p2Size = p2.size();
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == data) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == data) {
                flag = 1;
                break;
            }
        }
    }
    if (data >= 1 && data <= 9 && flag == 0) {
        p2.push_back(data);
    }
}

void TicTacToe::setP2G2(int data, vector<int>& p1, vector<int>& p2) {
    int flag = 0;
    int p1Size = p1.size();
    int p2Size = p2.size();
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == data) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == data) {
                flag = 1;
                break;
            }
        }
    }
    if (data >= 1 && data <= 17 && flag == 0) {
        p2.push_back(data);
    }
}

void TicTacToe::setP2G3(int data, vector<int>& p1, vector<int>& p2) {
    int flag = 0;
    int p1Size = p1.size();
    int p2Size = p2.size();
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == data) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == data) {
                flag = 1;
                break;
            }
        }
    }
    if (data >= 1 && data <= 21 && flag == 0) {
        p2.push_back(data);
    }
}