#ifndef USER_H
#define USER_H

#include <filesystem>
#include "Wallet.h"
#include "Account.h"
#include "Information.h"

extern std::string folder4 = "data/user_transaction_history/",
                   folder5 = "data/transaction_log/";
namespace fs = std::filesystem;

// bool valid_money(std::string money) {
//     for(char &c : money) {
//         if(!std::isdigit(c)) return false;
//     }
//     return true;
// }

class User : public Information {
private:
    Account account;
    Wallet wallet; 
public:
    User();

    void set_account(Account _account);

    void set_full_name(const std::string& name);

    void set_address(const std::string& addr);

    void set_country(const std::string& country);

    void set_phone_number(const std::string& phone);

    void set_age(int age);

    void set_gender(bool gender);

    bool change_password();

    // void transfer_money(User &b) {
    //     auto valid_money = [&](std::string &money) -> bool {
    //         for (char &c : money) {
    //             if (!std::isdigit(c)) return false;
    //         }
    //         return true;
    //     };

    //     auto error_transaction_log = [&](unsigned long long amount, const std::string &error_msg) {
    //         // Lấy thời gian hiện tại
    //         time_t now = time(nullptr);
    //         struct tm *tm_info = localtime(&now);
            
    //         char time_buffer[80];
    //         strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d_%H-%M-%S", tm_info); // Định dạng thời gian
    //         std::string error_log_file = folder5 + std::string(time_buffer) + ".txt"; // Tạo tên file

    //         std::ofstream error_log(error_log_file, std::ios::app);
    //         if (error_log.is_open()) {
    //             error_log << std::ctime(&now) << " - " << "Transaction Error: " << error_msg
    //                     << " | From: " << this->Information::get_full_name() << " (ID: " << this->wallet.get_ID() << ")"
    //                     << " | To: " << b.Information::get_full_name() << " (ID: " << b.wallet.get_ID() << ")"
    //                     << " | Amount: " << amount << '\n';
    //             error_log.flush();
    //             error_log.close();
    //         } else {
    //             // backup
    //         }
    //     };

    //     std::string hash_a = bcrypt::generateHash(this->wallet.get_ID());
    //     std::string hash_b = bcrypt::generateHash(b.wallet.get_ID());
    //     std::string wallet_b = folder3 + hash_b + ".txt";
    //     std::string wallet_a = folder3 + hash_a + ".txt";

    //     if (!fs::exists(wallet_b) || (this->wallet.get_ID() == b.wallet.get_ID())) {
    //         std::cout << "Tài khoản không tồn tại! " << std::endl;
    //         return;
    //     }

    //     std::string temp_wallet_a = wallet_a + ".tmp";
    //     std::string temp_wallet_b = wallet_b + ".tmp";

    //     std::ofstream outfile_a(temp_wallet_a);
    //     std::ofstream outfile_b(temp_wallet_b);
    //     std::ifstream infile_a(wallet_a);
    //     std::ifstream infile_b(wallet_b);

    //     if (!infile_a || !infile_b || !outfile_a || !outfile_b) {
    //         std::cout << "Lỗi giao dịch vui lòng thử lại!" << std::endl;
    //         return;
    //     }

    //     unsigned long long balance_a, balance_b, d_valid = 0;
    //     infile_a >> balance_a;
    //     infile_b >> balance_b;
    //     infile_a.close();
    //     infile_b.close();

    //     std::string d;
    //     std::cout << "Nhập số tiền cần chuyển: ";
    //     std::getline(std::cin, d);
    //     if (valid_money(d)) {
    //         for (char c : d) {
    //             d_valid = d_valid * 10ULL + (c - '0');
    //         }
    //     } else {
    //         std::cout << "Số tiền nhập vào không hợp lệ" << std::endl;
    //         return;
    //     }

    //     if (balance_a < d_valid) {
    //         std::cout << "Số tiền trong tài khoản không đủ!" << std::endl;
    //         return;
    //     } else if (!gotp::verify_otp()) {
    //         return;
    //     }

    //     balance_a -= d_valid;
    //     balance_b += d_valid;

    //     outfile_a << balance_a;
    //     outfile_a.flush();
    //     if (!outfile_a.good()) {
    //         error_transaction_log(d_valid, "Ghi không thành công vào ví A");
    //         return;
    //     }

    //     outfile_b << balance_b;
    //     outfile_b.flush();
    //     if (!outfile_b.good()) {
    //         error_transaction_log(d_valid, "Ghi không thành công vào ví B");
    //         return;
    //     }

    //     outfile_a.close();
    //     outfile_b.close();

    //     try {
    //         fs::rename(temp_wallet_a, wallet_a);
    //         fs::rename(temp_wallet_b, wallet_b);
    //     } catch (const std::exception &e) {
    //         error_transaction_log(d_valid, "Lỗi đổi tên tệp sau khi ghi");
    //         return;
    //     }

    //     time_t now = time(nullptr);
    //     struct tm *tm_info = localtime(&now);
        
    //     char transaction_buffer[80];
    //     strftime(transaction_buffer, sizeof(transaction_buffer), "%Y-%m-%d_%H-%M-%S", tm_info); // Định dạng thời gian
    //     std::string transaction_log_file = folder5 + std::string(transaction_buffer) + ".txt";

    //     std::ofstream update_a(folder4 + this->Information::get_full_name() + ".txt", std::ios::app);
    //     std::ofstream update_b(folder4 + b.Information::get_full_name() + ".txt", std::ios::app);
    //     std::ofstream update_transaction_log(transaction_log_file, std::ios::app);

    //     if (update_transaction_log.is_open()) {
    //         time_t now = time(nullptr);
    //         update_transaction_log << std::ctime(&now) << " - " << "Completed Transfer"
    //                             << " | From: " << this->Information::get_full_name() << " (ID: " << this->wallet.get_ID() << ")"
    //                             << " | To: " << b.Information::get_full_name() << " (ID: " << b.wallet.get_ID() << ")"
    //                             << " | Amount: " << d_valid << '\n';
    //         update_transaction_log.flush();
    //         update_transaction_log.close();
    //     } else {
    //         error_transaction_log(d_valid, "Không ghi được log giao dịch");
    //     }

    //     update_a << "Bạn đã chuyển " << d_valid << " điểm cho " << b.Information::get_full_name() << std::endl;
    //     update_b << "Bạn đã nhận được " << d_valid << " điểm từ " << this->Information::get_full_name() << std::endl;

    //     update_a.flush();
    //     if (!update_a.good()) {
    //         error_transaction_log(d_valid, "Không ghi được thông báo update cho tài khoản A");
    //     }

    //     update_b.flush();
    //     if (!update_b.good()) {
    //         error_transaction_log(d_valid, "Không ghi được thông báo update cho tài khoản B");
    //     }

    //     update_a.close();
    //     update_b.close();
    // }
};

#endif
