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

void while_func(ListNode *head, int remove_n) {

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

    // remove code allowing last node to be removed
    /*
    int remove_n = 8;

    ListNode *prev = NULL;
    while(head != NULL) {

        if (head->val == remove_n) {
            if (head->next != NULL){
                head->val = head->next->val;
                head->next = head->next->next;
            }
            else{
                // end of list removal
                // point preveious to null
                prev->next = NULL;
            }
        }
        prev = head;
        head = head->next;
    }
    */


    int remove_n = 2;

    while(head != NULL) {
        if (head->val == remove_n) {

            head->val = head->next->val;
            head->next = head->next->next;
        }
        head = head->next;
    }

    printList(dummy->next);
    return 0;
}
