#include <fstream>
#include "bcrypt.h"
#include <random>
#include <filesystem>
#include "gotp.h"
#include "Wallet.h"

Wallet::Wallet() {
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
    this->ID = generate_ID();
    std::string hash = bcrypt::generateHash(ID);
    std::ofstream outfile_ID(folder3 + hash + ".txt"); // tên file
    // if (std::filesystem::exists(outfile_ID)) {
    //     // Handle trường hợp file đã tồn tại
    // }
    outfile_ID << 0;
    outfile_ID.close();
}

std::string Wallet::get_ID() { return ID; }
