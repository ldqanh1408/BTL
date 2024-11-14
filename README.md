1. Tải Visual Studio Code
  Truy cập Visual Studio Code.
  Tải xuống và cài đặt phiên bản phù hợp với hệ điều hành của bạn.
2.Cài đặt Compiler C++(làm theo link hướng dẫn bên dưới)
  Windows:https://code.visualstudio.com/docs/cpp/config-mingw
3.Cài đặt git.
  3.1. Truy cập vào https://git-scm.com/downloads/win, và tải 1 trong 2 bản "Standalone Installer" tương thích với máy.
  3.2. Tạo tài khoản trên https://github.com, nếu chưa có.
4.Thiết lập hệ thống trên github.
  4.1. Tạo 1 Repositories trên github(https://github.com)
  4.2. Truy cập đường link https://github.com/ldqanh1408/BTL.git, chọn mục "code" và chọn "download zip".
  4.3. Truy vẫn vào Repositories vừa tạo ở bước 4.1 chọn "uploading an existing file" và chọn những file và folder ở trong folder(compressed zip) vừa tải xuống ở bước 4.2 kéo vào ô trước màn hình và chọn "commit           changes".
5.Thiết lập chương trình kết nối với hệ thống.
  5.1. Tạo 1 folder lưu trữ Repositories vừa tạo ở bước 4.
  5.2. Cấu hình Git trên máy tính:
     Gõ:
      git config --global user.name "Tên của bạn"
      git config --global user.email "email@gmail.com"
    Thay "Tên của bạn" và "email@gmail.com" bằng tên và email của bạn đã dùng trên GitHub.
  5.3. Thiết lập Bash làm terminal mặc định trong Visual Studio Code
      5.3.1.Mở VS Code.
      5.3.2.Truy cập File > Preferences > Settings (hoặc nhấn Ctrl + ,).  
      5.3.3.Tìm "Terminal Integrated Default Profile".
      5.3.4.Chọn Git Bash (hoặc Bash) làm terminal mặc định.
   5.4. Truy vậy vào folder vừa tạo ở bước 5.1, click chuột phải > Git Bash
      Gõ:
       git init
       git branch -M main
       git remote add origin "URL của remote repository vừa tạo ở bước 4.1"
       git pull origin main
6. Để chạy chương trình vào folder vừa tạo ở bước 5.1 và double click vào run.bat để sử dụng.


  

