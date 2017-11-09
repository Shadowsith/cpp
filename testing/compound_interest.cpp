#include <iostream>
#include <string>

double compound_interest(double value, double percentage, int months){
    
    if(months == 0){
        return value; 
    }
    else{
        value = value + value * (percentage/100);
        months--;
        std::cout << value << " " << months << std::endl;
        compound_interest(value, percentage, months);
    }
}


int main(void){
    double compound = 1;
    int months = 36;
    double percentage = (0.5/12); 
    double spreizen = 50;
    double total_spreizen;

    for(int i = 0; i < months; i++) {
        compound += spreizen + compound * (percentage/100);
        total_spreizen += spreizen;
        i++;
    }
    std::cout << compound << " " << compound - 5000 - total_spreizen << std::endl;
}
