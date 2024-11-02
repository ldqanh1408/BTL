#ifndef INFORMATION_H
#define INFORMATION_H

#include <iostream>

extern std::string folder1;

class Information {
protected:
    std::string full_name, address, country, phone_number;
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
