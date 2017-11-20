// file name -- movie.h
// This header file contains the specifications

#ifndef CLASS_MOVIE_
#define CLASS_MOVIE_

using namespace std;

class Movie
{
   private:
      char* rating;
      char* company;
      char* movieTitle;
      char* id;

   public:
      Movie();   // default constructor
      Movie(char*, char*, char*, char*); // constructor
      Movie(const Movie&);      // copy constructor
      ~Movie();    // destructor
      bool operator==(const Movie& source);

      char* getMovie();  // accessor function
      char* getRating();   // accessor function
      char* getCompany();  // accessor function
      char* getId(); // accessor function
      void changeMovie(char*);   // mutator function
      void changeRating(char*); // mutator function
      void changeCompany(char*);   // mutator function
      void changeId(char*);  // mutator function

      virtual double calculateCharge() = 0;
      virtual double calculateLateFee(int) = 0;
 }; // Movie

#endif
