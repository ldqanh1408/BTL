#include<iostream>
#include<fstream>
#include<filesystem>
#include <random>
#include"User.h"
#include"bcrypt.cpp"
#include"blowfish.cpp"
using namespace std;

namespace fs = filesystem;

extern random_device rd;           // Sử dụng random_device để làm seed
extern mt19937 gen(rd());          // Bộ sinh số Mersenne Twister

extern string generate_ID() {   //random 12 số, chia ra 3 phần random
    string res = "";
    uniform_int_distribution<int> uni(1, 9999);

    for(int i = 0; i < 3; i++) {
        int tmp = uni(gen);
        string s = to_string(tmp);
        res += string(4 - s.size(), '0') + s;
    }

    return res;
}

extern string generate_otp() {
    // All possible characters of my OTP
    const string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    constexpr int length_otp = 6, length_str = 62;

    string otp = "";
    for(int i = 0; i < length_otp; ++i) otp += str[gen() % length_str];
    return otp;
}
extern bool verify_otp() {
    string otp = generate_otp();
    cout << "OTP đã được gửi: " << otp << endl;

    string entered_otp;
    cout << "Nhập OTP: ";
    cin >> entered_otp;

    if(otp == entered_otp) {
        cout << "Xác thực OTP thành công";
    } else {
        cout << "Xác thực OTP thất bại";
    }
    cout << endl;
    return otp == entered_otp;
}


const extern string folder1 = "data/store_information/", folder2 = "data/store_password/", 
                    folder3 = "data/store_wallet/", folder4 = "data/user_transaction_history/";

const extern string file_path = "data/transaction_log.txt";

string generate_password(User &person) {
    string first_name = "", full_name = person.get_full_name();
    for(int i = full_name.size(); i >= 0 && full_name[i] != ' '; --i) {
        first_name = full_name + first_name;
    }

    return first_name +  "&" + to_string(person.get_age()) + "&" + to_string(int(person.get_gender()));
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
    string new_password = generate_password(person);
    person.set_account(Account(new_account, new_password));

    // thiếu kiểm tra điều kiện nhập vào
    outfile1 << person.get_full_name() << endl;
    outfile1 << person.get_address() << endl;
    outfile1 << person.get_country() << endl;
    outfile1 << person.get_phone_number() << endl;
    outfile1 << person.get_age() << endl;
    outfile1 << person.get_gender() << endl;

    string hash = bcrypt::generateHash(new_password);
    outfile2 << hash << endl;

    outfile1.close();
    outfile2.close();
    return 1;
}


int main() {
    cout << "HI" << endl;
    return 0;
}