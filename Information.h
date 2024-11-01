#ifndef INFORMATION_H
#define INFORMATION_H

#include <iostream>

extern std::string folder1 = "data/store_information/";

class Information {
private:
    std::string full_name, address, country, phone_number;
    int age; 
    bool gender;

public:
    Information();
    
    std::string get_full_name();
    std::string get_address();
    std::string get_country();
    std::string get_phone_number();
    int get_age();
    bool get_gender();

    void set_full_name(const std::string& _full_name);
    void set_address(const std::string& _address);
    void set_country(const std::string& _country);
    void set_phone_number(const std::string& _phone_number);
    void set_age(int _age);
    void set_gender(bool _gender);

    friend std::istream& operator>>(std::istream &in, Information &data);
    friend std::ostream& operator<<(std::ostream &os, Information &person);
};

#endif
