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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        if (!head || !head->next) return;
        // Mid element like list become 2 --> 4 and 6--->8
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* curr = second;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        second = prev;
        ListNode* first = head;
        while (second) {
            ListNode* l1 = first->next;
            ListNode* l2 = second->next;
            first->next = second;
            second->next = l1;

            first = l1;
            second = l2;
        }
    }
};
