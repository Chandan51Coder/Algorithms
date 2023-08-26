/******** 01 Medium*/
//it's not a greedy approach.it check all combination of items 
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> &values, vector<int> &weights, int index, int capacity){
	if(index == 0){
		if(weights[0]<= capacity){
			return values[0];
		}
		else{
			return 0;
		}
	}
	int include = 0;
	if(weights[index]<= capacity){
		include = values[index] + solve(values,weights,index-1,capacity-weights[index]);
	}
	int exclude = 0 + solve(values,weights,index-1,capacity);
	int ans = max(exclude,include);
	return ans;

}
//adding memoization
int solveMem(vector<int> &values, vector<int> &weights, int index, int capacity,
vector<vector<int>>&dp){
	if(index == 0){
		if(weights[0]<= capacity){
			return values[0];
		}
		else{
			return 0;
		}
	}
	if(dp[index][capacity] != -1){
		return dp[index][capacity];
	}
	int include = 0;
	if(weights[index]<= capacity){
		include = values[index] + solveMem(values,weights,index-1,capacity-weights[index],dp);
	}
	int exclude = 0 + solveMem(values,weights,index-1,capacity,dp);
	int ans = max(exclude,include);
	dp[index][capacity] = ans;
	return dp[index][capacity];
}
// using the tabulation method
int solveTab(vector<int> &values, vector<int> &weights, int n, int capacity){
	
	vector<vector<int>>dp(n,vector<int>(capacity+1,0));
	for (int w = weights[0]; w<= capacity; w++){
		if(weights[0]<=capacity){
			dp[0][w] = values[0];
		}else{
			dp[0][w] = 0;
		}
	}
	for(int index = 1; index <n; index++){
		for(int w= 0; w<= capacity; w++){
			int include = 0;
			if(weights[index]<= w){
				include = values[index] + dp[index-1][w-weights[index]];
			}
			int exclude = 0 + dp[index-1][w];
			dp[index][w] = max(exclude,include);
		}
	}
	
	return dp[n-1][capacity];
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here

	// return solve(values,weights,n-1,w);
	// vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
	// return solveMem(values,weights,n-1,w,dp);
	return solveTab(values,weights,n-1,w);
}

/***Easy*/
#include <bits/stdc++.h> 
using namespace std;
int solveTab(vector<int> &values, vector<int> &weights, int n, int capacity){
	vector<vector<int>>dp(n,vector<int>(capacity+1,0));
	for (int w = weights[0]; w<= capacity; w++){//esase vo object remove ho gaye jinaki capacity knapsack se jyada hai.
		if(weights[0]<=capacity){
			dp[0][w] = values[0];
		}else{
			dp[0][w] = 0;
		}
	}
	for(int index = 1; index <n; index++){
		for(int w= 0; w<= capacity; w++){
			int include = 0;
			if(weights[index]<= w){
				include = values[index] + dp[index-1][w-weights[index]];
			}
			int exclude = 0 + dp[index-1][w];
			dp[index][w] = max(exclude,include);
		}
	}
	
	return dp[n-1][capacity];
}
//optimizing space
int solveSO(vector<int> &values, vector<int> &weights, int n, int capacity){
	vector<int>prev(capacity+1,0);
	vector<int>curr(capacity+1,0);
	for (int w = weights[0]; w<= capacity; w++){
		if(weights[0]<=capacity){
			prev[w] = values[0];
		}else{
			prev[w] = 0;
		}
	}
	for(int index = 1; index <n; index++){
		for(int w= 0; w<= capacity; w++){
			int include = 0;
			if(weights[index]<= w){
				include = values[index] + prev[w-weights[index]];
			}
			int exclude = 0 + prev[w];
			curr[w] = max(exclude,include);
		}
		prev = curr;
	}
	
	return prev[capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
	return solveSO(value,weight,n,maxWeight);
}