#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    vector<ListNode*> visited;
    ListNode* curr = head;
    while(curr!= NULL){
        if(find(visited.begin(),visited.end(),curr) != visited.end()){
            return true;
        }
        else{
            visited.push_back(curr);
            curr = curr->next;
        }
    }
    return false;
}

int main(){
    ListNode* head = new ListNode(0);
    ListNode* curr = head;

    /*for(int i=0;i<10;i++){
        ListNode* temp = new ListNode(5);
        curr->next = temp;
        curr = temp;
    }*/

    ListNode* middle = curr;

    middle->next = head;
    
    std::cout << hasCycle(head);


}
