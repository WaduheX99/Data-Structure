#include <iostream>

using namespace std;

struct stack {
    string nama;
    int nilai;
    stack *next;
};

stack *head = NULL;
stack *tail = NULL;

int top;
int maks;