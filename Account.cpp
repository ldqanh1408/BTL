#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "Account.h"

std::string folder2 = "data/store_password/";

Account::Account() {
}

Account::Account(std::string _user_name, std::string _password) {
    this->user_name = _user_name;
    this->password = _password;
}

std::string Account::get_user_name() { return user_name; } // tí xóa để sửa mục C
std::string Account::get_password() { return password; } // tí xóa để sửa mục C
bool Account::valid_password(const std::string &_password) {
    
    std::bitset<4> valid; 

    for (char c : _password) {
        if (c >= 'a' && c <= 'z') valid.set(0);
        else if (c >= 'A' && c <= 'Z') valid.set(1); 
        else if (c >= '0' && c <= '9') valid.set(2); 
        else if (c >= char(32) && c <= char(126)) valid.set(3);
        else {
            return false; 
        }
    }

    return valid.all(); 
}

bool Account::set_password(const std::string &_password) {
    if (valid_password(_password)) {
        this->password = _password;

        return true;
    } else {
        return false;
    }
}
void Account::set_user_name(const std::string &_user_name) {
    this->user_name = _user_name;
}

