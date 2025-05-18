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
    bool usingStack(ListNode* head) {
        stack<int> st;
        ListNode* head1 = head;
        while (head1 != nullptr) {
            st.push(head1->val);
            head1 = head1->next;
        }
        while (!st.empty()) {
            if (st.top() == head->val) {
                st.pop();
                head = head->next;
            } else {
                return false;
            }
        }
        return true;
    }
    bool usingRecursion(ListNode* head, ListNode*& temp) {
        if (head->next == nullptr) {
            if (head->val == temp->val) {
                temp = temp->next;
                return true;
            } else
                return false;
        }
        bool ans = usingRecursion(head->next, temp);
        if (ans == false) {
            return ans;
        }
        if (head->val == temp->val) {
            temp = temp->next;
            return true;
        }
        return false;
    }
    bool bruteForce(ListNode* head){
         vector<int> arr;
        while (head != nullptr) {
            arr.push_back(head->val);
            head = head->next;
        }
        int i = 0, j = arr.size() - 1;
        while (i <= j) {
            if (arr[i] == arr[j]) {
                i++;
                j--;
            } else
                return false;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        return usingRecursion(head, head);
        return usingStack(head);
        return bruteForce(head);
       
    }
};