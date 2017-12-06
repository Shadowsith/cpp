#include <iostream>
#include "String.h"

void EqualTest(){
    String s1 = "hello";
    String s2 = "hello";
    if( s1 == s2){
        std::cout << "EqualTest: true" << std::endl;
    }
    else std::cout << "EqualTest: false" << std::endl;
}

void NotEqual(){
    String s1 = "hello";
    String s2 = "hella";
    if( s1 != s2){
        std::cout << "NotEqual: true" << std::endl;
    }
    else std::cout << "NotEqual: false" << std::endl;
}

void EmptyTest(){
    String s;
    if(s.isEmpty())
        std::cout << "EmptyTest: true" << std::endl;
    else std::cout << "EmtpyTest: false" << std::endl;
}

void EmptyOrWhiteSpaceTest(){
    String s1;
    String s2 = " ";
    if(s1.isEmptyOrWhiteSpace() && s2.isEmptyOrWhiteSpace())
        std::cout << "EmptyOrWhiteSpaceTest: true" << std::endl;
    else std::cout << "EmptyOrWhiteSpaceTest: false" << std::endl;
}

void CopyTest(){
    String s1 = "hallo";
    String s2;
    s1.copy(s2);
    if(s1 == s2){
        std::cout << "CopyTest: true" << std::endl;
    }
    else std::cout << "CopyTest: false" << std::endl;
}

void CopyToTest(){
    String s1;
    String s2 = "hallo";
    s1.copyTo(s2);
    if(s1 == s2){
        std::cout << "\033[1;32mCopyToTest: true\033[0m" << std::endl;
    }
    else std::cout << "CopyToTest: false" << std::endl;
}


int main(void){
    EqualTest();
    NotEqual();
    EmptyTest();
    EmptyOrWhiteSpaceTest();
    CopyTest();
    CopyToTest();
}
