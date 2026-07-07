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
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        
        while(true){
            int minvalue=-1;
            for(int i=0;i<lists.size();i++){
                if(!lists[i]) continue;
                if(minvalue==-1||lists[minvalue]->val>lists[i]->val){
                    minvalue=i;
                }
            }

            if(minvalue==-1) break;
            curr->next=lists[minvalue];
            lists[minvalue]=lists[minvalue]->next;
            curr=curr->next;
        }
        ListNode* res=dummy->next;
        delete dummy;
        return res;
    }
};
