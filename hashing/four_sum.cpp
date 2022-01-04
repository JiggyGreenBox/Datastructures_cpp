#include <iostream>
#include <vector>
#include <algorithm>

#define print(x) std::cout << x << std::endl;

std::vector<std::vector<int>> fourSum(std::vector<int> nums, int target){

    std::vector<std::vector<int>> ans;
    if(nums.empty())
        return ans;

    int n = nums.size();
    std::sort(nums.begin(), nums.end());


    // time complexity is N^3 for 3 loops
    for(int i=0; i<n; i++){

        for(int j=i+1; j<n; j++){

            int target_2 = target - nums[i] - nums[j];

            int low = j+1;
            int high = n-1;



            while(low < high){

                int two_target = nums[low] + nums[high];

                if(two_target < target_2)
                    low++;
                else if(two_target > target_2)
                    high--;
                else{
                    // sum is equal
                    std::vector<int> quad(4,0);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[low];
                    quad[3] = nums[high];
                    ans.push_back(quad);

                    // increment duplicate indexes (3 and 4)
                    while(low < high && nums[low] == quad[2]) ++low;
                    while(low < high && nums[high] == quad[3]) --high;
                }
            }

            // duplicates of num 2
            while(j+1<n && nums[j] == nums[j+1]) ++j;

        }
        // duplicates of num 1
        while(i+1<n && nums[i] == nums[i+1]) ++i;
    }

    return ans;
}

int main(){

    // Four Sum Problem

    // 3 pointer and binary sum is the first solutionn
    // first sort, i=0; j=i+1; k=j+1;
    // O(N^3) loop plus binary search logN  k+1 to n-1

    // optimal
    // sort
    // 2 pointers with left and right pointers
    // i=0; j=i+1;

    // now its 2 sum, left and right
    // if left+right < target; left++
    // if left+right > target; right--
    // if equal 4 pair found

    // make sure when moving j, left and right values should not be repeated


    std::vector<int> vec = {4,3,4,4,2,1,2,1,1};

    int target = 9;
    std::vector<std::vector<int>> ans;

    ans = fourSum(vec, target);
    //print(ans.size());


    for(auto x: ans){
        for(auto y: x){
            print(y);
        }
        print("\n");
    }


    return 0;
}
