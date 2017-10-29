#include <iostream>
#include <string>
#include "ShopData.h"
#include "Evaluator.h"

std::string inputFilename(){
    std::string input;
    std::cout << "Geben Sie bitte den Dateinamen ein: ";
    std::cin >> input;
    return input;
}

int main(int argc, char* argv[]){
    if (argc > 1){
        std::string filename = argv[1];
        Evaluator a(filename);
        a.evaluateData();
    }
    else {
        std::string filename = inputFilename();
        Evaluator a(filename);
        //a.printShopList();
        a.evaluateData();
    }
}
