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
    ListNode* BruteForce(ListNode* headA,ListNode* headB){
          ListNode* h1,*h2;
        h1=headA;
        h2=headB;
        ListNode* finalNode=nullptr;
        int skipA=0,skipB=0;
        while(h1!=nullptr){
                skipB=0;
                h2=headB;
            while(h2!=nullptr){
                if(h1==h2){
                    finalNode=h1;
                  return finalNode;
                }
                skipB++;
                h2=h2->next;
            }
             skipA++;
             h1=h1->next;

        }
        return finalNode;
    }
    ListNode* usingHashMap(ListNode* headA,ListNode* headB){

        set<ListNode*>st;
        while(headA!=nullptr){
            st.insert(headA);
            headA=headA->next;
        }

            while(headB!=nullptr){
               if(st.find(headB)!=st.end()){
                    return headB;
               }
               headB=headB->next;
            }
            return nullptr;

    }
    ListNode* twoPointer(ListNode* headA,ListNode* headB){
        ListNode* temp1=headA;
        ListNode* temp2=headB;

        int n1=0,n2=0;
        while(temp1!=nullptr){
            n1++;
            temp1=temp1->next;
        }
        while(temp2!=nullptr){
            n2++;
            temp2=temp2->next;
        }
        int n;
         ListNode* h1=headA;
            ListNode* h2=headB;
        if(n1>n2){
            n=n1-n2;
            while(n--){
                h1=h1->next;
            }
            while(h1!=nullptr){
                if(h1==h2) return h1;
                h1=h1->next;
                h2=h2->next;
            }
        }else{
            n=n2-n1;
            while(n--){
                h2=h2->next;
            }
            while(h2!=nullptr){
                if(h2==h1) return h2;
                h2=h2->next;
                h1=h1->next;
            }
        }
        return nullptr;

    }
    ListNode* optimiseMethod(ListNode* headA,ListNode* headB){
        ListNode* d1=headA;
        ListNode* d2=headB;

        while(d1!=d2){
            if(d1==nullptr)
            d1=headB;
            else d1=d1->next;
            if(d2==nullptr)
            d2=headA;
            else
            d2=d2->next; 
        }
        return d1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      return optimiseMethod(headA,headB);
      return twoPointer(headA,headB);
      return usingHashMap(headA,headB);
      return BruteForce(headA,headB);
    }
};