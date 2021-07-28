#include <iostream>
#include <vector>

int main() {

    // Maximum Subarray Sum
    std::vector<int> nums = {-2,-3,4,-1,-2,1,5,-3};

    int sum = 0;
    int maxi = INT_MIN;
    for(auto x : nums) {

        sum += x;

        maxi = std::max(maxi,sum);

        if (sum < 0){ // only carryforward a net positive val, 4,-3 allowed,  4,-5 not
            sum = 0;
        }
    }

    std::cout << maxi << std::endl;
}
