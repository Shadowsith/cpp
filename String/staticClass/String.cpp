#include "String.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <vector>
#include <iterator>

bool String::equals(std::string &str1, std::string &str2){
    if (str1.compare(str2) == 0)
        return true;
    else return false;
}

int String::indexOf(std::string &str, std::string fin){
    std::size_t found = str.find(fin);
    if(found != std::string::npos){
        int i = static_cast<int>(found);
        return i;
    }
}

int String::lastIndexOf(std::string &str, std::string fin){
    std::size_t found = str.rfind(fin);
    if(found != std::string::npos){
        int i = static_cast<int>(found);
        return i;
    }
}

std::string String::replace(std::string &str, std::string oldstr, std::string newstr){
    boost::replace_all(str,oldstr,newstr);    
    return str;
}

std::string String::replaceFirst(std::string &str, std::string oldstr, std::string newstr){
    boost::replace_first(str,oldstr,newstr);    
    return str;
}

std::string String::replaceLast(std::string &str, std::string oldstr, std::string newstr){
    boost::replace_last(str,oldstr,newstr);    
    return str;
}

std::string replaceHead(std::string &str, int headsize, std::string newstr){
    boost::replace_head(str,headsize,newstr);    
    return str;
}

std::string replaceTail(std::string &str, int tailsize, std::string newstr){
    boost::replace_tail(str,tailsize,newstr);    
    return str;
}

std::string erase(std::string &str, std::string erasestr){
    boost::erase_all(str,erasestr);
    return str;
}

std::string eraseFirst(std::string &str, std::string erasestr){
    boost::erase_first(str,erasestr);
    return str;
}

std::string eraseLast(std::string &str, std::string erasestr){
    boost::erase_last(str,erasestr);
    return str;
}

std::string eraseHead(std::string &str, int headsize){
    boost::erase_head(str,headsize);    
    return str;
}

std::string eraseTail(std::string &str, int tailsize){
    boost::erase_tail(str,tailsize);    
    return str;
}
std::vector<std::string> String::split(std::string &str, std::string split){
    std::vector<std::string> strs;
    boost::split(strs,str,boost::is_any_of(split));
    return strs;
}

std::vector<char> String::toCharArr(std::string &str){
    std::vector<char> arr;
    for(int i = 0; i < str.length(); i++){
        arr.push_back(str.at(i));
    }
    return arr;
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

std::string String::normPathUnix(std::string &str){
    boost::replace_all(str,"\\","/");
    for(int i = 1; i < str.length(); i++){
        if(str.at(i) == str.at(i-1)){
            str.erase(i);
        }
    }
    return str;
}

std::string String::normPathWindows(std::string &str){
    boost::replace_all(str,"/","\\");
    for(int i = 1; i < str.length(); i++){
        if(str.at(i) == str.at(i-1)){
            str.erase(i);
        }
    }
    return str;
}

short String::toShort(std::string &str){
    try{
        short num = boost::lexical_cast<short>(str);
        return num;
    }
    catch(const boost::bad_lexical_cast &e){
        std::cout << "Caught bad lexical cast, reference is not from type short:" << std::endl;
    }
}

int String::toInt(std::string &str){
    try{
        int num = boost::lexical_cast<int>(str);
        return num;
    }
    catch(const boost::bad_lexical_cast &e){
        std::cout << "Caught bad lexical cast, reference is not from type int:" << std::endl;
    }
}

float String::toFloat(std::string &str){
    try{
        float num = boost::lexical_cast<float>(str);
        return num;
    }
    catch(const boost::bad_lexical_cast &e){
        std::cout << "Caught bad lexical cast, reference is not from type float:" << std::endl;
    }
}

double String::toDouble(std::string &str){
    try{
        double num = boost::lexical_cast<double>(str);
        return num;
    }
    catch(const boost::bad_lexical_cast &e){
        std::cout << "Caught bad lexical cast, reference is not from type double:" << std::endl;
    }
}

std::string String::fromShort(short &num){
    try{
        std::string str = boost::lexical_cast<std::string>(num);
        return str;
    }
    catch(const boost::bad_lexical_cast &e){
        std::cout << "Caught bad lexical cast with error " << e.what() << std::endl;
    }
}

std::string String::fromInt(int &num){
    try{
        std::string str = boost::lexical_cast<std::string>(num);
        return str;
    }
    catch(const boost::bad_lexical_cast &e){
        std::cout << "Caught bad lexical cast with error " << e.what() << std::endl;
    }
}

std::string String::fromLong(long &num){
    try{
        std::string str = boost::lexical_cast<std::string>(num);
        return str;
    }
    catch(const boost::bad_lexical_cast &e){
        std::cout << "Caught bad lexical cast with error " << e.what() << std::endl;
    }
}

std::string String::fromFloat(float &num){
    try{
        std::string str = boost::lexical_cast<std::string>(num);
        return str;
    }
    catch(const boost::bad_lexical_cast &e){
        std::cout << "Caught bad lexical cast with error " << e.what() << std::endl;
    }
}

std::string String::fromDouble(double &num){
    try{
        std::string str = boost::lexical_cast<std::string>(num);
        return str;
    }
    catch(const boost::bad_lexical_cast &e){
        std::cout << "Caught bad lexical cast with error " << e.what() << std::endl;
    }
}

int main(void){
}

