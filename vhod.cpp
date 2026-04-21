#include <iostream>
#include <registr.h>
#include <string>
using namespace std;
string get_log() {
    string log;
    cout << "Введите логин:" << endl;
    getline(cin, log);
    return log;
}

string get_pass() {
    string pass;
    cout << "Введите пароль:" << endl;
    getline(cin, pass);
    return pass;
}
bool IsLogin(string login, string password) {
    ifstream file("logins.txt");
    
    string fLogin, fPassword;
    
    // Читаем парами: первая строка — логин, вторая — пароль
    while (getline(file, fLogin) && getline(file, fPassword)) {
        if (fLogin == login && fPassword == password) {
            file.close();
            return true; // Нашли совпадение
        }
    }

    file.close();
    return false; // Совпадений не найдено
}
