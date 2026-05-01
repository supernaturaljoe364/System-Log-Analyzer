#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>


namespace fs = std::filesystem;
void logAnalyzer(std::ifstream& file, const std::string& filepath){
    std::string filename = fs::path(filepath).filename().string();
    std::string arr;
    int error_count = 0, warning_count = 0, info_count = 0;
    while(std::getline(file, arr)){
        if(arr.find("ERROR") != std::string::npos){
            error_count++;
        }
        else if(arr.find("WARNING") != std::string::npos)  {
            warning_count++;
        }
        else info_count++;
    }
    std::cout << "Log Analysis of " << filename << '\n';
    std::cout << "Errors: " << error_count << "\n";
    std::cout << "Warning: " << warning_count << '\n';
    std::cout << "Info: " << info_count << '\n';
}