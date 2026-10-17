#include <iostream>
#include<filesystem>



#include <string>


namespace fs = std::filesystem;

int main() {

    std::string command;

    std::getline(std::cin, command);
    const char* home_env = std::getenv("HOME");
    std::string name;
    std::getline(std::cin, name);

    fs::path dir_path = fs::path(home_env) / "Documents" / name;



    if (command == "create folder") {



        if (fs::create_directories(dir_path)) {
            std::cout << "Папка создана в \n"<<dir_path<<std::endl;
        }

    }else if (command != "create folder") {
        std::cerr<<"command not found"<<std::endl;

        }
    }
