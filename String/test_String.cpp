#include <iostream>
#include <chrono>
#include "String.h"
#include "../dyeText/DyeText.h"

DyeText d;

void EqualTest(){
    String s1 = "hello";
    String s2 = "hello";
    std::string str = "hello";
    char c[5] = {'h','e','l','l','o'};
    char* ch = c;
    if( s1 == s2 && s1 == str && s1 == ch){
        std::cout << d.green("EqualTest: accepted") << std::endl;
    }
    else std::cout << d.red("EqualTest: denied") << std::endl;
}

void NotEqual(){
    String s1 = "hello";
    String s2 = "hella";
    if( s1 != s2){
        std::cout << d.green("NotEqual: accepted") << std::endl;
    }
    else std::cout << d.red("NotEqual: denied") << std::endl;
}

void CompareTest(){
    String s1 = "hello";
    String s2 = "hello";
    std::string str = "hello";
    char c[5] = {'h','e','l','l','o'};
    char* ch = c;
    if (s1.compare(s2) && s1.compare(str) && s1.compare(ch))
        std::cout << d.green("CompareTest: accepted") << std::endl;
    else std::cout << d.red("CompareTest: denied") << std::endl;
}

void CompareNotTest(){
    String s1 = "hello";
    String s2 = "hella";
    std::string str = "hella";
    char c[5] = {'h','e','l','l','a'};
    char* ch = c;
    if ((s1.compare(s2) || s1.compare(str) || s1.compare(ch)) == false)
        std::cout << d.green("CompareNotTest: accepted") << std::endl;
    else std::cout << d.red("CompareNotTest: denied") << std::endl;
}

void EmptyTest(){
    String s;
    if(s.isEmpty())
        std::cout << d.green("EmptyTest: accepted") << std::endl;
    else std::cout << d.red("EmtpyTest: denied") << std::endl;
}

void EmptyOrWhiteSpaceTest(){
    String s1;
    String s2 = " ";
    if(s1.isEmptyOrWhiteSpace() && s2.isEmptyOrWhiteSpace())
        std::cout << d.green("EmptyOrWhiteSpaceTest: accepted") << std::endl;
    else std::cout << d.red("EmptyOrWhiteSpaceTest: denied") << std::endl;
}

void CopyTest(){
    String s1 = "hallo";
    String s2;
    s1.copy(s2);
    if(s1 == s2){
        std::cout << d.green("CopyTest: accepted") << std::endl;
    }
    else std::cout << d.red("CopyTest: denied") << std::endl;
}

void CopyToTest(){
    String s1;
    String s2 = "hallo";
    s1.copyTo(s2);
    if(s1 == s2){
        std::cout << d.green("CopyToTest: accepted") << std::endl;
    }
    else std::cout << d.red("CopyToTest: denied") << std::endl;
}

void SplitTest(){
    String s = "hi;bye;seeyousoon";
    std::vector<std::string> vec = s.split(';');
    if(vec[0].compare("hi") == 0 && vec[1].compare("bye") == 0 && vec[2].compare("seeyousoon") == 0)
        std::cout << d.green("SplitTest: accepted") << std::endl;
    else std::cout << d.red("SplitTest: denied") << std::endl;
}

void UpperTest(){
    String s = "hello";
    std::string str = "HELLO";
    s.toUpper();
    if(s.compare(str))
        std::cout << d.green("UpperTest: accepted") << std::endl;
    else std::cout << d.red("UpperTest: denied") << std::endl;
}

void LowerTest(){
    String s = "HELLO";
    std::string str = "hello";
    s.toLower();
    if(s.compare(str))
        std::cout << d.green("LowerTest: accepted") << std::endl;
    else std::cout << d.red("LowerTest: denied") << std::endl;
}


int main(void){
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    EqualTest();
    NotEqual();
    CompareTest();
    CompareNotTest();
    EmptyTest();
    EmptyOrWhiteSpaceTest();
    CopyTest();
    CopyToTest();
    SplitTest();
    UpperTest();
    LowerTest();
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
    std::cout << "Test finished in: " << duration << " Microseconds"<< std::endl;

    return 0;
}
