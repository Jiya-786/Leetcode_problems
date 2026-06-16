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

 // using the dummy node in place of head
 // otherwise, it is like head -> 1 -> 2 -> 3 -> 4 -> 5
 // dummy replaces head with a node that has value 0 and points to the same thing as the head
 // now: dummy -> 1 -> 2 -> 3 -> 4 -> 5
 //               ^
 //               head
 // now it is easy to remove first node ie 1 and return pointer(dummy) again
 // dummy trick is one of the most used in LL qs
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0,head);

        int length=0;
        ListNode* current=head;
        while(current!=NULL){
            length++;
            current=current->next;
        }

        ListNode* prev= &dummy;
// so now it will look like prev -> dummy -> 1 -> 2 -> 3 -> 4 -> 5
//                                           ^
//                                           head
// this setup allows us to delete head ie 1 the same way we would delete other nodes
        for(int i=0;i<length-n;i++){    // becuase we want prev to stop before the node we want to delete
            prev=prev->next;
        }
        ListNode* toDelete=prev->next;
        prev->next=prev->next->next;
        delete toDelete;

        return dummy.next;
    }
};
