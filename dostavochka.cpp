#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <clocale>
#include "header.h"

using namespace std;
int main()
{
    system("chcp 65001 > nul");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    int select = 0;
    string login;
    string password;
    string address;
    bool running_log = true;
    

    while (running_log == true) {
        cout << "Здравствуйте, Гость" << endl;
        cout << "Выберите действие: " << endl;
        cout << "0 - Выход " << endl;
        cout << "1 - Регистрация " << endl;
        cout << "2 - Вход в аккаунт" << endl;
        cin >> select;

        switch (select)
        {
        case 0:
            running_log = false;
            break;

        case 1: {
            cin.ignore(); //после ввода select остаётся \n, который игнорируется этим
            login = get_log();
            password = get_pass();
            address = get_address();
            ofstream fout("users.txt", ios::out);

            if (!fout.is_open()) {
                cout << "Файл не открыт" << endl;
                break;
            }
            fout << login << endl << password << endl << address << endl;
            fout.close();
            break;
        }
        
        case 2:
            cout << "Введите логин: ";
            cin >> login;
            cout << "Введите пароль: ";
            cin >> password;
            if (IsLogin(login, password) == true) {
                cout << "Пользователь найден" << endl;
                running_log = false;
            }
            else {
                cout << "Пользователь не найден" << endl;
            }
            break;
        }
    }

    while (!running_log)
    {
        cout << "Здравствуйте, " << login << endl;
        cout << "Выберите действие: " << endl;
        cout << "0 - Выход " << endl;
        cout << "1 - Поиск " << endl;
        //cout << "2 - Вход в аккаунт" << endl;
        cin >> select;
        switch (select)
        {
        case 0:
            running_log = true;
            break;

        case 1:
            search();
            break;
        
        }
    }

    return 0;

}
