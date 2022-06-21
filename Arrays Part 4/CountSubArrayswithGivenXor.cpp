#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //Initialize the variables
    int xor_val = 0,ans = 0;
    int n = arr.size(); 
    unordered_map<int,int> pre_xor;
    
    //Iterate through the array
    /*
    <----xor------>
    <---S----><-k->
    1 2 3 4 5 6 7 8
    */
    for(int i=0;i<n;i++){
        xor_val^=arr[i];
        int target = xor_val^x;
        if(xor_val == x){
            ans++;
        }
        ans+=pre_xor[target];
        pre_xor[xor_val]++;
    }
    
    return ans;
}