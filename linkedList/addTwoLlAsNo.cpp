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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*temp1,*temp2;
        temp1=l1;
        temp2=l2;
        int digit=0;
        ListNode* dummyNode=new ListNode(-1);
        ListNode* head=dummyNode;
        while(temp1 && temp2){
            int sum=temp1->val+temp2->val+digit;
            if(sum>=10){
                digit=sum/10;
                sum=sum%10;
            }else digit=0;
            ListNode* newNode=new ListNode();
            newNode->val=sum;
            newNode->next=nullptr;
                dummyNode->next=newNode;
                dummyNode=dummyNode->next;

                temp1=temp1->next;
                temp2=temp2->next;
            
        }

        while(temp1){
            int sum=temp1->val+digit;
            if(sum>=10){
                digit=sum/10;
                sum=sum%10;
            }else digit=0;
              ListNode* newNode=new ListNode();
            newNode->val=sum;
            newNode->next=nullptr;
                dummyNode->next=newNode;
                dummyNode=dummyNode->next;
                temp1=temp1->next;
        }

        while(temp2){
            int sum=temp2->val+digit;
            if(sum>=10){
                digit=sum/10;
                sum=sum%10;
            }else digit =0;
              ListNode* newNode=new ListNode();
            newNode->val=sum;
            newNode->next=nullptr;
                dummyNode->next=newNode;
                dummyNode=dummyNode->next;
                temp2=temp2->next;
        }
        if(digit!=0){
            ListNode *newNode=new ListNode();
             newNode->val=digit;
            newNode->next=nullptr;
                dummyNode->next=newNode;
                dummyNode=dummyNode->next;
        }
        return head->next;
    }
};