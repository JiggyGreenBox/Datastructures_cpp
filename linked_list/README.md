# Linked List

* [Reverse a Linked List](#reverse-a-linked-list)
* [Middle of a Linked List](#reverse-a-linked-list)



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
