#include<iostream>
using namespace std;

class User {
private:
    string full_name, address, country, phone_number;
    int age; bool gender;

    string account, password;
public:
    User() {}

    friend istream& operator>> (istream &in, User &who) {
        cout << "Nhap thong tin nguoi dung:" << endl;
        cout << "Ho va ten: ";
        getline(in, who.full_name);
        cout << endl << "Ten dang nhap: ";
        getline(in, who.account);
        cout << endl << "Tuoi: ";
        in >> who.age;
        cout << endl << "Dia chi: ";
        getline(in, who.address);
        cout << endl << "Quoc gia: ";
        getline(in, who.country);
        cout << endl << "So dien thoai: ";
        getline(in, who.phone_number);
        cout << endl << "Gioi tinh (1: Nam, 0: Nu): ";
        in >> who.gender;
        cout << endl << "Mat khau: ";
        getline(in, who.password);

        return in;
    }
};
