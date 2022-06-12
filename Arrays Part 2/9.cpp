#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	//Gap Algorithm 
      //or
    //Start merging from the last element(means greater element)
    
    //Declare variables
    int ptr1 = m-1, ptr2 = n-1,ans_ptr = m+n-1;
    
    //Iterate through the arrays in reverse order and pick the max
    //element and then place it at the last index of the ans arr(here
    //the first arr is ans array so space complexity is O(1))
    while(ans_ptr >= 0){
        if(ans_ptr == 0){
            arr1[ans_ptr] = min(arr1[0],arr2[0]);
            --ans_ptr;
            continue;
        }
        else if(arr1[ptr1] > arr2[ptr2]){
            arr1[ans_ptr] = arr1[ptr1];
            --ptr1;
            --ans_ptr;
        }
        else{
            arr1[ans_ptr] = arr2[ptr2];
            --ptr2;
            --ans_ptr;
        }
    }
    
    return arr1;
}