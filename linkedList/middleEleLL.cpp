#include<bits/stdc++.h>
using namespace std;
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
    ListNode* usingStack(ListNode* head){
        if(head==nullptr) return head;
        stack<ListNode*>st;
        ListNode* temp=head;
        while(temp!=nullptr){
            st.push(temp);
            temp=temp->next;
        }
        int middle=(st.size()/2)+1;
        int remove=st.size()-middle;
        
        while(remove--){
            st.pop();
        }
        return st.top();
    }
    ListNode* usingIteration(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        int middle=(count/2)+1;

        int i=1;
        temp=head;
        while(temp!=nullptr){
            if(i==middle) return temp;
            i++;
            temp=temp->next;
        }
        return nullptr;

    }
    
    ListNode* middleNode(ListNode* head) {
        return usingIteration(head);
        return usingStack(head);

    }
};