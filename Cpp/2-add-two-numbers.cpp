/**
 * Runtime: 55 ms, faster than 62.91% of C++ online submissions for Add Two Numbers.
 * Memory Usage: 70.8 MB, less than 97.67% of C++ online submissions for Add Two Numbers.
*/

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
private:
    void calculateLeading(ListNode* l1, int* leading) {
        *leading = l1 -> val / 10;
        l1->val = l1 -> val % 10;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int* leading = new int;
        *leading = 0;
        ListNode* first = l1;
        ListNode* previous;
        while (l1 != NULL && l2 != NULL) {
            l1->val = l1->val + l2->val + *leading;
            
            calculateLeading(l1, leading);
            previous = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        if (l1 == NULL) {
            previous -> next = l2;
            l1 = l2;
        }
        
        while(l1 != NULL) {
            l1->val = l1->val + *leading;
            
            calculateLeading(l1, leading);
            previous = l1;
            l1 = l1->next;
        }
        
        if (*leading == 1) {
            previous -> next = new ListNode();
            previous -> next -> val = 1;
        }
        
        return first;
    }
};
