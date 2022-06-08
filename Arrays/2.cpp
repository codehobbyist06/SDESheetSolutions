#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>> triangle;
    
    //Inserting the top row
    triangle.push_back({1});
    
    //Building other levels of the triangle based on the top row
    for(int level=1;level<n;level++){
        vector<long long int> elements;
        for(int el=0;el<=level;el++){
            if(el == 0){
                elements.push_back(triangle[level-1][0]);
            }
            else if(el == level){
                elements.push_back(triangle[level-1][level-1]);
            }
            else{
                elements.push_back(triangle[level-1][el-1] + triangle[level-1][el]);
            }
         }
         triangle.push_back(elements);
    }
    return triangle;
}
