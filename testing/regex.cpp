#include <iostream>
#include <string>
#include <regex>

int main()
{
    std::string str("1231");
    std::string str1 = "Hallo {0} ich bin {1} {2} {32}";
    std::regex r("\\{[0-9]{1,3}\\}");

    std::sregex_iterator iter(str1.begin(), str1.end(), r);
    std::sregex_iterator end;
    std::string str2; 

    int matches = 0;
    while ( iter != end ) {
        for (int i = 0; i < iter->size(); i++) {
            str2 = (*iter)[i];
            std::cout << str2  << std::endl;
        }
        iter++; 
        matches++; 
    }
    std::cout << "Matches: " << matches << std::endl;

    return 0;
}
