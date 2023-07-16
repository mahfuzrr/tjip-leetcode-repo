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
    ListNode* reverseList(ListNode* head) {
        ListNode* prv = NULL;
        ListNode* curr = head;
        if (curr == NULL) return head;
        ListNode* nxt = curr->next;
        while(curr)
        {
            curr->next = prv; /// [0 <- 1 2]
            prv = curr;
            curr = nxt;
            nxt = curr ? curr->next : NULL;
        }
        return prv;
    }
    int pairSum(ListNode* head) {
        int maxPairSum = 0;
        auto slow = head, fast = head;
        while (fast != nullptr && fast -> next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverseList(slow);
        while (slow != nullptr) {
            maxPairSum = max(maxPairSum, slow->val + head->val);
            slow = slow->next;
            head = head->next;
        }
        return maxPairSum;
    }
};
