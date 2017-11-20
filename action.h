// file name -- action.h
// This header file contains the specifications for the Action class

#ifndef CLASS_ACTION__
#define CLASS_ACTION_
#include "movie.h"

class Action : public Movie
{
   public:
      Action();   // default constructor
      Action(char*, char*, char*, char*); // constructor
     // Action operator=(const Action& source);


      double calculateCharge();
      double calculateLateFee(int);
 }; // class Action

#endif
