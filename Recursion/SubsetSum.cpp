//Helper function for recursion
void findSubsetSum(vector<int> &num,int left,int right,int sum,vector<int> &ans){
    if(left>right){
        ans.push_back(sum);
        return;
    }
    
    //Consider the current element in my subset sum
    findSubsetSum(num,left+1,right,sum+num[left],ans);
    
    //Do not consider the current element in my subset sum
    findSubsetSum(num,left+1,right,sum,ans);
}

vector<int> subsetSum(vector<int> &num)
{
    //Initialize variables
    int len = num.size();
    vector<int> ans;
    
    //Call the recursive function
    findSubsetSum(num,0,len-1,0,ans);
    
    sort(ans.begin(),ans.end());
    
    return ans;
}