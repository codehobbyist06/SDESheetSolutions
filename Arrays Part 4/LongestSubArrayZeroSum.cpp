#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {
    //Initialize the variables
    unordered_map<int,int> mp;
    long sum = 0;
    int ans = 0, n = arr.size();
    
    //Keep a track of the previous obtained sum
    /*Concept:
    <-------S----->
    <-- S --> <-0->
    1 2 3 4 5 6 7 8
    */
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum == 0){
            ans = max(ans,i+1);
        }
        else if(mp.find(sum) != mp.end()){
            ans = max(ans,i-mp[sum]);
        }
        else
            mp[sum] = i;
    }
    
    return ans;
}