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
    ListNode* partition(ListNode* head, int x) {
        ListNode *ptr1, *ptr2, *last;
        if(head == NULL)return head;
        function<void(ListNode*)>partitionNode = [&](ListNode* cur){
            if(cur->next == NULL){
                if(cur->val < x){
                    ptr1 = cur;
                    last = cur;
                    ptr1->next = NULL;
                    ptr2 = NULL;
                }
                else {
                    ptr1 = NULL;
                    ptr2 = cur;
                }
                return;
            }
            partitionNode(cur->next);
            if(cur-> val < x) {
                if(ptr1 == NULL)last = cur;
                cur->next = ptr1;
                ptr1 = cur;
            }
            else{
                cur->next = ptr2;
                ptr2 = cur;
            }
            return;
        };
        partitionNode(head);
        if(ptr1 == NULL)return ptr2;
        if(ptr2 == NULL)return ptr1;
        head = ptr1;
        last->next = ptr2;
        /*
        while(1){
            if(ptr1->next == NULL){
                ptr1->next = ptr2; break;
            }
            ptr1 = ptr1->next;
        }*/
        return head;
        
    } 
};