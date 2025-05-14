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
    ListNode* usingInplace(ListNode* head){
         struct ListNode* prev,*curr,*nxt;
      int size=0;
      struct ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
            if(size==0||size==1) return head;
            if(size==2){
                struct ListNode* t=head->next;
                head->next=nullptr;
                t->next=head;
                head=t;
                return head;
            }
            curr=head->next;
            nxt=curr->next;
            head->next=nullptr;
            while(true){
                curr->next=head;
                head=curr;
                curr=nxt;
                
                if(nxt->next==nullptr){
                    curr->next=head;
                    head=curr;
                    break;
            }
                nxt=nxt->next;
            }
        return head;
    }

    ListNode* usingStack(ListNode* head){
        stack<int>st;
        struct ListNode* temp=head;
        while(temp!=nullptr){
            st.push(temp->val);
            temp=temp->next;
        }
        struct ListNode* temp2=head;
        while(!st.empty()){
            temp2->val=st.top();
            st.pop();
            temp2=temp2->next;
        }
        return head;
    }
    void recersiveSolve(ListNode* head,ListNode*& finalAns){
       if(head->next==nullptr){
        finalAns=head;
        return;
       }
       solve(head->next,finalAns);
       head->next->next=head;
       head->next=nullptr;
    }
    ListNode* usingRecursion(ListNode* head){
        if(head==nullptr) return head;
        ListNode* finalAns=nullptr;
        recersiveSolve(head,finalAns);
        return finalAns;
    }
    ListNode* reverseList(ListNode* head) {
        return usingRecursion(head);
        return usingStack(head);
        return usingInplace(head);

    }
};