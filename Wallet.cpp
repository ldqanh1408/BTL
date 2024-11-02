#include <fstream>
#include "bcrypt.h"
#include <random>
#include <filesystem>
#include "gotp.h"
#include "Wallet.h"

Wallet::Wallet() {}

std::string Wallet::get_ID() { return ID; }
