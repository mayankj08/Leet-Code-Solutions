#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {

    if(head == nullptr)
        return head;
    
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* after = curr->next;
    while(1){
        curr->next = prev;
        if(after == nullptr){
            break;
        }
        prev = curr;
        curr = after;
        after = curr->next;
    }
    return curr;
}


int main(){
    ListNode* head = new ListNode(-1);
    ListNode* curr = head;

    /*for(int i=0;i<5;i++){
        ListNode* temp = new ListNode(i);
        curr->next = temp;
        curr = temp;
    }*/


    ListNode* temp = head;
    while(temp!= NULL){
        std::cout << temp->val << ' ';
        temp = temp->next;
    }
    std::cout << "\n";

    ListNode* newHead = reverseList(head);

    temp = newHead;
    while(temp!= NULL){
        std::cout << temp->val << '\n';
        temp = temp->next;
    }


}
