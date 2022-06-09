#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    //This is a classical problem of Kadane's algorithm
    
    //Initialize variables
    long long curr_sum = 0, max_sum = 0;
    
    //Iterate through the array and keep a track of the current sum
    //If the current sum reduces to less than 0 then we set it back to 0 since this means that there is
    //no need to carry forward the current sum as this would reduce
    //our max_sum
    for(int ind=0;ind<n;ind++){
        curr_sum+=arr[ind];
        if(curr_sum < 0){
            curr_sum = 0;
        }
        else{
            max_sum = max(curr_sum, max_sum);
        }
    }
    return max_sum;
}