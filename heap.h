#include <iostream>
#include <iomanip>
#include <vector>

class myHeap{
    public:
        myHeap(){data.push_back(0);}

        void insert(int newNum);
        int top();
        int pop();
        bool empty(){return data.size() < 1;}

        void visualPrint();
        void arrayPrint();

    private:
        std::vector<int> data;
        void percolateDown(int i);
};

void myHeap::insert(int newNum){
    int i = data.size();
    data.push_back(0); //dummy value
    while (i > 1 && data[i / 2] < newNum){
        data[i] = data[i / 2];
        i = i / 2;
    }
    data[i] = newNum;
}

int myHeap::top(){
    if(data.size() > 0){
        return data[1];
    } else {
        std::cerr << "Error: Empty Heap" << std::endl;
        return INT_MIN;
    }
}

int myHeap::pop(){
    if(data.size() > 0){
        int max = data[1];
        data[1] = data[data.size() - 1];
        data.pop_back();
        percolateDown(1);
        return max;

    } else {
        std::cerr << "Error: Empty Heap" << std::endl;
        return INT_MIN;
    }
}

void myHeap::visualPrint(){
    std::cout << std::endl << "[   Heap Visualizer   ]" << std::endl;
    int index = 1;
    while(index < data.size()){
        int cur = index;
        std::cout << "     ";
        while((cur < index * 2) && cur < data.size()){
            std::cout << std::setw(3) << data.at(cur);
            cur++;
        }
        std::cout << std::endl;
        index = index * 2;
    }
    std::cout << "[                     ]" << std::endl << std::endl;
    return;
}

void myHeap::arrayPrint(){
    for (size_t i = 0; i < data.size(); i++){
        std::cout << "[" << i << "]  ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < data.size(); i++){
        std::cout << " " << std::setw(4) << std::left << data.at(i);;
    }
    std::cout << std::endl;
}

void myHeap::percolateDown(int i){
    int child = i * 2;
    while(child <= data.size()){
        if(child < data.size()){
            if(data[child] < data[child + 1]){
                child++;
            }
        }

        if(data[i] < data[child]){
            int tmp = data[i];
            data[i] = data[child];
            data[child] = tmp;
        } else {break;}

        i = child;
        child = i * 2;
    }
}
