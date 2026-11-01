#include <iostream>
#include<filesystem>
#include <fstream>



#include <string>


namespace fs = std::filesystem;


int main() {
    while (true) {
        std::string user;
        std::getline(std::cin, user);
        std::cout <<"$"<<user;





        std::string command;
        std::getline(std::cin, command);




        const char* home_env = std::getenv("HOME");








        if (command == "create folder") {
            std::string name;
            std::getline(std::cin, name);
            fs::path dir_path = fs::path(home_env) / "Documents" / name;
            //fs::path file_path = fs::path(home_env) / "Documents" / "my_file.txt";



            if (fs::create_directories(dir_path)) {
                std::cout << "Папка создана в \n"<<dir_path<<std::endl;

            }

        }else if (command != "create folder" && command != "show progressbar"&& command != "exit" && command != "create file") {
            std::cerr<<"command not found"<<std::endl;

        }
        if (command == "show progressbar") {
            int i=0;
            for (i=0;i<100;i++) {
                std::cout<<"#";

            }

        }


        // Создаём файл: если он уже есть — перезапишется, если нет — создастся
        if (command=="create file") {


            std::string name_for_file;
            std::getline(std::cin, name_for_file);
            std::string what_extension;
            std::string what_path;
            std::getline(std::cin, what_path);
            std::getline(std::cin, what_extension);
            //fs::path file_path = fs::path(home_env) / "Documents" / "my_file.py";
            fs::path file_pat = fs::path(home_env) / what_path / (name_for_file + what_extension);
            fs::path file_path(file_pat);


            std::ofstream out_file(file_pat);
            if (out_file.is_open()) {
                // Можно сразу что-то записать:
                //out_file << ";
                out_file.close();
                std::cout << "Файл создан: " << file_pat << "\n";
            } else {
                std::cerr << "Не удалось создать файл: " << file_pat << "\n";
            }
        }




    }
    return 0;
}