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
    bool isBalanced(TreeNode* root) {
        if(not root)
        {
            return true;
        }
        
        stack<TreeNode*> stack;
        unordered_map<TreeNode*, int> depths;
        depths[nullptr] = 0;

        stack.push(root);

        while (not stack.empty()) {
            TreeNode* node = stack.top();
            
            auto left = depths.find(node->left);
            if (left == depths.end())
            {
                stack.push(node->left);
                continue;
            }
            
            auto right = depths.find(node->right);
            if (right == depths.end())
            {
                stack.push(node->right);
                continue;
            }

            stack.pop();

            if(std::abs(left->second - right->second) > 1)
            {
                return false;
            }

            depths[node] = 1 + std::max(left->second, right->second);
        }
        return true;
    }
};