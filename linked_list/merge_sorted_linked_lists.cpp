#include <iostream>
#include <stack>


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};


void printList(ListNode *head){

    while(head != NULL){
        std::cout << head->val <<std::endl;
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    /*
    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    //head->next->next->next->next->next->next->next = new ListNode(8);
    */
    //printList(head);

    ListNode* h1 = new ListNode(1);
    h1->next = new ListNode(3);
    h1->next->next = new ListNode(5);
    h1->next->next->next = new ListNode(7);


    ListNode* h2 = new ListNode(2);
    h2->next = new ListNode(4);
    h2->next->next = new ListNode(6);
    h2->next->next->next = new ListNode(8);


    ListNode *temp_node = new ListNode(-1);
    ListNode *curr_node = temp_node;

    while(h1 != NULL && h2 != NULL){
        if (h1->val < h2->val){
            curr_node->next = h1;
            h1 = h1->next;
        }
        else{
            curr_node->next = h2;
            h2 = h2->next;
        }
        curr_node = curr_node->next;
    }

    while(h1 != NULL){
        curr_node->next = h1;
        h1 = h1->next;
        curr_node = curr_node->next;
    }

    while(h2 != NULL){
        curr_node->next = h2;
        h2 = h2->next;
        curr_node = curr_node->next;
    }

    printList(temp_node->next);

    return 0;
}
