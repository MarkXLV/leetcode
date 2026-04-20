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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return head;
        ListNode* tail=head;
        ListNode* currhead=head;
        for(int i=0;i<k-1;i++)
        {
            if(currhead)
            {
                currhead=currhead->next;
            }
        }
        if(currhead)
        {
            ListNode* newhead=currhead->next;
            currhead->next=NULL;
            ListNode* res=reverse(tail);
            tail->next=reverseKGroup(newhead,k);
            return res;
        }else
        {
            return head;
        }
    }

    ListNode* reverse(ListNode* head)
    {
        if(!head)return head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        return prev;
    }
};