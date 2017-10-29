#include <iostream>
#include <fstream>

int main(void){
    std::ifstream csvFile;
    csvFile.open("Shops.csv");
    std::string line;
    int i = 0;
    while (std::getline(csvFile,line)){
       if(i > 0)
            std::cout << line << "\t" << i << std::endl;
        i++;
    }
    return 0;
}
