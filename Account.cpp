#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "Account.h"

Account::Account() {
    this->auto_password = true;
}

Account::Account(std::string _user_name, std::string _password) {
    this->user_name = _user_name;
    this->password = _password;
}

std::string Account::get_user_name() { return user_name; } // tí xóa để sửa mục C

bool Account::valid_password(const std::string &_password) {
    if (_password.size() < 12 || _password.size() > 16) {
        std::cout << "Mật khẩu phải có độ dài từ 12 đến 16 ký tự." << std::endl;
        return false;
    }
    
    std::bitset<4> valid; 

    for (char c : _password) {
        if (c >= 'a' && c <= 'z') valid.set(0);
        else if (c >= 'A' && c <= 'Z') valid.set(1); 
        else if (c >= '0' && c <= '9') valid.set(2); 
        else if (c >= char(32) && c <= char(126)) valid.set(3);
        else {
            std::cout << "Mật khẩu chứa ký tự không hợp lệ." << std::endl;
            return false; 
        }
    }

    if (!valid.test(0)) std::cout << "Mật khẩu phải chứa ít nhất một ký tự viết thường." << std::endl; 
    if (!valid.test(1)) std::cout << "Mật khẩu phải chứa ít nhất một ký tự viết hoa." << std::endl;
    if (!valid.test(2)) std::cout << "Mật khẩu phải chứa ít nhất một số." << std::endl; 
    if (!valid.test(3)) std::cout << "Mật khẩu phải chứa ít nhất một ký tự đặc biệt." << std::endl;
    if (!gotp::verify_otp()) return false;

    return valid.all(); 
}

bool Account::set_password(const std::string &_password) {
    if (auto_password || valid_password(_password)) {
        this->password = _password;
        if (!auto_password) std::cout << "Mật khẩu hợp lệ." << std::endl;
        else auto_password = false;
        
        return true;
    } else {
        std::cout << "Mật khẩu không hợp lệ. Vui lòng thử lại." << std::endl;
        return false;
    }
}
