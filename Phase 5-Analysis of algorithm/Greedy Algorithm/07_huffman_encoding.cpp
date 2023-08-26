//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
    public:
        int data;
        Node *left;
        Node *right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
class cmp{
    public:
        bool operator()(Node *a, Node *b){
            return a->data > b->data;
        }
};
void traverse(Node*root, vector<string>&ans, string temp){
    if(root->left == NULL && root->right == NULL){
        ans.emplace_back(temp);
        return;
    }
    traverse(root->left,ans,temp+'0');
    traverse(root->right,ans,temp+'1');
}
class Solution
{
	public:
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    priority_queue<Node*, vector<Node*>, cmp>pq;
			//pushing element in priority queue on the increasing order of their frequency.
		    for(int i=0; i<N; i++){
		        Node *temp = new Node(f[i]);
		        pq.push(temp);
		    }
		    while(pq.size()>1){
		        Node *left = pq.top();//first min
		        pq.pop();
		        Node *right = pq.top();//second min
		        pq.pop();
		        Node *newNode = new Node(left->data + right -> data);//create new node using first and second minimum
		        newNode -> left = left;
		        newNode -> right = right;
		        pq.push(newNode);//push new node into priority queue.
		    }
		Node*root = pq.top();//for finding the code of string
		vector<string>ans;//store the code of string
		string temp = "";
		traverse(root,ans,temp);
		return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends