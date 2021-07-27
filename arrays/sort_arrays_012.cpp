#include <iostream>
#include <vector>

template<typename T>
void printVector(std::vector<T> vec) {
    for(auto x: vec) {
        std::cout << x << std::endl;
    }
    std::cout << std::endl;
}

int main() {

    // sort arrays of 0's 1's 2's
    // sort using sort NlogN
    // count 0s 1s 2s 3N
    // dutch flag algorithm

    // low mid high pointer
    //
    // everything left  of low  = 0
    // everything left  of mid  = 1
    // everything right of high = 2

    //int a1[] = {0,1,10,1,2,1,2,0,0,0,1};
    std::vector<int> nums = {0,1,1,1,2,1,2,0,0,0,1};

    int low = 0;
    int mid = 0;
    int high = nums.size()-1;

    printVector(nums);


    // 0(N)
    while(mid <= high) {
        switch(nums[mid]) {
        case 0:
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
            break;

        case 1:
            mid++;
            break;

        case 2:
            std::swap(nums[mid],nums[high]);
            --high;
            break;
        }
    }

    printVector(nums);
}
