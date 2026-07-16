class Solution {
public:
    bool isBalanced(TreeNode* root) {
        stack<TreeNode*> st;
        stack<int> depths;
        
        TreeNode* node = root;
        TreeNode* last = nullptr;

        while (!st.empty() || node != nullptr) {
            if (node != nullptr) {
                st.push(node);
                node = node->left;
                continue;
            }

            TreeNode* topNode = st.top();

            if (topNode->right == nullptr || last == topNode->right) {
                st.pop();

                int right = 0;
                if (topNode->right != nullptr) {
                    right = depths.top();
                    depths.pop();
                }

                int left = 0;
                if (topNode->left != nullptr) {
                    left = depths.top();
                    depths.pop();
                }

                if (std::abs(left - right) > 1) return false;

                depths.push(1 + std::max(left, right));

                last = topNode;
                node = nullptr; 
                continue;
            }

            node = topNode->right;
        }
        return true;
    }
};
