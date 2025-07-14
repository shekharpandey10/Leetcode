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
    int getDecimalValue(ListNode* head) {
        int binary;
        vector<int>arr;
        ListNode* temp=head;

        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }

        int n=arr.size();
        int ans=0;
        int j=0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]==1){
                ans+=pow(2,j);
            }
            j++;
        }
        return ans;
    }
};