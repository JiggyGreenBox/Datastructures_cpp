#include <iostream>
#include <vector>
#include <algorithm>    // std::binary_search, std::sort

class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0) {
        real = r;
        imag = i;
    }

    Complex operator + (Complex const &obj) {
         Complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }

    void print() {
        std::cout << real << " + i" << imag << std::endl;
    }
};


int main(){
    Complex a1(10,5);
    Complex a2(13,4);
    Complex c3 = a1 + a2;
    c3.print();

    return 0;
}

