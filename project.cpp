#include <iostream>
#include<windows.h>
#include <string>
#include <registr.h>
using namespace std;
int main()
{
    int select = 0;
    string login;
    string password;
    bool running = true;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (running) {
        cout << "Выберите действие: " << endl;
        cout << "0 - Выход " << endl;
        cout << "1 - Регистрация " << endl;
        cout << "2 - Вход в аккаунт" << endl;
        //cout << "3-: " << endl;
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
        }

    }
    return 0;
   
}

