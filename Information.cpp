#include <iostream>
#include "Information.h"

Information::Information() {}

std::string Information::get_full_name() { return this->full_name; }
std::string Information::get_address() { return this->address; }
std::string Information::get_country() { return this->country; }
std::string Information::get_phone_number() { return this->phone_number; }
int Information::get_age() { return this->age; }
bool Information::get_gender() { return this->gender; }  

void Information::set_full_name(const std::string& _full_name) { this->full_name = _full_name; }
void Information::set_address(const std::string& _address) { this->address = _address; }
void Information::set_country(const std::string& _country) { this->country = _country; }
bool Information::set_phone_number(const std::string& _phone_number) {
    for(char &c : _phone_number) {
        if(!isdigit(c)) return 0;
    }
    this->phone_number = _phone_number;
    return 1;
}
bool Information::set_age(int _age) {
    if(_age < 0) return 0;
    this->age = _age;
    return 1;
}
void Information::set_gender(bool _gender) { this->gender = _gender; }  

std::istream& Information::operator>>(std::istream& in, Information& data) {
    std::cout << "Nhap thong tin nguoi dung:" << std::endl;
    std::cout << "Ho va ten: ";
    std::getline(in, data.full_name);
    std::cout << "Tuoi: ";
    in >> data.age;
    in.ignore(); // Ignore newline character left in the buffer
    std::cout << "Dia chi: ";
    std::getline(in, data.address);
    std::cout << "Quoc gia: ";
    std::getline(in, data.country);
    std::cout << "So dien thoai: ";
    std::getline(in, data.phone_number);
    std::cout << "Gioi tinh (1: Nam, 0: Nu): ";
    in >> data.gender;

    return in;
}

std::ostream& Information::operator<<(std::ostream& os, Information& person) {
    os << person.get_full_name() << " "
       << person.get_address() << " "
       << person.get_country() << " "
       << person.get_phone_number() << " "
       << person.get_age() << " "
       << (person.get_gender() ? "Male" : "Female") << " ";
    return os;
}
