#include "Information.h"

std::string folder1 = "data/store_information/", folder3 = "data/store_wallet/";

Information::Information() {}

// Getter functions
std::string Information::get_full_name() const { return this->full_name; }
std::string Information::get_address() const { return this->address; }
std::string Information::get_country() const { return this->country; }
std::string Information::get_phone_number() const { return this->phone_number; }
int Information::get_age() const { return this->age; }
bool Information::get_gender() const { return this->gender; }
std::string Information::get_ID() const { return this->ID; }

// Setter functions
void Information::set_ID(std::string _ID) { 
    if(!_ID.empty()) {
        this->set_ID(_ID);
    } else {
        auto generate_ID = [&]() -> std::string {
            std::string res = "";
            std::uniform_int_distribution<int> uni(1, 9999);
            for (int i = 0; i < 3; i++) {
                int tmp = uni(gotp::gen);
                std::string s = std::to_string(tmp);
                res += std::string(4 - s.size(), '0') + s;
            }
            return res;
        };
        std::string ID_tmp;
        do {
            ID_tmp = generate_ID();
        } while(std::filesystem::exists(folder3 + bcrypt::generateHash(ID_tmp) + ".txt"));
        this->set_ID(ID_tmp);
        std::ofstream outfile_ID(folder3 + bcrypt::generateHash(ID_tmp) + ".txt"); // tên file
        outfile_ID << 0;
        outfile_ID.close();
    }
}
void Information::set_full_name(const std::string& _full_name) { this->full_name = _full_name; }
void Information::set_address(const std::string& _address) { this->address = _address; }
void Information::set_country(const std::string& _country) { this->country = _country; }

bool Information::set_phone_number(const std::string& _phone_number) {
    for(const char &c : _phone_number) {
        if(!isdigit(c)) return false;
    }
    this->phone_number = _phone_number;
    return true;
}

bool Information::set_age(int _age) {
    if(_age < 0) return false;
    this->age = _age;
    return true;
}

void Information::set_gender(bool _gender) { this->gender = _gender; }

// Operator overloads
std::istream& operator>>(std::istream& in, Information& data) {
    std::getline(in, data.full_name);
    std::getline(in, data.address);
    std::getline(in, data.country);
    std::getline(in, data.phone_number);
    in >> data.ID;
    in >> data.age;
    in >> data.gender;

    return in;
}

std::ostream& operator<<(std::ostream& os, Information& person) {
    os << person.get_full_name() << "\n"
       << person.get_address() << "\n"
       << person.get_country() << "\n"
       << person.get_phone_number() << "\n"
       << person.get_ID() << "\n"
       << person.get_age() << "\n"
       << (person.get_gender() ? "Male" : "Female") << "\n";
    return os;
}
