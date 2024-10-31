#include<iostream>
#include<fstream>
#include<filesystem>
#include <random>
// #include"User.h"
#include"gotp.h"
// #include"bcrypt.cpp"
// #include"blowfish.cpp"
#include"Console.h"
#include "Menu.h"

using namespace std;
namespace fs = filesystem;



// bool create_account() {
    // auto generate_password = [&](User &person)->string {
    //     string first_name = "", full_name = person.get_full_name();
    //     for(int i = full_name.size() - 1; i >= 0 && full_name[i] != ' '; --i) {
    //         first_name = full_name[i] + first_name;
    //     }

    //     return first_name + "&" + to_string(person.get_age()) + "&" + to_string(int(person.get_gender()));
    // };

//     cout << "Tên tài khoản: ";
//     string new_account; cin >> new_account;
//     cout << endl;

//     string file_path1 = folder1 + new_account + ".txt", file_path2 = folder2 + new_account + ".txt";

//     ofstream outfile1(file_path1), outfile2(file_path2);

//     if(fs::exists(file_path1)) {
//         cout << "Tài khoản đã tồn tại" << endl;
//         return 0;
//     }
//     if (!outfile1 || !outfile2) {
//         cerr << "Error" << endl;
//         return 0;
//     }

//     User person; cin >> person;
//     string new_password = generate_password(person);
//     person.set_account(Account(new_account, new_password));

//     // thiếu kiểm tra điều kiện nhập vào
//     outfile1 << person;

//     string hash = bcrypt::generateHash(new_password);
//     outfile2 << hash << endl;

//     outfile1.close();
//     outfile2.close();
//     return 1;
// }


int main() {
    //thao tác của m ở đây, chỉnh sửa là trong kia
    //2 file header kia mà thiếu hàm thì m include thư viện vào
        bool oke = 1;
    
    while(oke) {

    	Menu::printLoginFrame();
    	
    	string username = Console::input(41, 7, true, false);
    	
    	if(username == "") { // end
    		break;
		}
		if(username == "+") {
			while(true) {
				if(Console::Create_Account() == 1) { // bam tab
					break;
				}
			}
			continue; // tro ve giao dien dang nhap
		}
		
		string password = Console::input(41, 10, true, true);
		
		if(password == "") { // end
    		break;
		}
		if(password == "+") {
			while(true) {
				if(Console::Create_Account() == 1) { // bam tab
					break;
				}
			}
			continue; // tro ve giao dien dang nhap
		}
			
		// L?u username và password ==================================================================================================
		
		/*if(/* Thong tin khong hop le ----------------------------------------------------------------------------------------------------) {
			continue; //  Nhap lai
		}
		*/
		
		
		bool Manager = 1; // kiem tra neu la quan tri vien ===============================================
		bool oke1 = 1;
		
		/*while(oke1) {
			char c;
			
			while(1) {
				if(Manager) {
					Print_Manager_Menu();
				}
				else {
					Print_User_Menu();
				}
				
				gotoxy(4,27);
				cout << "--> Enter your choice: ";
				
				char mx;
				if(Manager) {	// neu quan tri vien thi 5 phan
					mx = '5';
				}
				else {			// nguoi dung 4 phan
					mx = '4';
				}
				
				c = _getch(); 
				cout << c;
				Sleep(200);
				
				if(c == 9) {
					Exit();
					return 0;
				}
				if (c < '1' || c > mx) {
	            	Invalid_Result();
	            	Sleep(3000);
		        } 
				else {
		            break;
		        }
			}
			
			switch(c) {
				case '1': {
					A.Change_Information();
					break;
				}
				case  '2': {
					A.Print_Information();
					break;
				}
			}	
		}*/
	}
	
	Menu::Notification("The program has ended", 50, 5); // Thong bao ket thuc
    return 0;
}