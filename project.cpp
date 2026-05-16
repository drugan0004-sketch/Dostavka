#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <clocale>
#include "header.cpp"
#include "login.cpp"
#include "search.cpp"
using namespace std;
int main()
{
    system("chcp 65001 > nul");
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);


    int select = 0;
    string login;
    string password;
    bool running_log = true;
    
    start1:
    while (running_log == true) {
        printlog();

        cin >> select;

        switch (select)
        {
        case 0:
            running_log = false;
            exit(1);
            break;

        case 1: {

            cin.ignore(); //после ввода select остаётся \n, который игнорируется этим
            login = get_log();
            password = get_pass();
            ofstream fout("users.txt", ios::out);

            if (!fout.is_open()) {
                cout << "Файл не открыт" << endl;
                break;
            }
            fout << login << endl << password << endl;//<<// address << endl;
            fout.close();
            login.clear(); password.clear();
            break;
        }
        
        case 2:
            cin.ignore();
            login = get_log();
            password = get_pass();
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
        start2:
        search();
        printrun();
        cin >> select;
        switch (select) {
            case 0:
                exit(1);
                break;
            case 1 :
                goto start2;
                break;
            case 2:
                running_log = 1;
                goto start1;
                break;
    }



    }

    return 0;
}
