#ifndef WALLET_H
#define WALLET_H
#include<fstream>
#include"bcrypt.h"
#include<random>
#include<filesystem>
#include"gotp.h"

extern std::string folder3 = "data/store_wallet/";

class Wallet {
    private:
        std::string ID;
    public:
        Wallet();

        std::string get_ID();
};

#endif
