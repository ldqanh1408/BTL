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
        string wallet_b = "user.wallet/" + b.wallet.get_ID() + ".txt";
        string wallet_a = "user.wallet/" + this->wallet.get_ID() + ".txt";

        if(!fs::exists(wallet_b) ||  (this->wallet.get_ID() == b.wallet.get_ID())) { //kiểm tra ngoại lệ
            cout << "Tài khoản không tồn tại! " << endl;
            return;
        }

        ofstream user_a(wallet_a);
        ofstream user_b(wallet_b);

        ifstream file_a(wallet_a);
        ifstream file_b(wallet_b);

        string tmp, tmp1;
        getline(file_a, tmp);
        getline(file_b, tmp1);

        long long totals;
        long long so_du_a = stoll(tmp);
        long long so_du_b = stoll(tmp1);
        string total; //tiền cần chuyển
        

        while(1) {
            cout << "Nhập số tiền cần chuyển: ";
            cin >> total;

            if(total.empty() || total[0] == '0') continue;
            bool oke = 1;

            for(char& c : total) {
                if(c < '0' || c > '9') {    // Không phải kí tự số
                    oke = 0;
                    break;
                }
            }

            if(oke) {
                totals = stoll(total);

                if(so_du_a < totals) {
                    cout << "Số dư không đủ để thực hiện giao dịch\n";
                    cout << "Bạn có muốn nhập lại số tiền không!\n";
                    cout << "1 / 0\n";

                    while(1) {
                        string s; cin >> s;

                        if(s == "1") break;
                        else if(s == "0") return;
                        else {
                            cout << "Không hợp lệ, vui lòng nhập lại\n";
                        };
                    }
                }
            }
            else {
                cout << "\nSố tiền không hợp lệ, vui long nhập lại\n";
            }
        }
//dd
        cout << "Bạn đã giao dịch thành công!\n";
        so_du_a -= totals;
        so_du_b += totals;
        
        user_a << to_string(so_du_a);
        user_b << to_string(so_du_b);

        user_a.close();
        user_b.close();
        file_a.close();
        file_b.close();

        ofstream his_a("user_history/" + this->account.get_user_name() + ".txt", ios::app);
        ofstream his_b("user_history/" + b.account.get_user_name() + ".txt", ios::app);

        his_a << "Bạn đã chuyển " << totals << "VNĐ cho " << b.account.get_user_name() << endl;
        his_b << "Bạn đã nhận được " << totals << "VNĐ từ " << this->account.get_user_name() << endl;
        
        his_a.close();
        his_b.close();
    }
};
