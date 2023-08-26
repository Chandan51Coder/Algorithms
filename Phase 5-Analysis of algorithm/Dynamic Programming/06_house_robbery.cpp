#include <bits/stdc++.h> 
//optimizing space (using the concept of the minimum element )
long long int solveSO(vector<long long int>&nums){
    //removing dp vector by analyzing dependies of dp[i]
    int n = nums.size();
    long long int p2 = 0;
    long long int  p1 = nums[0];
    
    //recursive call
    for(int i = 1; i<n; i++){
        long long int inc = nums[i]+ p2;
        long long int exc = 0+p1;
        long long int ans = max(inc,exc);
        p2= p1;
        p1= ans;
    }
    return p1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if(n==1){
        return valueInHouse[0];
    }
    vector<long long int>first;
    vector<long long int>second;
    for(int i = 0; i<n; i++){
        if(i != n-1){
            first.push_back(valueInHouse[i]);
        }
        if(i != 0){
            second.push_back(valueInHouse[i]);
        }
    }
    return max(solveSO(first),solveSO(second));
}