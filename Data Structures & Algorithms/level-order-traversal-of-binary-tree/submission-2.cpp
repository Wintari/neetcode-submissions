#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> q;
        
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Фиксируем размер текущего уровня
            std::vector<int> levelResult;
            levelResult.reserve(levelSize); // Оптимизация памяти

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                levelResult.push_back(node->val);

                // Добавляем детей в очередь «на ходу»
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(std::move(levelResult));
        }

        return result;
    }
};
