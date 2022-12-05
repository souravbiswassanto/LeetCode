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
    ListNode* middleNode(ListNode* head) {
        ListNode *firstPointer = head, *secondPointer = head;
        int cntr = 0;
        while(secondPointer != NULL) {
            if(cntr % 2)firstPointer = firstPointer->next;
            secondPointer = secondPointer -> next;
            cntr++;
        }
        return firstPointer;
    }
};