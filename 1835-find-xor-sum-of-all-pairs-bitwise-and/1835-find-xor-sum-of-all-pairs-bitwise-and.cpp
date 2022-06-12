class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int xora = arr1[0], xorb=arr2[0];
    
        for(int i=1; i<arr1.size(); i++)
        xora = xora ^ arr1[i];
    
        for(int i=1; i<arr2.size(); i++)
        xorb = xorb ^ arr2[i];
    
        return xora & xorb;
    }
};