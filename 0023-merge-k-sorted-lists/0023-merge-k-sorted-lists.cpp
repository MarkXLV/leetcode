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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return devide(lists,0,lists.size()-1);
    }
    ListNode* merge(ListNode* left,ListNode* right)
    {
        if(!left)return right;
        if(!right)return left;
        if(left->val<right->val)
        {
            left->next=merge(left->next,right);
            return left;
        }else
        {
            right->next=merge(left,right->next);
            return right;
        }
    }
    ListNode* devide(vector<ListNode*>& lists,int l,int r)
    {
        if(l>r)return NULL;
        if(l==r)
        return lists[l];

        int mid=(l+r)/2;
        ListNode* left=devide(lists,l,mid);
        ListNode* right=devide(lists,mid+1,r);
        return merge(left,right);
    }
};