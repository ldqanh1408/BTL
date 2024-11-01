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
void Information::set_phone_number(const std::string& _phone_number) { this->phone_number = _phone_number; }
void Information::set_age(int _age) { this->age = _age; }
void Information::set_gender(bool _gender) { this->gender = _gender; }  

std::istream& operator>>(std::istream& in, Information& data) {
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

std::ostream& operator<<(std::ostream& os, Information& person) {
    os << "Full Name: " << person.get_full_name() << "\n"
       << "Address: " << person.get_address() << "\n"
       << "Country: " << person.get_country() << "\n"
       << "Phone Number: " << person.get_phone_number() << "\n"
       << "Age: " << person.get_age() << "\n"
       << "Gender: " << (person.get_gender() ? "Male" : "Female") << "\n";
    return os;
}
