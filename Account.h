#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <bitset>
#include "gotp.h"
#include <string>
using namespace std;
extern string folder2 = "data/store_password/";

class Account {
private:
    string user_name, password;
    bool auto_password;
public:

    Account();
    Account(string _user_name, string _password);
    string get_user_name();
    bool valid_password(const string &_password);
    bool set_password(const string &_password);

};
#endif