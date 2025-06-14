#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int i=0;
    reverse(a.begin(),a.end());
    Node* head=new Node();
    Node* temp=head;
    while(i<n){
        Node* newNode=new Node();
        newNode->data=a[i++];
        newNode->next=nullptr;
        temp->next=newNode;
        temp=newNode;
    }

    Node* ptr=head->next;
    int finalNum=0;
    i=0;
    while(ptr!=nullptr){
        if(ptr->data==1){
            finalNum += pow(2,i);
        }
        ptr=ptr->next;
        i++;
    }

    cout<<finalNum;
}