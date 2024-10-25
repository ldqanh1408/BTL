#include<iostream>
using namespace std;

class Information {
private:
    string full_name, address, country, phone_number;
    int age; bool gender;
public:
    Information() {}
    
    string get_full_name() {return this->full_name;}
    string get_address() {return this->address;}
    string get_country() {return this->country;}
    string get_phone_number() {return this->phone_number;}
    int get_age() {return this->age;}
    bool get_gender() {return this->gender;}  

    void set_full_name(const string& _full_name) { this->full_name = _full_name; }
    void set_address(const string& _address) { this->address = _address; }
    void set_country(const string& _country) { this->country = _country; }
    void set_phone_number(const string& _phone_number) { this->phone_number = _phone_number; }
    void set_age(int _age) { this->age = _age; }
    void set_gender(bool _gender) { this->gender = _gender; }  

    friend istream& operator>> (istream &in, Information &data) {
        cout << "Nhap thong tin nguoi dung:" << endl;
        cout << "Ho va ten: ";
        getline(in, data.full_name);
        cout << endl << "Tuoi: ";
        in >> data.age;
        cout << endl << "Dia chi: ";
        getline(in, data.address);
        cout << endl << "Quoc gia: ";
        getline(in, data.country);
        cout << endl << "So dien thoai: ";
        getline(in, data.phone_number);
        cout << endl << "Gioi tinh (1: Nam, 0: Nu): ";
        in >> data.gender;

        return in;
    }

    
};
