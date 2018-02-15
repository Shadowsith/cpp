#include <iostream>
#include <string>
#include <vector>

void Output() {
    std::cout<<std::endl;
}

template<typename First, typename ... Strings> 
void Output(First arg, const Strings&... rest) {

    std::cout<<arg<<" ";
    Output(rest...); 
}; 

template<typename Numbers>
double sum(Numbers numbers) {
    return numbers;
}

template<typename T, typename... Rest>
double sum(T t, Rest... rest) {
    return t + sum(rest...); 
}

template<typename Strings>
std::string combine(Strings strings) {
    return strings;
}

template<typename T, typename... Rest>
std::string combine(T t, Rest... rest) {
    std::string str(";"); 
    return t + str +  combine(rest...); 
}


int main(void){
    Output("I","am","a","sentece");
    double c = sum(1,2,3,6); 
    std::cout << c  << std::endl;
    std::string str = "Hallo";
    std::string s = combine(str,"Welt","du","bist","hier");
    std::cout << s << std::endl;

    return 0;
}
