#include <iostream>
#include <registr.h>
#include <string>

std::string get_log() {
    std::string log;
    std::cout << "Введите логин:" << std::endl;
    std::getline(std::cin, log);
    return log;
}

std::string get_pass() {
    std::string pass;
    std::cout << "Введите пароль:" << std::endl;
    std::getline(std::cin, pass);
    return pass;
}