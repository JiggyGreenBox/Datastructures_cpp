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

    printList(head);

    ListNode *prev = NULL;

    while(head != NULL) {
        ListNode *next_node = head->next;
        head->next = prev;
        prev = head;
        head = next_node;
    }

    printList(prev);

    return 0;
}
