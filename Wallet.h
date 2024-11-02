#ifndef WALLET_H
#define WALLET_H
#include <fstream>
#include "bcrypt.h"
#include <random>
#include <filesystem>
#include "gotp.h"

extern std::string folder3;

class Wallet {
    private:
        std::string ID;
    public:
        Wallet();
        void set_ID(std::string &_ID);
        std::string get_ID();
};

#endif
