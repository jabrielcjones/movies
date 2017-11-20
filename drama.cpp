// file name -- drama.cpp
// This file contains the implementation of the Drama class

// ============== header files ================

#include "drama.h"          // for drana class
#include <iostream>        // for input/output stream
using namespace std;

// ============== named constants ======================

// ============== implementation of functions ================

Drama::Drama()
       :Movie()
/**
   precondition:  none
   
   postcondition: initializes the member variable of the
                  derived member variables.

**/
{
}  // default constructor


Drama::Drama(char* company, char* movieTitle, char* id, char* rating)
       :Movie(company, movieTitle, id, rating)
/**
   precondition: none

   postcondition: intializes the member variables of the Movie
                  class based on the arguments passed to the
                  constructor of the Action class
**/
{
}  // constructor


double Drama::calculateCharge()
/**
   precondition: none

   postcondition: calculates the charge for movie rental
**/
{
   return 1.50;
}


double Drama::calculateLateFee(int days)
/**
   precondition: none

   postcondition: calculate late fees for movie
**/
{
   return days * 2.00;
}
