#include <iostream>
#include "heap.h"

int main(){
    myHeap a;

    a.insert(50);
    a.insert(30);
    a.insert(40);
    a.insert(20);
    a.insert(25);
    a.insert(2);
    a.insert(12);
    a.insert(3);
    a.insert(15);
    a.insert(16);
    a.insert(4);

    std::cout << "Initial Values:"<< std::endl;
    a.arrayPrint();
    a.visualPrint();

    std::cout << "Top: " << a.top() << std::endl;
    a.arrayPrint();

    std::cout << std::endl << "Pop everything off the heap: " << std::endl;
    while(!a.empty()){
        std::cout << " " << a.pop();
    }
    std::cout << std::endl;

}
