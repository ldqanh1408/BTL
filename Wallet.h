#include<fstream>
#include"bcrypt.h"
#include<random>
#include<filesystem>
#include"gotp.h"

using namespace std;
extern string folder3 = "data/store_wallet/";

class Wallet {
    private:
        string ID;
    public:
        Wallet() {
            auto generate_ID = [&]()->string {
                string res = "";
                uniform_int_distribution<int> uni(1, 9999);
                for(int i = 0; i < 3; i++) {
                    int tmp = uni(gotp::gen);
                    string s = to_string(tmp);
                    res += string(4 - s.size(), '0') + s;
                }
                return res;
            };
            this->ID = generate_ID();
            string hash = bcrypt::generateHash(ID);
            ofstream outfile_ID(folder3 + hash + ".txt"); //ten file
            // if (filesystem::exists(outfile_ID)) {
            //     // Handle the case where the file already exists
            // }
            outfile_ID << 0;
            outfile_ID.close();
        }

        string get_ID() { return ID; }
};
