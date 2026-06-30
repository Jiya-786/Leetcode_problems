// Last updated: 30/06/2026, 19:34:13
// Most optimal- FLOYD'S ALGORITHM on time and o1 space
bool isPalindrome(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }
    return false;
}

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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        vector<int> path1;
        
        while(temp){
            path1.push_back(temp->val);
            temp=temp->next;
        }

        int n=path1.size();
        vector<int> path2;
        for(int i=n-1;i>=0;i--){
            path2.push_back(path1[i]);
        }

        return path1==path2;
        // bool palindrome=true;
        // int n=elts.size();
        // if(count%2==0){
        //     if(elts[])
        // }
    }
};