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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* p = head;
        while(p){
            s.push(p);
            p = p->next;
        }
        
        int size = s.size();
        
        ListNode* newHead = head;
        // push stack nodes alternate
        
        for(int i=0; i<size/2; i++){
            ListNode* node = s.top();
            s.pop();
            
            node->next = newHead->next;
            newHead->next = node;
            newHead = newHead->next->next;
        }
        newHead->next = NULL;
    }
};