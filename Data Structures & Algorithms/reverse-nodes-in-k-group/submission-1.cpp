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

private:

    ListNode* findKthNode(ListNode* node , int k){
        ListNode* temp = node;

        k--;

        while(temp && k > 0){
            temp = temp -> next;
            k--;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;

        ListNode* temp = head;

        while(temp){
            ListNode* nextNode = temp-> next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        ListNode* prevLast = nullptr;

        while(temp!= nullptr){
            
            auto kthNode = findKthNode(temp , k);
            
            if(!kthNode){
                if(prevLast) prevLast -> next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;

            reverse(temp);

            if(temp == head){
                head = kthNode;
            }else{
                prevLast->next = kthNode;
            }

            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};
