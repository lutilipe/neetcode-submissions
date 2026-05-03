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
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

    // 1. Find size
    int listSize = 0;
    ListNode* curr = head;
    while (curr) {
        curr = curr->next;
        listSize++;
    }

    int m = (listSize + 1) / 2;
    ListNode* l2 = head;
    ListNode* prevMid = nullptr;

    while (m--) {
        prevMid = l2;
        l2 = l2->next;
    }
    prevMid->next = nullptr;

    l2 = reverseLinkedList(l2);

    ListNode* l1 = head;
    while (l1 && l2) {
        ListNode* t1 = l1->next;
        ListNode* t2 = l2->next;

        l1->next = l2;
        l2->next = t1;

        l1 = t1;
        l2 = t2;
    }
    }
};
