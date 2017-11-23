#include "String.h"
#include <iostream>

bool EqualTest(String& lhs, String& rhs){
    if( lhs == rhs){
        return true;
    }
    else false;
}

int main(void){
    String s = "hallo";
    String s1 = "hallo";
    std::cout <<  EqualTest(s, s1) << std::endl;

}
