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
    vector<int> rightSideView(TreeNode* root) {
        if(not root)
        {
            return {};
        }

        vector<int> result;
        std::vector<TreeNode*> storage;
        storage.push_back(root);

        while(not storage.empty())
        {
            result.push_back(storage.back()->val);

            std::vector<TreeNode*> tmp;
            tmp.reserve(storage.size() * 2);

            for(auto node : storage)
            {
                if(node->left)
                {
                    tmp.push_back(node->left);
                }

                if(node->right)
                {
                    tmp.push_back(node->right);
                }
            }

            std::swap(storage, tmp);
        }

        return result;
    }
};
