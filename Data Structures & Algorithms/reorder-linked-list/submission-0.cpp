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
        ListNode* ans = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right_start = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;

        while(right_start){
            ListNode* node = right_start->next;
            right_start ->next = prev;
            prev = right_start;
            right_start = node;
        }

        ListNode* curr = head;
        while(curr && prev){
            ListNode* currNxt = curr->next;
            ListNode* fastNxt = prev->next;

            curr->next = prev;
            prev->next = currNxt;
            curr = currNxt;
            prev = fastNxt;
        }
    }
};
