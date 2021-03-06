// file name -- drama.h
// This header file contains the specifications for the drama class

#ifndef CLASS_DRAMA__
#define CLASS_DRAMA__
#include "movie.h"

class Drama : public Movie
{
   public:
      Drama();   // default constructor
      Drama(char*, char*, char*, char*); // constructor

      double calculateCharge();
      double calculateLateFee(int);
 }; // class Drama

#endif
