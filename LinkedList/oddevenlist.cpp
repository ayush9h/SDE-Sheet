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
        ListNode* odd_dummy = new ListNode(0);
        ListNode* odd_tail = odd_dummy;

        ListNode* even_dummy = new ListNode(0);
        ListNode* even_tail = even_dummy;

        int pos = 1;
        ListNode* curr = head;

        while(curr)
        {
            if(pos%2 == 1)
            {
                odd_tail->next = curr;
                odd_tail = odd_tail->next;
            }
            else{
                even_tail->next = curr;
                even_tail = even_tail->next;
            }
            pos++;
            curr = curr->next;
        }

        odd_tail->next = even_dummy->next;
        even_tail ->next= NULL;
        return odd_dummy ->next;
    }
};
