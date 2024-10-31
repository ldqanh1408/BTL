#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;
extern void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;	// col
    coord.Y = y;	// row
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

namespace Menu {
	// thêm mấy cái frontend vào đây còn mấy cái xử lý đăng nhập là làm ở main
    // Hàm gotoxy n?m ngoài l?p LoginScreen

    void printLoginFrame() {
            system("cls");
            string s = R"(
                                            _________________________________________
                                        |                                         |
                                        |           WELCOME TO OUR BANK           |
                                        |              PLEASE LOGIN!              |
                                        |_________________________________________|
                                        |                                         | 
                                        | Enter username:                         |
                                        |_________________________________________|
                                        |                                         |  
                                        | Enter password:                         |
                                        |_________________________________________|	
                                        |                                         |
                                        | Note that pressing the 'Tab' will exit  |
                                        |_________________________________________|
                                                    Press '+' to create an account                                       
            )";
            
            cout << s;
    }
        
    void Print_Change_Information() {
        system("cls");
        string s = R"(
                                            ________________________________________
                                        |                                        |
                                        |           CHANGE INFORMATION           |
                                        |________________________________________|
                                        |                                        |
                                        | 1. Fullname                            |
                                        |________________________________________|
                                        |                                        |	
                                        | 2. Password                            |
                                        |________________________________________|
                                        |                                        |
                                        | 3. Address                             |
                                        |________________________________________|
                                        |                                        |
                                        | 4. Age                                 |
                                        |________________________________________|
                                        |                                        |
                                        | 5. Phone Number                        |
                                        |________________________________________|
                                        |                                        |
                                        | 6. Country                             |
                                        |________________________________________|
                                        |                                        |
                                        | Note that pressing the 'Tab' will exit |
                                        |________________________________________|)";
        
        cout << s;
    }

    void Print_User_Menu() {
        system("cls");
        string str = R"(
                                            ________________________________________
                                        |                                        |
                                        |               MENU BANK                |
                                        |________________________________________|
                                        |                                        |
                                        | 1. Change Information                  |
                                        |________________________________________|
                                        |                                        |
                                        | 2. Check Information                   |
                                        |________________________________________|
                                        |                                        |
                                        | 3. Transfer Money                      |
                                        |________________________________________|
                                        |                                        |
                                        | 4. Check Transaction History           |
                                        |________________________________________|
                                        |                                        |
                                        | Note that pressing the 'Tab' will exit |
                                        |________________________________________|)"	;
        cout << str;
    }

    void Notification(string s, int x, int y){
        system("cls");
        cout << R"(
                                _____________________________________________________________
                                |                                                             |
                                |                    O~~~NOTIFICATION~~~O                     |
                                |                                                             |
                                |                                                             |
                                |                                                             |
                                |_____________________________________________________________|
        )";
        
        gotoxy(x, y);
        cout << s;
        Sleep(3000);
        gotoxy(5,25);
    }
	void Create_Account_Screen() {
			system("cls");
			string s = R"(
											_________________________________________
										|                                         |
										|             CREATE ACCOUNT              |
										|_________________________________________|
										|                                         | 
										| Enter username:                         |
										|_________________________________________|
										|                                         |  
										| Enter password:                         |
										|_________________________________________|
										|                                         |  
										| Enter password again:                   |
										|_________________________________________|
										|                                         |  
										| Note that pressing the 'Tab' will back  |
										|_________________________________________|)";
			cout << s;                                          
	}    
    void Create_Information_Screen(){
        system("cls");
        cout << R"(
                                    ______________________________________________________________
                                    |                                                              |
                                    |                    CREATE INFORMATION                        |
                                    |______________________________________________________________|
                                    |                                                              |
                                    | 1. Enter Full Name:                                          |
                                    |______________________________________________________________|
                                    |                                                              |
                                    | 2. Enter Age (dd/mm/yyyy):                                   |
                                    |______________________________________________________________|
                                    |                                                              |
                                    | 3. Enter Gender (Male : 1, Female : 0):                      |
                                    |______________________________________________________________|
                                    |                                                              |
                                    | 4. Enter Phone Number:                                       |
                                    |______________________________________________________________|
                                    |                                                              |
                                    | 5. Enter Address:                                            |
                                    |______________________________________________________________|
                                    |                                                              |
                                    | 6. Enter Country:                                            |
                                    |______________________________________________________________|

        )";
	}
    void Print_OTP() {
        system("cls");
    	cout << R"(
                                        ________________________________________
                                       |                                        |
                                       |          CHANGE                        |
                                       |________________________________________|
                                       |                                        |
                                       | Enter password:                        |
                                       |________________________________________|
                                       |                                        |
                                       | Enter new                              |
                                       |________________________________________|
                                       |                                        |
                                       |          OTP:                          |
                                       |   __________________________________   |                           
                                       |  |                                  |  |  
                                       |  | __   __   __   __   __   __   __ |  |     
                                       |  |__________________________________|  | 
                                       |________________________________________|                                       
                                       |                                        |
                                       | Note that pressing the 'Tab' will back |
                                       |________________________________________|)";
    }	
}










// void print(int x, int y, string s) {
// 	gotoxy(x, y);
// 	cout << s;
// }

// string Change(string& title, string& enter_new, string& old_ans, string& old_password) {
// 		Menu::Print_OTP();
// 		gotoxy(58,3);
// 		cout << title;
// 		gotoxy(52,9);
// 		cout << enter_new;
// 		gotoxy(41,6); //password
				
// 		char ch;
// 		bool clearedPrompt = false;
// 		string password = "";
				
// 		while (true) {
// 		    ch = _getch();
			
// 			if(ch == 9) return "";	// tab: back
			
// 		    if (password.length() >= 38 && ch != 8 && ch != 13) {
// 		        continue; 
// 		    }
			
// 		    if (ch == 13) { // Enter
// 		        break;
// 		    } else if (ch == 8) { // Backspace
// 		        if (!password.empty()) {
// 		            password.pop_back();
// 		            gotoxy(41 + password.length(), 6);
// 		            cout << ' ';
// 		            gotoxy(41 + password.length(), 6);
// 		        }
// 		    } else {
// 		        if (!clearedPrompt) {
// 		            cout << "               ";
// 		            gotoxy(41, 6);
// 		            clearedPrompt = true;
// 		        }
// 		        password.push_back(ch);
// 		        cout << "*";
// 		    }
// 		}
		
// 		gotoxy(41,9); //ans
// 		clearedPrompt = false;
// 		string ans = "";
		
// 		while (true) {
// 		    ch = _getch();
			
// 			if(ch == 9) return "";	// tab: back
			
// 		    if (ans.length() >= 38 && ch != 8 && ch != 13) {
// 		        continue; 
// 		    }
		
// 		    if (ch == 13) { // Enter
// 		    	if(ans.length() > 8) break;
// 		    	else continue;
// 		    } else if (ch == 8) { // Backspace
// 		        if (!ans.empty()) {
// 		            ans.pop_back();
// 		            gotoxy(41 + ans.length(), 9);
// 		            cout << ' ';
// 		            gotoxy(41 + ans.length(), 9);
// 		        }
// 		    } else {
// 		        if (!clearedPrompt) {
// 		            cout << "                                 ";
// 		            gotoxy(41, 9);
// 		            clearedPrompt = true;
// 		        }
// 		        ans.push_back(ch);
// 		        cout << ch;
// 		    }
// 		}
		
// 		gotoxy(56,12); //otp
// 		string OTP = "000000"/*               OTPPPPPPPPPPPPPPPPPPPP                  */; 
// 		cout << OTP;
		
// 		gotoxy(47,15);
// 		char c;
// 		string check_otp = "";
		
// 		while(true) {
// 			c = _getch();
			
// 			if(c == 9) return ""; //tab
			
// 			else if(check_otp.size() == 6 && c != 8) {
// 				if(c == 13) break;
// 				continue;
// 			}
// 			else if(c == 13) continue;
// 			else if(c == 8) {
// 				if(!check_otp.empty()) {
// 					check_otp.pop_back();
// 					gotoxy(48 + check_otp.size()*5 - 1,15);
// 					cout << " ";
// 					gotoxy(48 + check_otp.size()*5 - 1,15);
// 				}
// 			}
// 			else {
// 				check_otp.push_back(c);
// 				cout << c;
// 				if(check_otp.size() == 6)
// 					gotoxy(48 + check_otp.size()*5 + 1 -5, 15);
// 				else
// 					gotoxy(48 + check_otp.size()*5 - 1, 15);
// 			}
// 		}
		
// 		if(ans == old_ans || password != old_password || OTP != check_otp) {
// 			gotoxy(5,25);
// 			Sleep(3000);
// 			ans = Change(title, enter_new, old_ans, old_password);
// 		}
		
// 		Menu::Notification("----Successful operation----",42,5);
// 		return ans;
// 	}

// class LoginScreen {
// public:
    
// 	bool Create_Account() {
// 		Menu::Create_Account_Screen();
		
// 		string create_username = input(41, 7, false, false);
// 		if(create_username == "") return 1;
		
// 		string create_password = input(41, 10, false, true);
// 		if(create_password == "") return 1;
		
// 		string create_password_again = input(41, 13, false, true);
// 		if(create_password_again == "") return 1;
		
	
// 		if(create_username) { 	// ================================================Kiem tra da ton tai chua=========================)
// 			Menu::Notification("Username already exists",50, 5);
// 			return false; // da ton tai
// 		}
// 		if(create_password != create_password_again) {
// 			Menu::Notification("Password is incorrect !", 47, 5);
// 			return false; // mau khau lan 1 khac mat khau lan 2
// 		}
		
// 		//==========================================================Luu thong tin tk va mk===============================================
		
// 		while(true) {
// 			if(Create_Information() == 0) {  // Bam tab
// 				Create_Account_Screen();
// 				print(41, 7, create_username);
// 				print(41, 10, create_password);
// 				print(41, 13, create_password_again);
// 				gotoxy(5, 25);
				
// 				if()
// 			}
// 		}
// 	}
	
//     string input(int x, int y, bool isPlus, bool ispassword) {
//     string res = "";
//     char ch;
//     bool clearedPrompt = false;

//     gotoxy(x, y);
//     while (true) {
// 	    ch = _getch();
			
// 		if(ch == 9) {	//tab
// 			return "";
// 		}
// 		if(isPlus && ch == 43) {	// neu dang nhap thi co tao tai khoan moi
// 			return "+";
// 		}
//         if (res.length() >= 39 && ch != 8 && ch != 13) {
//                continue; 
//         }

//         if (ch == 13) { // Enter
//             if(res.length() > 8) break; //toi thieu 8 ki tu
//             else continue;
                
//         } else if (ch == 8) { // Backspace
//             if (!res.empty()) {
//                 res.pop_back();
//                 gotoxy(x + res.length(), y);
//                 cout << ' ';
//                 gotoxy(x + res.length(), y);
//             }
//         } else {
//             if (!clearedPrompt) {
//                 cout << "               "; // Xóa nhãn "Enter username:"
//                 gotoxy(x, y);
//                 clearedPrompt = true;
//             }
//             res.push_back(ch);
            
// 			if(ispassword) {
// 				cout << "*";	
// 			}
// 			else {
// 				cout << ch;
// 			}
//         }
//     }
//     return res;
// }
    

//     void Change_Information() {
//     	char c; 
//     	bool stop = 1;
    	
//     	while (stop) {
//     		Print_Change_Information();
// 	        gotoxy(4, 27);
// 	        cout << "--> Enter your choice: ";
	
// 	        c = _getch(); 
// 			cout << c;
// 			Sleep(200);
	    	
// 	    	if(c == 9) return;
	    	
// 	        if (c < '1' || c > '7') {
// 	            Notification("----Invalid result----", 42,5);
// 	            Sleep(3000);
// 	        }
		
// 			string old_password = "00000000" /* PASSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSWWORDDDDDDDDD?*/;
			
// 	    	switch (c) {
	    		
// 				case '1': {//full name
// 					string old_name = "aa" /* NAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAMMMMMMMMMMMMMMMMMMMMMMMMMMMMeeeeeeeeeeeeeeeeeeee*/;
// 					string title = "FULL NAME";
// 					string enter_new = "fullname";
// 					string name = Change(title, enter_new, old_name, old_password);
// 					// if !name.emmtpy() thi luu lai, lam voi tat ca cac truong hop o ben duoi
// 					break;
// 				}
				
// 				case '2': {// password
// 					string title = "PASSWORD";
// 					string enter_new = "password";
// 					string password_current = Change(title, enter_new, old_password, old_password);
// 					break;
// 				}	
				
// 				case '3': {//address
// 					string old_address = "a" /*ADDRESSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS*/;
// 					string title = "ADDRESS";
// 					string enter_new = "address";
// 					string address = Change(title, enter_new, old_address, old_password);
// 					break;
// 				}
// 			}
// 		}
// 	}
	
	
// 	void Print_Information(){
// 	    system("cls");
// 	    string str = R"(
// 	    IDENTIFICATION INFORMATION
// 	    --------------------------------------------------------------------------------------
	
// 	    Full Name:                                 
// 	    Date of Birth:
// 	    Gender:
	
// 	    ACCOUNT INFORMATION
// 	    --------------------------------------------------------------------------------------
// 	    Phone Number:
// 	    Country:
		
//         --------------------------------------------------------------------------------------
//                                  Note that pressing the 'Tab' will back	
// 	    )";
// 	    cout << str;
	    
	    
// 	    gotoxy(52,4);
// 	    string fullname = "a"; //==============================================================
// 	    cout << fullname;
// 	    gotoxy(52,5);
// 	    string age = "a"; //=================================================;
// 	    gotoxy(52,6);
// 	    string ge;
// 	    char ch;
// 	    while(1) {
// 	    	ch = _getch();
// 	    	if(ch != 9)
// 	    		continue;
// 	    	else break;
// 		}
// 	}	
// };

// int main() {
//     bool oke = 1;
    
//     while(oke) {
//     	LoginScreen A;
//     	printLoginFrame();
    	
//     	string username = input(41, 7, true, false);
    	
//     	if(username == "") { // end
//     		break;
// 		}
// 		if(username == "+") {
// 			while(true) {
// 				if(Create_Account() == 1) { // bam tab
// 					break;
// 				}
// 			}
// 			continue; // tro ve giao dien dang nhap
// 		}
		
// 		string password = input(41, 10, true, true);
		
// 		if(password == "") { // end
//     		break;
// 		}
// 		if(password == "+") {
// 			while(true) {
// 				if(Create_Account() == 1) { // bam tab
// 					break;
// 				}
// 			}
// 			continue; // tro ve giao dien dang nhap
// 		}
			
// 		// L?u username và password ==================================================================================================
		
// 		/*if(/* Thong tin khong hop le ----------------------------------------------------------------------------------------------------) {
// 			continue; //  Nhap lai
// 		}
// 		*/
		
		
// 		bool Manager = 1; // kiem tra neu la quan tri vien ===============================================
// 		bool oke1 = 1;
		
// 		/*while(oke1) {
// 			char c;
			
// 			while(1) {
// 				if(Manager) {
// 					Print_Manager_Menu();
// 				}
// 				else {
// 					Print_User_Menu();
// 				}
				
// 				gotoxy(4,27);
// 				cout << "--> Enter your choice: ";
				
// 				char mx;
// 				if(Manager) {	// neu quan tri vien thi 5 phan
// 					mx = '5';
// 				}
// 				else {			// nguoi dung 4 phan
// 					mx = '4';
// 				}
				
// 				c = _getch(); 
// 				cout << c;
// 				Sleep(200);
				
// 				if(c == 9) {
// 					Exit();
// 					return 0;
// 				}
// 				if (c < '1' || c > mx) {
// 	            	Invalid_Result();
// 	            	Sleep(3000);
// 		        } 
// 				else {
// 		            break;
// 		        }
// 			}
			
// 			switch(c) {
// 				case '1': {
// 					A.Change_Information();
// 					break;
// 				}
// 				case  '2': {
// 					A.Print_Information();
// 					break;
// 				}
// 			}	
// 		}*/
// 	}
	
// 	Notification("The program has ended", 50, 5); // Thong bao ket thuc
	
//     return 0;
// }
