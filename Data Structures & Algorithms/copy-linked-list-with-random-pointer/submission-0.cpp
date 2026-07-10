/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   private:
    std::unordered_map<Node*, Node*> hash;

    Node* copyNode(Node* node) {
        if (not node) {
            return nullptr;
        }

        auto it = hash.find(node);

        if (it != hash.end()) {
            return it->second;
        }

        Node* copy = new Node(node->val);
        hash.emplace(node, copy);

        copy->next = copyNode(node->next);
        copy->random = copyNode(node->random);

        return copy;
    }

   public:
    Node* copyRandomList(Node* head) {
        return copyNode(head);
    }
};
