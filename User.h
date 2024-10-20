#include<iostream>
#include"Account.h"
#include"Information.h"
using namespace std;

class User : public Information {
private:
    Account account; 
public:
    User() {}
    void set_user_name(string _user_name) {
        this->account.set_user_name(_user_name);
    }
    void set_password(string _password) {
        this->account.set_password(_password);
    }
    
};
