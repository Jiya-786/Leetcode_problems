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

 // ONE-PASS SOLUTION
//  Interview Tip: Always mention the dummy node trick when working with linked list problems. It shows you know how to avoid messy edge cases for head deletion. Many candidates waste time with special-case if statements that a dummy node eliminates entirely.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0,head);
        ListNode* slow= &dummy;
        ListNode* fast= &dummy;

        // move the fast pointer ahead 
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy.next;

    }
};