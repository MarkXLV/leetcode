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
    // ListNode* fun(ListNode* head1,ListNode* head2)
    // {
    //     if(!head1)return head2;
    //     if(!head2)return head1;
    //     head1->next=fun(head2,head1->next);
    //     return head1;
    // }
    void reorderList(ListNode* head) {
        if(!head or !head->next)return;
        ListNode* slow=head;
        ListNode* sloww=head;
        ListNode* fast=head;
        while(fast && fast->next)
        {
            sloww=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        sloww->next=NULL;
        ListNode* curr=slow;
        ListNode* prev=NULL;
        ListNode* forward=slow;
        while(curr)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        ListNode* head1=head;
        ListNode* head2=prev;
        // head1->next=fun(head2,head1->next);
        while(head1 && head2)
        {
            ListNode* head11=head1->next;
            ListNode* head22=head2->next;
            if(head2)
            head1->next=head2;
            if(head11)
            head2->next=head11;
            head1=head11;
            head2=head22;
        }
        //   1 2 
        //   5 4 3
        //   1-5-2
        //   4 3

        //   1-5-2-4-null
        //   3
    }
};