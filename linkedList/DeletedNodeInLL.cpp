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
    void deleteNode(ListNode* node) {
        ListNode* temp=node;
        ListNode* check;
        while(temp->next!=nullptr){
            swap(temp->val,temp->next->val);
            check=temp;
            temp=temp->next;
        }
     check->next=nullptr;
      delete temp;
    }
};