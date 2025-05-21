#include<bits/stdc++.h>
using namespace std;
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* Optimal(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=newNode->next;
        }

        temp=head;
            while(temp!=nullptr){
                if(temp->random==nullptr)
                temp->next->random=temp->random;
                else
                temp->next->random=temp->random->next;
                temp=temp->next->next;
            }
            Node* dummy=new Node(-1);
            Node* d=dummy;
            temp=head;
            while(temp!=nullptr){
                d->next=temp->next;
                d=d->next;
                temp->next=d->next;
                temp=temp->next;
                
            }
            return dummy->next;

    }
    Node* copyRandomList(Node* head) {
        return Optimal(head);
        if(head==nullptr) return nullptr;
        Node* temp=head;
        map<Node*,Node*>mp;
        while(temp!=nullptr){
            Node* newNode=new Node(temp->val);
            mp[temp]=newNode;
            temp=temp->next;
        }
        temp=head;
        while(temp!=nullptr){
           Node* copyNode=mp[temp];
           copyNode->next=mp[temp->next];
           copyNode->random=mp[temp->random];
           temp=temp->next;
        }

        return mp[head];
    }
};