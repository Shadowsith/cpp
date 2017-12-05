#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <iostream>

std::vector<std::string> split(const std::string& s, char delim){
    std::vector<std::string> vec;
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss,item,delim)){
        vec.push_back(item);
    }
    return vec;
}

int main(void){
    std::string str = "hallo;1234";
    std::vector<std::string> vec;
    vec = split(str,';'); 
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << std::endl;
    }
}
