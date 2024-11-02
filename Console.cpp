#include<iostream>
#include "Menu.cpp"
#include "Account.h"
#include "Information.h"
#include "User.h"
#include "gotp.cpp"
#include "Console.h"
#include <filesystem>
namespace fs = filesystem;

Console::Console() {
    this->user_name = "";
}
void Console::print(int x, int y, std::string s) {
    Menu::gotoxy(x, y);
    std::cout << s;
}

std::string Console::input(int x, int y, bool isPlus, bool ispassword, int mn) {
    std::string res = "";
    char ch;
    bool clearedPrompt = false;

    Menu::gotoxy(x, y);
    while (true) {
        ch = _getch();
            
        if(ch == 9) {	//tab
            return "";
        }
        if(isPlus && ch == 43) {	// neu dang nhap thi co tao tai khoan moi
            return "+";
        }
        if (res.length() >= 38 && ch != 8 && ch != 13) {
            continue; 
        }

        if (ch == 13) { // Enter
            if(res.length() >= mn) break; //toi thieu ki tu
            else continue;
                
        } else if (ch == 8) { // Backspace
            if (!res.empty()) {
                res.pop_back();
                Menu::gotoxy(x + res.length(), y);
                std::cout << ' ';
                Menu::gotoxy(x + res.length(), y);
            }
        } else {
            if (!clearedPrompt) {
                std::cout << "                              "; // Xóa nhãn "Enter username:"
                Menu::gotoxy(x, y);
                clearedPrompt = true;
            }
            res.push_back(ch);
            
            if(ispassword) {
                std::cout << "*";	
            }
            else {
                std::cout << ch;
            }
        }
    }
    return res;
}


std::string Console::change(std::string& title, std::string& enter_new, std::string& old_ans, std::string& old_password, bool age, bool gender, bool phone_number) {
    Menu::print_otp();
    Menu::gotoxy(53,3);
    std::cout << title;
    Menu::gotoxy(51,9);
    std::cout << enter_new << ":";
    Menu::gotoxy(41,6); //password
            
    char ch;
    bool clearedPrompt = false;
    std::string password = "";
    int mn;

    if(age) mn = 10;
    else if(gender) mn = 1;
    else if(phone_number) mn = 10;
    else mn = 5;

    while (true) {
        ch = _getch();
        
        if(ch == 9) return "";	// tab: back
        
        if (password.length() >= 38 && ch != 8 && ch != 13) {
            continue; 
        }
        
        if (ch == 13) { // Enter
            if(password.length() >= 8) {
                break;
            }
        } else if (ch == 8) { // Backspace
            if (!password.empty()) {
                password.pop_back();
                Menu::gotoxy(41 + password.length(), 6);
                std::cout << ' ';
                Menu::gotoxy(41 + password.length(), 6);
            }
        } else {
            if (!clearedPrompt) {
                std::cout << "               ";
                Menu::gotoxy(41, 6);
                clearedPrompt = true;
            }
            password.push_back(ch);
            std::cout << "*";
        }
    }
        
    Menu::gotoxy(41,9); //ans
    clearedPrompt = false;
    std::string ans = "";
    
    while (true) {
        ch = _getch();
        
        if(ch == 9) return "";	// tab: back
        
        if (ans.length() >= 38 && ch != 8 && ch != 13) {
            continue; 
        }
    
        if (ch == 13) { // Enter
            if(ans.length() >= mn) break;
            else continue;
        } else if (ch == 8) { // Backspace
            if (!ans.empty()) {
                ans.pop_back();
                Menu::gotoxy(41 + ans.length(), 9);
                std::cout << ' ';
                Menu::gotoxy(41 + ans.length(), 9);
            }
        } else {
            if (!clearedPrompt) {
                std::cout << "                                    ";
                Menu::gotoxy(41, 9);
                clearedPrompt = true;
            }
            ans.push_back(ch);
            std::cout << ch;
        }
    }
    
    Menu::gotoxy(56,12); //otp
    std::string OTP = gotp::generate_otp();
    std::cout << OTP;
    
    Menu::gotoxy(47,15);
    char c;
    std::string check_otp = "";
    
    while(true) {
        c = _getch();
        
        if(c == 9) return ""; //tab
        
        else if(check_otp.size() == 6 && c != 8) {
            if(c == 13) break;
            continue;
        }
        else if(c == 13) continue;
        else if(c == 8) {
            if(!check_otp.empty()) {
                check_otp.pop_back();
                Menu::gotoxy(48 + check_otp.size()*5 - 1,15);
                std::cout << " ";
                Menu::gotoxy(48 + check_otp.size()*5 - 1,15);
            }
        }
        else {
            check_otp.push_back(c);
            std::cout << c;
            if(check_otp.size() == 6)
                Menu::gotoxy(48 + check_otp.size()*5 + 1 -5, 15);
            else
                Menu::gotoxy(48 + check_otp.size()*5 - 1, 15);
        }
    }
    
    if(password != old_password || OTP != check_otp) {
        Menu::notification("Incorrect Password or OTP!", 47, 5);
        ans = change(title, enter_new, old_ans, old_password, 0, 0, 0);
    }

    if(age) {
        //if(ans khong hop le (dd/mm/yyyy)) {   ===========================================================================
        //   Menu::notification("Invalid information!", 47, 5);
        //   ans = change(title, enter_new, old_ans, old_password, age, gender, phone_number);
        //}
    }
    else if(gender) {
        if(ans != "1" && ans != "0") {
            Menu::notification("Invalid information!", 48, 5);
            ans = change(title, enter_new, old_ans, old_password, age, gender, phone_number);
        }
    }
    else if(phone_number) {
        //if(SDT khong hop le) { ===========================================================================
        //   Menu::notification("Invalid information!", 48, 5);
        //   ans = change(title, enter_new, old_ans, old_password, age, gender, phone_number);
        //}
    }
    else if(ans == old_ans) {
        Menu::notification("Duplicate Old Information!", 47, 5);
        ans = change(title, enter_new, old_ans, old_password, 0, 0, 0);
    }

    if(ans != "") {
        Menu::notification("----Successful Operation----", 45, 5);
    }
    return ans;
}


bool Console::create_account() {
    Menu::create_account_screen();
    
    Account tmp1; Information tmp2;
    std::string username = input(21, 6, false, false, 8);

    if(username == "") return 1; //tab
    else {
        std::string file_path = folder1 + username + ".txt";
        if(fs::exists(file_path)) {
            Menu::notification("Username already exist !", 44, 5); // chưa check
            return 0;
        } else {
            tmp1.set_user_name(username);
        }
    }

    std::string password = input(21, 9, false, true, 8);
    if(password == "") return 1;
    else {
        if(!tmp1.set_password(password)) {
            Menu::notification("Password must contain at least 1 uppercase, lowercase, number, special character and must not contain invalid characters!", 44, 5);
            return 0;
        }
    }
    
    std::string password_again = input(21, 12, false, true, 8);
    if(password_again == "") return 1;
    
    if(password != password_again) {
        Menu:: notification("Password is incorrect !", 49, 5);
        return 0;
    }

    std::string phone;
    while(true) {
        phone = input(21, 15, false, false, 10);
        if(phone == "") return 1;
        else {
            if(!tmp2.set_phone_number(phone)) {
                Menu:: notification("Phone number is incorrect !", 49, 5); // không rõ
                return 0;
            } else break;
        }
        // if(phong khong hop le ===================================================================) continue;
    }

    std::string fullname = input(62, 6, false, false, 5);
    
    std::string age;
    while(true) {
        age = input(62, 9, false, false, 10);

        if(age == "") return 1; // tab
        if(!tmp2.set_age()) {
            print(41, 19, "Age is incorrect !!!                   ");
            
        } else break;
    }

    char ch;

    while(true) {
        Menu::gotoxy(62, 12);
        ch = _getch();
        std::cout << "                                       ";
        Menu::gotoxy(62, 12);

        if(ch == 9) return 1; // tab
        if(ch == '0' || ch == '1') {
            tmp2.set_gender(ch);
            std::cout << ch;
            break;
        }
    }

    std::string address = input(62, 15, false, false, 8);
    std::string country = input(62, 18, false, false, 5);
    tmp2.set_address(address);
    tmp2.set_country(country);
    Menu::gotoxy(5, 33);
    // luu 9 thong tin lại =======================================================================================;
    Menu::notification("Account created successfully", 45, 5);
    User new_user(tmp1, tmp2);
    return 1; // tro ve đăng nhập
}


void Console::change_information() {
    char c; 
    while (true) {
        Menu::print_change_information();
        Menu::gotoxy(4, 27);
        std::cout << "--> Enter your choice: ";

        c = _getch(); 
        std::cout << c;
        Sleep(200);
        
        if(c == 9) return;
        
        if (c < '1' || c > '8') {
            Menu::notification("Invalid result !!!", 50, 5);
        }
    
        std::string old_password = "00000000" /* PASSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSWWORDDDDDDDDD?*/;
        
        switch (c) {
            
            case '1': {//full name
                std::string old_name = "aa" /* NAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMMMMMMMMMMMMMMMMMMMMMMMMMMMMeeeeeeeeeeeeeeeeeeee*/;
                std::string title = "FULL NAME";
                std::string enter_new = "fullname";
                std::string name = change(title, enter_new, old_name, old_password, 0, 0, 0);
                // if !name.emmtpy() thi luu lai, lam voi tat ca cac truong hop o ben duoi ===============================================
                break;
            }
            
            case '2': {// password
                std::string title = "PASSWORD";
                std::string enter_new = "password";
                std::string password_current = change(title, enter_new, old_password, old_password, 0, 0, 0);
                break;
            }	
            
            case '3': {//address
                std::string old_address = "a" /*ADDRESSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS*/;
                std::string title = "ADDRESS";
                std::string enter_new = "address";
                std::string address = change(title, enter_new, old_address, old_password, 0, 0, 0);
                break;
            }

            case '4': {
                std::string old_age = "a";
                std::string title = "AGE";
                std::string enter_new = "age (dd/mm/yyyy)";
                std::string age = change(title, enter_new, old_age, old_password, 1, 0, 0);
                break;
            }

            case '5': {
                std::string old_gender = "a";
                std::string title = "GENDER";
                std::string enter_new = "gender (Male: 1, Female: 0)";
                std::string gender = change(title, enter_new, old_gender, old_password, 0, 1, 0);
                break;
            }

            case '6': {
                std::string old_phone_number = "a";
                std::string title = "PHONE NUMBER";
                std::string enter_new = "phone number";
                std::string phone_number = change(title, enter_new, old_phone_number, old_password, 0, 0, 1);
                break;
            }

            case '7': {
                std::string old_country = "aaaaaa"; //Country ========================================================
                std::string title = "COUNTRY";
                std::string enter_new = "country";
                std::string country = change(title, enter_new, old_country, old_password, 0, 0, 0);
                break;
            }
        }
    }
}


void Console::print_information(){
    Menu::identification_information();
    
    ifstream infile(foler1 + this->user_name + ".txt");
    std::string full_name, age, gender, country, address, phone_number, ID; //fullname==============================================================
    infile >> full_name >> address >> country >> phone_number >> age >> gender;
    print(48, 4, fullname);

    print(48, 5, age);

    print(48, 6, gender);

    std::string tmp = "aaaaaaaaaaaaaa";  //account balance=================================================;
    std::string account_balance = "";

    for (int i = tmp.size() - 1, count = 0; i >= 0; --i, ++count) {
        account_balance = tmp[i] + account_balance;
        if (count == 2 && i != 0) {
            account_balance = "," + account_balance;
            count = -1; //
        }
    }
    print(48, 11, account_balance + "VND");

    std::string phone_number = "aaaaaaaaaa"; //phone number==========================================
    print(48, 12, phone_number);

    std::string country = "aaaaaaaaa"; //country ======================================
    print(48, 13, country);

    Menu::gotoxy(5, 20);
    char ch;
    while(1) {
        ch = _getch();
        if(ch != 9)
            continue;
        else break;
    }
}


void Console::transfer_money() {
    Menu::transfer_money_screen();

    std::string amount = input(41, 6, 0, 0, 1);
    if(amount == "") return;

    /*
    if(so tien khong hop le) {===================================================================================
        Menu::notification("Invalid amount !", 50, 5);
        transfer_money();
        return;
    }

    if(so tien khong du) {===================================================================================
        Menu::notification("Insufficient balance !", 48, 5);
        transfer_money();
        return;
    }
    */

    std::string ID = input(41, 9, 0, 0, 12);
    if(ID == "") return;

    /*
    if(khong ton tai) {===================================================================================
        Menu::notification("ID does not exist!", 48, 5);
        transfer_money();
    }
    */


    Menu::gotoxy(56,12); //otp
    std::string OTP = gotp::generate_otp();
    std::cout << OTP;

    Menu::gotoxy(47,15);
    char c;
    std::string check_otp = "";
    
    while(true) {
        c = _getch();
        
        if(c == 9) return; //tab
        
        else if(check_otp.size() == 6 && c != 8) {
            if(c == 13) break;
            continue;
        }
        else if(c == 13) continue;
        else if(c == 8) {
            if(!check_otp.empty()) {
                check_otp.pop_back();
                Menu::gotoxy(48 + check_otp.size()*5 - 1,15);
                std::cout << " ";
                Menu::gotoxy(48 + check_otp.size()*5 - 1,15);
            }
        }
        else {
            check_otp.push_back(c);
            std::cout << c;
            if(check_otp.size() == 6)
                Menu::gotoxy(48 + check_otp.size()*5 + 1 -5, 15);
            else
                Menu::gotoxy(48 + check_otp.size()*5 - 1, 15);
        }
    }

    if(OTP != check_otp) {
        Menu::notification("OTP is incorrect !", 50, 5);
        transfer_money();
        return;
    }
    else {
        // thao tac chuyen tien luu vao file ==================================================================
        Menu::notification("--You have successfully transferred the money--", 37, 5);
        transfer_money();
        return;
    }

    return;
}


void Console::transaction_history() {
    Menu::print_transaction_history();

    //
    // thao tac in lich su giao dich ===================================================================
    //
    //

    char ch;
    while(true) {
        ch = _getch();
        if(ch == 9) return;
    }
}

void Console::Start_The_Program() {

    while(true) {	// Login

    	Menu::print_login_frame();
    	
    	std::string username = Console::input(41, 7, true, false, 1); //username

    	
    	if(username == "") { // end
    		break;
		}
		if(username == "+") {	// create account
			while(true) {
				Menu::gotoxy(41, 7);
				if(Console::create_account() == 1) { // bam tab
					break;
				}
			}
			continue; // tro ve giao dien dang nhap
		}



        std::string password = Console::input(41, 10, true, true, 8);

		
		if(password == "") { // end
    		break;
		}
		if(password == "+") {	// create accont
			while(true) {
				if(Console::create_account() == 1) { // bam tab
					break;
				}
			}
			continue; // tro ve giao dien dang nhap
		}
        if(std::fs::exist(foler2 + username + ".txt")) {
            ifstream infile(foler2 + username + ".txt");
            this->user_name = username;
            std::string valid_password;
            infile >> valid_password;
            if(!bcrypt::validatePassword(valid_password, bcrypt::generateHash(password))) {
                Menu::notification("Incorrect username or password", 45, 5);
                continue; // khoong ro
            }            
        } else {
            Menu::notification("Incorrect username or password", 45, 5);
            continue;
        }

		while(true) {	// menu
            Sleep(200);
            system("cls");
			Menu::print_user_menu();

			Menu::gotoxy(4,27);
			std::cout << "--> Enter your choice: ";
            char c;
			c = _getch();
			std::cout << c;
            Sleep(200);

			if(c == 9) {
				break;
			}
			if(c < '1' || c > '4') {
				Menu::gotoxy(5, 10);
				Menu::notification("Invalid result !", 52, 5);
				continue;
			}

			switch (c) {
				case '1': {
					Console::change_information();
					break;
				}
				case '2' : {
					Console::print_information();
					break;
				}
				case '3' : {
					Console::transfer_money();
					break;
				}
				case '4' : {
					Console::transaction_history();
					break;
				}
			}
		}
	}

	Menu::gotoxy(5, 10);
	Menu::notification("The program has ended", 49, 5); // Thong bao ket thuc
    return;
}