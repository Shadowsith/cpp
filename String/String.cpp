#include "String.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <iostream>
#include <vector>
#include <iterator>

bool String::equals(std::string &str1, std::string &str2){
    if (str1.compare(str2) == 0)
        return true;
    else return false;
}

int String::findFirst(std::string &str, std::string fin){
    boost::iterator_range<std::string::iterator> r = boost::find_first(str,fin);
    std::string::iterator it;
    int i = std::distance( r.begin(), it);
    return i;
}

std::vector<std::string> String::split(std::string &str, std::string split){
    std::vector<std::string> strs;
    boost::split(strs,str,boost::is_any_of(split));
    return strs;
}

std::string String::toUpper(std::string &str){
    boost::to_upper(str);
    return str;
}

std::string String::toLower(std::string &str){
    boost::to_lower(str);
    return str;
}

std::string String::trim(std::string &str){
    boost::trim(str);
    return str;
}

std::string String::trimLeft(std::string &str){
    boost::trim_left(str);
    return str;
}

std::string String::trimRight(std::string &str){
    boost::trim_right(str);
    return str;
}

short String::toShort(std::string &str){
    std::string::size_type ss;
    int num = std::stoi(str,&ss);
    if ((num <= 32767) || (num >= -32767)){
            short snum = num;
            return snum;
    }
    else return 0; // exception needed here
}

int String::toInt(std::string &str){
    std::string::size_type si;
    int num = std::stoi(str,&si);
    return num;
}

long String::toLong(std::string &str){
    std::string::size_type sl;
    long num = std::stoi(str,&sl);
    return num;
}

float String::toFloat(std::string &str){
    std::string::size_type sf;
    float num = std::stof(str,&sf);
    return num;
}

double String::toDouble(std::string &str){
    std::string::size_type sd;
    double num = std::stod(str,&sd);
    return num;
}

/*
int main(void){
    std::string test = "Hallo";
    test = String::toLower(test);
    std::cout << "!" << test << "!" << std::endl;
    int num = String::findFirst(test,"l");

}
*/
