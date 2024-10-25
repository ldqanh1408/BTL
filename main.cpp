#include<iostream>
#include<fstream>
#include<filesystem>
#include <random>
#include"User.h"
#include"bcrypt.cpp"
#include"blowfish.cpp"
using namespace std;

namespace fs = filesystem;

extern string generate_otp() {
    // All possible characters of my OTP
    const string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    constexpr int length_otp = 6, length_str = 62;

    random_device rd;           // Sử dụng random_device để làm seed
    mt19937 gen(rd());          // Bộ sinh số Mersenne Twister
    string otp = "";
    for(int i = 0; i < length_otp; ++i) otp += str[gen() % length_str];
    return otp;
}   

const string folder1 = "user_information/", folder2 = "user_password/";

string generate_password(User &person) {
    string first_name = "", full_name = person.get_full_name();
    for(int i = full_name.size(); i >= 0 && full_name[i] != ' '; --i) {
        first_name = full_name + first_name;
    }

    return first_name +  "&&" + to_string(person.get_age()) + "&&" + to_string(int(person.get_gender()));
}

bool create_account() {

    cout << "Tên tài khoản: ";
    string new_account; cin >> new_account;
    cout << endl;

    string file_path1 = folder1 + new_account + ".txt", file_path2 = folder2 + new_account + ".txt";

    ofstream outfile1(file_path1), outfile2(file_path2);

    if(fs::exists(file_path1)) {
        cout << "Tài khoản đã tồn tại" << endl;
        return 0;
    }

    if (!outfile1 || !outfile2) {
        cerr << "Error" << endl;
        return 0;
    }

    User person; cin >> person;
    string auto_password = generate_password(person);
    person.set_user_name(new_account);
    person.set_password(auto_password);

    // thiếu kiểm tra điều kiện nhập vào
    outfile1 << person.get_full_name() << endl;
    outfile1 << person.get_address() << endl;
    outfile1 << person.get_country() << endl;
    outfile1 << person.get_phone_number() << endl;
    outfile1 << person.get_age() << endl;
    outfile1 << person.get_gender() << endl;

    string hash = bcrypt::generateHash(auto_password);
    outfile2 << hash << endl;

    outfile1.close();
    outfile2.close();
    return 1;
}


int main() {
    return 0;
}