#include <iostream>
#include <fstream>
#include "Evaluator.h"

Evaluator::Evaluator(std::string shopListFilename){
    std::ifstream csvFile;
    csvFile.open(shopListFilename);
    std::string line;
    int i = 0;
    // loop go through all lines
    while(std::getline(csvFile,line)){
        // Ignores the expression line in csv Table
        if(i > 0){
            ShopData sh(line);
            shop_list.push_back(sh);
        }
        i++;
    }

    // Now Evaluate all usable sale data from shop_list
    for(int i = 0; i < shop_list.size(); i++){
        // For shops with id 1
        if ( shop_list[i].getShop() == 1 ){
            this->sumShop1 += shop_list[i].getSales();
        }
        // For shops with id 2
        if ( shop_list[i].getShop() == 2 ){
            this->sumShop2 += shop_list[i].getSales();
        }
        // For shops with id 3
        if ( shop_list[i].getShop() == 3 ){
            this->sumShop3 += shop_list[i].getSales();
        }
        this->sumAll += shop_list[i].getSales();
    }
    std::cout << std::endl;
    // Now get Shop with min and max sale value
    this->min = shop_list[0];
    this->max = shop_list[0];
    for(int i = 0; i< shop_list.size(); i++){
        if ( this->max.getSales() < shop_list[i].getSales() ){
                this->max = shop_list[i];
        }
        if ( this->min.getSales() > shop_list[i].getSales()){
            this->min = shop_list[i];
        }
    }
}

double Evaluator::getSumShop1(){
    return this->sumShop1;
}

double Evaluator::getSumShop2(){
    return this->sumShop2;
}

double Evaluator::getSumShop3(){
    return this->sumShop3;
}

double Evaluator::getSumAll(){
    return this->sumAll;
}

ShopData Evaluator::getMax(){
    return this->max;
}

ShopData Evaluator::getMin(){
    return this->min;
}

void Evaluator::evaluateData(){
    std::cout << "Umsatzauswertung für:" << std::endl;
    std::cout << "Shop Id 1:\t" << getSumShop1() << std::endl;
    std::cout << "Shop Id 2:\t" << getSumShop2() << std::endl;
    std::cout << "Shop Id 3:\t" << getSumShop3() << std::endl;
    std::cout << "Total:\t" << getSumAll() << std::endl;
    std::cout << "Shopauswertung:" << std::endl;
    std::cout << "Minimaler Umsatz:" << min.getShop() << "|" << min.getTenant() << "|" << min.getSales() << std::endl;
    std::cout << "Maximaler Umsatz:" << max.getShop() << "|" << max.getTenant() << "|" << max.getSales() << std::endl;
}

void Evaluator::printShopList(){
    for(int i = 0; i < shop_list.size(); i++){
        //shop_list[i].printShopData();
        shop_list[i].getShop();
    }
}
