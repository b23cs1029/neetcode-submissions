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
        // if(head==nullptr){
        //     return nullptr;
        // }
        // if(head->next == nullptr ||(head->next)->next==nullptr){
        //     return head;
        // }
        // ListNode* dummy =new LIstNode(0);
        // ListNode* pre=head;
        // ListNode* curr=head->next;
        // ListNode* temp=curr->next;
        // ListNode* res;
        // int c=1;
        // while(true){
        //     if(c==k){
        //         curr->next=nullptr;
        //         dummy->next=pre;
        //         pre=curr;
        //         curr=temp;
        //         temp=curr->next;


        //     }
        //     else if(temp==nullptr){
        //         curr->next=pre;
        //         pre=curr;
        //         curr=temp;
        //         head->next=pre;
        //         break;
        //     }
        //     else{
        //         curr->next=pre;
        //         pre=curr;
        //         curr=temp;
        //         temp=curr->next;
        //         c++;
        //     }
        // }
        // return res;
        int counter=0;
        ListNode* curr=head;
        while(curr!=nullptr&&counter<k){
            counter++;
            curr=curr->next;
        }
        
        if(counter==k){
            curr=reverseKGroup(curr,k);
            while(counter>0){
                ListNode* tmp=head->next;
                head->next=curr;
                curr=head;
                head=tmp;
                counter--;
            }
            head=curr;
        }
        return head;
        


    }
};
