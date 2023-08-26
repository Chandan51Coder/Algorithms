//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool cmp(Job a, Job b){
        return a.profit > b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,cmp);//sort the array on the basis of profit
        int maxiDeadline = INT_MIN;
        for(int i = 0; i<n; i++){
            maxiDeadline = max(maxiDeadline,arr[i].dead);
        }
        //a vector with maximum deadline + 1
        vector<int> schedule(maxiDeadline+1,-1);
        int count = 0;
        int maxProfit = 0;
        for(int i = 0; i<n ; i++){//for all jobs
            int cp = arr[i].profit;
            int cpid = arr[i].id;
            int cdead = arr[i].dead;
            for(int k = cdead; k>0; k--){//kya us deadline ya usase pahale niptaya ja sakata hai.
                if(schedule[k] == -1){//if time slot available(usi time pe complete karenge jab need hogi.)
                    count ++;
                    maxProfit += cp;
                    schedule[k] = cpid;//schedule job (at that time no any other job can schedule)
                    break;//for next job.
                }
            }
        }
        vector<int>ans;
        ans.emplace_back(count);
        ans.emplace_back(maxProfit);
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends