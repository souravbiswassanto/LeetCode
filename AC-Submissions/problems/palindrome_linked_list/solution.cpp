class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // convert it to a string
        string s;
        while (head != NULL) {
            s += head->val;
            head = head->next;
        }
        // test if a string is palindrome
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
};