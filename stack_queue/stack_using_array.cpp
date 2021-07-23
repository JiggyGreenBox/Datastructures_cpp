#include <iostream>

// [Implement Stack using Array] #implement-stack-using-array

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


myStack::myStack(){}

void myStack::push(int val){
    if (!isFull()){
        ++top;
        arr[top] = val;
    }
}

void myStack::pop(){
    if (!empty()){
        --top;
    }
}

int myStack::peek() {
    if (!empty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

bool myStack::empty(){
    if (top == -1)
        return true;
    return false;
}

int myStack::size(){
    return top + 1;
}

bool myStack::isFull() {
    if (size() == max_size)
        return true;
    return false;
}


int main() {

    // push
    // pop
    // top / peek
    // empty
    // size

    myStack s;

    if (s.empty()){
        std::cout << "empty" << std::endl;
    }

    s.push(5);
    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << s.peek() << std::endl;
    s.pop();
    s.pop();

    std::cout << s.peek() << std::endl;

    return 0;
}
