#include <iostream>
#include <fstream>
#include <vector>
#include "ShopData.h"

ShopData::ShopData() {

}

ShopData::ShopData(std::string csvLine){
    std::vector<int> csvCol; 
    for(int i = 0; i < csvLine.length(); i++){
        if(csvLine.at(i) == ';'){
            csvCol.push_back(i); 
        }
    }
    std::string shopNum = csvLine.substr(0,csvCol[0]);
    std::string shopTenant = csvLine.substr(csvCol[0]+1,csvCol[1]-2);
    std::string shopSales = csvLine.substr(csvCol[1]+1,csvLine.length());
    //std::cout << shopNum << "|" << shopTenant << "|" << shopSales << std::endl;
    //
    //
    std::string::size_type si;
    int shop_Num = std::stoi(shopNum,&si);
    std::string::size_type sd;
    double shop_Sales = std::stod(shopSales,&sd);
    
    this->shop = shop_Num;
    this->tenant = shopTenant;
    this->sales = shop_Sales; 
}

ShopData::ShopData(int shop, std::string tenant, double sales){
    this->shop = shop;
    this->tenant = tenant;
    this->sales = sales;
}

int ShopData::getShop(){
    return shop;
}

std::string ShopData::getTenant(){
    return tenant;
}

double ShopData::getSales(){
    return sales;
}

void ShopData::printShopData(){
    std::cout << this->getShop() << " | " << this->getTenant() << " | " << this->getSales() << std::endl;
}

/*int main(void){
    ShopData s("1;Michael;1200");
    s.printShopData();
    ShopData m("2;Adolf Hitler;1888");
    m.printShopData();
}*/
