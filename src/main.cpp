#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <algorithm>

void logAnalyzer(std::ifstream& file, const std::string& filename);
namespace fs = std::filesystem;
int main(){

    std::vector<std::string> entries;
    for(const auto& entry : fs::directory_iterator{"data/"}){
        std::string name = fs::path(entry).filename().string();
        entries.push_back(name);
    }
    entries.push_back("EOD");
    for(auto i : entries) std::cout << i << '\n';

    while(true){
        std::string command;
        std::string second_command;
        std::cout << "===SYSTEM LOG ANALYZER===\n";
        std::getline(std::cin, command, ' ');
        std::getline(std::cin, second_command);


        if(command == "show"){
            if(second_command == "logs"){
                for(const auto& entry : fs::directory_iterator{"data/"}){
                    std::string name = entry.path().filename().string();
                    std::cout << name << '\n';
                }
            }
            else{
                auto it = std::find(entries.begin(), entries.end(), second_command);
                if(it != entries.end()){
                    std::ifstream file("data/" + second_command);
                    logAnalyzer(file, "data/" + second_command);
                }
                else std::cout << "File Not Found." << '\n';
            }
        }
        if(command == "exit") break;

    }

}