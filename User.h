#include<iostream>
using namespace std;

class User {
private:
    string full_name, address, country, phone_number;
    int age;
    bool gender;
    //thêm 1 số thuộc tính
public:
    User(const string& _full_name, const string& _address, const string& _country, const string& _phone_number, const int& _age, const bool& _gender) {
        this->full_name = _full_name;
        this->address = _address;
        this->country = _country;
        this->phone_number = _phone_number;
        this->age = _age;
        this->gender = _gender;
    }
    //thêm code
};