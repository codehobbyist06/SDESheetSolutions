#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
    //Initialize variables
   int count0 = 0,count1 = 0,count2 = 0;
    
    //Iterate through the array and count all the 0s, 1s and 2s
    for(int ind=0;ind<n;ind++){
        switch (arr[ind]){
            case 0: count0++;break;
            case 1: count1++;break;
            case 2: count2++;break;
            default: break;
        }
    }
    
    //Rebuilding the sorted array based on the count
    for(int i=0;i<n;i++){
        if(count0 > 0){
            arr[i] = 0;
            count0--;
        }
        else if(count1 > 0){
            arr[i] = 1;
            count1--;
        }
        else{
            arr[i] = 2;
            count2--;
        }
    }
}