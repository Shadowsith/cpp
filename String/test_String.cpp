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
    std::vector<std::string> vec = s.split(";");
    if(vec[0].compare("hi") == 0 && vec[1].compare("bye") == 0 && vec[2].compare("seeyousoon") == 0)
        std::cout << d.green("SplitTest: accepted") << std::endl;
    else std::cout << d.red("SplitTest: denied") << std::endl;
}

void SplitTestString(){
    String s = "hi--ho--ha";
    String delimiter = "--";
    std::vector<String> vec = s.split(delimiter);
    if(vec[0].compare("hi") && vec[1].compare("ho") && vec[2].compare("ha"))
        std::cout << d.green("SplitTestString: accepted") << std::endl;
    else std::cout << d.red("SplitTestString: denied") << std::endl;
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

void FindTest(){
    String s = "asd_das_dfs";
    std::vector<int> vec = s.find("d");
    if(vec[0] == 2 && vec[1] == 4 && vec[2] == 8)
        std::cout << d.green("FindTest: accepted") << std::endl;
    else std::cout << d.red("FindTest: denied") << std::endl;
}

void FindFirstTest(){
    String s = "hello";
    int pos = s.findFirst("l");
    if(pos == 2){
        pos = s.findFirst("e");
        if(pos == 1){
            std::cout << d.green("FindFirstTest: accepted") << std::endl;    
        }
        else std::cout << d.red("FindFirstTest: denied") << std::endl;
    }
    else std::cout << d.red("FindFirstTest: denied") << std::endl;
}

void FindLastTest(){
    String s = "hello";
    int pos = s.findLast("o");
    if( pos == 4){
        pos = s.findLast("l");
        if(pos == 3){
            std::cout << d.green("FindLastTest: accepted") << std::endl;
        }
    }
    else std::cout << d.red("FindLastTest: denied") << std::endl;
}

void TrimTest(){
    String s = "     ";
    String a = "  hello  ";
    s.trim();
    a.trim();
    if(s.isEmpty() && a.compare("hello"))
        std::cout << d.green("TrimTest: accepted") << std::endl;
    else std::cout << d.red("TrimTest: denied") << std::endl;
}

void TrimLeftTest(){
    String s = "      ";
    String a = "  hello  ";
    s.trimLeft();
    a.trimLeft();
    if(s.isEmpty() && a.compare("hello  "))
        std::cout << d.green("TrimLeftTest: accepted") << std::endl;
    else std::cout << d.red("TrimLeftTest: denied") << std::endl;
}

//TODO
void TrimRightTest(){
    String s = "      ";
    String a = "  hello  ";
    s.trimRight(); //does not trim all spaces:
    a.trimRight();
    if(s.isEmpty() && a.compare("  hello"))
        std::cout << d.green("TrimRightTest: accepted") << std::endl;
    else std::cout << d.red("TrimRightTest: denied") << std::endl;
}

void FillLeftTest(){
    String s = "1";
    s.fillLeft(3,'0');
    if(s.compare("0001"))
        std::cout << d.green("FillLeftTest: accepted") << std::endl;
    else std::cout << d.red("FillRightTest: denied") << std::endl;
}

void FillRightTest(){
    String s = "1";
    s.fillRight(3,'0');
    if(s.compare("1000"))
        std::cout << d.green("FillRightTest: accepted") << std::endl;
    else std::cout << d.red("FillRightTest: denied") << std::endl;
}

void EraseTest(){
    String s = "Hello World! Hello Sun!";
    s.erase("Hello ");
    if(s.compare("World! Sun!"))
        std::cout << d.green("EraseTest: accepted") << std::endl;
    else std::cout << d.red("EraseTest: denied") << std::endl;
}

void EraseFirstTest(){
    String s = "Hello World! Hello Sun!";
    s.eraseFirst("Hello ");
    if(s.compare("World! Hello Sun!"))
        std::cout << d.green("EraseFirstTest: accepted") << std::endl;
    else std::cout << d.red("EraseFirstTest: denied") << std::endl;
}

void EraseLastTest(){
    String s = "Hello World! Hello Sun!";
    s.eraseLast("Hello ");
    if(s.compare("Hello World! Sun!"))
        std::cout << d.green("EraseLastTest: accepted") << std::endl;
    else std::cout << d.red("EraseLastTest: denied") << std::endl;     
}

void EraseHeadTest(){
    String s = "12345678";
    s.eraseHead(4);
    if(s.compare("5678"))
        std::cout << d.green("EraseHeadTest: accepted") << std::endl;
    else std::cout << d.red("EraseHeadTest: denied") << std::endl;
}

void EraseTailTest(){
    String s = "12345678";
    s.eraseTail(4);
    if(s == "1234")
        std::cout << d.green("EraseTailTest: accepted") << std::endl;
    else std::cout << d.red("EraseTailTest: denied") << std::endl;
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
    SplitTestString();
    UpperTest();
    LowerTest();
    FindTest();
    FindFirstTest();
    FindLastTest();
    TrimTest();
    TrimLeftTest();
    TrimRightTest();
    FillLeftTest();
    FillRightTest();
    EraseTest();
    EraseFirstTest();
    EraseLastTest();
    EraseHeadTest();
    EraseTailTest();
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
    std::cout << "Test finished in: " << duration << " Microseconds"<< std::endl;

    return 0;
}
