#include<iostream>
#include"Account.h"
#include"Information.h"
#include"Wallet.h"
using namespace std;

bool valid_money(string money) {
    for(char &c : money) {
        if(!isdigit(c)) return false;
    }
    return true;
}

class User : public Information {
private:
    Account account;
    Wallet wallet; 
public:
    User() {}

    void set_account(Account _account) {
        this->account = _account;
    }

    void set_full_name(const string& name) {
        Information::set_full_name(name);
        if(!verify_otp()) return;
        cout << "Thay đổi họ và tên thành công!" << endl;
    }

    void set_address(const string& addr) {
        Information::set_address(addr);
        if(!verify_otp()) return;
        cout << "Thay đổi địa chỉ thành công!" << endl;
    }

    void set_country(const string& country) {
        Information::set_country(country);
        if(!verify_otp()) return;
        cout << "Thay đổi quốc gia thành công!" << endl;
    }

    void set_phone_number(const string& phone) {
        Information::set_phone_number(phone);
        if(!verify_otp()) return;
        cout << "Thay đổi số điện thoại thành công!" << endl;
        
    }

    void set_age(int age) {
        if (age > 0) {
            Information::set_age(age);
            cout << "Thay đổi tuổi thành công!" << endl;
            if(!verify_otp()) return;
        } else {
            cout << "Tuổi không hợp lệ. Thay đổi thất bại!" << endl;
        }
    }

    void set_gender(bool gender) {
        Information::set_gender(gender);
        if(!verify_otp()) return;
        cout << "Thay đổi giới tính thành công!" << endl;
    }


    bool change_password() {
        string new_password, confirm_password;

        cout << "Nhập mật khẩu mới: ";
        cin >> new_password;
        cout << "Nhập lại mật khẩu mới: ";
        cin >> confirm_password;

        if (new_password != confirm_password) {
            cout << "Mật khẩu không khớp. Đổi mật khẩu thất bại." << endl;
            return false;
        }

        if (this->account.set_password(new_password)) {

            if (verify_otp()) {
                cout << "Đổi mật khẩu thành công!" << endl;
                return true;
            } else {
                cout << "Đổi mật khẩu thất bại." << endl;
                return false;
            }
        } else {
            cout << "Mật khẩu mới không hợp lệ. Đổi mật khẩu thất bại." << endl;
            return false;
        }
    }

    void transfer_money(User &b) {
        string hash_a = bcrypt::generateHash(this->wallet.get_ID()), hash_b = bcrypt::generateHash(b.wallet.get_ID());
        string wallet_b = folder3 + hash_b + ".txt";
        string wallet_a = folder3 + hash_a + ".txt";

        if (!fs::exists(wallet_b) || (this->wallet.get_ID() == b.wallet.get_ID())) { // kiểm tra ngoại lệ
            cout << "Tài khoản không tồn tại! " << endl;
            return;
        }

        string temp_wallet_a = wallet_a + ".tmp";
        string temp_wallet_b = wallet_b + ".tmp";

        // Mở tệp tạm cho ví A và B
        ofstream outfile_a(temp_wallet_a);
        ofstream outfile_b(temp_wallet_b);

        ifstream infile_a(wallet_a);
        ifstream infile_b(wallet_b);

        if (!infile_a || !infile_b || !outfile_a || !outfile_b) {
            cout << "Lỗi khi mở tệp!" << endl;
            return;
        }

        unsigned long long balance_a, balance_b, d_valid = 0;
        infile_a >> balance_a;
        infile_b >> balance_b;
        infile_a.close();
        infile_b.close();

        string d;
        cout << "Nhập số tiền cần chuyển: ";
        getline(cin, d);
        if (valid_money(d)) {
            for (char c : d) {
                d_valid = d_valid * 10ULL + (c - '0');
            }
        } else {
            cout << "Số tiền nhập vào không hợp lệ" << endl;
            return;
        }

        if (balance_a < d_valid) {
            cout << "Số tiền trong tài khoản không đủ!" << endl;
            return;
        } else if(!verify_otp()) {
            return;
        }

        cout << "Bạn đã giao dịch thành công!\n";
        balance_a -= d_valid;
        balance_b += d_valid;

        outfile_a << balance_a;
        outfile_b << balance_b;

        outfile_a.close();
        outfile_b.close();

        fs::rename(temp_wallet_a, wallet_a);
        fs::rename(temp_wallet_b, wallet_b); 

        ofstream update_a(folder4 + this->Information::get_full_name() + ".txt", ios::app);
        ofstream update_b(folder4 + b.Information::get_full_name() + ".txt", ios::app);
        ofstream update_transaction_log(file_path, ios::app);

        if (update_transaction_log.is_open()) {
            time_t now = time(nullptr);
            update_transaction_log << ctime(&now) << " - " << "Transfer"
                                << " | From: " << this->Information::get_full_name() << " (ID: " << this->wallet.get_ID() << ")"
                                << " | To: " << b.Information::get_full_name() << " (ID: " << b.wallet.get_ID() << ")"
                                << " | Amount: " << d_valid << '\n';
            update_transaction_log.close();
        }

        update_a << "Bạn đã chuyển " << d_valid << " điểm cho " << b.Information::get_full_name() << endl;
        update_b << "Bạn đã nhận được " << d_valid << " điểm từ " << this->Information::get_full_name() << endl;

        update_a.close();
        update_b.close();
    }

};
