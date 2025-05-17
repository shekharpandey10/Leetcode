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
    bool usingMap(ListNode* head){
        map<ListNode*,int>mp;
        ListNode* temp=head;
        while(temp!=nullptr){
           mp[temp->next]++;
            temp=temp->next;
             for(auto m:mp){
            if(m.second>=2){
                return true;
            }
        }
        }
        return false;
    }
    bool usingSet(ListNode* head){
        set<ListNode*>st;
        while(head!=nullptr){
            if(st.find(head)!=st.end()) return true;
             st.insert(head);
            head=head->next;
        }
        return false;
    }
    bool floydCycleAlgo(ListNode*head){
        ListNode* t1=head;
        ListNode* t2=head;
        while(t2!=nullptr && t2->next){
            
            t1=t1->next;
            t2=t2->next->next;
            if(t1==t2) return true;
        }
        return false;
    }
    bool hasCycle(ListNode *head) {
        return floydCycleAlgo(head);
        return usingSet(head);
        return usingMap(head);
    }
};