#include<bits/stdc++.h>

void findUniqueSubsets(vector<vector<int>>& ans,vector<int>& arr,int left,int right,vector<int>& subset,unordered_map<int,int> count){
    //Handle base case
    if(left > right){
        ans.push_back(subset);
        return;
    }
    
 //Making recursive calls to build the subset
    findUniqueSubsets(ans,arr,left+count[arr[left]],right,subset,count);
    subset.push_back(arr[left]);
    count[arr[left]]-=1;
    findUniqueSubsets(ans,arr,left+1,right,subset,count);
    subset.pop_back();
}

vector<vector<int>> uniqueSubsets(int n,vector<int>& arr)
{
    //Initialize the variables
    unordered_map<int,int> count;
    vector<vector<int>> ans;
    vector<int> subset;
    
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    
    sort(arr.begin(),arr.end());
    
    //Call the recursive function
    findUniqueSubsets(ans,arr,0,n-1,subset,count);
    
    sort(ans.begin(),ans.end());
    
    return ans;
}
