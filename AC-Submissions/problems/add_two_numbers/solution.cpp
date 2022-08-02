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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode* temp = dummy; int carry  = 0;
        while(l1 != NULL or l2 != NULL){
            int firstnum = 0;
            int secondnum = 0;
            if(l1 != NULL) firstnum = l1->val, l1 = l1-> next;
            if(l2 != NULL) secondnum = l2->val, l2 = l2 -> next;
            int totalsum = firstnum + secondnum + carry;
            if(totalsum > 9) carry = 1;
            else carry = 0;
            ListNode *newNode = new ListNode(totalsum % 10);
            temp-> next = newNode;
            temp = newNode;
        }
        if(carry != 0) {
            ListNode *newNode = new ListNode(1);
            temp-> next = newNode;
            temp = newNode;
        }
        return dummy->next;
    }
};