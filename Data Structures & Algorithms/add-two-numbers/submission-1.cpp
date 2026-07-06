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
        vector<ListNode*> sum;
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
            sum.push_back(node);
        }

        if(extra){
            ListNode* node= new ListNode(1);
            sum.push_back(node);
        }
        int n=sum.size();
        for(int i=0;i<n-1;i++){
            sum[i]->next=sum[i+1];
        }
        return sum[0];
    }
};
