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
    ListNode* bruteForce(ListNode* list1,ListNode* list2){
         ListNode* head;
        if(list1!=nullptr && list2!=nullptr){
            ListNode* temp=list1;
            while(temp!=nullptr){
                if(temp->next==nullptr) {
                    temp->next=list2; 
                    head=list1;
                    break;
                }
                temp=temp->next;
            }
        }else if(list1==nullptr) head=list2;
        else head=list1;
        ListNode* list=head;
        vector<int>arr;
        while(list!=nullptr){
            arr.push_back(list->val);
            list=list->next;
        }
        sort(arr.begin(),arr.end());
        int i=0;
        list=head;
        while(list!=nullptr){
            list->val=arr[i++];
            list=list->next;
        }
        return head;
    }
    ListNode* usingMerge(ListNode* list1, ListNode* list2){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->val<=list2->val){
                temp->next=list1;
                list1=list1->next;
            }else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        if(list1!=nullptr){
            temp->next=list1;
        }else temp->next=list2;
        return dummy->next;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return usingMerge(list1,list2);
       return bruteForce(list1,list2);

    }
};