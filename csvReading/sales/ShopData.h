#ifndef SHOPDATA_H
#define SHOPDATA_H 


#include <string>

class ShopData {
    private:
        int shop;
        std::string tenant;
        double sales;

    public:
        ShopData();
        ShopData(std::string csvLine);
        ShopData(int shop, std::string tenant, double sales);
        int getShop();
        std::string getTenant();
        double getSales();
        void printShopData();
};

#endif
