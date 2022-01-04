#include <iostream>
#include <vector>
#include <unordered_map>

#define print(x) std::cout << x << std::endl;

std::vector<int> twoSum(std::vector<int> vec, int target){

    // brute force
    // N^2 loop, space 0(1)

    // check if val = (target - ele) in set
    // return ele index and cur index

    // o(N) worst O(N^2) if hash collisions
    // space O(N)

    std::vector<int> ans;
    std::unordered_map<int, int> mpp;  // val, index

    for(int i=0; i<vec.size(); i++){
        int val = target - vec[i];

        if(mpp.find(val) != mpp.end()){
            // val is in map
            ans.push_back(mpp[val]);
            ans.push_back(i);
            return ans;
        }

        mpp[vec[i]] = i;
    }


    return ans;
}

int main(){

    // Two Sum Problem
    std::vector<int> vec = {2,6,5,8,11};

    int target = 14;
    std::vector<int> ans;

    ans = twoSum(vec, target);

    for(auto x: ans){
        print(x);
    }

    return 0;
}
