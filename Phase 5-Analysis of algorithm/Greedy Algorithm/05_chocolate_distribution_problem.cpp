//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());//sabko minimum me hee nipata diya jaye.
    long long int  i = 0; 
    long long int  j = m-1;//have to distribute m number of students.
    long long int  mini = INT_MAX;
    while(j<n){
        long long int diff = a[j] - a[i];
        mini = min(mini , diff);//calculate and update the minimum.
        i++;
        j++;
    }   
    return mini;
    }
};

//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends