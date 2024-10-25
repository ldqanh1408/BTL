#include<fstream>
#include"bcrypt.cpp"
#include"blowfish.cpp"
#include<random>
#include<filesystem>


class Wallet {
    private:
        string ID;
    public:
        Wallet() {
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
