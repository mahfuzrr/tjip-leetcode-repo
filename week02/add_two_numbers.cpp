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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = NULL;
        int sum = 0;
        int carry = 0;
        ListNode *newNode = NULL;
        ListNode *last = NULL;
        
        while(l1 || l2)
        {
            sum = carry + (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0);
            carry = sum >= 10 ? 1 : 0;
            sum %= 10;
            newNode = new ListNode(sum);
            if(res == NULL) res = newNode;
            else last -> next = newNode;
            
            last = newNode;
            
            if(l1) l1 = l1 -> next;
            if(l2) l2 = l2 -> next;
        }
        if(carry) last -> next = new ListNode(carry);
        return res;
    }
};
