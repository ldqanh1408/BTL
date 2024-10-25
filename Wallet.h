#include<iostream>
#include<vector>
#include<fstream>
#include"bcrypt.h"
#include<random>
using namespace std;

string random_ID() {   //random 12 số, chia ra 3 phần random
    string res = "";
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> uni(1, 9999);

    for(int i = 0; i < 3; i++) {
        int tmp = uni(rng);
        string s = to_string(tmp);
        res += string(4 - s.size(), '0') + s;
    }

    return res;
}

class Wallet {
    private:
        string ID;
        long long total;
    public:
        Wallet() {
            string ID = bcrypt::generateHash(random_ID());
            ofstream outfile_ID("user_wallet/" + ID + ".txt"); //ten file
            outfile_ID.close();
        }

        string get_ID() { return ID; }
};
