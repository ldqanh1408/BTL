#include "Wallet.h"

std::string folder3 = "data/store_wallet/";

Wallet::Wallet() {}

std::string Wallet::get_ID() { 
    return this->ID; 
}

void Wallet::set_ID(std::string &_ID) { 
    this->ID = _ID; 
}
