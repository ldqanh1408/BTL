#include<iostream>
#include<fstream>
#include <filesystem>
#include"User.h"
using namespace std;

bool create_account() {
    const string folder = "user_information/";

    cout << "Tên tài khoản: ";
    string new_account; cin >> new_account;
    cout << endl;

    string file_path = folder + new_account + ".txt";

    ofstream outfile(file_path);

    if(filesystem::exists(file_path)) {
        cout << "Tài khoản đã tồn tại" << endl;
        return 0;
    }

    if (!outfile) {
        cerr << "Error" << endl;
        return 0;
    }
    User person; cin >> person;

    person.set_user_name_from_user(new_account);
    outfile << person.get_full_name() << endl;
    outfile << person.get_address() << endl;
    outfile << person.get_country() << endl;
    outfile << person.get_phone_number() << endl;
    outfile << person.get_age() << endl;
    outfile << person.get_gender() << endl;
    
    outfile.close();

    return 1;
}


int main() {
    User A; cin >> A;
    return 0;
}