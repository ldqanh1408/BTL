#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include "Menu.h"
#include "Account.h"
#include "gotp.h"

// Avoid using namespace std in headers to prevent conflicts

namespace Console {
    void print(int x, int y, std::string s);

    std::string input(int x, int y, bool is_plus, bool is_password, int mn);

    std::string change(std::string& title, std::string& enter_new, std::string& old_ans, std::string& old_password, bool age, bool gender, bool phone_number);

    bool create_account();

    void change_information();

    void print_information();

    void transfer_money();

    void transaction_history();

    void Start_The_Program();
}

#endif
