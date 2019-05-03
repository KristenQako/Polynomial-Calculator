/****************************************************
 * File Name: queue_array.h
 * Author: Robert Kruse and Alexander Ryba
 *         from "Data Structures and Program Design in C++"
 * Modified by: Constance Royden
 * Course: CSCI132
 * Modification Date: February 10, 2012
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

const int maxqueue = 100; //  small value for testing

class Queue {
 public:
  Queue();
  bool empty() const;
  Error_code serve();
  Error_code append(const Queue_entry &item);
  Error_code retrieve(Queue_entry &item) const;

 protected:
  int count;
  int front, rear;
  Queue_entry entry[maxqueue];
};

class Extended_queue : public Queue {
 public:
  bool full() const;
  int size() const;
  void clear();
  Error_code serve_and_retrieve(Queue_entry &item);
};

#endif
