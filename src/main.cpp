#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <sstream>

void logAnalyzer(std::ifstream& file, const std::string& filename);
namespace fs = std::filesystem;
int main(){

    std::vector<std::string> entries;
    for(const auto& entry : fs::directory_iterator{"data/"}){
        if(entry.path().extension() == ".log"){
            std::string name = fs::path(entry).filename().string();
            entries.push_back(name);
        }
    }
    entries.push_back("EOD");
    std::cout << "===SYSTEM LOG ANALYZER===\nTo exit, type \"exit\".\n\n";
    
    while(true){
        std::string input;
        std::getline(std::cin, input);

        std::string command;
        std::string second_command;

        std::istringstream iss(input);
        iss >> command >> second_command;
        

        if(command == "show"){
            if(second_command == "logs"){
                std::cout << "========" << '\n';
                for(const auto& entry : fs::directory_iterator{"data/"}){
                    std::string name = entry.path().filename().string();
                    std::cout << name << '\n';
                }
                std::cout << "\n"; 
            }
            else if(second_command == "all"){
                for(const auto& entry : fs::directory_iterator{"data/"}){
                    std::string name = entry.path().filename().string();
                    std::ifstream log_file("data/" + name);
                    if(!log_file.is_open()){
                        std::cout << "Failed to open file.\n";
                        continue;
                    }
                    else logAnalyzer(log_file, "data/" + name);
                }
                std::cout << "\n";
            }
            else{
                auto it = std::find(entries.begin(), entries.end(), second_command);
                if(it != entries.end()){
                    std::ifstream file("data/" + second_command);
                    logAnalyzer(file, "data/" + second_command);
                    std::cout << "\n";
                }
                else std::cout << "File Not Found." << '\n';
            }
        }
        if(command == "exit") break;
        if(command == "help"){
            std::cout << "Basic commands to use System Log Anayzer\n====================================\n\n";
            std::cout << "show <filename>.log: Display the results of <filename>.log\n";
            std::cout << "show all:  Display the results of all log files.\n";
            std::cout << "show logs:  Display log files present inside the directory.\n";
            std::cout << "exit : Exit from SLA\n\n";
        }

    }

}