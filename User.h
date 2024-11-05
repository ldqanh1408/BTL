#ifndef USER_H
#define USER_H

#include <iostream>
#include <iomanip>
#include "Account.cpp"
#include "Information.cpp"
#include <filesystem>
#include "User.h"
#include <fstream>

extern std::string folder4, folder5;
namespace fs = std::filesystem;

// bool valid_money(std::string money) {
//     for(char &c : money) {
//         if(!std::isdigit(c)) return false;
//     }
//     return true;
// }

class User : public Information {
private:
    Account account;
public:
    User();
    User(Information &i, Account &j);

    void set_account(Account _account, bool is_tmp = 0);
    
    void set_information(Information _information, bool is_tmp = 0);

    int transfer_money(std::string &ID_B, std::string &amount);

};

#endif
