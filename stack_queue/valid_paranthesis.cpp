#include <iostream>
#include <stack>
#include <string>
#include <vector>

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


int main() {

    std::string t1 = "(jig)gy";
    std::string t2 = "[{()()[]{()}}]";
    std::string t3 = "[{]";
    std::string t4 = "}[]{";
    std::string t5 = "(jig)";

    std::vector<std::string> vec;
    vec.push_back(t1);
    vec.push_back(t2);
    vec.push_back(t3);
    vec.push_back(t4);
    vec.push_back(t5);

    for(auto x: vec){
        if(isBalanced(x)) {
            std::cout << x << ": BALANCED" <<  std::endl;
        }
        else{
            std::cout << x << ": NOT BALANCED" <<  std::endl;
        }
    }

}
