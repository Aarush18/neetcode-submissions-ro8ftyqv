class Solution {
private:
    ListNode* merge2lists(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a && b) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = (a ? a : b);
        return dummy.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        ListNode* head = lists[0];
        for (int i = 1; i < (int)lists.size(); i++) {
            head = merge2lists(head, lists[i]);
        }
        return head;
    }
};
