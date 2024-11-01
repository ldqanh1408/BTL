#ifndef GOTP_H
#define GOTP_H

#include <random>
#include <string>
#include <iostream>

namespace gotp {
    std::mt19937 gen(std::random_device{}());          // Định nghĩa mt19937

    std::string generate_otp();

    bool verify_otp();

}
#endif
