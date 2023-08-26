//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static bool comp(pair<int,int>a, pair<int,int>b){
        return a.second<b.second;//sorting the meeting on basis of the end time.
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>v;
        //pusing the element in the vector
        for(int i = 0; i<n; i++){
            pair<int,int>p = {start[i],end[i]};
            v.emplace_back(p);
        }
        //sort the vector on  the basis of their end time.
        sort(v.begin(),v.end(),comp);
        int count = 1; 
        int ansEnd = v[0].second;
        for(int i = 1; i<n; i++){//for all the meeting 
            if(v[i].first>ansEnd){//if another meeting start time is greater than first meeting endtime
                count++;
                ansEnd = v[i].second;//complete the another meeting 
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends