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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<TreeNode*> layer;
        vector<vector<int>> result;

        layer.push_back(root);

        while (not layer.empty()) {
            std::vector<TreeNode*> tmp;
            vector<int> levelResult;

            for (TreeNode* node : layer) {
                if(not node)
                {
                    continue;
                }

                levelResult.push_back(node->val);

                tmp.push_back(node->left);
                tmp.push_back(node->right);
            }

            layer = std::move(tmp);
            if(not levelResult.empty())
            {
                result.push_back(std::move(levelResult));
            }
        }

        return result;
    }
};
