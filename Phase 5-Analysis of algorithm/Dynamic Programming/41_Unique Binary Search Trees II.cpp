/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<pair<int,int>,vector<TreeNode*>>mp;
    vector<TreeNode*>solve(int start, int end){
        if(start>end){
            return {NULL};//all number traversed
        }
        if(start == end){//single number
            TreeNode*root = new TreeNode(start);
            return mp[{start,end}]={root};
        }
        if(mp.find({start,end}) != mp.end()){
            return mp[{start,end}];
        }
        //crating root to each number
        vector<TreeNode*>result;
        for(int i = start; i<=end; i++){
            vector<TreeNode*> leftBsts= solve(start,i-1);
            vector<TreeNode*> rightBsts= solve(i+1, end);
            //mapping left root right
            for(TreeNode *Lbst: leftBsts){
                for(TreeNode *Rbst: rightBsts){
                    TreeNode* root = new TreeNode(i);
                    root->left = Lbst;
                    root->right = Rbst;
                    result.push_back(root);
                }
            }
        }
        return mp[{start,end}]=result;
    }
    vector<TreeNode*> generateTrees(int n) {
        //node can contains data between 1 to n
        return solve(1,n);
    }
};