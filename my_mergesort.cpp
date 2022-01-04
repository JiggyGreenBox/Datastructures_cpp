#define print(x) std::cout << x << std::endl;


#include <iostream>
#include <vector>

void merge(int arr[], int left, int mid, int right){
    // make 2 temp arrays
    int n1 = mid-left+1;
    int n2 = right-mid;
    int a[n1];
    int b[n2];

    // populate left array
    for(int i=0; i<n1; i++){
        a[i] = arr[left+i];
    }

    // populate right array
    for(int i=0; i<n2; i++){
        b[i] = arr[mid+1+i];
    }

    // pointers
    int i=0;
    int j=0;
    int k=left;

    while(i<n1 && j <n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            k++; i++;
        }
        else{
            arr[k]=b[j];
            k++; j++;
        }
    }

    // i and j pointers if they dont reach the end
    while(i<n1){
        arr[k]=a[i];
        k++; i++;
    }
    while(j<n2){
        arr[k]=b[j];
        k++; j++;
    }
}

void mergeSort(int arr[], int left, int right){

    if(left < right){
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        merge(arr, left, mid, right);
    }
}




int main() {

    int arr[] = {5,4,3,2,1};

    mergeSort(arr,0,4);

    for(auto x:arr){
        print(x);
    }




    return 0;
}
