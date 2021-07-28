#include <iostream>
#include <vector>
#include <algorithm>    // std::binary_search, std::sort

class Base{
public:
    void show(){
        std::cout <<"Base class show function"<< std::endl;
    }
    virtual void print(){
        std::cout <<"Base class print function"<< std::endl;
    }
};

class Derived: public Base{
public:
    void show(){
        std::cout <<"Derived class show function"<< std::endl;
    }

    void print(){
        std::cout <<"Derived class print function"<< std::endl;
    }

};

class Animal{
public:
    virtual void eat(){
        std::cout <<"I'm eating generic food"<< std::endl;
    }
};

class Cat: public Animal{
public:
    void eat(){
        std::cout <<"I'm eating a cat food"<< std::endl;
    }
};

class Dog: public Animal{
public:
    void eat(){
        std::cout <<"I'm eating a dog food"<< std::endl;
    }
};

void function1(Animal *xyz){
    xyz->eat();
}

int main(){

    // virtual allows base pointer to access derived methods
    /*
    Base *baseptr;
    Derived derived;
    baseptr = &derived;

    baseptr->print();
    baseptr->show();
    */

    Animal *ptr;
    Cat catObj;
    Dog dogObj;

    ptr = &catObj;

    // comment and uncomment virtual
    // virtual comment allows function1 to be reused
    // otherwise 3 functions for 3 classes
    function1(ptr);
}

