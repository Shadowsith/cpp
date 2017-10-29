#include <iostream>

class A{
    //friend class B;
    private:
        int one;
        int two;

    public:
        A();
        void setOne(int one);
        int getOne();
};

A::A(){

}

void A::setOne(int one){
    this->one = one;
}

int A::getOne(){
    return this->one;
}

class B {
    //friend class A;
    private:
        int three;
        int four;

    public:
        B();
        //friends
        void setOne(A& a);
        int getOne();
};

B::B(){

}

void B::setOne(A& a){
    a.setOne(5);
}

int main(void){
    A a;
    a.setOne(1);
    B b;
    b.setOne(a);
    std::cout << a.getOne() << std::endl;


}
