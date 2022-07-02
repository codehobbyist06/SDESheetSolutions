#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    //Initialize the variables
    unordered_map<char,int> maptoIndex;
    int n = s.size(),ans = 0,left = 0, right = 0;
    
    //Maintain two pointers left and right starting at index 0
    for(int i=0;i<n;i++){
        if(maptoIndex.find(s[i]) != maptoIndex.end() and maptoIndex[s[i]]>= left and maptoIndex[s[i]]<=right){
            left = maptoIndex[s[i]]+1;
            right++;
            maptoIndex[s[i]] = left;
        }
        else{
            ans = max(ans,right-left+1);
            right++;
        }
        maptoIndex[s[i]] = i;
    }
    
    return ans;
}