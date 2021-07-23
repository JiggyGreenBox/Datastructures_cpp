# Stack and Queue

* [Implement Stack using Array](#implement-stack-using-array)


### Implement Stack using Array
```cpp
class myStack{
private:
    #define max_size 5
    //int max_size = 5;
    int top = -1;
    int arr[max_size];
public:
    myStack();
    void push(int val);
    void pop();
    int peek();
    bool empty();
    int size();
    bool isFull();
};
```
