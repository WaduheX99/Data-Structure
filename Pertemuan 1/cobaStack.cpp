#include <iostream>

using namespace std;

class Stack_overflow {};
class Stack_underflow {};

class Stack {
    public:
        Stack(int sz) : sz{sz}, top{-1}, elem {new int[sz]} {};
        ~Stack() { delete[] elem; };
        bool empty();
        void push(int* x);
        int* pop();
    private:
        int* elem;
        int top;
        int sz;
};

bool Stack::empty() {
    if (top < 0) return true;
    return false;
}

void Stack::push(int* x) {
    if(top+1 > sz) throw Stack_overflow{};
    ++top;
    elem[top] = *x;
}

int* Stack::pop() {
    if (empty()) throw Stack_underflow{};
    --top;
    return &elem[top+1];
}

int main() {
    Stack s{2};
    int a = 5;
    int b = 7;
    s.push(&a);
    s.push(&b);
    int* y = s.pop();
    cout << *y << endl;
    y = s.pop();
    cout << *y << endl;
    return 0;
}