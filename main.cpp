/*Hoori1*/
#include <iostream>
#include <vector>

using namespace std;

class game {
private:
    vector<int> p1;
    vector<int> p2;
public:
    void doz3_3();

    void doz3_5();
};

void game::doz3_3() {
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << "O";
    }
    cout << " | ";
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << "O";
    }
    cout << " | ";
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << "O";
    }
    cout << endl;
    cout << "----------" << endl;
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << "O";
    }
    cout << " | ";
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << "O";
    }
    cout << " | ";
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << "O";
    }
    cout << endl;
    cout << "----------" << endl;
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << "O";
    }
    cout << " | ";
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << "O";
    }
    cout << " | ";
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << "O";
    }
    flag = 0;
    cout << endl << endl << "==================================" << endl;
}

void game::doz3_5() {
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
        cout << "* ";
    } else if (flag == 2) {
        cout << "+ ";
    } else {
        cout << "1 ";
    }
    cout << "----";
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
        cout << " * ";
    } else if (flag == 2) {
        cout << " + ";
    } else {
        cout << " 2 ";
    }
    cout << "----";
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
        cout << " *";
    } else if (flag == 2) {
        cout << " +";
    } else {
        cout << " 3";
    }
    cout << endl << "|      |      |" << endl;
    cout << "|      |      |" << endl;
    cout << "| ";
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << " 4 ";
    }
    cout << "-";
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << " 5 ";
    }
    cout << "-";
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << " 6 ";
    }
    cout << " |" << endl;
    cout << "|  |   |   |  |" << endl;
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << "7";
    }
    cout << "--";
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << "8";
    }
    cout << "---";
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << "9";
    }
    cout << "--";
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
        cout << "-*";
    } else if (flag == 2) {
        cout << "-+";
    } else {
        cout << "1O";
    }
    cout << "--";
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
        cout << "*";
    } else if (flag == 2) {
        cout << "+";
    } else {
        cout << "11";
    }
    cout << endl << "|  |   |   |  |" << endl;
    cout << "| ";
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
        cout << " *";
    } else if (flag == 2) {
        cout << " +";
    } else {
        cout << "12";
    }
    cout << " -";
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
        cout << " *";
    } else if (flag == 2) {
        cout << " +";
    } else {
        cout << "13";
    }
    cout << "-";
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
        cout << "  *";
    } else if (flag == 2) {
        cout << "  +";
    } else {
        cout << " 14";
    }
    cout << "  |";
    cout << endl << "|      |      |" << endl;
    cout << "|      |      |" << endl;
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
        cout << "* ";
    } else if (flag == 2) {
        cout << "+ ";
    } else {
        cout << "15";
    }
    cout << "----";
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
        cout << " * ";
    } else if (flag == 2) {
        cout << " + ";
    } else {
        cout << "16 ";
    }
    cout << "----";
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
        cout << " *";
    } else if (flag == 2) {
        cout << " +";
    } else {
        cout << "17";
    }
    cout<<endl;
}
/*Hoori1*/
int main() {

    return 0;
}