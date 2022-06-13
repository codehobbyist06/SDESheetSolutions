#include <bits/stdc++.h> 

long long countInversions(long long *arr,int left, int right){
    //Initialize variables
    int mid = 0,i = 0,j = 0;
    long long merge_inversions = 0, count_left_inversions = 0, count_right_inversions = 0, it = left;
    vector<int> sorted;
    
    //Handle base case
    if(left >= right){
        return 0;
    }
    else if(right - left == 1){
        if(arr[right] < arr[left]){
            swap(arr[left],arr[right]);
            return 1;  
        } 
        else return 0;
    }
    
    //Calculate the mid point
    mid = left+(right-left)/2;
    i = left, j = mid+1;
    
    count_left_inversions = countInversions(arr, left, mid);
    count_right_inversions = countInversions(arr, mid+1, right);
    
    //Count the number of inversions while merging the sorted arrays
    while(i < mid+1 and j < right+1){
        if(arr[i] > arr[j]){
            merge_inversions+=(mid-i+1);
            sorted.push_back(arr[j]);
            j++;
        }
        else{
            sorted.push_back(arr[i]);
            i++;
        }
    }
    
    //Push the remaining elements in the left array
    while(i < mid+1){
        sorted.push_back(arr[i]);
        i++;
    }
    
    //Push the remaining elements in the right array
    while(j < right+1){
        sorted.push_back(arr[j]);
        j++;
    }
    
    //Put the elements in sorted order back to the array
    for(int in=0;in < sorted.size() and it <= right;in++){
        arr[it] = sorted[in];
        it++;
    }
    
    return count_left_inversions + count_right_inversions + merge_inversions;
}

long long getInversions(long long *arr, int n){
    return countInversions(arr,0,n-1);
}