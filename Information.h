#ifndef INFORMATION_H
#define INFORMATION_H

#include <iostream>
#include <fstream>
#include "bcrypt.cpp"
#include "blowfish.cpp"
#include "gotp.cpp"
#include <filesystem>

extern std::string folder1, folder3;
extern std::string file_path1;

class Information {
protected:
    std::string full_name, address, country, phone_number, ID;
    unsigned long long balance;
    int age; 
    bool gender;

public:
    Information();
    
    std::string get_full_name() const;
    std::string get_address() const;
    std::string get_country() const;
    std::string get_phone_number() const;
    int get_age() const;
    bool get_gender() const;
    std::string get_ID() const;
    unsigned long long get_balance() const;


    void set_balance(unsigned long long _balance);
    void set_ID(std::string _ID = "");
    void set_full_name(const std::string& _full_name);
    void set_address(const std::string& _address);
    void set_country(const std::string& _country);
    bool set_phone_number(const std::string& _phone_number);
    bool set_age(int _age);
    void set_gender(bool _gender);

    friend std::istream& operator>>(std::istream &in, Information &data);
    friend std::ostream& operator<<(std::ostream &os, Information &person);
};

#endif
