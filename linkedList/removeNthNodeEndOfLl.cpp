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
    void removenthele(ListNode* head,int& n){
        if(head->next==nullptr){
            n=n-1;
            return;
        }
        removenthele(head->next,n);
        n=n-1;
        if(n==-1){
            head->next=head->next->next;
        }
    }
    int sizell(ListNode* head){
        int s=0;
        while(head!=nullptr){
            s++;
            head=head->next;
        }
        return s;
    }
    ListNode* usingTwoPointer(ListNode* head,int n){
        if(head==nullptr) return nullptr;
        ListNode* slow,*fast;
        slow=fast=head;
        while(n--){
            fast=fast->next;
        }
        if(fast==nullptr) return head->next;
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* temp=slow->next;
        slow->next=slow->next->next;
        delete temp;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return usingTwoPointer(head,n);
        
        //recursive solution
        if(head==nullptr) return head;
        else if(head->next==nullptr) head=nullptr;
        else if(sizell(head)<=n) head=head->next;
        else
        removenthele(head,n);
        return head;


    }
};