#include<iostream>
using namespace std;
class Account {
private:
    string user_name, password;
public:
    void set_user_name(string _user_name) {this->user_name = _user_name;}
    void set_password(string _password) {this->password = _password;}
    Account() {

    }
    
};
