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

    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next->next->next = new ListNode(8);

    printList(head);

    // take care of null list
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    ListNode *first = head;
    ListNode *second = head;

    int remove_n = 2;

    for(int i=1; i< remove_n+1; i++) {
        second = second->next;
    }


    while(second != NULL) {
        first = first->next;
        second = second->next;
    }

    std::cout << "Node to remove: " << first->val << std::endl;
    std::cout << std::endl;

    // remove node operation
    first->val = first->next->val;
    first->next = first->next->next;

    printList(dummy->next);

    return 0;
}
