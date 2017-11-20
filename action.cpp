// file name -- action.cpp
// This file contains the implementation of the Action class

// ============== header files ================

#include "action.h"          // for action class
#include <iostream>        // for input/output stream
using namespace std;

// ============== named constants ======================

// ============== implementation of functions ================

Action::Action()
       :Movie()
/**
   precondition:  none
   
   postcondition: initializes the member variable of the
                  derived member variables.

**/
{
}  // default constructor


Action::Action(char* company, char* movieTitle, char* id, char* rating)
       :Movie(company, movieTitle, id, rating)
/**
   precondition: none

   postcondition: intializes the member variables of the Movie
                  class based on the arguments passed to the
                  constructor of the Action class
**/
{
}  // constructor


/**Action Action::operator=(const Action& source)
/**
   precondition: none

   postcondition: intializes the member variables of the Movie
                  class based on the arguments passed to the
                  overloaded operator of the source object.

{
   changeCompany(source.getCompany());
   changeMovie(source.getMovie());
   changeId(source.getId());
   changeRating(source.getRating());
}**/


double Action::calculateCharge()
/**
   precondition: none

   postcondition: calculates the charge for movie rental
**/
{
   return 2.00;
}


double Action::calculateLateFee(int days)
/**
   precondition: none

   postcondition: calculate late fees for movie
**/
{
   return days * 3.00;
}

