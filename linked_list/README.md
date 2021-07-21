# Linked List

* [Reverse a Linked List](#reverse-a-linked-list)
* [Middle of a Linked List](#reverse-a-linked-list)
* [Merge 2 Sorted Linked Lists](#merge-2-sorted-linked-lists)
* [Remove Nth From End of Linked List](#remove-nth-from-end-of-linked-list)
* [Delete Node From Linked List](#delete-node-from-linked-list)



### Reverse a Linked List
```cpp
// 1-2-3-null
// 3-2-1-null

// P-H-N
// Prev-Head-NextNode
// point head to prev
// shift head and prev forward

ListNode *prev = NULL;

while (head != NULL) {
    ListNode *next_node = head->next;
    head->next = prev;
    prev = head;
    head = next_node;
}
```

### Middle of a Linked List
```cpp
ListNode *slow = head;
ListNode *fast = head;

while(fast != NULL && fast->next != NULL){
    slow = slow->next;
    fast = fast->next->next;
}
```

### Merge 2 Sorted Linked Lists
```cpp
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
}

while(h2 != NULL){
    curr_node->next = h2;
    h2 = h2->next;
}
```

### Remove Nth From End of Linked List
```cpp
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

// remove node operation
first->val = first->next->val;
first->next = first->next->next;

return dummy->next;
```

### Delete Node From Linked List
```cpp
int remove_n = 2;

while(head != NULL) {
    if (head->val == remove_n) {
        head->val = head->next->val;
        head->next = head->next->next;
    }
    head = head->next;
}
// if last node is to be deleted
// check if head->next is null 
// need reference to prev, and set prev->next = NULL
```
