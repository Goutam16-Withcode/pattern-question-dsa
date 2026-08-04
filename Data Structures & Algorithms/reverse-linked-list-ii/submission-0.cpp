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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode dummy(0, head);
        ListNode* before = &dummy;
        for (int i = 1; i < left; i++) {
            before = before->next;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = before->next;
        ListNode* tail = curr;
        for (int i = left; i <= right; i++) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        before->next = prev;
        tail->next = curr;
        return dummy.next;
    }
};