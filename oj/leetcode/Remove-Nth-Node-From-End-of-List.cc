/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *slow = head, *fast = head, *reference = head;
        bool slow_move_flag = false;

        for (int i = 0; i < n; i++) {
            if (reference != NULL) {
                reference = reference->next;
            }
        }

        if(reference != NULL) {
            while(reference != NULL) {
                reference = reference->next;
                fast = fast->next;
                if (slow_move_flag == true) slow = slow->next;
                else slow_move_flag = true;
            }
            slow->next = fast->next;
            free(fast);
            return head;
        } else {
            fast = slow->next;
            free(slow);
            return fast;
        }

    }
};
