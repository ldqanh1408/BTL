#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include "Menu.h"
#include "Account.h"
#include "gotp.h"

using namespace std;
// Avoid using namespace std in headers to prevent conflicts

namespace Console {
    void print(int x, int y, string s);

    string input(int x, int y, bool is_plus, bool is_password, int mn);

    string change(string& title, string& enter_new, string& old_ans, string& old_password, bool age, bool gender, bool phone_number);

    bool create_account();

    void change_information();

    void print_information();
}

#endif
