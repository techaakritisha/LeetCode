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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        
        while(curr) {
           ListNode* run = curr;
            int sum = 0;
            
            while(run->val){
                sum += run->val;
                run = run->next;
            }
            curr->val = sum;
            curr->next = run->next;
            
            curr = curr->next;
        }
        
        return head->next;
    }
};