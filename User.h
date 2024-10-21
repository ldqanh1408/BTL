#include<iostream>
#include"Account.h"
#include"Information.h"
#include"Wallet.h"
using namespace std;

class User : public Information {
private:
    Account account;
    Wallet wallet; 
public:
    User() {}
    void set_user_name(string _user_name) {
        this->account.set_user_name(_user_name);
    }
    void set_password(string _password) {
        this->account.set_password(_password);
    }
    void chuyen_tien(User &b) {
        string total;

        while(1) {
            cout << "Nhập số tiền cần chuyển: ";
            cin >> total;

            if(total.empty() || total[0] == '0') continue;
            bool oke = 1;

            for(char& c : total) {
                if(c < '0' || c > '9') oke = 0;
            }

            if(oke) break;
            else {
                cout << "\nSố tiền không hợp lệ, vui long nhập lại\n";
            }
        }

        long long totals = stoll(total);
        string tmp = "user.wallet/" + b.wallet.get_mdd() + ".txt";
        ofstream outfile(tmp);

        if(!fs::exists(tmp) ||  (wallet.get_mdd() == b.wallet.get_mdd())) {
            cout << "Tài khoản không tồn tại! " << endl;
            return;
            //hj
        }
        else {
            if(this->wallet.get_total() < totals) {
                cout << "Tài khoản của quý khách không đủ!" << endl;
                return;
            }
            else {
                outfile.close();
                this->wallet.tru_tien(totals);
                b.wallet.cong_tien(totals);

                ofstream All_history(mainn, ios::app);
                All_history << this->get_full_name() + " đã chuyển tiền cho " + b.get_full_name() << " " << totals << "VND" << endl;
                All_history.close();

                ofstream user1("user_history/" + this->wallet.get_mdd() + ".txt", ios::app);
                ofstream user2("user_history/" + b.wallet.get_mdd() + ".txt", ios::app);

                user1 << this->get_full_name() + " đã chuyển " << totals << "VND cho " << b.get_full_name() << endl;
                user2 << b.get_full_name() + " đã nhận " << totals << "VND từ " << this->get_full_name() << endl;

                user1.close();
                user2.close();
            }
        }
    }
};
