# Stack and Queue

* [Implement Stack using Array](#implement-stack-using-array)
* [Implement Queue using Array](#implement-queue-using-array)
* [Valid Parenthesis](#valid-parenthesis)


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

### Implement Queue using Array
```cpp
// capacity = 0
// front = -1
// rear = -1

void myQueue::enqueue(int val) {
    if(isFull()) {
        return;
    }
    else if(empty()) {
        front++;
        rear++;
        capacity++;
    }
    else {
        rear = (rear+1) % max_size;
        capacity++;
    }
    arr[rear] = val;
}
void myQueue::dequeue(){
    if(!empty()){
        front = (front+1) % max_size;
        --capacity;
        if(capacity == 0) {
            front = -1;
            rear = -1;
        }
    }
}
```

### Valid Parenthesis
```cpp
bool isBalanced(std::string str) {

    std::stack<char> s;

    for(char x: str) {

        if( x=='[' || x=='{' || x=='(' ) {
            s.push(x);
        }
        else if(x==']' || x=='}' || x==')') {
            if(s.empty()){
                return false;
            }
            if( (x==']') && (s.top()== '[')) {
                s.pop();
            }
            else if((x==')') && (s.top()=='(')) {
                s.pop();
            }
            else if((x=='}') && (s.top()=='{')) {
                s.pop();
            }
            else {
                s.push(x);
            }
        }
    }

    if(s.empty())
        return true;
    return false;
}
```
