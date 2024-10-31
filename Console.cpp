#include<iostream>
#include "Menu.h"
#include "Account.h"
#include "gotp.h"
#include "Console.h"
using namespace std;

void Console::print(int x, int y, string s) {
    Menu::gotoxy(x, y);
    cout << s;
}

string Console::input(int x, int y, bool isPlus, bool ispassword) {
    string res = "";
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
        if (res.length() >= 39 && ch != 8 && ch != 13) {
            continue; 
        }

        if (ch == 13) { // Enter
            if(res.length() > 8) break; //toi thieu 8 ki tu
            else continue;
                
        } else if (ch == 8) { // Backspace
            if (!res.empty()) {
                res.pop_back();
                Menu::gotoxy(x + res.length(), y);
                cout << ' ';
                Menu::gotoxy(x + res.length(), y);
            }
        } else {
            if (!clearedPrompt) {
                cout << "               "; // Xóa nhãn "Enter username:"
                Menu::gotoxy(x, y);
                clearedPrompt = true;
            }
            res.push_back(ch);
            
            if(ispassword) {
                cout << "*";	
            }
            else {
                cout << ch;
            }
        }
    }
    return res;
}

string Console::change(string& title, string& enter_new, string& old_ans, string& old_password) {
    Menu::print_otp();
    Menu::gotoxy(58,3);
    cout << title;
    Menu::gotoxy(52,9);
    cout << enter_new;
    Menu::gotoxy(41,6); //password
            
    char ch;
    bool clearedPrompt = false;
    string password = "";
            
    while (true) {
        ch = _getch();
        
        if(ch == 9) return "";	// tab: back
        
        if (password.length() >= 38 && ch != 8 && ch != 13) {
            continue; 
        }
        
        if (ch == 13) { // Enter
            break;
        } else if (ch == 8) { // Backspace
            if (!password.empty()) {
                password.pop_back();
                Menu::gotoxy(41 + password.length(), 6);
                cout << ' ';
                Menu::gotoxy(41 + password.length(), 6);
            }
        } else {
            if (!clearedPrompt) {
                cout << "               ";
                Menu::gotoxy(41, 6);
                clearedPrompt = true;
            }
            password.push_back(ch);
            cout << "*";
        }
    }
        
    Menu::gotoxy(41,9); //ans
    clearedPrompt = false;
    string ans = "";
    
    while (true) {
        ch = _getch();
        
        if(ch == 9) return "";	// tab: back
        
        if (ans.length() >= 38 && ch != 8 && ch != 13) {
            continue; 
        }
    
        if (ch == 13) { // Enter
            if(ans.length() > 8) break;
            else continue;
        } else if (ch == 8) { // Backspace
            if (!ans.empty()) {
                ans.pop_back();
                Menu::gotoxy(41 + ans.length(), 9);
                cout << ' ';
                Menu::gotoxy(41 + ans.length(), 9);
            }
        } else {
            if (!clearedPrompt) {
                cout << "                                 ";
                Menu::gotoxy(41, 9);
                clearedPrompt = true;
            }
            ans.push_back(ch);
            cout << ch;
        }
    }
    
    Menu::gotoxy(56,12); //otp
    string OTP = gotp::generate_otp();
    cout << OTP;
    
    Menu::gotoxy(47,15);
    char c;
    string check_otp = "";
    
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
                cout << " ";
                Menu::gotoxy(48 + check_otp.size()*5 - 1,15);
            }
        }
        else {
            check_otp.push_back(c);
            cout << c;
            if(check_otp.size() == 6)
                Menu::gotoxy(48 + check_otp.size()*5 + 1 -5, 15);
            else
                Menu::gotoxy(48 + check_otp.size()*5 - 1, 15);
        }
    }
    
    if(ans == old_ans || password != old_password || OTP != check_otp) {
        Menu::gotoxy(5,25);
        Sleep(3000);
        ans = change(title, enter_new, old_ans, old_password);
    }
    
    Menu::notification("----Successful operation----",42,5);
    return ans;
}


bool Console::create_account() {
    Menu::create_information_screen();
    
    string create_username = input(41, 7, false, false);
    if(create_username == "") return 1;
    
    string create_password = input(41, 10, false, true);
    if(create_password == "") return 1;
    
    string create_password_again = input(41, 13, false, true);
    if(create_password_again == "") return 1;
    
    /*
    if(create_username) { 	// ================================================Kiem tra da ton tai chua=========================)
        Menu::notification("Username already exists",50, 5);
        return false; // da ton tai
    }
    if(create_password != create_password_again) {
        Menu::notification("Password is incorrect !", 47, 5);
        return false; // mau khau lan 1 khac mat khau lan 2
    }
    
    //==========================================================Luu thong tin tk va mk===============================================
    */

    // while(true) {
    // 	if(Create_Information() == 0) {  // Bam tab
    // 		Menu::create_information_screen();
    // 		print(41, 7, create_username);
    // 		print(41, 10, create_password);
    // 		print(41, 13, create_password_again);
    // 		Menu::gotoxy(5, 25);
            
    // 		if()
    // 	}
    // }
    return 0;
}




void Console::change_information() {
    char c; 
    bool stop = 1;
    
    while (stop) {
        Menu::print_change_information();
        Menu::gotoxy(4, 27);
        cout << "--> Enter your choice: ";

        c = _getch(); 
        cout << c;
        Sleep(200);
        
        if(c == 9) return;
        
        if (c < '1' || c > '7') {
            Menu::notification("----Invalid result----", 42,5);
            Sleep(3000);
        }
    
        string old_password = "00000000" /* PASSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSWWORDDDDDDDDD?*/;
        
        switch (c) {
            
            case '1': {//full name
                string old_name = "aa" /* NAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMMMMMMMMMMMMMMMMMMMMMMMMMMMMeeeeeeeeeeeeeeeeeeee*/;
                string title = "FULL NAME";
                string enter_new = "fullname";
                string name = change(title, enter_new, old_name, old_password);
                // if !name.emmtpy() thi luu lai, lam voi tat ca cac truong hop o ben duoi
                break;
            }
            
            case '2': {// password
                string title = "PASSWORD";
                string enter_new = "password";
                string password_current = change(title, enter_new, old_password, old_password);
                break;
            }	
            
            case '3': {//address
                string old_address = "a" /*ADDRESSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS*/;
                string title = "ADDRESS";
                string enter_new = "address";
                string address = change(title, enter_new, old_address, old_password);
                break;
            }
        }
    }
}


void Console::print_information(){
    system("cls");
    string str = R"(
    IDENTIFICATION INFORMATION
    --------------------------------------------------------------------------------------

    Full Name:                                 
    Date of Birth:
    Gender:

    ACCOUNT INFORMATION
    --------------------------------------------------------------------------------------
    Phone Number:
    Country:
    
    --------------------------------------------------------------------------------------
                                Note that pressing the 'Tab' will back	
    )";
    cout << str;
    
    
    Menu::gotoxy(52,4);
    string fullname = "a"; //==============================================================
    cout << fullname;
    Menu::gotoxy(52,5);
    string age = "a"; //=================================================;
    Menu::gotoxy(52,6);
    string ge;
    char ch;
    while(1) {
        ch = _getch();
        if(ch != 9)
            continue;
        else break;
    }
}	