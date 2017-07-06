#include<iostream>
#include<vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(std::vector<int> data){
	ListNode* head = new ListNode(-1);
	ListNode* last = head;

	for(auto elem : data){
		ListNode* temp = new ListNode(elem);
		last->next = temp;
		last = temp;
	}

	return head;
}

ListNode* deleteDuplicates(ListNode* head){

    if(head == NULL){
        return head;
    }

    ListNode* curr = head;    

    while(curr->next!= NULL){
        if(curr->val == curr->next->val){
            ListNode* temp;
            temp = curr->next;
            curr->next = curr->next->next;

            // free temp's memory
            free(temp);
        } 
        else{
            curr = curr->next;
        }
    }

    return head;
}

void print(ListNode* head){
    auto temp = head->next;
    while(temp!= NULL){
        std::cout << temp->val <<" ";
        temp = temp->next;
    }

}

int main(){
	{
		std::vector<int> elem = {};
		ListNode* head = createList(elem);
        head = deleteDuplicates(head);   
        print(head);
		
	}

}
