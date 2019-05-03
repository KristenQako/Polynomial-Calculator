/****************************************************
 * File Name: queue.cc
 * Author: Robert Kruse and Alexander Ryba
 *         from "Data Structures and Program Design in C++"
 * Course: CSCI 262
 * Purpose: Implementation of Queue class
 * Date: February 10, 2002
 *****************************************************/

#include "queue_array.h"

Queue::Queue()
  /*
Post: The Queue is initialized to be empty.
  */
{
  count = 0;
  rear = maxqueue - 1;
  front = 0;
}


bool Queue::empty() const
  /*
Post: Return true if the Queue is empty, otherwise return false.
  */
{
  return count == 0;
}


Error_code Queue::append(const Queue_entry &item)
  /*
Post: item is added to the rear of the Queue. If the Queue is full
return an Error_code of overflow and leave the Queue unchanged.
  */

{
  if (count >= maxqueue) return overflow;
  count++;
  rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
  entry[rear] = item;
  return success;
}


Error_code Queue::serve()
  /*
Post: The front of the Queue is removed. If the Queue
is empty return an Error_code of underflow.
  */

{
  if (count <= 0) return underflow;
  count--;
  front = ((front + 1) == maxqueue) ? 0 : (front + 1);
  return success;
}


Error_code Queue::retrieve(Queue_entry &item) const
  /*
Post: The front of the Queue retrieved to the output
      parameter item. If the Queue is empty return an Error_code of underflow.
  */

{
  if (count <= 0) return underflow;
  item = entry[front];
  return success;
}

int Extended_queue::size( ) const
/**********************************************************************
* Pre: None
* Post: Return the number of entries in the Extended_queue. 
**********************************************************************/
{
  return count;
} //end size()

bool Extended_queue :: full() const
/**********************************************************************
* Pre: None
* Post: Return true if no room in queue.
**********************************************************************/
{
  if (count == maxqueue) {
  	return true;
  } else {
  	return false;
  }
} //end full()

void Extended_queue::clear() 
/**********************************************************************
* Pre: None
* Post: Delete all the entries of the queue.
**********************************************************************/
{
  while (!empty()) {
    serve();
  } //end while
} //end clear()

Error_code Extended_queue :: serve_and_retrieve(Queue_entry &item)
/**********************************************************************
* Pre: None
* Post: Return entry at front of queue in item, then delete front node
**********************************************************************/
{
  if(retrieve(item) == underflow) {
    return underflow;
  } //end if
  return serve();
} //end serve_and_retrieve( )

Term :: Term(int exponent, double scalar)
  /**********************************************************************
   * Pre: None
   * Post: The Term is initialized with the given coefficient 
   *       and exponent, or with default parameter values of 0.
   **********************************************************************/
{
  degree = exponent;
  coefficient = scalar;
} //end Term()
