#include <iostream>
#include <stack>

#define print(x) std::cout << x << std::endl;


class queue_using_stack{
private:
    std::stack<int> input;
    std::stack<int> output;

public:
    void push(int x){
        input.push(x);
    }

    int top(){
        // top always done from output
        if(!output.empty()){
            return output.top();
        }
        else{
            while(!input.empty()){
                // push input into output
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }

    int pop(){
        // pop always done from output
        if(!output.empty()){
            output.pop();
        }
        else{
            while(!input.empty()){
                // push input into output
                output.push(input.top());
                input.pop();
            }
            output.pop();
        }
    }

    /*
    TODO
        add these methods
        also add underflow conditions
    // Empty
    bool isEmpty(){
        if(s1.empty() && s2.empty()){
            cout << "Empty "<< endl;
            return true;
        }
        cout << "Not Empty "<< endl;
        return false;
    }

    // Size
    int size(){
        int s = s1.size() + s2.size();
        cout << "size :" << s << endl;
        return s;
    }
    */
};


int main(){
    /*
    Implement a Queue using a stack
      - Queue has a front() function to get the first element added
        Stack has a top() function to get the last element added
      - Hence 2 stacks are required, such that the first element added
        will be retained as the top element. Swapping between both the
        stacks, is how this is acheived.
      - There is an optimal solution where the swapping is only done
        during the top() and pop() functions


      - Non-optimal solution:
        push(x)
            transfer s1 -> s2
            push x -> s1
            transfer s2 -> s1

        top()
            s1.top()

        pop()
            s1.pop()

        for pop() Time Complexity and Space Complexity is:
            TC O(N)
            SC O(2)


      - Optimal solution
        use 2 stacks input stack and output stack

        push(x)
            input.push(x)

        pop()
            if output.notEmpty():
                output.pop()
            else:
                input -> output
                output.pop()


        top()
            if output.notEmpty():
                return output.top()
            else:
                input -> output
                return output.top()


        TC and SC
            push is O(1)
            pop and top is mostly O(1) and worst O(N)
            so amortised O(1)


    */




    queue_using_stack s;
    s.push(5);
    s.push(6);
    s.push(7);
    print(s.top());
    s.pop();
    print(s.top());



    return 0;
}
