/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         unordered_set<ListNode*> seen;

//         ListNode* current = head;
//         while (current != nullptr) {
//             // If we've seen this node before, it's the cycle start
//             if (seen.count(current)) {
//                 return current;
//             }
//             seen.insert(current);
//             current = current->next;
//         }

//         // No cycle found
//         return nullptr;
//     }
// };

// most optimal solution- FLOYD'S ALGORITHM
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;

            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
