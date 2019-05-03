/*******************************************************************
* Name: Kristen Qako
* Date: 02/28/2019
* Course: CSCI 132
* Assignment: Assignment 4
* Program: polynomial.cc
* Purpose: Implementation of polynomial class
***************************************************************************/
#include <iostream>
#include "polynomial.h"
using namespace std;

void Polynomial :: equals_difference(Polynomial p, Polynomial q)
/**********************************************************************
* Pre: None
* Post: The Polynomial object is reset as the difference of the two parameters.
**********************************************************************/
{
    clear( );
    while (!p.empty( ) || !q.empty( )) {
        Term p_term, q_term;
        if (p.degree( ) > q.degree( )) {
            p.serve_and_retrieve(p_term);
            append(p_term);
        } else if (q.degree( ) > p.degree( )) {
            q.serve_and_retrieve(q_term);
            q_term.coefficient = (-1*q_term.coefficient); //when subtracting by a negative, you add
            append(q_term);
        } else {
            p.serve_and_retrieve(p_term);
            q.serve_and_retrieve(q_term);
            if (p_term.coefficient - q_term.coefficient != 0) {
                Term answer_term(p_term.degree, p_term.coefficient - q_term.coefficient);
                append(answer_term);
            } //end inner if
        } //end if-else
    } // end while
}
  //your code goes here

void Polynomial :: equals_product(Polynomial p, Polynomial q)
/**********************************************************************
* Pre: None
* Post: The Polynomial object is reset as the product of the two parameters.
**********************************************************************/
{
    //your code goes here  
    clear();
    Term p_term, answer_term;
    Polynomial temp,final;
    while(!p.empty()){
        p.serve_and_retrieve(p_term); //retrieves the items in the polynomial.
        temp.mult_term(q,p_term); 
        final.equals_sum(final, temp);
    }
    while (!final.empty()){
        final.serve_and_retrieve(answer_term);
        append(answer_term);  
    }
}

void Polynomial :: mult_term(Polynomial p, Term t)
/**********************************************************************
* Pre: None
* Post: The Polynomial object is reset as the product of the polynomial,
*       p, and the single term, t.
**********************************************************************/
{
  //your code goes here
    clear();
    while(!p.empty()){
        Term p_term;
        p.serve_and_retrieve(p_term); //retrieves item in polynomial.
        Term answer_term(p_term.degree + t.degree, p_term.coefficient * t.coefficient); //add degrees and multiply coefficients.
        append(answer_term);        
    }           
}

double Polynomial :: evaluate (double number)
/**********************************************************************
* Pre: None
* Post: Evaluates the Polynomial object at number.
**********************************************************************/
{
    Polynomial p = *this;  //uses the object "receiving the message", but
    //does not change the object data.
    double answer;

    //your code goes here
    answer = 0;
    double num_copy = 1;
    Term p_term;
    while(!p.empty()){
        p.serve_and_retrieve(p_term);
        for(int i = 0; i < p_term.degree;i++){ //for loop to raise the number to a power.
            num_copy = number*num_copy;
        }
        num_copy = num_copy * p_term.coefficient;    //multipy it by the coefficient 
        answer = num_copy + answer;  //add the next element.
        num_copy = 1; //reset num_copy.
    }
    return answer;
}
//end evaluate

Error_code Polynomial :: equals_quotient(Polynomial p, Polynomial q)
/**********************************************************************
* Pre: None
* Post: The Polynomial object is reset as the quotient of the two parameters.
**********************************************************************/
{
  cout << "This function not yet implemented." << endl;
  return success;
} //end equals_quotient()


void Polynomial :: print( )
/**********************************************************************
* Pre: None
* Post: The Polynomial is printed to cout. If the polynomial is empty, 
*       0 is printed.
**********************************************************************/
{
  
  double r;
  Polynomial temp;
  bool first_term = true;
  while (!empty( )) {
    Term print_term;
    serve_and_retrieve(print_term);
    temp.append(print_term);
    if (first_term) { // In this case, suppress printing an initial +.
      first_term = false;
      if (print_term.coefficient < 0) {
        cout << "- ";
      } 
    } else if (print_term.coefficient < 0) {
      cout << " - ";
    } else {
      cout << " + ";
    }
    if (print_term.coefficient >= 0) {    
      r = print_term.coefficient;
    } else {
      r = -(print_term.coefficient);
    } 
    if (r != 1) {
      cout << r;
    } 
    if (print_term.degree > 1) {
      cout << " X^" << print_term.degree;
    } 
    if (print_term.degree == 1) {
      cout << " X";
    }
    if (r == 1 && print_term.degree == 0) {
      cout << " 1";
    }
  } //end while
  if (first_term) {
    cout << "0"; // Print 0 for an empty Polynomial.
  } //end if
  cout << endl;
  while(!temp.empty( )) {
    Term temp_term;
    temp.serve_and_retrieve(temp_term);
    append(temp_term);
  }
} // end print()

void Polynomial :: read( )
/**********************************************************************
* Pre: None
* Post: The Polynomial is read from cin.
**********************************************************************/
{
  clear( );                  /* An Extended_queue function */
  double coefficient;
  int last_exponent, exponent;
  bool first_term = true;
  cout << "Enter the coefficients and exponents for the polynomial, "
       << "one pair per line. Exponents must be in descending order." << endl
       << "Enter a coefficient of 0 or an exponent of 0 to terminate." << endl;
  do {
    cout << "coefficient? " << flush;
    cin >> coefficient;
    if (coefficient != 0.0) {
      cout << "exponent? " << flush;
      cin >> exponent;
      if ((!first_term && exponent >= last_exponent) || exponent < 0) {
        exponent = 0;
        cout << "Bad exponent: Polynomial terminates without its last term."
             << endl;
      } else {
        Term new_term(exponent, coefficient);
        append(new_term);
        first_term = false;
      } //end if
      last_exponent = exponent;
    }
  } while (coefficient != 0.0 && exponent != 0); //end do-while
} // end read()

void Polynomial :: equals_sum(Polynomial p, Polynomial q)
/**********************************************************************
* Pre: None
* Post: The Polynomial object is reset as the sum of the two parameters.
**********************************************************************/
{
  clear( );
  while (!p.empty( ) || !q.empty( )) {
    Term p_term, q_term;
    if (p.degree( ) > q.degree( )) {
      p.serve_and_retrieve(p_term);
      append(p_term);
    } else if (q.degree( ) > p.degree( )) {
      q.serve_and_retrieve(q_term);
      append(q_term);
    } else {
      p.serve_and_retrieve(p_term);
      q.serve_and_retrieve(q_term);
      if (p_term.coefficient + q_term.coefficient != 0) {
        Term answer_term(p_term.degree, p_term.coefficient + q_term.coefficient);
        append(answer_term);
      } //end inner if
    } //end if-else
  } // end while
} //end equals_sum()


int Polynomial :: degree( ) const
/**********************************************************************
* Pre: None
* Post:If the Polynomial is identically 0, a result of -1 is returned. 
*      Otherwise the degree of the Polynomial is returned.
**********************************************************************/
{
  if (empty( )) return -1;
  Term lead;
  retrieve(lead);
  return lead.degree;
} //end degree( )

