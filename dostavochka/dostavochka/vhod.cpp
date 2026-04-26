#include <iostream>
#include "header.h"
#include <string>
#include <fstream>
using namespace std;

string get_log() {
    string log;
    cout << "Введите логин: " << endl;
    getline(cin, log);
    return log;
}

string get_pass() {
    string pass;
    cout << "Введите пароль: " << endl;
    getline(cin, pass);
    return pass;
}

string get_address() {
    string addr;
    cout << "Введите адрес через запятую: " << endl;
    getline(cin, addr);
    return addr;
}

bool IsLogin(string lg, string ps) {
    ifstream file("users.txt");

    string fLogin, fPassword, not_important;

    // Читаем: первая строка — логин, вторая — пароль, третья - адрес (его пропускаем)
    while (getline(file, fLogin) && getline(file, fPassword) && getline(file, not_important)) {
        if (fLogin == lg && fPassword == ps) {
            file.close();
            return true; // Нашли совпадение
        }
    }

    file.close();
    return false; // Совпадений не найдено
}
