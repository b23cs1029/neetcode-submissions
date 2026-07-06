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
        ListNode* curr=head;
        int m=0;
        while(curr){
            curr=curr->next;
            m++;
        }
        // we travel from front 
        int k=0;
        

        if(m==n){
            ListNode* tmp=head;
            head=head->next;
            delete tmp;
            return head;
        }

        k=m-n-1;

        ListNode* tmp=head;
        while(k){
            tmp=tmp->next;
            k--;
        }
        curr=tmp->next;
        tmp->next=curr->next;
        delete curr;
        return head;

    }
};
