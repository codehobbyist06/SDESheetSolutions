#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    //Initialize the variables
    int arr_xor = 0, all_xor = 0, missingXorRepeating = 0;
    int bits = 0, xorb1 = 0, xorb2 = 0, count1 = 0, count2 = 0;
    vector<int> bucket1, bucket2, bucket3, bucket4;
    
    //1. Find the xor of the complete array
    for(int i=0;i<n;i++){
        arr_xor^=arr[i];
    }
    
    //2. Find the xor of all the numbers from 1 to n
    for(int i=1;i<=n;i++){
        all_xor^=i;
    }
    
    //3. Find the xor of above two number.. that will be xor of the missing number and the repeating number
    missingXorRepeating = all_xor ^ arr_xor;
    
    //4. Find any bit in the xor of missing and repeating number that is set to 1
    while((missingXorRepeating & (1 << bits)) == 0){
        bits++;
    }
    
    //5. Now, distribute the arr in two buckets based on if the above bit is set or not
    for(int i=0;i<n;i++){
        if((arr[i] & (1 << bits)) == 0){
            bucket1.push_back(arr[i]);
        }
        else{
            bucket2.push_back(arr[i]);
        }
    }
    
    //6. Distribute the numbers from 1 to N in two sets based on if the bit is set or not 
    for(int i=1;i<=n;i++){
        if((i & (1 << bits)) == 0){
            bucket3.push_back(i);
        }
        else{
            bucket4.push_back(i);
        }
    }
    
    //7. Find the xor of bucket1 and bucket3(number with bit set as 0)
    for(int i=0;i<bucket1.size();i++){
        xorb1^=bucket1[i];
    }
    for(int i=0;i<bucket3.size();i++){
        xorb1^=bucket3[i];
    }
    
    //8. Find the xor of bucket3 and bucket4(number with bit set as 1)
    for(int i=0;i<bucket2.size();i++){
        xorb2^=bucket2[i];
    }
    for(int i=0;i<bucket4.size();i++){
        xorb2^=bucket4[i];
    }
    
    //9. The above two number are the missing and repeating number
    //To check which one is exactly of which type just perform a single iteration and count its occurence
    for(int i=0;i<n;i++){
        if(arr[i] == xorb1) count1++;
        if(arr[i] == xorb2) count2++;
    }

    //10. Return the answer in the desired order(missing, repeating)
    if(count1 == 2){
        return {xorb2,xorb1};
    }
    else{
        return {xorb1,xorb2};
    }
}
