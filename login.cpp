#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
using namespace std;

void printlog() {
    cout << "Здравствуйте, Гость" << endl;
    cout << "Выберите действие: " << endl;
    cout << "0 - Выход " << endl;
    cout << "1 - Регистрация " << endl;
    cout << "2 - Вход в аккаунт" << endl;
};
void printrun() {
    system("chcp 65001 > nul");
    cout << "Выберите действие: " << endl;
    cout << "0 - Выход " << endl;
    cout << "1 - Вернутся на главную " << endl;
    cout << "2 - Вернутся на  страницу входа" << endl;
};

string get_log() {
    string log;
    cout << "Введите логин:" << endl;
    //print("Введите логин:");
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
    ifstream file("users.txt");
    
    string fLogin, fPassword;
    
    // Читаем парами: первая строка — логин, вторая — пароль
    while (getline(file, fLogin) && getline(file, fPassword)) {
        if (fLogin == login && fPassword == password) {
            file.close();
            
            return true; // Нашли совпадение
        }
    }

    file.close();
    cout << "Пользователь не найден" << endl;
    return false; // Совпадений не найдено
}
