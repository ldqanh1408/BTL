#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>


using namespace std;


namespace Menu {
	// thêm mấy cái frontend vào đây còn mấy cái xử lý đăng nhập là làm ở main
    // Hàm gotoxy n?m ngoài l?p LoginScreen
    void gotoxy(int x, int y);
    void print_login_frame();
    void print_change_information();
    void print_user_menu();
    void notification(std::string s, int x, int y);
    void create_account_screen();
    void create_information_screen();
    void print_otp();
}

#endif