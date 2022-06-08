#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	//Declaring all the variables
    bool top_row = false, top_col = false, first_el = matrix[0][0];
    int no_of_rows = matrix.size();
    int no_of_cols = matrix[0].size();
    
    //Checking if the first row contains any zero
    for(int col=0;col<no_of_cols;col++){
        if(matrix[0][col] == 0){
            top_row = 1;
            break;
        }
    }
    
    //Checking if the first col contains any zero
    for(int row=0;row<no_of_rows;row++){
        if(matrix[row][0] == 0){
            top_col = 1;
            break;
        }
    }
    
    //Marking the first row and column if any of the other rows or columns contain zero
    for(int row=1;row<no_of_rows;row++){
        for(int col=1;col<no_of_cols;col++){
            if(matrix[row][col] == 0){
                matrix[0][col] = 0;
                matrix[row][0] = 0;
            }
        }
    }
    
    //Iterating through the first row and mark all the elements of that col as 0 if the first element is 0
    for(int col=1;col<no_of_cols;col++){
        if(matrix[0][col] == 0){
            for(int row=1;row<no_of_rows;row++){
                matrix[row][col] = 0;
            }
        }
    }
    
    //Iterating through the first col and mark all the elements of that row as 0 if the first element is 0
    for(int row=0;row<no_of_rows;row++){
        if(matrix[row][0] == 0){
            for(int col=1;col<no_of_cols;col++){
                matrix[row][col] = 0;
            }
        }
    }
    
    //Setting the first row as 0 if top_row flag is 1 or matrix[0][0] is 0
    if(top_row or first_el == 0){
        for(int col=0;col<no_of_cols;col++){
            matrix[0][col] = 0;
        }    
    }
    
    //Setting the first col as 0 is top_col flag is 1 or matrix[0][0] is 0
    if(top_col or first_el == 0){
        for(int row=0;row<no_of_rows;row++){
            matrix[row][0] = 0;
        }    
    }
}