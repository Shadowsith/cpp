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

void showEvaluation(Evaluator a){
    std::cout << "Umsatzauswertung für:" << std::endl;
    std::cout << "Shop Id 1:\t" << a.getSumShop1() << std::endl;
    std::cout << "Shop Id 2:\t" << a.getSumShop2() << std::endl;
    std::cout << "Shop Id 3:\t" << a.getSumShop3() << std::endl;
    std::cout << "Total:\t" << a.getSumAll() << std::endl;
    std::cout << "Shopauswertung:" << std::endl;
    std::cout << "Minimaler Umsatz:" << a.getMin().getShop() << "|" << a.getMin().getTenant() << "|" << a.getMin().getSales() << std::endl;
    std::cout << "Maximaler Umsatz:" << a.getMax().getShop() << "|" << a.getMax().getTenant() << "|" << a.getMax().getSales() << std::endl;
    std::cout << std::endl;
}

int main(int argc, char* argv[]){
    if (argc > 1){
        std::string filename = argv[1];
        Evaluator a(filename);
        a.evaluateData();
        showEvaluation(a);
    }
    else {
        std::string filename = inputFilename();
        Evaluator a(filename);
        //a.printShopList();
        a.evaluateData();
        showEvaluation(a);
    }
}
