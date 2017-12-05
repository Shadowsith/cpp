#include "String.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>

//constructors--------------------------
String::String(){
    m_str = "";
}

String::String(const std::string str){
    m_str = str;
}

String::String(const char* c) : m_str(c) {}

String::String(std::vector<std::string> strvec){
    for(int i = 0; i < strvec.size(); i++){
        m_str += strvec[i];
    }
}

String::String(std::vector<char> cvec){
    for(int i = 0; i < cvec.size(); i++){
        m_str += cvec[i];
    }
    cvec.clear();
}

String::String(short num){
    m_str = std::to_string(num);
}

String::String(int num){
    m_str = std::to_string(num);
}

String::String(long num){
    m_str = std::to_string(num);
}

String::String(float num){
    m_str = std::to_string(num);
}

String::String(double num){
    m_str = std::to_string(num);
}

//operators----------------------------

// save object directly to std::string working!
String::operator std::string() const{
    return m_str;
}

String& String::operator= (String s){
    m_str = s.m_str;
}

String& String::operator= (std::string str){
    m_str = str;
}

String& String::operator= (const char* c){
    std::string convert(c);
    m_str = convert;
}

bool String::operator== (const String& S){
    return (m_str.compare(S.m_str) == 0);
}

bool String::operator== (const std::string str){
    return (m_str.compare(str) == 0);
}

bool String::operator== (const char* c){
    for(int i = 0; i < m_str.length(); i++){
        if(m_str[i] != c[i]){
            return false;
        }
    }
    return true;
}

bool String::operator!= (const String& S){
    return (m_str.compare(S.m_str) != 0);
}

bool String::operator!= (const std::string str){
    return (m_str.compare(str) != 0);
}

bool String::operator!= (const char* c){
    for(int i = 0; i < m_str.length(); i++){
        if(m_str[i] != c[i]){
            return true;
        }
    }
    return false;
}

String& String::operator+= (const String &S){
    this->m_str += S.m_str; 
    return *this;
}

String operator+ (String lhs, const String& rhs)
{
    lhs += rhs;
    return lhs;
}

String& String::operator+= (const std::string str){
    this->m_str += str;
    return *this;
}

String operator+ (String lhs, const std::string& rhs){
    lhs += rhs;
    return lhs;
}

String& String::operator+= (const char* c){
    std::string convert(c);
    this->m_str += convert;
    return *this;
}

String operator+ (String lhs, const char* rhs){
    lhs += rhs;
    return lhs;
}

String& String::operator+= (const char c){
    this->m_str += c;
    return *this;
}

String operator+ (String lhs, const char rhs){
    lhs += rhs;
    return lhs;
}

char& String::operator[] (int pos){
    return this->m_str[pos];
}

// shows member m_str for std::cout 
std::ostream& operator<< (std::ostream &out, const String &S){
   out << S.m_str; 
   return out;
}

std::istream& operator>> (std::istream &is, String &S){
    char* input = new char[256];
    is.getline(input,256);
    std::string convert(input);
    S = convert;
    return is;
}

//getters-------------------------------

//when operator= failes (e.g. for QString or something)
std::string String::get(){
    return m_str;
}

int String::size(){
    return m_str.size();
}

int String::getSize(){
    String::size();
}

int String::length(){
    return m_str.length();
}

int String::getLength(){
    String::length();
}

char String::charAt(int pos){
    return m_str.at(pos); 
}

std::vector<char> String::charList(){
    m_cList.clear();
    for(int i = 0; i < m_str.length(); i++){
        m_cList.push_back(m_str.at(i));
    }
    return m_cList;
}

//setters------------------------------

void String::set(std::string str){
    this->m_str = str;
}

//formatting----------------------------


bool String::compare(std::string &str){
    if (m_str.compare(str) == 0)
        return true;
    else return false;
}

// alias form compare, Java-String name
bool String::equals(std::string &str){
    String::equals(str);
}

template<typename T1, typename T2>
T1& String::concat(T1& a, T2& b){
    a += b;
    this->m_str = a;
    return a;
}



int String::findFirst(std::string find){
    std::size_t pos = m_str.find(find);
    if(pos != std::string::npos){
        int i = static_cast<int>(pos);
        return i;
    }
}

// alias form findFirst, Java-String name
int String::indexOf(std::string find){
    String::findFirst(find);
}

int String::findLast(std::string find){
    std::size_t pos = m_str.rfind(find);
    if(pos != std::string::npos){
        int i = static_cast<int>(pos);
        return i;
    }
}

// alias from findLast, Java-String name
int String::lastIndexOf(std::string find){
    String::findLast(find);
}

void String::replace(std::string oldstr, std::string newstr){
//    boost::replace_all(m_str,oldstr,newstr);    
    std::string str;
    str.reserve(m_str.length());

    std::string::size_type lastPos = 0;
    std::string::size_type findPos;

    while(std::string::npos != (findPos = m_str.find(oldstr, lastPos))){
        str.append(m_str, lastPos, findPos - lastPos);
        str += newstr;
        lastPos = findPos + oldstr.length();
    }

    str += m_str.substr(lastPos);
    m_str.swap(str);
}

void String::replaceFirst(std::string oldstr, std::string newstr){
    std::size_t pos = m_str.find(oldstr);
    if(pos != std::string::npos){
        m_str.replace(pos, oldstr.length(), newstr);
    }
}

void String::replaceLast(std::string oldstr, std::string newstr){
    std::size_t pos = m_str.rfind(oldstr);
    if(pos != std::string::npos){
        m_str.replace(pos, oldstr.length(), newstr);
    }
}

void String::replaceHead(int headsize, std::string newstr){
    boost::replace_head(m_str,headsize,newstr);    
}

void String::replaceTail(int tailsize, std::string newstr){
    boost::replace_tail(m_str,tailsize,newstr);    
}

void String::erase(std::string erasestr){
    boost::erase_all(m_str,erasestr);
}

void String::eraseFirst(std::string erasestr){
    boost::erase_first(m_str,erasestr);
}

void String::eraseLast(std::string erasestr){
    boost::erase_last(m_str,erasestr);
}

void String::eraseHead(int headsize){
    boost::erase_head(m_str,headsize);    
}

void String::eraseTail(int tailsize){
    boost::erase_tail(m_str,tailsize);    
}

std::vector<std::string>& String::split(const char c){
    m_parts.clear();
    std::stringstream ss(m_str);
    while(std::getline(ss, m_str, c)){
        m_parts.push_back(m_str);
    }
    return m_parts;
}

void String::toUpper(){
    std::locale loc;
    std::string str;
    for(std::string::size_type i = 0; i < m_str.length(); ++i)
    {
        str += std::toupper(m_str[i], loc);
    }
    m_str = str;
}

void String::toLower(){
    std::locale loc;
    std::string str;
    for(std::string::size_type i = 0; i < m_str.length(); ++i)
    {
        str += std::tolower(m_str[i], loc);
    }
    m_str = str;
}

void String::trim(){
    //trim left side
    std::string::size_type trimIt = 0;
    for(std::string::size_type i = 0; i < m_str.length(); i++)
    {
        if(m_str[i] == ' ')
        {
            trimIt++;    
        }
        else break;
    }
    m_str.erase(0,trimIt);

    //trim right side
    trimIt = m_str.length();
    for(std::string::size_type i = m_str.length()-1; i > 0; i--)
    {
        if(m_str[i] == ' '){
            trimIt--;
        }
        else break;
    }
    m_str.erase(trimIt,m_str.length()-1);
}

void String::trimLeft(){
    //boost::trim_left(m_str);
    std::string::size_type trimIt = 0;
    for(std::string::size_type i = 0; i < m_str.length(); i++)
    {
        if(m_str[i] == ' ')
        {
            trimIt++;    
        }
        else break;
    }
    m_str.erase(0,trimIt);
}

void String::trimRight(){
    //boost::trim_right(m_str);
    std::string::size_type trimIt = m_str.length();
    for(std::string::size_type i = m_str.length()-1; i > 0; i--)
    {
        if(m_str[i] == ' '){
            trimIt--;
        }
        else break;
    }
    m_str.erase(trimIt,m_str.length()-1);
}

void String::fillLeft(int length, char fill){
    for(int i = 0; i < length; i++){
        m_str.insert(m_str.begin(), fill);
    }
}

void String::padLeft(int length, char fill){
    String::fillLeft(length, fill);
}

void String::fillRight(int length, char fill){
    for (int i = 0; i < length; i++) {
        m_str += fill;
    }
}

void String::padRight(int length, char fill){
    String::fillRight(length, fill);
}

void String::normPathUnix(){
    boost::replace_all(m_str,"\\","/");
    for(int i = 1; i < m_str.length(); i++){
        if(m_str.at(i) == m_str.at(i-1)){
            m_str.erase(i);
        }
    }
}

void String::normPathWindows(){
    boost::replace_all(m_str,"/","\\");
    for(int i = 1; i < m_str.length(); i++){
        if(m_str.at(i) == m_str.at(i-1)){
            m_str.erase(i);
        }
    }
}

//casts------------------------------------

short String::toShort(){
    try{
        short num = boost::lexical_cast<short>(m_str);
        return num;
    }
    catch(const boost::bad_lexical_cast &e){
        std::cout << "Caught bad lexical cast, reference is not from type short:" << std::endl;
    }
}

int String::toInt(){
    try{
        int num = boost::lexical_cast<int>(m_str);
        return num;
    }
    catch(const boost::bad_lexical_cast &e){
        std::cout << "Caught bad lexical cast, reference is not from type int:" << std::endl;
    }
}

float String::toFloat(){
    try{
        float num = boost::lexical_cast<float>(m_str);
        return num;
    }
    catch(const boost::bad_lexical_cast &e){
        std::cout << "Caught bad lexical cast, reference is not from type float:" << std::endl;
    }
}

double String::toDouble(){
    try{
        double num = boost::lexical_cast<double>(m_str);
        return num;
    }
    catch(const boost::bad_lexical_cast &e){
        std::cout << "Caught bad lexical cast, reference is not from type double:" << std::endl;
    }
}

int main(void){
    String s = "ffggff";
    s.replaceFirst("ff","h");
    s.replaceLast("ff","h");
    std::cout << s << std::endl;
}

