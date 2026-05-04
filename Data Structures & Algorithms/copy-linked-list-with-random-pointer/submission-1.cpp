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
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;
        unordered_map<Node*, vector<Node*>> random;
        unordered_map<Node*, Node*> created;

        Node* newHead = new Node(0);
        Node* curr = newHead;

        while (head) {
            curr->next = new Node(head->val);
            curr = curr->next;

            created[head] = curr;

            if (head->random) {
                if (created.find(head->random) != created.end()) {
                    curr->random = created[head->random];
                } else {
                    random[head->random].push_back(curr);
                }
            }

            if (random.find(head) != random.end()) {
                for (auto& node : random[head]) {
                    node->random = curr;
                }
            }
            
            head = head->next;
        }
        return newHead->next;
    }
};
