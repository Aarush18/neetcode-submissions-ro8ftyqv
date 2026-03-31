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
        ListNode* fast = slow->next;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right_start = slow->next;
        slow->next = nullptr;
        
        ListNode* prev = nullptr;

        while(right_start){
            ListNode* cur = right_start->next;
            right_start->next = prev;
            prev = right_start;
            right_start = cur;
        }

        ListNode* tmp = head;

        while(tmp && prev){
            ListNode* tmpNext = tmp->next;
            ListNode* prevNext = prev->next;

            tmp->next = prev;
            prev->next = tmpNext;
            tmp = tmpNext;
            prev = prevNext;
        }

    }
};
