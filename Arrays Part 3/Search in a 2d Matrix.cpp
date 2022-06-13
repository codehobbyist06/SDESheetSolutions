#include <bits/stdc++.h> 

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    //Initialize the variables
    int left = 0, right = m*n-1, mid = 0;
    
    //Map the row/col to linear co-ordinates(0 to m*n-1) and apply binary search
    while(left <= right){
        mid = left + (right-left)/2;
        
        int row = mid/n;
        int col = mid%n;
        if(mat[row][col] == target){
            return 1;
        }
        else if(mat[row][col] < target){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return 0;
}