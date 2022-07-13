#include<bits/stdc++.h>

void buildPermutations(string &s,vector<bool>& visited,vector<string>& ans,string& curr_string){
    if(curr_string.size() == s.size()){
        ans.push_back(curr_string);
        return;
    }
    
    for(int i=0;i<s.size();i++){
        if(visited[i]) continue;
        curr_string+=s[i];
        visited[i] = 1;
        buildPermutations(s,visited,ans,curr_string);
        visited[i] = 0;
        curr_string.pop_back();
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    string curr_string;
    vector<bool> visited(s.size(),0);
    
    buildPermutations(s,visited,ans,curr_string);
    
    sort(ans.begin(),ans.end());
    
    return ans;
}