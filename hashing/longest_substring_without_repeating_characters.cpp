#include <iostream>
#include <string>
#include <vector>

#define print(x) std::cout << x << std::endl;


int lengthOfLongestSubstring(std::string s){

    // count array of chars
    std::vector<int> mpp(256,-1);

    int left = 0;
    int right = 0;
    int n = s.length();
    int maxi = 0;

    while(right < n){

        // abcdeefg
        // when R reaches second E, make L directly come to first E
        // instead of a,b,c,d,e for L

        // mpp[char] = index
        // mpp[char]+1 = next index

        // left may be ahead, so dont go back
        // std::max(next_index , left)

        // letter is repeated
        if(mpp[s[right]] != -1){
            left = std::max(mpp[s[right]]+1, left);
        }

        // letter is new
        // store char and its index
        mpp[s[right]] = right;

        // if L=1, R=3 then length is (3-1)+1
        maxi = std::max(maxi, right-left+1);

        // go to next element
        right++;

    }



    return maxi;
}

int main(){

    // Longest Substring Without Repeating Characters
    std::string str = "abcaabcdba";


    // L and R pointers
    print(lengthOfLongestSubstring(str));




    return 0;
}
