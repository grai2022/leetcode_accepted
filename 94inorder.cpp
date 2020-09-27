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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        traverse(root,output);
        
        return output;
    }
    
    void traverse(TreeNode* root, vector<int>& output){
        if(root == NULL){
            return;
        }
        traverse(root -> left, output);
        output.push_back(root->val);
        traverse(root ->right, output);
    }
};
