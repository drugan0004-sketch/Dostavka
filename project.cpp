#include <iostream>
#include<windows.h>
#include <string>
#include <fstream>
#include <vector>
#include "registr.h"
using namespace std;

std::string get_log() {
    std::string log;
    std::cout << "Введите логин:" << std::endl;
    std::cin >> log;
    //std::getline(std::cin, log);
    return log;
}
std::string get_pass() {
    std::string pass;
    std::cout << "Введите пароль:" << std::endl;
    std::cin >> pass;
    //std::getline(std::cin, pass);
    return pass;
}
void find_in_menu() {
    
    ifstream file("каталог.txt");

    if (!file.is_open()) {
        return;
    }

    vector<string> katalog;
    string line;

    while (getline(file, line)) {
        katalog.push_back(line);
    }
    file.close();

    cout << "поиск: ";
    string query;
    cin >> query;
    //getline(cin, query); не работало

    cout << "\n Результаты:" << endl;

    for (int i = 0; i < katalog.size(); i++) {
        if (katalog[i].find(query) != string::npos) {
            cout << "- " << katalog[i] << endl;
        }
    }
}
int main()
{
    int select = 0;
    string login;
    string password;
    bool running = true;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (running) {
        cout << endl;
        cout << "Выберите действие: " << endl;
        cout << "0 - Выход " << endl;
        cout << "1 - Регистрация " << endl;
        //cout << "2 - Вход в аккаунт" << endl;
        cout << "2- Поиск " << endl;
        //cout << "4-: " << endl;
        cin >> select;
        switch (select)
        {
        case 0:
            running = false;
            break;

        case 1:
            login = get_log();
            password = get_pass();
            break;
        
        case 2:
            find_in_menu();
            break;
        }
    }
    return 0;

}
