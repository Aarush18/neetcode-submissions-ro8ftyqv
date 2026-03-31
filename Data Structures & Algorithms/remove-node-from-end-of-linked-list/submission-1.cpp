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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);

        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        while(n){
            fast = fast -> next;
            n --;
        }  

        ListNode* prev = nullptr;

        while(fast != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        prev -> next = slow ->next;
        slow->next = nullptr;

        return dummy.next;

    }
};
