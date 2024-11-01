#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <bitset>
#include "gotp.h"
#include <string>

extern std::string folder2 = "data/store_password/";

class Account {
private:
    std::string user_name, password;
    bool auto_password;
public:

    Account();
    Account(std::string _user_name, std::string _password);
    std::string get_user_name();
    bool valid_password(const std::string &_password);
    bool set_password(const std::string &_password);
};

#endif
