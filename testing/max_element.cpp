#include <iostream>
#include <vector>

int main(void){
    
    int arr[5] = { 0, 2, 1, 3, 5 }; 

    int biggest;
    biggest;

    for( int i = 0; i < 5; i++){
        if ( biggest < arr[i] )
            biggest = arr[i];
    }

    std::cout << biggest << std::endl;
    return 0;

}
