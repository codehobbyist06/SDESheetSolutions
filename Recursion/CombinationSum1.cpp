#include<bits/stdc++.h>

void findSubsets(vector<int>& arr,int left,int right,int sum,int target,vector<vector<int>>& ans,vector<int> subset){
    //Handle the base case
    if(left > right){
        if(sum == target and subset.size() != 0){
            ans.push_back(subset);
        }
        return;
    }
    
    //Making recursive calls to build all the subsets using pick-not pick technique
    subset.push_back(arr[left]);
    findSubsets(arr,left+1,right,sum+arr[left],target,ans,subset);
    subset.pop_back();
    findSubsets(arr,left+1,right,sum,target,ans,subset);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    //Initialize the variables
    vector<vector<int>> ans;
    
    //Call the helper recursive function
    findSubsets(arr,0,n-1,0,k,ans,{});
    
    sort(ans.begin(),ans.end());
    
    return ans;
}