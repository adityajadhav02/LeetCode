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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevToA = list1;
        ListNode* afterB = list1;
        
        while(a>1){
            prevToA = prevToA->next;
            a--;
        }
        while(b>=0){
            afterB = afterB->next;
            b--;
        }
        
        ListNode* tail2 = list2;
        while(tail2->next){
            tail2 = tail2->next;
        }
        
        prevToA->next = list2;
        tail2->next = afterB;
        
        return list1;
    }
};