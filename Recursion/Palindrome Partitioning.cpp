#include<bits/stdc++.h>

bool check_palindrome(string s){
    int len = s.size();
    
    for(int i=0;i<len/2;i++){
        if(s[i] != s[len-i-1]){
            return 0;
        }
    }
    
    return 1;
}

void findPartitions(string &s,int left,int right, vector<vector<string>>& ans,vector<int>& partitions){
    //Handle the base case
    if(left > right){
       //Initialize the variables
        int part_len = partitions.size();
        int prev_ind = 0;
        vector<string> parts;
        
       //If partitions exist
        if(part_len > 0){
            //Build the partition strings based on the partition indexes
            for(int i=0;i<part_len;i++){
                string temp = s.substr(prev_ind,partitions[i]-prev_ind);
                parts.push_back(temp);
                prev_ind = partitions[i];
            }
            //Insert the last remaining part of the string
            parts.push_back(s.substr(prev_ind,s.size()-prev_ind));
            
            //Insert the partition in the answer array only if all the substrings in the partition are palindromes
            for(int i=0;i<parts.size();i++){
                if(!check_palindrome(parts[i]))
                    return;
            }
            ans.push_back(parts);
        }
       //If no partitions check the whole string
        else{
            if(s.size() > 0 and check_palindrome(s)){
                parts.push_back(s);
                ans.push_back(parts);
            }
        }
        return;
    }
    
    //Call recursive function not considering the current partition
    findPartitions(s,left+1,right,ans,partitions);
    partitions.push_back(left);
       
    //Call the recursive function considering the current partition
    findPartitions(s,left+1,right,ans,partitions);
    partitions.pop_back();
}

vector<vector<string>> partition(string &s) 
{
    //Initialize the variables
    vector<vector<string>> ans;
    vector<int> partitions;
    
    //Call the recursive function
    findPartitions(s,1,s.size()-1,ans,partitions);
    
    //Sort the ans based on the output format requirements
    sort(ans.begin(),ans.end());
    
    //Insert an empty subset in case of empty string since empty string is also a palindrome
    if(ans.size() == 0) ans.push_back({});
    return ans;
}