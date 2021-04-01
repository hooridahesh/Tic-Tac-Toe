/*Hoori1*/
#include <iostream>
#include <vector>

using namespace std;

class game {
private:
    vector<int> p1;
    vector<int> p2;
    string answer;
public:
    void doz1();

    void doz2();

    void doz3();

    string getAnswer();

    bool setP1Zamin1(int p);

    bool setP1Zamin2(int p);

    bool setP1Zamin3(int p);

    bool setP2Zamin1(int p);

    bool setP2Zamin2(int p);

    bool setP2Zamin3(int p);

    bool endGameZamin1();

    bool endGameZamin2();

    bool endGameZamin3();

    bool winP1GameZamin1();

    bool winP2GameZamin1();

    bool winP1GameZamin2();

    bool winP2GameZamin2();

    bool winP1GameZamin3();

    bool winP2GameZamin3();


};

/*Hoori3*/
bool game::setP1Zamin1(int p) {
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
    } else {
        //cout << "Khane vared shode mojod nist!!" << endl;
        return false;
    }
}

bool game::setP2Zamin1(int p) {
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
    } else {
        //cout << "Khane vared shode mojod nist!!" << endl;
        return false;
    }
}

bool game::setP1Zamin2(int p) {
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
    if (p >= 1 && p <= 17 && flag == 0) {
        p1.push_back(p);
        return true;
    } else {
        //cout << "Khane vared shode mojod nist!!" << endl;
        return false;
    }
}

bool game::setP2Zamin2(int p) {
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
    if (p >= 1 && p <= 17 && flag == 0) {
        p2.push_back(p);
        return true;
    } else {
        //cout << "Khane vared shode mojod nist!!" << endl;
        return false;
    }
}

bool game::setP1Zamin3(int p) {
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
    } else {
        //cout << "Khane vared shode mojod nist!!" << endl;
        return false;
    }
}

bool game::setP2Zamin3(int p) {
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
    } else {
        //cout << "Khane vared shode mojod nist!!" << endl;
        return false;
    }
}

bool game::endGameZamin1() {
    unsigned int total = p1.size() + p2.size();
    if (total == 9) {
        return true;
    }
    return false;
}

bool game::endGameZamin2() {
    unsigned int total = p1.size() + p2.size();
    if (total == 17) {
        return true;
    }
    return false;
}

bool game::endGameZamin3() {
    unsigned int total = p1.size() + p2.size();
    if (total == 21) {
        return true;
    }
    return false;
}

bool game::winP1GameZamin1() {
    int flag = 0;
    int p1Size = p1.size();
    int arr[3] = {1, 2, 3};
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

bool game::winP2GameZamin1() {
    int flag = 0;
    int p2Size = p2.size();
    int arr[3] = {1, 2, 3};
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

bool game::winP1GameZamin2() {
    int flag = 0;
    int p1Size = p1.size();
    int arr[3] = {1, 2, 3};
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

bool game::winP2GameZamin2() {
    int flag = 0;
    int p2Size = p2.size();
    int arr[3] = {1, 2, 3};
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

bool game::winP1GameZamin3() {
    int flag = 0;
    int p1Size = p1.size();
    int arr[3] = {1, 2, 3};
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

bool game::winP2GameZamin3() {
    int flag = 0;
    int p2Size = p2.size();
    int arr[3] = {1, 2, 3};
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

/*Hoori3*/
void game::doz1() {
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
    } else if (flag == 2) {
        answer = "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
        answer += "9";
    }
    flag = 0;
    answer += "\n\n==================================\n";
}

void game::doz2() {
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
    } else if (flag == 2) {
        answer = "+ ";
    } else {
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
    } else if (flag == 2) {
        answer += " + ";
    } else {
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
    } else if (flag == 2) {
        answer += " +";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "-+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += " +";
    } else {
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
    } else if (flag == 2) {
        answer += " +";
    } else {
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
    } else if (flag == 2) {
        answer += "  +";
    } else {
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
    } else if (flag == 2) {
        answer += "+ ";
    } else {
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
    } else if (flag == 2) {
        answer += " + ";
    } else {
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
    } else if (flag == 2) {
        answer += " +";
    } else {
        answer += "17";
    }
    answer += "\n\n==================================\n";
}
/*Hoori1*/
/*Hoori2*/
void game::doz3() {
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
    } else if (flag == 2) {
        answer = " +";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += " +";
    } else {
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
    } else if (flag == 2) {
        answer += " +";
    } else {
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
    } else if (flag == 2) {
        answer += "+ ";
    } else {
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
    } else if (flag == 2) {
        answer += "+ ";
    } else {
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
    } else if (flag == 2) {
        answer += "+ ";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
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
    } else if (flag == 2) {
        answer += " +";
    } else {
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
    } else if (flag == 2) {
        answer += "+ ";
    } else {
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
    } else if (flag == 2) {
        answer += " +";
    } else {
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
    } else if (flag == 2) {
        answer += "-+";
    } else {
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
    } else if (flag == 2) {
        answer += " +";
    } else {
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
    } else if (flag == 2) {
        answer += "+";
    } else {
        answer += "21";
    }
    flag = 0;
    answer += "\n\n========================================\n";
}

string game::getAnswer() {
    return answer;
}
/*Hoori2*/
/*Hoori4*/
string help() {
    string str = "\n==========================================\n";
    str += "Name Zamin: 1\n";
    str += "Andaze Zamin: 9 khane\n";
    str += "Tedad khanehaye posht sar ham baraye bord: 3 ta\n";
    str += "Format Koli Zamin: \n";
    str += "1---2---3\n|   |   |\n4---5---6\n|   |   |\n7---8---9\n";
    str += "\n==========================================\n";
    str += "Name Zamin: 2\n";
    str += "Andaze Zamin: 17 khane\n";
    str += "Tedad khanehaye posht sar ham baraye bord: 3 ta\n";
    str += "Format Koli Zamin: \n";
    str += "1 ---- 2 ---- 3\n|      |      |\n|      |      |\n|  4 - 5 - 6  |\n|  |   |   |  |\n7--8---9--1O--11\n|  |   |   |  |\n| 12 -13- 14  |\n|      |      |\n|      |      |\n15----16 ----17\n";
    str += "\n==========================================\n";
    str += "Name Zamin: 3\n";
    str += "Andaze Zamin: 21 khane\n";
    str += "Tedad khanehaye posht sar ham baraye bord: 3 ta\n";
    str += "Format Koli Zamin: \n";
    str += " 1------2------3\n |      |      |\n |      |      |\n |  4---5---6  |\n |  |   |   |  |\n |  | 7-8-9 |  |\n |  | |   | |  |\n10-11-12 13-14-15\n |  | |   | |  |\n |  |16---17|  |\n |  |/     \\|  |\n | 18------19  |\n |/           \\|\n20-------------21\n";
    str += "\n==========================================\n";
    return str;
}

string menu() {
    string str;
    str = "\n******************************************\n";
    str += "1. Entekhabe Zamin 1\n";
    str += "2. Entekhabe Zamin 2\n";
    str += "3. Entekhabe Zamin 3\n";
    str += "4. Help\n";
    str += "5. Exit\n";
    str += "Adade Morede Nazar ra Vared Namaiid: :))\n";
    return str;
}

/*Hoori4*/
int main() {
    cout << menu();

    cout << help();
    return 0;
}