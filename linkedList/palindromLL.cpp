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
    int sizeLL(ListNode* head){
        int c=0;
        while(head!=nullptr){
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode* reverseLL(ListNode* head){
        if(head->next==nullptr){
            return head;
        }
        ListNode* List=reverseLL(head->next);
        head->next->next=head;
        head->next=nullptr;
        return List;
    }
    bool usingTwoPointerApproach(ListNode* head){
        ListNode* slow=head,*fast=head,*temp=head;
        ListNode* secondList;
       int n= sizeLL(head);
       if(n==1) return true;
           while(fast!=nullptr){

            if(fast->next==nullptr){
                fast=nullptr;
                break;
            }else fast=fast->next->next;
            slow=slow->next;
           }
           if(n%2==0)
          secondList=reverseLL(slow);
         else  secondList=reverseLL(slow->next);
         while(secondList!=nullptr){
            if(head->val!=secondList->val) return false;
            secondList=secondList->next;
            head=head->next;
         }
         return true;
        
    }
    bool isPalindrome(ListNode* head) {
        return usingTwoPointerApproach(head);
        return usingRecursion(head, head);

        return usingStack(head);
        return bruteForce(head);
       
    }
};