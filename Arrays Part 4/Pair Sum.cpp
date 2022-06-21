#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    //Initialize the variables
    unordered_map<int,int> mp;
    int len = arr.size();
    vector<vector<int>> ans;
    
    //Count the number of occurence of each element in the array
    for(int i=0;i<len;i++){
        mp[arr[i]]++;
    }
    
    //Iterate through the array and push the pairs found in the ans arr based on the count
    for(int i=0;i<len;i++){
        mp[arr[i]]-=1;
        
        int target = s-arr[i];
        int count = mp[target];
        
        while(count--){
            if(arr[i] < target)
                ans.push_back({arr[i],target});
            else
                ans.push_back({target,arr[i]});
        }
    }
    
    //Sort the ans to match the output format
    
    sort(ans.begin(),ans.end());
    
    return ans;
}