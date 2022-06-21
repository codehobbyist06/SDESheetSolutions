#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    //Initialize the variables
    map<int,int> count;
    int ans = 1;

    if(N == 0)
        return 0;
    
    //Iterate through the array and keep of count of all the values in the map
    for(int i=0;i<n;i++){
       count[arr[i]]++; 
    }
    
    //Iterate through the array and find the element for which the 
//     previous consecutive element does not exist. Now this can be the
//         starting point of the consecutive elements subsequence
    for(int i=0;i<n;i++){
        int val = arr[i];
        if(count.find(val-1) == count.end()){
            while(count.find(val) != count.end()){
                val++;
            }
            ans = max(val-arr[i],ans);
        }
    }
    
    return ans;
}