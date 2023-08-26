//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        int mini = 0;
        int buy = 0;//for minimum cost we start from least value
        int freeCandy = N-1;
        while(buy<=freeCandy){
            mini = mini + candies[buy];//cost for the candy.
            buy++;//buy one
            freeCandy = freeCandy-K;//get k free.
        }
        int maxi = 0;
        buy = N-1;//for maximum cost we start from most value
        freeCandy = 0;
        while(freeCandy<=buy){
            maxi = maxi + candies[buy];
            buy--;
            freeCandy = freeCandy + K;
        }
        vector<int>v;
        v.emplace_back(mini);
        v.emplace_back(maxi);
        return v;
    }
};

//{ Driver Code Starts.
zint main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends