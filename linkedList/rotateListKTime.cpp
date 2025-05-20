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
    int sizeLL(ListNode* head) {
        int c = 0;
        while (head != nullptr) {
            c++;
            head = head->next;
        }
        return c;
    }
    ListNode* optimalSol(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr)
            return head;
        int size = sizeLL(head);
        if (k > size) {
            k = k % size;
            while (k--) {
                ListNode* temp = head;
                ListNode* t2 = head;
                while (temp->next != nullptr) {
                    t2 = temp;
                    temp = temp->next;
                }
                temp->next = head;
                head = temp;
                t2->next = nullptr;
            }
        } else {
            k = size - k;
            if (k == size || k == 0)
                return head;

            ListNode* temp = head;
            while (--k) {
                temp = temp->next;
            }
            ListNode* t2 = temp->next;

            while (t2 != nullptr && t2->next != nullptr) {
                t2 = t2->next;
            }

            t2->next = head;
            head = temp->next;
            temp->next = nullptr;
        }

        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        return optimalSol(head, k);
        if (head == nullptr)
            return nullptr;
        int size = sizeLL(head);
        if (k > size) {
            k = k % size;
        }
        while (k--) {
            ListNode* temp = head;
            ListNode* t2 = head;
            while (temp->next != nullptr) {
                t2 = temp;
                temp = temp->next;
            }
            temp->next = head;
            head = temp;
            t2->next = nullptr;
        }
        return head;
    }
};