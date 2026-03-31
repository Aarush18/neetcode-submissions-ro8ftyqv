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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        int cnt = 0 ; 

        while(temp != nullptr){
            cnt++;
            temp = temp->next;
        }

        temp = head;

        int reversals = cnt / k ;

        int i = 0 ; 
        int cnt_nodes = 0 ;

        ListNode* newhead = nullptr;
        ListNode* lasttail = nullptr;

        while(reversals > 0){
            int i = 0;

            ListNode* grouphead = temp;

            while( i < k ){
                ListNode* node = temp -> next;
                temp->next = prev;
                prev = temp;
                temp = node;
                i++; 
            }   
            if(newhead == nullptr) {
                newhead = prev ; 
            }
            if(lasttail != nullptr){
                lasttail->next = prev;
            }
            lasttail = grouphead;
            reversals--;
        }

        lasttail->next = temp;
        return newhead;
    }
};
