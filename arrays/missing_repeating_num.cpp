#include <iostream>
#include <vector>


int main() {

    // Missing and Repeating Number

    // using count array
    // O(N) + O(N)

    std::vector<int> nums = {4,3,6,2,1,1};

    // count array
    std::vector<int> count_arr(nums.size(), 0);

    for(int x : nums) {
        count_arr[x]++;
    }

    /*
    for(int x : count_arr) {
        std::cout << x << std::endl;
    }
    */


    for(int i=1; i<count_arr.size(); i++) {
        std::cout << count_arr[i] << std::endl;

        if(count_arr[i] == 0){
            std::cout << "missing num: " << i << std::endl;
        }
        else if(count_arr[i] > 1){
            std::cout << "repeated num: " << i << std::endl;
        }
    }
}
