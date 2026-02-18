#include <iostream>
#include<windows.h>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

// Родион - ПОИСК

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
    getline(cin, query);

    cout << "\n Результаты:" << endl;

    for (int i = 0; i < katalog.size(); i++) {
        if (katalog[i].find(query) != string::npos) {
            cout << "- " << katalog[i] << endl;
        }
    }
}

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    int select = 0;
    char login[20]{}, password[20]{};
    bool running = true;
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
        
        case 2:
            cout << "Введите логин" << endl;
            cin >> login;
            cout << "Введите логин" << endl;
            cin >> password;

        }

    }

    find_in_menu(); //для проверки, если в названии блюдо пишется с
    //большой буквы, то в поиске пишем с большой буквы
    // пример: "Наб" -> Набор ...

    return 0;
   
}

