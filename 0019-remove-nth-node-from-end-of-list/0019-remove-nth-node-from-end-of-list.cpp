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
        ListNode* temp=new ListNode(-1);
        temp->next=head;
        ListNode* second=temp;
        ListNode* first=temp;
        for(int i=0;i<=n;i++)
        {
            if(second)
            second=second->next;
        }

        while(second)
        {
            second=second->next;
            first=first->next;
        }

        first->next=first->next->next;
        return temp->next;
    }
};