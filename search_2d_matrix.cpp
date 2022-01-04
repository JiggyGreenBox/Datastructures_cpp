#define print(x) std::cout << x << std::endl;


#include <iostream>
#include <vector>




// search in a 2D-matrix
int main() {

    // leetcode
    // each row is sorted
    // next row first ele, is greater than prev rows last ele
    std::vector<std::vector<int>> mat = {
                                            {1,2,3},
                                            {4,5,6},
                                            {7,8,9}
                                        };

    // gfg
    // each row is sorted, next row is independent of the last row,
    // values can be lesser than previous rows last ele
    std::vector<std::vector<int>> mat2 = {
                                            {10,20,30,40},
                                            {11,21,36,43},
                                            {25,29,39,50},
                                            {50,60,70,80},
                                        };



    /*
    for gfg
        start at first row last col
        if less go left
        if more go bottom

        if more go right and then bottom
    
    */                                   

    //
    /*
    // print mat
    for(int i=0;i<mat.size();i++){
        for(int j=0;j<mat[i].size();j++){
            print(mat[i][j]);
        }
    }
    */

    // get total elements
    // total = size of rows * size of cols -1
    // lo=0
    // hi = total

    // binary search
    // while lo < hi
    //  mid = lo +(hi-lo) / 2
    // if mat[mid/cols][mid%cols] == target
    // else if less lo = mid+1
    // else if more hi = mid-1


    return 0;
}
