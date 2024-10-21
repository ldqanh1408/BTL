#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

extern const string mainn = "user_history/all.txt";

class Wallet {
    private:
        static unsigned long long id;
        static unsigned long long sum;

        long long total;
        vector<string> data;
        string mdd;
        string path;
    public:
        Wallet() {
            total = 0;
            id++;
            
            string s = to_string(id);
            string mdd = string(18 - s.size(), '0') + s;    // Mã định danh
            path = "user_wallet/" + mdd + ".txt";
            ofstream outfile(path);
            outfile << "0";
            outfile.close();
        }

        string get_mdd() { return mdd; }
        int get_total() { return total; }

        void tru_tien(long long x) { 
            total -= x;  
            sum -= x;
            ofstream outfile(path);
            outfile << to_string(total);
            outfile.close();
            }

        void cong_tien(long long x) { 
            total += x;  
            sum += x;
            ofstream outfile(path);
            outfile << to_string(total);
            outfile.close();
        }
};
