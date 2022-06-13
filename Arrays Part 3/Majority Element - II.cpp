#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    /*Use Moore's Voting algorithm(here we know there will be at max
    two elements whose count will be greater than n/3, so we will
    maintain two different variables to store these elements and
    their counts)*/
    
    //Initialize the vraibles
    int n = arr.size();
    int count1 = 0, count2 = 0, el1 = -1, el2 = -1;
    vector<int> ans;
        
    for(int i=0;i<n;i++){
    //cout<<el1<<" "<<el2<<" "<<count1<<" "<<count2<<endl;
        if(el1 == arr[i]) count1++;
        else if(el2 == arr[i]) count2++;
        else if(count1 == 0){
            el1 = arr[i];
            count1++;
        } 
        else if(count2 == 0){
            el2 = arr[i];
            count2++;
        } 
        else{
            count1--;
            count2--;
        }
    }
    
    //Verify if the possible majority elements obtained in the above
    //loop, are actual majority elements
    count1 = count2 = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == el1) count1++;
        if(arr[i] == el2) count2++;
    }
    
    if(count1 > n/3) ans.push_back(el1);
    if(count2 > n/3) ans.push_back(el2);
    
    return ans;
}