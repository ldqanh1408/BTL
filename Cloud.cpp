#include "Cloud.h"

void Cloud::backup() {

    std::string command, commit_msg;

    time_t now = time(0);
    tm *ltm = localtime(&now);

    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    command = "git add .";
    std::system(command.c_str());

    // Commit với thông điệp được truyền vào
    commit_msg = std::string(buffer);
    command = "git commit -m \"" + commit_msg + "\"";
    std::system(command.c_str());

    // Đẩy thay đổi lên nhánh chính (hoặc nhánh mong muốn)
    command = "git push origin main";
    std::system(command.c_str());
}   
void Cloud::restore(std::string position) {
    std::string command;

    if (is_tracked(position)) {
        // Nếu tệp đã được theo dõi, sử dụng git restore
        command = "git restore --source=origin/main " + position + " --staged";
    } else {
        // Nếu tệp không được theo dõi và không có trong kho local, dùng git pull để kéo từ remote
        command = "git clean -f";
    }

    // Thực thi lệnh
    std::system(command.c_str());
}

bool Cloud::is_tracked(std::string position) {
    // Kiểm tra xem tệp có được Git theo dõi không
    std::string command = "git ls-files --error-unmatch " + position;

    int result = std::system(command.c_str());

    // Nếu result là 0, tức là tệp đã được Git theo dõi
    return (result == 0);
}
