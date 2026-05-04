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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        int carrie = 0;
        ListNode* curr = head;

        while (l1 && l2) {
            curr->next  = new ListNode();
            curr = curr->next;

            int sum = l1->val + l2->val + carrie;
            carrie = sum >= 10;
            sum = sum%10;
            curr->val = sum;

            l1=l1->next;
            l2=l2->next;
        }

        ListNode* remaining = l1 ? l1 : l2;

        while (remaining) {
            curr->next  = new ListNode();
            curr = curr->next;

            int sum = remaining->val + carrie;
            carrie = sum >= 10;
            sum = sum%10;
            curr->val = sum;

            remaining=remaining->next;
        }

        if (carrie) {
            curr->next = new ListNode(1);
        }

        return head->next;
    }
};
