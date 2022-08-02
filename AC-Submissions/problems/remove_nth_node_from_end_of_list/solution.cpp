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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode (-1); dummy->next = head;
        function<int(ListNode*, ListNode*)> recursion = [&] (ListNode* prev, ListNode* cur){
            if(cur == NULL) return 0;
            int cntr = recursion(cur, cur -> next) + 1;
            if(cntr == n){
                prev->next = cur->next;
            }
            return cntr;
        };
        int ans = recursion(dummy, head);
        if(dummy->next == NULL) return NULL;
        return dummy->next;
    }
};