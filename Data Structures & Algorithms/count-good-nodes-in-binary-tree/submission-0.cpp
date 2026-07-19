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
    int goodNodes(TreeNode* root) {
        if(not root)
        {
            return 0;
        }

        int counter = 0;
        std::queue<std::pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while(not q.empty())
        {
            auto [node, maxAncestor] = q.front();
            q.pop();

            if(node->val >= maxAncestor)
            {
                ++counter;
                maxAncestor = node->val;
            }

            if(node->left)
            {
                q.push({node->left, maxAncestor});
            }

            if(node->right)
            {
                q.push({node->right, maxAncestor});
            }
        }

        return counter;
    }
};
