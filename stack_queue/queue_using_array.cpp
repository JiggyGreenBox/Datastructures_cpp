#include <iostream>

// [Implement Stack using Array] #implement-stack-using-array

class myQueue{
private:
    #define max_size 5
    int arr[max_size];
    int front;
    int rear;
    int capacity;
public:
    myQueue();
    bool empty();
    int size();
    int frontEle();
    void enqueue(int val);
    void dequeue();
    bool isFull();
    void print();
};

myQueue::myQueue(){
    front = -1;
    rear = -1;
    capacity = 0;
}

bool myQueue::empty(){
    if(capacity == 0)
        return true;
    return false;
}
bool myQueue::isFull(){
    if(capacity == max_size)
        return true;
    return false;
}
int myQueue::size(){
    return max_size - capacity;
}
int myQueue::frontEle(){
    if (!empty()) {
        //std::cout << "front: " << arr[max_size] << std::endl;
        return arr[front];
    }
    else {
        std::cout << "erroor: " << std::endl;
        exit(EXIT_FAILURE);
    }
}
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

void myQueue::print(){

    std::cout << std::endl;
}





int main() {

    // empty()
    // size()
    // front()
    // push_back(int val)
    // pop_front()
    // isFull()

    myQueue q;
    q.enqueue(0);
    for(int i=1;i<100;i+=2){
        q.enqueue(i);
        q.dequeue();
        std::cout << q.frontEle() << std::endl;
    }

    return 0;
}
