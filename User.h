#include<iostream>
#include"Account.h"
#include"Information.h"
using namespace std;

class User : public Information {
private:
    Account account; 
public:
    User() {}
    void set_user_name_from_user(string _user_name) {
        this->account.set_user_name_from_account(_user_name);
    }
    
};
