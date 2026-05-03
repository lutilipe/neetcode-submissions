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
    ListNode* reverse(ListNode* head) {
        ListNode* curr= head;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head) return;
        int size = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            size++;
        }
        int mid = (size+1) / 2;
        ListNode* prev = nullptr;
        ListNode* l2 = head;
        while (mid--) {
            prev = l2;
            l2 = l2->next;
        }
        prev->next = nullptr;
        l2 = reverse(l2);

        ListNode* l1 = head;

        while (l1 && l2) {
            ListNode* t1 = l1->next;
            ListNode* t2 = l2->next;

            l1->next = l2;
            l2->next = t1;

            l2 = t2;
            l1= t1;
        }
    }
};
