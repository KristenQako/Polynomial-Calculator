/****************************************************
 * File Name: queue.h
 * Author: Robert Kruse and Alexander Ryba
 *         from "Data Structures and Program Design in C++"
 * Modified by: Kristen Qako
 * Course: CSCI132
 * Modification Date: February 10, 2002
 * Purpose: specification of Queue class
 *****************************************************/
#include <cstdlib>
using namespace std;

#ifndef ERROR_C
#define ERROR_C
enum Error_code {success, fail, underflow, overflow};
#endif

#ifndef QUEUE_H
#define QUEUE_H
struct Term {
  int degree;
  double coefficient;
  Term (int exponent = 0, double scalar = 0);
};

typedef Term Queue_entry;
typedef Queue_entry Node_entry;

struct Node {
  //data members
  Node_entry entry ;
  Node *next ;
  //constructors
  Node();
  Node(Node_entry item ,Node *add_on = NULL );
};


class Queue {
 public:
  Queue();
  bool empty() const;
  Error_code serve();
  Error_code append(const Queue_entry &item);
  Error_code retrieve(Queue_entry &item) const;
  ~Queue();
  Queue(const Queue &original);
  void operator = (const Queue &original);

 protected:
  Node *front, *rear;
};

class Extended_queue : public Queue {
 public:
  bool full() const;
  int size() const;
  void clear();
  Error_code serve_and_retrieve(Queue_entry &item);
};

#endif
