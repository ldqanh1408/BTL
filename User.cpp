#include "User.h"


// bool valid_money(std::string money) {
//     for(char &c : money) {
//         if(!std::isdigit(c)) return false;
//     }
//     return true;
// }
namespace fs = std::filesystem;
std::string folder4 = "data/user_transaction_history/",
            folder5 = "data/transaction_log.txt";

User::User() {}
User::User(Information &i, Account &j) {
    Information::set_ID();
    set_account(j);
    set_information(i);
}

Account User::get_account() const {
    return this->account; 
}

void User::set_account(Account _account, bool is_tmp) {
    this->account = _account;
    if(!is_tmp) {
         // chưa thêm toán tư = cho account
        std::ofstream of(folder2 + account.get_user_name() + ".txt");
        of << bcrypt::generateHash(account.get_password());
        of.close();
        // chưa xử lý ghi file lỗi
    }
}   


void User::set_information(Information _information, bool is_tmp) {
    this->full_name = _information.get_full_name();
    this->address = _information.get_address();
    this->country = _information.get_country();
    this->phone_number = _information.get_phone_number();
    this->age = _information.get_age();
    this->gender = _information.get_gender();
    if(!is_tmp) {
        std::ofstream outfile(folder1 + this->account.get_user_name() + ".txt");
        outfile << _information;
        outfile.close();
    }
}


int User::transfer_money(std::string &ID_B, std::string &amount) {
    auto valid_money = [&](std::string &money) -> bool {
        for (char &c : money) {
            if (!std::isdigit(c)) return false;
        }
        return true;
    };

    auto error_transaction_log = [&](unsigned long long amount, const std::string &error_msg) {
        // Get the current time
        std::time_t now = std::time(nullptr);
        struct std::tm *tm_info = std::localtime(&now);
        
        char time_buffer[80];
        std::strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d_%H-%M-%S", tm_info); // Format time
        std::string error_log_file = folder5; // Create file name

        std::ofstream error_log(error_log_file, std::ios::app);
        if (error_log.is_open()) {
            error_log << std::ctime(&now) << " - " << "Transaction Error: " << error_msg
                      << " | From: " <<  " (ID: " << this->get_ID() << ")"
                      << " | To: " << " (ID: " << ID_B << ")"
                      << " | Amount: " << amount << '\n';
            error_log.flush();
            error_log.close();
        } else {
            // backup
        }
    };

    std::string ID_A = this->get_ID();
    std::string hash_a = bcrypt::generateHash(this->get_ID());
    std::string hash_b = bcrypt::generateHash(ID_B);
    std::string wallet_b = folder3 + hash_b + ".txt";
    std::string wallet_a = folder3 + hash_a + ".txt";

    if (!fs::exists(wallet_b) || (this->get_ID() == ID_B)) {
        return 1;
    }

    std::string temp_wallet_a = wallet_a + ".tmp";
    std::string temp_wallet_b = wallet_b + ".tmp";

    std::ofstream outfile_a(temp_wallet_a);
    std::ofstream outfile_b(temp_wallet_b);
    std::ifstream infile_a(wallet_a);
    std::ifstream infile_b(wallet_b);

    if (!infile_a || !infile_b || !outfile_a || !outfile_b) {
        return 2;
    }

    unsigned long long balance_a, balance_b, amount_valid = 0;
    infile_a >> balance_a;
    infile_b >> balance_b;
    infile_a.close();
    infile_b.close();

    if (valid_money(amount)) {
        for (char &c : amount) {
            amount_valid = amount_valid * 10ULL + 1ULL * (c - '0');
        }
    } else {
        return 3;
    }

    if (balance_a < amount_valid) {
        return 4;
    } else {
        int last_noti = gotp::verify_otp();
        if (last_noti != 7) return last_noti;
    }

    balance_a -= amount_valid;
    balance_b += amount_valid;

    outfile_a << balance_a;
    outfile_a.flush();
    if (!outfile_a.good()) {
        error_transaction_log(amount_valid, "Failed to write to wallet A");
        //thiếu
    }

    outfile_b << balance_b;
    outfile_b.flush();
    if (!outfile_b.good()) {
        error_transaction_log(amount_valid, "Failed to write to wallet B");
        //thiếu
    }

    outfile_a.close();
    outfile_b.close();

    try {
        fs::rename(temp_wallet_a, wallet_a);
        fs::rename(temp_wallet_b, wallet_b);
    } catch (const std::exception &e) {
        error_transaction_log(amount_valid, "Error renaming file after write");
        //thiếu
    }

    std::time_t now = std::time(nullptr);
    struct std::tm *tm_info = std::localtime(&now);
    char transaction_buffer[30];
    std::strftime(transaction_buffer, sizeof(transaction_buffer), "%Y-%m-%d_%H-%M-%S", tm_info); // Format time

    std::ofstream update_a(folder4 + ID_A + ".txt", std::ios::app);
    std::ofstream update_b(folder4 + ID_B + ".txt", std::ios::app);
    std::ofstream update_transaction_log(folder5, std::ios::app);

    if (update_transaction_log.is_open()) {


        update_transaction_log << std::string(transaction_buffer)
                            << " Transfer from " << (ID_A)
                            << " to " << (ID_B)
                            << " with amount: " << amount_valid
                            << '\n';

        update_transaction_log.flush();
        update_transaction_log.close();
    } else {
        error_transaction_log(amount_valid, "Failed to write transaction log");
    }

    update_a << std::setw(35) << std::left << std::string(transaction_buffer)              // Căn lề trái, độ rộng 35 cho ngày giao dịch
            << std::setw(40) << std::left << (ID_A + " transferred to " + ID_B) // Căn lề trái, độ rộng 40 cho chuỗi "ID_A transferred to ID_B"
            << std::setw(10) << std::right << amount_valid                     // Căn lề phải, độ rộng 10 cho số tiền giao dịch
            << std::endl;
    update_a << std::setw(35) << std::left << std::string(transaction_buffer)              // Căn lề trái, độ rộng 35 cho ngày giao dịch
            << std::setw(40) << std::left << (ID_A + " received from " + ID_B) // Căn lề trái, độ rộng 40 cho chuỗi "ID_A transferred to ID_B"
            << std::setw(10) << std::right << amount_valid                     // Căn lề phải, độ rộng 10 cho số tiền giao dịch
            << std::endl;     


    update_a.flush();
    if (!update_a.good()) {
        error_transaction_log(amount_valid, "Failed to update notification for account A");
    }

    update_b.flush();
    if (!update_b.good()) {
        error_transaction_log(amount_valid, "Failed to update notification for account B");
    }

    update_a.close();
    update_b.close();
    return 7;
}


