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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL or head->next == NULL or head->next->next == NULL) return head;
        ListNode *odd = head, *even = head->next, *firsteven = even, *firstodd = head;
        int cntr = 0;
        head = head->next->next;
        while(head != NULL) {
            cntr++;
            if (cntr % 2) {
                odd->next = head;
                odd = odd->next;
            }
            if (cntr % 2 == 0) {
                even->next = head;
                even = even->next;
            }
            head = head->next;
        }
        even->next = NULL;
        odd->next = firsteven;
        return firstodd;
    }
};