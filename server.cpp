/*
Bind socket to port 8888 on localhost
*/
#include<io.h>
#include<stdio.h>
#include<winsock2.h>
#include<iostream>
#include<thread>
#include<vector>
#include<string>
#include <sstream>
#include<cstdio>
#include <chrono>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void timer();

class TicTacToe {
private:
    string answer;
    vector<int> p1;
    vector<int> p2;
public:
    static int shift;
    static int x;
    string playGround1();
    string playGround2();
    string playGround3();
    bool checkWinningP1();
    bool checkWinningP2();
    bool checkEnding();
    bool setP1G1(int p);
    bool setP1G2(int p);
    bool setP1G3(int p);
    bool setP2G1(int p);
    bool setP2G2(int p);
    bool setP2G3(int p);

};
string TicTacToe::playGround1() {
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

string TicTacToe::playGround2() {
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
        answer += " * ";
    }
    else if (flag == 2) {
        answer += " + ";
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
        answer += " * ";
    }
    else if (flag == 2) {
        answer += " + ";
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
        answer += " * ";
    }
    else if (flag == 2) {
        answer += " + ";
    }
    else {
        answer += " 6 ";
    }
    answer += " |\n";
    answer += "|  |       |  |\n";
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
    answer += "       ";
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
        answer += "*";
    }
    else if (flag == 2) {
        answer += "+";
    }
    else {
        answer += "10";
    }
    answer += "\n|  |       |  |\n";
    answer += "| ";
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
    answer += " -";
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
    answer += "-";
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
        answer += "  *";
    }
    else if (flag == 2) {
        answer += "  +";
    }
    else {
        answer += " 13";
    }
    answer += "  |";
    answer += "\n|      |      |\n";
    answer += "|      |      |\n";
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
    answer += "----";
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
        answer += " * ";
    }
    else if (flag == 2) {
        answer += " + ";
    }
    else {
        answer += " 15 ";
    }
    answer += "----";
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
    answer += "\n\n==================================\n";
    return answer;
}

string TicTacToe::playGround3() {
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
bool TicTacToe::checkWinningP1() {
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
        arr[0] = 11;
        arr[1] = 12;
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
        arr[0] = 14;
        arr[1] = 15;
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
        arr[0] = 3;
        arr[1] = 10;
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
        arr[0] = 4;
        arr[1] = 8;
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
        arr[0] = 1;
        arr[1] = 7;
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
bool TicTacToe::checkEnding() {
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
        if (total == 16) {
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
bool TicTacToe::checkWinningP2() {
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
        arr[0] = 11;
        arr[1] = 12;
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
        arr[0] = 14;
        arr[1] = 15;
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
        arr[0] = 3;
        arr[1] = 10;
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
        arr[0] = 4;
        arr[1] = 8;
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
        arr[0] = 1;
        arr[1] = 7;
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

bool TicTacToe::setP1G1(int p) {
    int flag = 0;
    int p1Size = p1.size();
    int p2Size = p2.size();
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == p) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == p) {
                flag = 1;
                break;
            }
        }
    }
    if (p >= 1 && p <= 9 && flag == 0) {
        p1.push_back(p);
        return true;
    }
    else {
        //cout << "Khane vared shode mojod nist!!" << endl;
        return false;
    }
}

bool TicTacToe::setP2G1(int p) {
    int flag = 0;
    int p1Size = p1.size();
    int p2Size = p2.size();
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == p) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == p) {
                flag = 1;
                break;
            }
        }
    }
    if (p >= 1 && p <= 9 && flag == 0) {
        p2.push_back(p);
        return true;
    }
    else {
        //cout << "Khane vared shode mojod nist!!" << endl;
        return false;
    }
}

bool TicTacToe::setP1G2(int p) {
    int flag = 0;
    int p1Size = p1.size();
    int p2Size = p2.size();
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == p) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == p) {
                flag = 1;
                break;
            }
        }
    }
    if (p >= 1 && p <= 16 && flag == 0) {
        p1.push_back(p);
        return true;
    }
    else {
        //cout << "Khane vared shode mojod nist!!" << endl;
        return false;
    }
}

bool TicTacToe::setP2G2(int p) {
    int flag = 0;
    int p1Size = p1.size();
    int p2Size = p2.size();
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == p) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == p) {
                flag = 1;
                break;
            }
        }
    }
    if (p >= 1 && p <= 16 && flag == 0) {
        p2.push_back(p);
        return true;
    }
    else {
        //cout << "Khane vared shode mojod nist!!" << endl;
        return false;
    }
}

bool TicTacToe::setP1G3(int p) {
    int flag = 0;
    int p1Size = p1.size();
    int p2Size = p2.size();
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == p) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == p) {
                flag = 1;
                break;
            }
        }
    }
    if (p >= 1 && p <= 21 && flag == 0) {
        p1.push_back(p);
        return true;
    }
    else {
        //cout << "Khane vared shode mojod nist!!" << endl;
        return false;
    }
}

bool TicTacToe::setP2G3(int p) {
    int flag = 0;
    int p1Size = p1.size();
    int p2Size = p2.size();
    for (int i = 0; i < p1Size; i++) {
        if (p1[i] == p) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        for (int i = 0; i < p2Size; i++) {
            if (p2[i] == p) {
                flag = 1;
                break;
            }
        }
    }
    if (p >= 1 && p <= 21 && flag == 0) {
        p2.push_back(p);
        return true;
    }
    else {
        //cout << "Khane vared shode mojod nist!!" << endl;
        return false;
    }
}


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
int member;
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
        for (int i = 0; i < clients.size(); ++i) {
            if (clients[i].getName() != client.getName())
                send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
        }
    }

}

bool start;
int strToNum(string str) {
    stringstream converted(str);
    int num = 0;
    converted >> num;
    return num;
}

void main2(Client client) {
    //if (!start==false) {
    TicTacToe game;
    //start = true;
//}
    int recv_size;
    while (1) {

        char msg[2000];
        if ((recv_size = recv(client.getSocket(), msg, 2000, 0)) == SOCKET_ERROR)
        {
            puts("recv failed");
        }
        msg[recv_size] = '\0';
        if (start && game.shift == 1 && game.x == 1 && clients[0].getName() == client.getName()) {
            if (game.setP2G1(member)) {
                start = false;
            }
        }
        else if (start && game.shift == 2 && game.x == 1 && clients[1].getName() == client.getName()) {
            if (game.setP1G1(member)) {
                start = false;
            }
        }
        else if (start && game.shift == 1 && game.x == 2 && clients[0].getName() == client.getName()) {
            if (game.setP2G2(member)) {
                start = false;
            }
        }
        else if (start && game.shift == 2 && game.x == 2 && clients[1].getName() == client.getName()) {
            if (game.setP1G2(member)) {
                start = false;
            }
        }
        else if (start && game.shift == 1 && game.x == 3 && clients[0].getName() == client.getName()) {
            if (game.setP2G3(member)) {
                start = false;
            }
        }
        else if (start && game.shift == 2 && game.x == 3 && clients[1].getName() == client.getName()) {
            if (game.setP1G3(member)) {
                start = false;
            }
        }
        string sendMsg = client.getName() + " : ";
        string order = string(msg);
        if (order == "-h" || order == "--help") {
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
            for (int i = 0; i < clients.size(); ++i) {
                if (clients[i].getName() == client.getName())
                    send(clients[i].getSocket(), str.c_str(), str.size(), 0);
            }
        }
        else if (order == "--exit") {
            string str = "--exit";
            for (int i = 0; i < clients.size(); ++i) {
                if (clients[i].getName() == client.getName())
                    send(clients[i].getSocket(), str.c_str(), str.size(), 0);
            }
        }
        else if (game.x == 0) {
            if (order == "1") {
                sendMsg = game.playGround1();
                game.x = 1;
                send(clients[1].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                sendMsg += "\nIt's your shift :)";
                send(clients[0].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                timer();
            }
            else if (order == "2") {
                sendMsg = game.playGround2();
                game.x = 2;
                send(clients[1].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                sendMsg += "\nIt's your shift :)";
                send(clients[0].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                timer();
            }
            else if (order == "3") {
                sendMsg = game.playGround3();
                game.x = 3;
                send(clients[1].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                sendMsg += "\nIt's your shift :)";
                send(clients[0].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                timer();
            }
            else if (game.x == 1) {
                int orderNum = strToNum(order);
                if (game.shift == 1) {
                    timer();
                    if (clients[0].getName() == client.getName()) {
                        bool flag = game.setP1G1(orderNum);
                        if (flag) {
                            game.shift = 2;
                            start = true;
                            member = orderNum;
                            sendMsg = game.playGround1();
                            send(clients[0].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                            sendMsg += "\nIt's your shift :)";
                            send(clients[1].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);

                        }
                        else {
                            sendMsg = "Home isn't exist :( Please enter a home =)";
                            for (int i = 0; i < clients.size(); ++i) {
                                if (clients[i].getName() == client.getName())
                                    send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                            }
                        }
                    }
                }
                bool win = game.checkWinningP1();
                if (win) {
                    sendMsg = "\n=============\nWinner : " + client.getName() + "\n=============\n";
                    for (int i = 0; i < clients.size(); ++i) {
                        if (true)
                            send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                    }
                    game.x = -1;
                }

            }
            else if (game.shift == 2) {
                timer();
                if (clients[1].getName() == client.getName()) {
                    bool flag = game.setP2G1(orderNum);
                    if (flag) {
                        game.shift = 1;
                        start = true;
                        member = orderNum;
                        sendMsg = game.playGround1();
                        send(clients[1].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                        sendMsg += "\nIt's your shift :)";
                        send(clients[0].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);

                    }
                    else {
                        sendMsg = "Home isn't exist :( Please enter a home =)";
                        for (int i = 0; i < clients.size(); ++i) {
                            if (clients[i].getName() == client.getName())
                                send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                        }
                    }
                }
                bool win = game.checkWinningP2();
                if (win) {
                    sendMsg = "\n=============\nWinner : " + client.getName() + "\n=============\n";
                    for (int i = 0; i < clients.size(); ++i) {
                        if (true)
                            send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                    }
                    game.x = -1;
                }
            }
            bool end = game.checkEnding();
            if (end) {
                sendMsg = "\n=============\nGame Over!!!\n=============\n";
                for (int i = 0; i < clients.size(); ++i) {
                    if (true)
                        send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                }
                game.x = -1;
            }
        }
        else if (game.x == 2) {
            int orderNum = strToNum(order);
            if (game.shift == 1) {
                timer();
                if (clients[0].getName() == client.getName()) {
                    bool flag = game.setP1G2(orderNum);
                    if (flag) {
                        game.shift = 2;
                        start = true;
                        member = orderNum;
                        sendMsg = game.playGround2();
                        send(clients[0].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                        sendMsg += "\nIt's your shift :)";
                        send(clients[1].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);

                    }
                    else {
                        sendMsg = "Home isn't exist :( Please enter a home =)";
                        for (int i = 0; i < clients.size(); ++i) {
                            if (clients[i].getName() == client.getName())
                                send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                        }
                    }
                }
                bool win = game.checkWinningP1();
                if (win) {
                    sendMsg = "\n=============\nWinner : " + client.getName() + "\n=============\n";
                    for (int i = 0; i < clients.size(); ++i) {
                        if (true)
                            send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                    }
                    game.x = -1;
                }

            }
            else if (game.shift == 2) {
                timer();
                if (clients[1].getName() == client.getName()) {
                    bool flag = game.setP2G2(orderNum);
                    if (flag) {
                        game.shift = 1;
                        start = true;
                        member = orderNum;
                        sendMsg = game.playGround2();
                        send(clients[1].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                        sendMsg += "\nIt's your shift :)";
                        send(clients[0].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);

                    }
                    else {
                        sendMsg = "Home isn't exist :( Please enter a home =)";
                        for (int i = 0; i < clients.size(); ++i) {
                            if (clients[i].getName() == client.getName())
                                send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                        }
                    }
                }
                bool win = game.checkWinningP2();
                if (win) {
                    sendMsg = "\n=============\nWinner : " + client.getName() + "\n=============\n";
                    for (int i = 0; i < clients.size(); ++i) {
                        if (true)
                            send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                    }
                    game.x = -1;
                }
            }
            bool end = game.checkEnding();
            if (end) {
                sendMsg = "\n=============\nGame Over!!!\n=============\n";
                for (int i = 0; i < clients.size(); ++i) {
                    if (true)
                        send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                }
                game.x = -1;
            }
        }
        else if (game.x == 3) {
            int orderNum = strToNum(order);
            if (game.shift == 1) {
                timer();
                if (clients[0].getName() == client.getName()) {
                    bool flag = game.setP1G3(orderNum);
                    if (flag) {
                        game.shift = 2;
                        start = true;
                        member = orderNum;
                        sendMsg = game.playGround3();
                        send(clients[0].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                        sendMsg += "\nIt's your shift :)";
                        send(clients[1].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);

                    }
                    else {
                        sendMsg = "Home isn't exist :( Please enter a home =)";
                        for (int i = 0; i < clients.size(); ++i) {
                            if (clients[i].getName() == client.getName())
                                send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                        }
                    }
                }
                bool win = game.checkWinningP1();
                if (win) {
                    sendMsg = "\n=============\nWinner : " + client.getName() + "\n=============\n";
                    for (int i = 0; i < clients.size(); ++i) {
                        if (true)
                            send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                    }
                    game.x = -1;
                }

            }
            else if (game.shift == 2) {
                timer();
                if (clients[1].getName() == client.getName()) {
                    bool flag = game.setP2G3(orderNum);
                    if (flag) {
                        game.shift = 1;
                        start = true;
                        member = orderNum;
                        sendMsg = game.playGround3();
                        send(clients[1].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                        sendMsg += "\nIt's your shift :)";
                        send(clients[0].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);

                    }
                    else {
                        sendMsg = "Home isn't exist :( Please enter a home =)";
                        for (int i = 0; i < clients.size(); ++i) {
                            if (clients[i].getName() == client.getName())
                                send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                        }
                    }
                }
                bool win = game.checkWinningP2();
                if (win) {
                    sendMsg = "\n=============\nWinner : " + client.getName() + "\n=============\n";
                    for (int i = 0; i < clients.size(); ++i) {
                        if (true)
                            send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                    }
                    game.x = -1;
                }
            }
            bool end = game.checkEnding();
            if (end) {
                sendMsg = "\n=============\nGame Over!!!\n=============\n";
                for (int i = 0; i < clients.size(); ++i) {
                    if (true)
                        send(clients[i].getSocket(), sendMsg.c_str(), sendMsg.size(), 0);
                }
                game.x = -1;
            }
        }

        else if (game.x == -1) {
            string str = "--exit";
            for (int i = 0; i < clients.size(); ++i) {
                if (true)
                    send(clients[i].getSocket(), str.c_str(), str.size(), 0);
            }
        }
    }
}
//static int shift = 1;
//static int x = 0;
int TicTacToe::x = 0;
int TicTacToe::shift = 1;
int main(int argc, char* argv[])
{
    WSADATA wsa;
    SOCKET s, new_socket;
    int c;
    const char* message;
    start = false;
    printf("\nInitialising Winsock...");
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("Failed. Error Code : %d", WSAGetLastError());
        return 1;
    }

    printf("Initialised.\n");

    //Create a socket
    if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d", WSAGetLastError());
    }

    printf("Socket created.\n");

    //Prepare the sockaddr_in structure
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    //Bind
    if (bind(s, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
    {
        printf("Bind failed with error code : %d", WSAGetLastError());
    }

    puts("Bind done");

    //Listen to incoming connections
    listen(s, 3);

    //Accept and incoming connection
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
        threads.push_back(thread(main2, client));
    }

    getchar();

    closesocket(s);
    WSACleanup();

    return 0;
}
void timer() {
    for (int i = 20; i != 0; i--) {
        string str = to_string(i);
        str += "-";
        if (TicTacToe::shift == 1)
            send(clients[0].getSocket(), str.c_str(), str.size(), 0);
        else if (TicTacToe::shift == 2)
            send(clients[1].getSocket(), str.c_str(), str.size(), 0);
        sleep_until(system_clock::now() + seconds(5));
        i = i - 5;
    }
}
