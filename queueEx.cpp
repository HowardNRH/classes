/*
  queueEx.cpp
  An example of what a queue class might look like FIFO (first in first out) dynamic data structure
  Nick Howard, Oct 16, 2025
*/

#include <iostream>
using namespace std;

class Queue{
public:
  Queue();
  ~Queue();

  void enqueue(int x); // add to back
  int dequeue(); // delete front 
  int getStart();
  int getEnd();
  void print();
  bool isEmpty();

private:
  struct Node{
    int data;
    Node* next;
  };

  Node* start;

};

int main() {
  Queue q;
 
  for (int i = 0; i < 6; i++) {
    cout << "enqueuing: " << i << endl;
    q.enqueue(i);
  }
  q.print();

  cout << "dequeuing " << q.dequeue() << endl;
  cout << "dequeuing " << q.dequeue() << endl;

  cout << "first item: " << q.getStart() << endl;
  cout << "last item: " << q.getEnd() << endl;

  return EXIT_SUCCESS;
}


Queue::Queue(){
  start = NULL;
}

Queue::~Queue(){
  if (!isEmpty()){
    Node* p;
    while (start != NULL){
      cout << "deleting: " << dequeue() << endl;
    }
  }
}

void Queue::enqueue(int x){ // ADD TO BACK 
  Node* p = new Node;
  p->data = x;
  p->next = NULL;
  if (isEmpty())
    start = p;
  else {
    Node* n = start;
    while (n->next != NULL)
      n = n->next;
    n->next = p;
  } 
}

int Queue::dequeue(){ // DELETE FRONT 
  if (isEmpty())
    return -1;
  else {
    int x;
    Node* p = start;
    start = start->next;

    x = p->data;
    delete p;
    return x;
  }
}

int Queue::getStart(){
  if(isEmpty())
    return -1;
  else{
    return start->data;
  }
}

int Queue::getEnd(){
  if (isEmpty())
    return -1;
  else {
    Node* p = start;
    while (p->next != NULL){
      p = p->next;
    }
    return p->data;
  }
}

void Queue::print(){
  if (isEmpty())
    cout << "Queue is empty" << endl;
  else {
    Node* p = start;
    while (p != NULL) {
      cout << "Queue item: " << p->data << endl;
      p = p->next;
    }  
  }
}

bool Queue::isEmpty(){
  if (start == NULL)
    return true;
  return false;
}
