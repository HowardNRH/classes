/*
  stackEx.cpp
  Example of what a stack class could look like with its methods
  Nick Howard Oct 10, 2025
*/

#include <iostream>
using namespace std;


class Stack{
public:
  Stack();
  ~Stack();
  void push( int x );
  int pop();
  int peek(); 
  bool isEmpty();
  void print();
 
private:
  struct Node{
    int data;
    struct Node* next;
  };
  typedef struct Node* NodePtr;

 NodePtr top;
};







int main() {
  Stack s;

  for ( int i = 0; i < 6; i++ ) {
    s.push(i);
    cout << "pushed " << i << " onto stack" << endl;
  }
  
  cout << s.peek() << " is the top of the stack" << endl;
  s.print(); 

  return EXIT_SUCCESS;
}



Stack::Stack() {
  top = NULL;
}

Stack::~Stack() {
  while (!isEmpty())
    cout << "deleting: " << pop() << endl;
}

void Stack::push( int x ) {
  NodePtr p = new Node;  
  p->data = x;
  p->next = top;
  top = p;
}

int Stack::pop() {
  NodePtr d = top;
  int x = d->data;
  if ( top != NULL)
    top = top->next;
  delete d;
  return x;
}

int Stack::peek() {
  if (top == NULL) {
    cout << "List empty" << endl;
    return -1;
  } 
  return top->data;
}

bool Stack::isEmpty() {
  if ( top == NULL )
    return true;
  else 
    return false;
}

void Stack::print() {
  NodePtr x = top;
  do {
    cout << "stack item: " << x->data << endl;
    x = x->next;
  } while ( x != NULL);
}
