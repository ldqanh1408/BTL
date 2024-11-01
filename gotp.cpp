#include <random>
#include <string>
#include <iostream>
#include "gotp.h"

std::string gotp::generate_otp() {
    const std::string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    constexpr int length_otp = 6, length_str = 62;

    std::string otp = "";
    for (int i = 0; i < length_otp; ++i) {
        otp += str[gen() % length_str];
    }
    return otp;
}

bool gotp::verify_otp() {
    std::string otp = gotp::generate_otp();
    std::cout << "OTP đã được gửi: " << otp << std::endl;

    std::string entered_otp;
    std::cout << "Nhập OTP: ";
    std::cin >> entered_otp;

    if (otp == entered_otp) {
        std::cout << "Xác thực OTP thành công";
    } else {
        std::cout << "Xác thực OTP thất bại";
    }
    std::cout << std::endl;
    return otp == entered_otp;
}
