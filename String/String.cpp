#include "String.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <limits>
#include <exception>
#include <sstream>

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

bool String::operator== (const String &s){
    return (m_str.compare(s.m_str) == 0);
}

bool String::operator== (const std::string &str){
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

//aprovement--------------------------

bool String::isEmpty(){
    return m_str.empty();
}

bool String::isEmptyOrWhiteSpace(){
    return (m_str.empty() || m_str.compare(" "));
}



//formatting----------------------------

void String::copy(String &s){
    s = m_str;
}

void String::copy(std::string &str){
    str = m_str; 
}

void String::copy(char* c){
    for (int i = 0; i < m_str.length(); i++) {
        c[i] = m_str[i];    
    }
}

void String::copyTo(const String &s){
    m_str = s;
}

void String::copyTo(const std::string &str){
    m_str = str;
}

void String::copyTo(const char* c){
    m_str = c;
}

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

std::vector<int> String::find(std::string search){
    std::vector<int> vec;

    std::size_t pos = m_str.find(search);
    while(pos != std::string::npos)
    {
        vec.push_back(pos);
        pos = m_str.find(search,pos+1);
    }
    return vec;
}

std::vector<int> String::findAll(std::string search){
    String::find(search);
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
    std::size_t pos = m_str.find(oldstr);
    while(pos != std::string::npos)
    {
        m_str.replace(pos, oldstr.length(), newstr);
        pos = m_str.find(oldstr,pos+1);
    }
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
    m_str.erase(0,headsize);
    m_str = newstr + m_str;
}

void String::replaceTail(int tailsize, std::string newstr){
    m_str.erase(m_str.end()-tailsize, m_str.end());
    m_str += newstr;
}

void String::erase(std::string erasestr){
    std::string::size_type n = erasestr.length();
    for (std::string::size_type i = m_str.find(erasestr); i != std::string::npos; 
         i = m_str.find(erasestr)) 
    {
        m_str.erase(i, n);    
    }
}

void String::eraseFirst(std::string erasestr){
    std::size_t pos = m_str.find(erasestr);
    if(pos != std::string::npos){
        m_str.erase(pos, erasestr.length());
    }
}

void String::eraseLast(std::string erasestr){
    std::size_t pos = m_str.rfind(erasestr);
    if(pos != std::string::npos){
        m_str.erase(pos, erasestr.length());
    }
}

void String::eraseHead(int headsize){
    m_str.erase(0,headsize);
}

void String::eraseTail(int tailsize){
    m_str.erase(m_str.end()-tailsize, m_str.end());
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

// TODO
void String::normPathUnix(){
    //boost::replace_all(m_str,"\\","/");
    for(int i = 1; i < m_str.length(); i++){
        if(m_str.at(i) == m_str.at(i-1)){
            m_str.erase(i);
        }
    }
}

// TODO
void String::normPathWindows(){
    //boost::replace_all(m_str,"/","\\");
    for(int i = 1; i < m_str.length(); i++){
        if(m_str.at(i) == m_str.at(i-1)){
            m_str.erase(i);
        }
    }
}

//casts------------------------------------

short String::toShort(){
    try
    {
        std::string::size_type si;
        int itos = std::stoi(m_str, &si);
        if(itos <= std::numeric_limits<short>::max() )
        {
            short num = itos;
            return num;
        }
        else std::cout << "The number was to big for short!" << std::endl;
    }
    catch(std::exception ex)
    {
        std::cout << "Can't convert short to string" << std::endl;
        std::cout << ex.what() << std::endl;
    }
}

int String::toInt(){
    try
    {
        std::string::size_type si;
        int num = std::stoi(m_str, &si);
    }
    catch(const std::exception& ex)
    {
        std::cout << "Caught bad cast, reference is not from type int:" << std::endl;
        std::cout << ex.what() << std::endl;
    }
}

float String::toFloat(){
    try
    {
        std::string::size_type sf;
        float num = std::stof(m_str, &sf);
        return num;
    }
    catch(const std::exception& ex)
    {
        std::cout << "Caught bad cast, reference is not from type float:" << std::endl;
        std::cout << ex.what() << std::endl;
    }
}

double String::toDouble(){
    try
    {
        std::string::size_type sd;
        double num = std::stod(m_str, &sd);
        return num;
    }
    catch(const std::exception& ex)
    {
        std::cout << "Caught bad cast, reference is not from type float:" << std::endl;
        std::cout << ex.what() << std::endl;
    }
}


