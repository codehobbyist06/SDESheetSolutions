#include <bits/stdc++.h>

//Moore Voting Algorithm(works only if we are sure that majority element exists)
int findMajorityElement(int arr[], int n) {
    int count = 0,el = 0;

    for(int i=0;i<n;i++){
        if(count == 0) el = arr[i];

        if(el == arr[i]) count++;
        else count--;
    }

    return el;
}


//alternative approach - returns -1 if there is no majority element
int findMajorityElement(int arr[], int n) {
    unordered_map<int,int> mp;
    
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    
    for(auto x:mp){
        if(x.second > n/2) return x.first;
    }
    
    return -1;
}