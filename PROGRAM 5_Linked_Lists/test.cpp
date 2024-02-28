#include <iostream>
#include "IntList.h"

int main() {
    IntList list;
    list.push_back(2);
    list.push_back(8);
    list.push_back(5);
    list.push_back(3);
    list.push_back(3);
    list.push_back(8);
    list.push_back(9);


    std::cout << "First List: " << list << std::endl;

    IntList copyList(list);
    std::cout << "Copied List: " << copyList << std::endl;

    IntList assignList = list;
    std::cout << "Assigned List: " << assignList << std::endl;

    list.remove_duplicates();
    std::cout << "Insert Ordered: " << list << std::endl;

    list.selection_sort();
    std::cout << "Selection Sort: " << list << std::endl;

    list.insert_ordered(4);
    std::cout << "Insert Ordered: " << list << std::endl;

   
    
    return 0;
}
