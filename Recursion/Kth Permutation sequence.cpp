int find_fact(int n){
    if(n == 0) return 1;
    
    return n*find_fact(n-1);
}

void buildPermutation(vector<int> options,int k,int n,vector<int>& ans){
    //Handle the base case
    if(n == 1){
        ans.push_back(options[0]);
        return;
    }
    
    //Calculate the required index from options array
    int tot_permutations = find_fact(n);
    int section_size = tot_permutations/n;
    int section_num = k/section_size;
    
    //Push the ans
    ans.push_back(options[section_num]);
    vector<int> rem_options;
    
    //Rebuild the options array with the remaining options
    for(int i=0;i<options.size();i++){
        if(options[i] != options[section_num])
            rem_options.push_back(options[i]);
    }
    
    //Modify k and n for the remaining options
    k = k%section_size;
    n-=1;
    
    //Recursively call build permutations to build the remaining part of the array
    buildPermutation(rem_options,k,n,ans);
}

string kthPermutation(int n, int k) {
    //Initialize the variables
    vector<int> options;
    vector<int> ans;
    string str_ans;
    
    //Building the options array
    for(int i=0;i<n;i++){
        options.push_back(i+1);
    }
    
    //Call the recursive function
    buildPermutation(options,k-1,n,ans);
    
    //Convert the ans to string to match the requested output format
    for(int i=0;i<ans.size();i++){
        str_ans+=to_string(ans[i]);    
    }
    
    return str_ans;
}