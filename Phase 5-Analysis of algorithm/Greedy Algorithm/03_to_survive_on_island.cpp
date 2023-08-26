//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minimumDays(int S, int N, int M){
        // code here
        int sunday = S/7;//total number of sunday
        int buyDay = S-sunday;//total number of day on which we can buy
        int totalfood = S*M;//total amount of food required to survive
        int ans = 0;
        if(totalfood % N == 0){//if we have exactly food that required
            ans =  totalfood/N;//return 
        }else{
            ans =  totalfood/N + 1;
        }
        if(ans<= buyDay){//if number of actual buy days less that constraint buy day
            return ans;
        }else{
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}
// } Driver Code Ends