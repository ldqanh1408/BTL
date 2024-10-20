#include<iostream>
using namespace std;

class Account {
private:
    string user_name, password;
public:
    void set_user_name_from_account(string _user_name) {this->user_name = _user_name;}
    Account() {}
    
};
