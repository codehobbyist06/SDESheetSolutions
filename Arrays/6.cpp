#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    //Declaring the variables
    int minima = INT_MAX,maxima = INT_MIN, ans = 0;
    int n = prices.size();
    
    //Iterating through the array and making the minima and maxima
    //same if prices[i] is less than minima and updating the maxima
    //if the current price is greater than maxima
    for(int i=0;i<n;i++){
        if(prices[i] < minima){
            minima = prices[i];
            maxima = prices[i];
        }
        else if(prices[i] > maxima){
            maxima = prices[i];
            ans = max(ans,maxima-minima);
        }
    }
    
    return ans;
}