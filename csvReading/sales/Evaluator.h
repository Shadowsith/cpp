#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <string>
#include <vector>
#include "ShopData.h"

class Evaluator {
    private:
        std::string reader;
        std::vector<ShopData> shop_list;
        ShopData sh;
        ShopData min;
        ShopData max;
        double sumShop1;
        double sumShop2;
        double sumShop3;
        double sumAll;

    public:
        Evaluator(std::string shopListFilename);
        void printShopList();
        double getSumShop1();
        double getSumShop2();
        double getSumShop3();
        double getSumAll();
        ShopData getMax();
        ShopData getMin();
        void evaluateData();
};

#endif
