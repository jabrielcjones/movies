// file name -- comedy.h
// This header file contains the specifications for the Comedy class

#ifndef CLASS_COMEDY__
#define CLASS_COMEDY__
#include "movie.h"

class Comedy : public Movie
{
   public:
      Comedy();   // default constructor
      Comedy(char*, char*, char*, char*); // constructor

      double calculateCharge();
      double calculateLateFee(int);
 }; // class Comedy

#endif
