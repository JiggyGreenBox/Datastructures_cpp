#include <iostream>
#include <vector>
#include <algorithm>    // std::binary_search, std::sort

class Point {
private:
    int x, y;
public:
    Point(int a, int b){
        x = a;
        y = b;
    }

    Point(Point const &P){
        x = P.x;
        y = P.y;
    }

    void print(){
        std::cout << "x: " << x;
        std::cout << " y: " << y << std::endl;
    }
};


int main(){
    Point p1(1,2);
    Point p2 = p1;
    p1.print();
    p2.print();
    return 0;
}

