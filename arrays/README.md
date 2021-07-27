# Arrays

* [Sort Arrays of 0s 1s 2s](#sort-arrays-of-0s-1s-2s)


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
