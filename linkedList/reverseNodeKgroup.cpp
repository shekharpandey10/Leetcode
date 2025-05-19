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
    ListNode* findKthNode(ListNode* temp, int k) {
        while (temp != nullptr && --k) {
            temp = temp->next;
        }
        return temp;
    }
    void reverseLL(ListNode* temp) {
        if (temp->next == nullptr) {
            return;
        }
        reverseLL(temp->next);
        temp->next->next = temp;
        temp->next = nullptr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = nullptr;

        while (temp != nullptr) {

            ListNode* kthNode = findKthNode(temp, k);
            if (kthNode == nullptr) {
                prevNode->next = temp;
                break;
            }
            ListNode* newNode = kthNode->next;
            kthNode->next = nullptr;
            reverseLL(temp);
            if (prevNode != nullptr)
                prevNode->next = kthNode;
            prevNode = temp;
            if (head == temp) {
                head = kthNode;
            }
            temp = newNode;
        }
        return head;
    }
};