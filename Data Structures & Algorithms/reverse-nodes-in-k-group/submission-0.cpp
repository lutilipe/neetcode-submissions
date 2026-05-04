/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    vector<ListNode*> reverse(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (k--) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        head->next = curr;

        return {curr, prev};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode* newHead = nullptr;
        ListNode* curr = head;

        while (curr) {
            curr = curr->next;
            size++;
        }

        if (k > size) return head;

        curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            if (k > size) break;
            vector<ListNode*> lists = reverse(curr, k);
            if (!newHead) {
                newHead = lists[1];
            }

            if (prev) {
                prev->next = lists[1];
            }

            prev = curr;

            curr = lists[0];
            size-=k;
        }

        return newHead;
    }
};
