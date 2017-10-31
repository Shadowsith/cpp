// This program only shows how to limit a vector
// And push a new one to the top and delete the last one

#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> vec;

void vecLimit(int v){
    //Limit are 3 elements
    if ( vec.size() < 3) {
        vec.insert(vec.begin(),v);
    }
    else if ( vec.size() == 3 ) {
        vec.pop_back(); //delete last
        vec.insert(vec.begin(),v); //insert new at the front
    }
    if ( vec.size() > 3 ) {
        vec.pop_back();
    }
}

void vecPrint(){
    for(int i = 0; i < vec.size(); i++){
        std::cout << vec[i] << std::endl;
    }
    std::cout << std::endl;
}

int main(void){
    vecLimit(3);
    vecLimit(2);
    vecLimit(1);
    //vecLimit(1);
    vecPrint();
    vecLimit(4);
    vecPrint();
    vecLimit(8);
    vecPrint();
}   
