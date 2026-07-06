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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int extra=0;
        ListNode* sum=new ListNode();
        ListNode* curr=sum;
        int value=0;
        while(l1!=nullptr || l2!=nullptr){
            if(l1==nullptr){
                value=0+l2->val+extra;
                l2=l2->next;
            }
            else if(l2==nullptr){
                value=l1->val+0+extra;
                l1=l1->next;
            }
            else{
                value=l1->val+l2->val+extra;
                l1=l1->next;
                l2=l2->next;
            }            
            extra=value/10;
            value%=10;
            
            ListNode* node= new ListNode(value);
            curr->next=node;
            curr=curr->next;
        }

        if(extra){
            ListNode* node= new ListNode(1);
            curr->next=node;
            curr=curr->next;
        }
        curr->next=nullptr;
        ListNode* res = sum->next;
        delete sum;
        return res;

        
        
    }
};
