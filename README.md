Cài Đặt chương trình:

- 1.Tải Visual Studio Code
  - 1.1 Truy cập Visual Studio Code.
  - 1.2 Tải xuống và cài đặt phiên bản phù hợp với hệ điều hành của bạn.

- 2.Cài đặt Compiler C++(làm theo link sau) Windows:https://code.visualstudio.com/docs/cpp/config-mingw

- 3.Cài đặt git.
  - 3.1. Truy cập vào https://git-scm.com/downloads/win, và tải 1 trong 2 bản "Standalone Installer" tương thích với máy.
  - 3.2. Tạo tài khoản trên https://github.com, nếu chưa có.

- 4.Thiết lập hệ thống trên github.
  - 4.1. Tạo 1 Repositories trên github(https://github.com)
  - 4.2. Truy cập đường link https://github.com/ldqanh1408/BTL.git, chọn mục "code" và chọn "download zip".
  - 4.3. Truy vẫn vào Repositories vừa tạo ở bước 4.1 chọn "uploading an existing file" và chọn những file và folder ở trong folder(compressed zip) vừa tải xuống ở bước 4.2 kéo vào ô trước màn hình và chọn "commit changes".

- 5.Thiết lập chương trình kết nối với hệ thống.
  - 5.1. Tạo 1 folder lưu trữ Repositories vừa tạo ở bước 4.
  - 5.2. Cấu hình Git trên máy tính:
    - Gõ:
      - git config --global user.name "Tên của bạn"
      - git config --global user.email "email@gmail.com"
    - Thay "Tên của bạn" và "email@gmail.com" bằng tên và email của bạn đã dùng trên GitHub.
  - 5.3. Thiết lập Bash làm terminal mặc định trong Visual Studio Code
      - 5.3.1.Mở VS Code.
      - 5.3.2.Truy cập File > Preferences > Settings (hoặc nhấn Ctrl + ,).  
      - 5.3.3.Tìm "Terminal Integrated Default Profile".
      - 5.3.4.Chọn Git Bash (hoặc Bash) làm terminal mặc định.
   - 5.4. Truy vậy vào folder vừa tạo ở bước 5.1, click chuột phải > Git Bash
      - Gõ:
       - git init
       - git branch -M main
       - git remote add origin "URL của remote repository vừa tạo ở bước 4.1"
       - git pull origin main

- 6.Để chạy chương trình vào folder vừa tạo ở bước 5.1 và double click vào run.bat để sử dụng.

-----------------------------------------------------------------------------------------------------------------------------------------------------------

Sơ lược về hệ thống:
- tài khoản của manager năm trong class Console của file header phần private dạng nhưu sau:
	- const std::un_manager = "lede", (tài khoản)
	- const std::pw_manager = "lede6666" (mật khẩu)
- có thể thay đổi bằng cách thay thế "lede" và "lede6666" bằng tài khoản hoặc mật khẩu khác mong muốn.

- class User kế thừa public class Information và "has-a" class Account
- class Console "has-a" class User, chứa tài khoản của manager và dùng để thực hiện các năng hệ thống.
- namespace Cloud dùng để sử dụng để sao lưu và phục hồi dữ liệu hệ thống trên GitHub
- namespace gotp dùng để tạo, hiện thị và xác thực OTP.
- namespace Menu dùng để hiện thị các chức năng hệ thống.
- một file main.cpp dùng để chạy chương trình khi double click vào run.bat
- các file còn lại trừ folder thư viện băm kiểu brcypt cho mật khẩu (thư viện này tải bên ngoài về).
- 1 folder data:
	- folder: store_information: lưu trữ đối tượng class Information(với tên file là "user_name" của class Account)
	- folder: store_password: lưu trữ mật khẩu(với tên file là "user_name" của class Account)
	- folder: store_walet: lưu trữ tiền(với tên file là "ID" của class Information) và trong này lưu trữ ví tổng (tên là "total_wallet.txt") sẽ trích ra radom từ 0 - > giá trị lớn nhất 	của kiểu dữ liệu unsigned short.
	- folder: user_transaction_history: lưu trữ lịch sử giao dịch của từng người dùng (với tên file là "ID" của class Information)
	- file: transaction_log : lưu trữ lịch sử giao dịch của hệ thống.
- mọi thay đổi điều được sao lưu và khi gặp lỗi thì lỗi hệ thống sẽ tự restore.
- hệ thống này chưa được tối ưu về mặt thuật toán và bộ nhớ nên sẽ có đôi lúc khá chậm.

Logic hệ thống: 
![image](https://github.com/user-attachments/assets/ae4b8bd2-9760-4883-a8ad-91964fb9dcc9)

Mô tả chương trình:
![screencapture-uis-ptithcm-edu-vn-2024-12-17-21_18_23](https://github.com/user-attachments/assets/993a448f-e6cf-459a-ad8f-34827f47989f)
 

-Lưu ý: hệ thống có thể gặp lỗi xung đột kiểu dữ liệu của thư viện có sẵn trong visual studio code mặc dù đã test máy khác nhưng lỗi này vẫn là tiềm năng, vậy nên để fix được lỗi này manager chạy chương trình bằng cách đăng nhập vào visual studio code và mở terminal và gõ lần lượt: 
	- g++ -o main main.cpp -static
 	- ./main
-sau đó ctrl + click vào những đường dẫn đẫn đến file bị bug ở terminal sửa "byte"->"my_byte";


