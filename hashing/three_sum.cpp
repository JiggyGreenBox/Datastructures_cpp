#include <iostream>
#include <vector>
#include <algorithm>

#define print(x) std::cout << x << std::endl;

std::vector<std::vector<int>> threeSum(std::vector<int> nums, int target){

    std::vector<std::vector<int>> ans;

    std::sort(nums.begin(),nums.end());

    int n = nums.size();


    // n-2 because 3 nums required

    for(int i=0;i<n-2;i++){
        if((i == 0)||(i>0 && nums[i] != nums[i-1])){
            // not duplicate
            int low = i+1;
            int high = n-1;
            int sum = target-nums[i];

            while(low < high){
                if(nums[low] + nums[high] == sum){

                    // push ans
                    std::vector<int> trio;
                    trio.push_back(nums[i]);
                    trio.push_back(nums[low]);
                    trio.push_back(nums[high]);
                    ans.push_back(trio);

                    // increment the duplicate indexes
                    while(low < high && nums[low] == nums[low+1]) low++;
                    while(low < high && nums[high] == nums[high+1]) high--;

                    // no duplicates go to next index
                    low++;
                    high--;
                }
                else if(nums[low] + nums[high] < sum){
                    low++;
                }
                else if(nums[low] + nums[high] > sum){
                    high--;
                }
            }
        }
    }

    return ans;
}

int main(){

    // Three Sum Problem

    // foreach and then 2 sum
    // sort first

    std::vector<int> nums = {-1,0,1,2,-1,-4};

    std::vector<std::vector<int>> ans;

    int target = 0;
    ans = threeSum(nums, target);

    for(auto x: ans){
        for(auto y: x){
            print(y);
        }
        print("\n");
    }

    return 0;
}
