#include <iostream>

int main(){

    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    
    int* newArray = new int[10];

    std::cout << "NewArray: " << newArray << std::endl;

    for (unsigned int i = 0; i < 10; ++i) {
        newArray[i] = array[i];
    }

    


}