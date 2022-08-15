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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int> (n, -1));
        
        int len = 0;
        ListNode* temp = head;
        while(!temp){
            temp = temp->next;
            len++;
        }
        
        int rowSt = 0, rowEnd=m-1, colSt=0, colEnd=n-1;
        
        temp = head;
        
        while(temp){
            // fill top row
            for(int i=colSt; i<=colEnd; i++){
                if(temp){
                    ans[rowSt][i] = temp->val;
                    temp = temp->next;
                }
            }
            rowSt++;
            
            // fill last col
            for(int i=rowSt; i<=rowEnd; i++){
                if(temp){    
                    ans[i][colEnd] = temp->val;
                    temp = temp->next;
                }
            }
            colEnd--;
            
            // fill last row
            for(int i=colEnd; i>=colSt; i--){
                if(temp){    
                    ans[rowEnd][i] = temp->val;
                    temp = temp->next;
                }
            }
            rowEnd--;
            
            // fill first col
            for(int i=rowEnd; i>=rowSt; i--){
                if(temp){
                    ans[i][colSt] = temp->val;
                    temp = temp->next;
                }
            }
            colSt++;   
        }
        return ans;
    }
};