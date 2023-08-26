//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp(pair<double,Item>a, pair<double,Item>b){
        return a.first > b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,Item>>v;
        for(int i = 0; i<n; i++){
            double pu = (1.0 * arr[i].value)/arr[i].weight;
            pair<double,Item>p = {pu,arr[i]};
            v.push_back(p);
        }
        //sort the items on the basis of their value/wt.
        sort(v.begin(),v.end(),cmp);
        double totalValue = 0;
        for(int i = 0; i<n; i++){//for all the items
            if(v[i].second.weight > W){//if any item's weight have greater than knapsack
                totalValue += W * v[i].first;
                W = 0;//bag fully occupied
            }else{
                totalValue += v[i].second.value;
                W = W - v[i].second.weight;//inserting complet item in the bag
            }
        }
        return totalValue;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends