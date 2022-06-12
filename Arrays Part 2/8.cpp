#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
bool canMerge(vector<int>& a,vector<int>& b){
    return a[1] >= b[0];
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    //Declaring the variables
    vector<vector<int>> ans;
    int len = intervals.size(), it = 0;
    
    //Handling corner case
    if(len == 0) return {};
    
    //sorting the intervals based on the starting time and then based on the ending time
    sort(intervals.begin(),intervals.end());
    
    //Inserting the first possible interval in the ans
    ans.push_back(intervals[0]);
    
    //Iterating through the array and merging the intervals
    for(int i=1;i<len;i++){
        if(canMerge(ans[it],intervals[i])){
            //if the current interval merges with the ans interval, 
            //update the ans interval with the maximum of both
            ans[it][0] = min(ans[it][0],intervals[i][0]);
            ans[it][1] = max(ans[it][1],intervals[i][1]);
        }
        else{
            //if the current interval does not merge with the ans
            //interval, add the current interval to the ans 
            ans.push_back(intervals[i]);
            it++;
        }
    }
    
    return ans;
}
