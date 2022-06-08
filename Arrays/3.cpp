#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &nums, int n)
{
    //Initialize variables
    int first_decreasing_index = -1;
    int next_greater_index = -1;
    
    //Find the first increasing element from the end of the array
    for(int i=n-1;i>0;i--){
        if(nums[i] > nums[i-1]){
            first_decreasing_index = i-1;
            break;
        }
    }
    
    //If the current permutation is the last possible permutation return the first permutation
    if(first_decreasing_index == -1){
        sort(nums.begin(),nums.end());
        return nums;
    }
    
    // Find the next greater element for the first decreasing element
    int next_greater_element = -1;
    for(int i=n-1;i>first_decreasing_index;i--){
        if(nums[i] > nums[first_decreasing_index]){
            next_greater_element = i;
            break;
        }
    }
    swap(nums[next_greater_element],nums[first_decreasing_index]);
    
    //Sort the decreasing the part of the array
    sort(nums.begin()+first_decreasing_index+1,nums.end());
    return nums;
}