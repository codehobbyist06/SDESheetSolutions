#include <bits/stdc++.h>

//Linkedlist list method
int findDuplicate(vector<int> &arr, int n){
    
	//Initialize variables
    int fast_ptr = arr[0], slow_ptr = arr[0];
    
    //Use tortoise method(here we will be iterating through the array like a graph)
    //1. Use two pointers fast_ptr and slow_ptr... increment fast_ptr by 2
    //increment slow_ptr by 1
   do{
        fast_ptr = arr[fast_ptr];
        fast_ptr = arr[fast_ptr];
        slow_ptr = arr[slow_ptr];
    }while(fast_ptr != slow_ptr);
    
    //2. Initialize the fast_ptr to the start of the array
    fast_ptr = arr[0];
    
    //3. Increment both the pointer by 1 until they are equal.. the equal element will be the duplicate element
    while(fast_ptr != slow_ptr){
        fast_ptr = arr[fast_ptr];
        slow_ptr = arr[slow_ptr];
    }
    
    return fast_ptr;
}
