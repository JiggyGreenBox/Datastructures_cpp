# Arrays

* [Sort Arrays of 0s 1s 2s](#sort-arrays-of-0s-1s-2s)
* [Missing and Repeating Number](#missing-and-repeating-numbers)
* [Merge two sorted arrays in O(1)](#merge-two-sorted-arrays-in-o1)
* [Maximum Subarray Sum](#maximum-subarray-sum)


### Sort Arrays of 0s 1s 2s
```cpp
// low mid high pointer
// everything left  of low  = 0     int low = 0;
// everything left  of mid  = 1     int mid = 0;
// everything right of high = 2     int high = nums.size()-1;
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
```

### Missing and Repeating Numbers
```cpp
// using count array
// O(N) + O(N)

std::vector<int> nums = {4,3,6,2,1,1};
std::vector<int> count_arr(nums.size(), 0); // count array

for(int x : nums) {
    count_arr[x]++;
}

for(int i=1; i<count_arr.size(); i++) {
    if(count_arr[i] == 0) {
        std::cout << "missing num: " << i << std::endl;
    }
    else if(count_arr[i] > 1) {
        std::cout << "repeated num: " << i << std::endl;
    }
}
```

### Merge two sorted arrays in O(1)
```cpp
// Merge two sorted arrays in O(1)
// 2 pointer swap and sort 2nd array

// gap algorithm
    // gap = ceil ( n1 + n2 / 2 )
// do while gap = 1
// 2 pointer swap
// NlogN
```

### Maximum Subarray Sum
```cpp
std::vector<int> nums = {-2,-3,4,-1,-2,1,5,-3};

int sum = 0;
int maxi = INT_MIN;
for(auto x : nums) {

    sum += x;
    maxi = std::max(maxi,sum);

    if (sum < 0) { // only carryforward a net positive val, 4,-3 allowed,  4,-5 not
        sum = 0;
    }
}
std::cout << maxi << std::endl;
```
