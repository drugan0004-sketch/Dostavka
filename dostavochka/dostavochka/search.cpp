#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <windows.h>
#include <clocale>
#include <vector>
#include "header.h"

using namespace std;

//функция поиска + корзина + офрмление заказа

void search() {

	//setlocale(LC_ALL, "Russian");
	//SetConsoleOutputCP(1251);
	//SetConsoleCP(1251);

	ifstream file("menu.txt");

	int k = 0;
	string line;
	while (getline(file, line)) {
		k += 1;
	}

	file.clear();
	file.seekg(0, ios::beg);
	//перетащим значения из блокнота в массив (меню)
	string* menu = new string[k];
	for (int i = 0; i < k; i += 1) {
		getline(file, menu[i]);
	}

	//объявим вектор для корзины продуктов
	vector<string> cart;

	while (true) {
		string chois = "хз че писать";
		cout << "\n \nГлавная \nвыберите действие: \n";
		cout << "1 - Корзина" << endl << "2 - Меню" << endl << "ваш выбор (1 или 2): "; cin >> chois; cout << endl; cin.ignore(10000, '\n');

		if (chois == "1") {
			cout << "количество продуктов в вашей корзине: " << cart.size() << endl;
			if (cart.size() == 0) {
				cout << "\nдля оформления заказа выберите хотя бы один продукт из нашего меню";
			}
			else {
				cout << "\nсодержимое корзины: \n\n";
				for (int i = 0; i < cart.size(); i += 1) {
					cout << cart[i] << endl;
				}
				cout << "\nчтобы оформить заказ, напишите - оформить, чтобы выйти в главное меню напишите - выход";
				string new_chois; cout << "\nваш выбор: "; cin >> new_chois;
				if (new_chois == "выход") {

				}
				else if (new_chois == "оформить") {
					cout << "\nзаказ успешно оформлен, оплата при получении\n"; break;
				}
				else {
					cout << "\nнекорректный ввод, попробуйте снова";
				}
			}
		}
		else if (chois == "2") {
			cout << "Выберите продукт, который вы хотите положить в корзину: \n";
			int count = 1;
			for (int i = 0; i < k; i += 1) {
				cout << left << setw(3) << count << " " << menu[i] << endl;
				count += 1;
			}
			string chois2;
			cout << "чтобы выбрать продукт из меню нажмите следующее: \n";
			cout <<
				"поиск - для поиска по названию"
				<< endl << "выход - для выхода в главное меню"
				<< endl << "номер продукта из меню, чтобы сразу добавить его в корзину\n" << endl;

			cout << "ваш выбор: "; cin >> chois2;
			if (chois2 == "выход") {

			}
			else if (chois2 == "поиск") {
				cin.ignore(10000, '\n');
				string search;
				cout << "введите букву или набор букв, дабы найти соответствия в меню: ";
				getline(cin, search);
				int dol = 0; //счетчик для условия
				int count3 = 1;
				for (int i = 0; i < k; i += 1) {
					if (menu[i].find(search) != string::npos) {
						cout << left << setw(3) << count3 << " " << menu[i] << endl;
						dol += 1;
						count3 += 1;
					}
				}
				if (dol != 0) {
					string num;
					string* new_menu_for_search = new string[dol]; // перенимаем значения результатов поиска в массив
					int new_count = 0;
					for (int i = 0; i < k; i += 1) {
						if (menu[i].find(search) != string::npos) {
							new_menu_for_search[new_count] = menu[i];
							new_count += 1;
						}
					}
					cout << "\nвыберите номер продукта (от 1 до " << count3 - 1 << "): "; cin >> num;
					cin.ignore(10000, '\n');
					try {
						int num1 = stoi(num);
						if ((num1 < count3) && (num1 > 0)) {
							cart.push_back(new_menu_for_search[num1 - 1]); cout << new_menu_for_search[num1 - 1] << " - успешно добавлен в корзину";
						}
						else {
							cout << "\nневерный ввод, продукт не был добавлен в корзину";
						}
					}
					catch (const invalid_argument& e) {
						cout << "\nневерный ввод, нужно ввести номер продукта из списка";
					}
					delete[] new_menu_for_search;
				}
				if (dol == 0) {
					cout << "соответствий не нашлось";
				}
			}

			else {
				try {
					int chois3 = stoi(chois2);
					if ((chois3 > 0) && (chois3 < k + 1)) {
						cart.push_back(menu[chois3 - 1]);
						cout << menu[chois3 - 1] << " - успешно добавлен в корзину";
					}
					else {
						cout << "\nнеправильный ввод, попробуйте снова";
					}
				}
				catch (const invalid_argument& e) {
					cout << "некорректный ввод, попробуйте снова";
				}
			}
		}
		else {
			cout << "\nнекорректный ввод, попробуйте снова";
		}
	}
	delete[] menu;
}
