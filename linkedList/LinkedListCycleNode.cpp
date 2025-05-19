#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* usingHash(ListNode* head){
        set<ListNode*>st;
        ListNode* temp=head;
        ListNode* cycleNode;
        while(temp!=nullptr){
           if(st.find(temp)!=st.end()){
            return temp;
           }
           st.insert(temp);
           temp=temp->next;
        }
        cout<<"no cycle";
        return nullptr;
    }
       
    ListNode* usingTwoPointer(ListNode* head){
        ListNode* slow=head,*fast=head;

        while(fast!=nullptr &&fast->next!=nullptr){
           
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
    ListNode *detectCycle(ListNode *head) {
         return usingTwoPointer(head);
       return usingHash(head);
      


    }
};