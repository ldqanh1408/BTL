#include "Console.h"
#include <algorithm>


Console::Console() {
}


bool kt(std::string age) {
    if(age.size() > 3) return 0;
    for(int i = 0; i < age.size(); i++) {
        if(age[i] > '9' || age[i] < '0') return 0;
    }
    if(age[0] == '0') return 0;
    return stoi(age) < 150;
}


std::string Console::otp(int x, int y) {
    Menu::gotoxy(x, y);
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
                Menu::gotoxy(48 + check_otp.size()*5 - 1, y);
                std::cout << " ";
                Menu::gotoxy(48 + check_otp.size()*5 - 1, y);
            }
        }
        else {
            check_otp.push_back(c);
            std::cout << c;
            if(check_otp.size() == 6)
                Menu::gotoxy(48 + check_otp.size()*5 + 1 - 5, y);
            else
                Menu::gotoxy(48 + check_otp.size()*5 - 1, y);
        }
    }
    return check_otp;
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
                std::cout << "                                      "; // Xóa nhãn "Enter username:"
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


std::string Console::change(std::string& title, std::string& enter_new, std::string& old_ans, bool age, bool gender, bool phone_number) {
    Menu::print_otp();
    Menu::gotoxy(53,3);
    std::cout << title;
    Menu::gotoxy(51,6);
    std::cout << enter_new << ":";
    Menu::gotoxy(41,6);
            
    char ch;
    bool clearedPrompt = false;
    std::string ans = "";
    int mn;

    if(age) mn = 10;
    else if(gender) mn = 1;
    else if(phone_number) mn = 10;
    else mn = 5;

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
                Menu::gotoxy(41 + ans.length(), 6);
                std::cout << ' ';
                Menu::gotoxy(41 + ans.length(), 6);
            }
        } else {
            if (!clearedPrompt) {
                std::cout << "                                      ";
                Menu::gotoxy(41, 6);
                clearedPrompt = true;
            }
            ans.push_back(ch);
            std::cout << ch;
        }
    }
    
    Menu::gotoxy(56,9); //otp
    std::string OTP = gotp::generate_otp();
    std::cout << OTP;
    std::string check_otp = otp(47, 12);
    if(check_otp == "") return "";

    if(OTP != check_otp) {
        Menu::notification("Incorrect OTP!", 52, 5);
        ans = change(title, enter_new, old_ans, 0, 0, 0);
    }

    else if(age) {
        //if(ans khong hop le ) {   ===========================================================================
        //   Menu::notification("Invalid information!", 47, 5);
        //   ans = change(title, enter_new, old_ans, old_password, age, gender, phone_number);
        //}
    }
    else if(gender) {
        if(ans != "1" && ans != "0") {
            Menu::notification("Invalid information!", 50, 5);
            ans = change(title, enter_new, old_ans, age, gender, phone_number);
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
        ans = change(title, enter_new, old_ans, 0, 0, 0);
    }

    if(ans != "") {
        Menu::notification("----Successful Operation----", 45, 5);
    }
    return ans;
}


bool Console::create_account() {
    Menu::create_account_screen();
    
    Account tmp1; Information tmp2;
    std::string username = input(21, 6, false, false, 1);

    if(username == "") return 1; //tab
    else {
        std::string file_path = folder1 + username + ".txt";
        if(std::filesystem::exists(file_path)) {
            Menu::notification("Username already exist!", 48, 5); // chưa check
            return 0;
        } else {
            tmp1.set_user_name(username);
        }
    }

    std::string password = input(21, 9, false, true, 8);
    if(password == "") return 1;
    else {
        if(!tmp1.set_password(password)) {
            system("cls");
            std::cout << R"(
                             _____________________________________________________________
                            |                                                             |
                            |                    O~~~NOTIFICATION~~~O                     |
                            |                                                             |
                            |          Password must contain at least 1 uppercase,        |
                            |           lowercase, number, special character and          |
                            |             must not contain invalid characters!            |
                            |                                                             |
                            |_____________________________________________________________|)";
            Menu::gotoxy(5, 20);
            Sleep(4000);
            return 0;
        }
    }
    
    std::string password_again = input(21, 12, false, true, 8);
    if(password_again == "") return 1;
    
    if(password != password_again) {
        Menu:: notification("Password is incorrect!", 48, 5);
        return 0;
    }

    std::string phone;
    while(true) {
        phone = input(21, 15, false, false, 10);
        if(phone == "") return 1;
        else {
            if(!tmp2.set_phone_number(phone)) {
                print(21, 15, "Phone number is incorrect!"); // không rõ
                Sleep(1000);
                print(21, 15, "                                      ");
                continue;
            } else break;
        }
    }

    std::string fullname = input(62, 6, false, false, 5);
    tmp2.set_full_name(fullname);
    
    std::string age;
    while(true) {
        age = input(62, 9, false, false, 1);    
        if(age == "") return 1; // tab

        reverse(age.begin(), age.end());
        while(!age.empty() && age.back() == '0') age.pop_back(); 
        reverse(age.begin(), age.end());
        // thiếu check age
        int _ = age.size() <= 3 ? stoi(age) : -1; 
        if(!tmp2.Information::set_age(_)) {
            print(62, 9, "Age is incorrect !!!                  ");
            Sleep(1000);
            print(62, 9, "                                      ");
        }
        else break;   
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

    std::string address = input(62, 15, false, false, 5);
    std::string country = input(62, 18, false, false, 5);
    tmp2.set_address(address);
    tmp2.set_country(country);
    // luu 9 thong tin lại =======================================================================================;
    Menu::notification("Account created successfully", 45, 5);
    User new_user(tmp2, tmp1);
    return 1; // tro ve đăng nhập
}


void Console::change_information(bool manager) {
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
            Menu::notification("Invalid result!!!", 50, 5);
        }
        if(manager && c == '2') {
            Menu::notification("The manager isn't  allowed to change the password", 43, 5);
            continue;
        }
        switch (c) {
            
            case '1': {//full name
                std::string old_name = "aa" /* NAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMMMMMMMMMMMMMMMMMMMMMMMMMMMMeeeeeeeeeeeeeeeeeeee*/;
                std::string title = "FULL NAME";
                std::string enter_new = "fullname";
                std::string name = change(title, enter_new, old_name, 0, 0, 0);
                // if !name.emmtpy() thi luu lai, lam voi tat ca cac truong hop o ben duoi ===============================================
                break;
            }
            
            case '2': {// password
                std::string old_password = "00000000" /* PASSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSWWORDDDDDDDDD?*/;
                std::string title = "PASSWORD";
                std::string enter_new = "password";
                std::string password_current = change(title, enter_new, old_password, 0, 0, 0);
                break;
            }	
            
            case '3': {//address
                std::string old_address = "a" /*ADDRESSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS*/;
                std::string title = "ADDRESS";
                std::string enter_new = "address";
                std::string address = change(title, enter_new, old_address, 0, 0, 0);
                break;
            }

            case '4': {
                std::string old_age = "a";
                std::string title = "AGE";
                std::string enter_new = "age";
                std::string age = change(title, enter_new, old_age, 1, 0, 0);
                break;
            }

            case '5': {
                std::string old_gender = "a";
                std::string title = "GENDER";
                std::string enter_new = "gender (Male: 1, Female: 0)";
                std::string gender = change(title, enter_new, old_gender, 0, 1, 0);
                break;
            }

            case '6': {
                std::string old_phone_number = "a";
                std::string title = "PHONE NUMBER";
                std::string enter_new = "phone number";
                std::string phone_number = change(title, enter_new, old_phone_number, 0, 0, 1);
                break;
            }

            case '7': {
                std::string old_country = "aaaaaa"; //Country ========================================================
                std::string title = "COUNTRY";
                std::string enter_new = "country";
                std::string country = change(title, enter_new, old_country, 0, 0, 0);
                break;
            }
        }
    }
}


void Console::print_information(){
    Menu::identification_information();
    std::string balance;
    std::ifstream infile(folder3 + bcrypt::generateHash(cur.Information::get_ID()) + ".txt");
    infile >> balance;
    infile.close();

    print(48, 4, cur.Information::get_full_name());

    print(48, 5, std::to_string(cur.Information::get_age()));

    print(48, 6, std::to_string(cur.Information::get_gender()));

    // std::string tmp = "aaaaaaaaaaaaaa";  //account balance=================================================;
    // std::string balance = "";

    // for (int i = tmp.size() - 1, count = 0; i >= 0; --i, ++count) {
    //     balance = tmp[i] + balance;
    //     if (count == 2 && i != 0) {
    //         balance = "," + balance;
    //         count = -1; //
    //     }
    // }
    print(48, 11, balance + "Points");

    // std::string phone_number = "aaaaaaaaaa"; //phone number==========================================
    print(48, 12, cur.Information::get_phone_number());

    // std::string country = "aaaaaaaaa"; //country ======================================
    print(48, 13, cur.Information::get_country());

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


    std::string ID = input(41, 9, 0, 0, 12);
    if(ID == "") return;

    //1->"Account does not exist! "
    //2->"Transaction error please try again!"
    //3->"Invalid amount !"
    //4->"Insufficient balance !"
    //5->"OTP is incorrect !"
    //6->"tab"
    //7->"--You have successfully transferred the money--"

    char ch = cur.transfer_money(ID, amount) + '0';

    switch (ch) {
        case '1':
            Menu::notification("Account does not exist!", 48, 5); // chưa check vị trí
            break;
        case '2':
            Menu::notification("Transaction error, please try again!", 46, 5); // chưa check vị trí
            break;
        case '3':
            Menu::notification("Invalid amount!", 50, 5);
            break;
        case '4':
            Menu::notification("Insufficient balance!", 49, 5);
            break;
        case '5':
            Menu::notification("OTP is incorrect!", 50, 5);
            break;
        case '6':
            //tab
            return;
        case '7':
            Menu::notification("--You have successfully transferred the money--", 37, 5);
            break;
    }

    transfer_money();

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


void Console::log_in_useraccount() {
    while(true) {
        Menu::print_log_in_user_account();
        std::string username = input(41, 3, 0, 0, 1);

        if(username == "") return;
        //kiem tra ten nguoi dung co ton tai hay khong ========================================================================
        //neu khong ton tai 
        //Menu::notification("username does not exist", 49, 5);
        //continue;
        user_operation(1);
    }
}


void Console::view_list_of_users_account() {
    Menu::print_list_of_user();

    //
    // thao tac xem danh sach nguoi dung ==============================================================
    //
    //

    char c;
    while(true) {
        c = _getch();
        if(c == 9) return;
    }
}


void Console::list_of_users() {
    while(true) {
        Sleep(100);
        Menu::print_list_of_users_main();
        Menu::gotoxy(4,27);
        std::cout << "--> Enter your choice: ";

        char c;
        c = _getch();
        std::cout << c;
        Sleep(200);

        if(c == 9) {
            break;
        }
        if(c < '1' || c > '2') {
            Menu::notification("Invalid result !", 52, 5);
            continue;
        }

        switch(c) {
            case '1': {
                log_in_useraccount();
                break;
            }
            case '2': {
                view_list_of_users_account();
                break;
            }
        }
    }
}


void Console::create_user_account() {
    while(true) {
        Menu::create_account_for_user_screen();

        std::string username = input(41, 6, 0, 0, 1);
        if(username == "") return;
        /*
        if(username da ton tai) {
            Menu::notification("Username already exist!", 48, 5);=====================================
            continue;
        }
        */

       std::string password;

        std::string fullname = input(41, 9, 0, 0, 1);
        if(fullname == "") return;

        std::string age;
        while(true) {
            age = input(41, 12, false, false, 1);
            
            if(age == "") return;
            if(kt(age) == false) {
                print(41, 19, "Age is incorrect !!!          ");
                continue;
            }
            else {
                //============================================luu tuoi vao========================================================
                break;
            }
        }

        char ch;
        while(true) {
            Menu::gotoxy(41, 12);
            ch = _getch();
            std::cout << "                                       ";
            Menu::gotoxy(41, 12);

            if(ch == 9) return; // tab
            if(ch == '0' || ch == '1') {
                std::cout << ch;
                break;
            }
        }

        std::string phone;
        while(true) {
            phone = input(41, 15, false, false, 10);
            if(phone == "") return;
            
            /* if(phonenumber khong hop le ===================================================================) {
                print(41, 15, "Phone number is incorrect");
                continue;
            }
            */
        }

        std::string address = input(41, 18, false, false, 5);
        if(address == "") return;

        std::string country = input(41, 21, false, false, 5);
        if(country == "") return;

        // luu cac thong tin ben tren ================================================================================

        Menu::notification("Account created successfully", 45, 5);
        return;
    }
}


void Console::system_transaction_history() {
    Menu::system_transaction_history_screen();
    //
    //
    // thao tac xem lich su giao dich tat ca user ==================================================================
    //
    //
    char ch;
    while(true) {
        ch = _getch();
        if(ch == 9) return;
    }
}


void Console::user_operation(bool manager) {
    while(true) {	// menu
        Sleep(100);
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
            Menu::notification("Invalid result !", 52, 5);
            continue;
        }

        switch (c) {
            case '1': {
                change_information(manager);
                break;
            }
            case '2' : {
                print_information();
                break;
            }
            case '3' : {
                transfer_money();
                break;
            }
            case '4' : {
                transaction_history();
                break;
            }
        }
    }
}


void Console::manager_opertion() {
    while(true) {	// menu
        Sleep(100);
        Menu::print_manager_menu();

        Menu::gotoxy(4,27);
        std::cout << "--> Enter your choice: ";
        char c;
        c = _getch();
        std::cout << c;
        Sleep(200);

        if(c == 9) {
            break;
        }
        if(c < '1' || c > '3') {
            Menu::gotoxy(5, 10);
            Menu::notification("Invalid result!", 52, 5);
            continue;
        }

        switch (c) {
            case '1': {
                list_of_users();
                break;
            }
            case '2' : {
                create_user_account();
                break;
            }
            case '3' : {
                system_transaction_history();
                break;
            }
        }
    }
}



void Console::Start_The_Program() {

    while(true) {	// Login

    	Menu::print_login_frame();
    	
    	std::string user_name = Console::input(41, 7, true, false, 1); //username

    	
    	if(user_name == "") { // end
    		break;
		}
		if(user_name == "+") {	// create account
			while(true) {
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

        bool user; // truong hop quan li
        if(un_manager == user_name && pw_manager == password) {
            user = false;
        } else {
            if(std::filesystem::exists(folder2 + user_name + ".txt")) {
                std::ifstream infile(folder2 + user_name + ".txt");
                std::string valid_password;
                infile >> valid_password;
                infile.close();
                if(!bcrypt::validatePassword(valid_password, bcrypt::generateHash(password))) {
                    Menu::notification("Incorrect username or password", 45, 5);
                    continue; // khoong ro
                }            
            } else {
                Menu::notification("Incorrect username or password", 45, 5);
                continue;
            }
            cur.set_account(Account(user_name, password), 1);
            std::ifstream infile(folder1 + user_name + ".txt");
            infile >> cur;
            

            user = true;
        }

        // kiem tra la quan li hay user, neu la quan li user = 0, neu la user -> user = 1 ==========================================================

        if(user) {
            user_operation(0);
        }
        else {
            manager_opertion();
        }
	}
	Menu::notification("The program has ended", 49, 5); // Thong bao ket thuc
    return;
}