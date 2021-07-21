# Linked List

* [Reverse a Linked List](#reverse-a-linked-list)



### Reverse a Linked List
```cpp
// 1-2-3-null
// 3-2-1-null
ListNode *prev = NULL;

while (head != NULL) {
    ListNode *next_node = head->next;
    head->next = prev;
    prev = head;
    head = next_node;
}
```
