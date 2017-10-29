#include <iostream>
#include <string>
#include "ShopData.h"
#include "Evaluator.h"

int main(void){
    Evaluator a("Shops.csv");
    //a.printShopList();
    a.evaluateData();
}
