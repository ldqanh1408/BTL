#ifndef ACCOUNT_H
#define ACCOUNT_H


#include <iostream>
#include <bitset>
#include <string>

// Khai báo `folder2` là biến extern để sử dụng trong các tệp khác
extern std::string folder2;

class Account {
private:
    std::string user_name, password;

public:
    Account();
    Account(std::string _user_name, std::string _password);

    std::string get_user_name();
    std::string get_password();
    bool valid_password(const std::string &_password);
    bool set_password(const std::string &_password);
    void set_user_name(const std::string &_user_name);
};

#endif // ACCOUNT_H
