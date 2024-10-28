#ifndef GOTP_H
#define GOTP_H

#include <random>
#include <string>
#include <iostream>
using namespace std;

namespace gotp {
    mt19937 gen(random_device{}());          // Định nghĩa mt19937

    string generate_otp()  {
        const string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        constexpr int length_otp = 6, length_str = 62;

        string otp = "";
        for(int i = 0; i < length_otp; ++i) otp += str[gen() % length_str];
        return otp;
    }

    bool verify_otp(){
        string otp = gotp::generate_otp();
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

}
#endif
