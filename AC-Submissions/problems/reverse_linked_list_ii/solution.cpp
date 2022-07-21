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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        deque<ListNode*> dq;
        ListNode* root = head;
        int check = 0; int cntr = 1;
        while(root){
            if(cntr == left){
                check = 1;
            }
            if(check){
                dq.push_back(root);
            }
            if(cntr == right)check = 0;
            root = root->next; cntr++;
        }
        while(dq.size() > 1){
            swap(dq.front()->val, dq.back()->val);
            dq.pop_front();
            dq.pop_back();
        }
        return head;
    }
};