#include <iostream>
#include <fstream>
#include<windows.h>
#include <string>
#include <registr.h>
#include"vhod.cpp"
using namespace std;
int main()
{
    int select = 0;
    string login;
    string password;
    bool running_log = true;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (running_log) {
        cout<<" Здревствуйте, гость. " << endl;
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
            running_log = false;
            break;
        
        case 1:
            login = get_log();
            password = get_pass();
            ofstream fout;
            fout.open("logins.txt", ios::out);
            fout<<login<<endl<<password<<endl;
            break;
        }
        case 2:
            if(IsLogin(login,password)){
                
            running_log = false;}
            break;

    }
    While(!running_log)
    {
        cout<<" Здревствуйте,"<< login << endl;
        cout << "Выберите действие: " << endl;
        cin >> select;
        
    }
    return 0;
   
}
