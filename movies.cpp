// file name -- assign05.cpp


// ============================== header files ===================================
#include <iostream>                 // for console I/O
#include <iomanip>                  // for input manipulation
#include <fstream>                  // for file stream
#include "action.h"                 // for Action class
#include "comedy.h"                 // for Comedy class
#include "drama.h"                  // for Drama class
#include <string>                   // for string
#include <cstring>                  // for string manipulation
#include <cctype>
using namespace std;


// ============================== named constants =============================
int const MAX = 50;
int const MAX_SIZE = 100;

// =================== data type declarations =========================
typedef Movie* MoviePointerArray[MAX_SIZE];
typedef char* GenrePointerArray[MAX_SIZE];

// ============================== function prototypes ==============================
void openFile(ifstream&);
void readData(MoviePointerArray, GenrePointerArray, ifstream&, int&, int*);
void outputData(MoviePointerArray, GenrePointerArray, int, int*);
void orderData(MoviePointerArray, GenrePointerArray, int, int*);

int main()
{
   MoviePointerArray moviePointer;
   GenrePointerArray genrePointer;
   int size;
   int* days_late = new int[MAX_SIZE];

   ifstream infile;
   openFile(infile);
   readData(moviePointer, genrePointer, infile, size, days_late);
   orderData(moviePointer, genrePointer, size, days_late);
   outputData(moviePointer, genrePointer, size, days_late);

   return 0;
} //function main





void openFile(ifstream& infile)
/**
   precondition: none

   postcondition: none
**/
{
   char infile_name[MAX];

   do
   {
      cout << "Enter data file name: ";
      cin>> infile_name;
      infile.open(infile_name);
      if (!infile)
         cout << infile_name
              << " was not opened successfully."
              << endl;
   } while (!infile);
}  // openFile function





void readData(MoviePointerArray moviePointer, GenrePointerArray genrePointer, ifstream& infile, int& size, int* days_late)
/**
   precondition: file is open

   postcondition: data from file is read
**/
{
   string temp;
   char company[MAX];
   char movie[MAX];
   char id[MAX];
   char rating[MAX];
   char genre;

   size = 0;
   getline(infile, temp);
   while(infile)
   {
      strcpy(company, temp.c_str());
      getline(infile, temp);
      strcpy(movie, temp.c_str());
      infile >> id;
      infile >> rating;
      infile >> days_late[size];
      infile >> genre;
      infile.ignore(1,'\0');
     
      if(toupper(genre) == 'A')
      {
         moviePointer[size] = new Action(company, movie, id, rating);
         genrePointer[size] = new char[MAX];
         strcpy(genrePointer[size], "Action");
      }
      else if(toupper(genre) == 'C')
      {
         moviePointer[size] = new Comedy(company, movie, id, rating);
         genrePointer[size] = new char[MAX];
         strcpy(genrePointer[size], "Comedy");
      }
      else if(toupper(genre) == 'D')
      {
         moviePointer[size] = new Drama(company, movie, id, rating);
         genrePointer[size] = new char[MAX];
         strcpy(genrePointer[size], "Drama");
      }
      else
         cout << "INVALID Genre" << endl;

      size++;
      getline(infile, temp);
   }
}  // readData function





void outputData(MoviePointerArray moviePointer, GenrePointerArray genrePointer, int size, int* days_late)
/**
   precondition: none

   postcondition: outputs the movie data in table format
**/
{
   cout << setw(20) << "COMPANY"
        << setw(15) << "ID"
        << setw(50) << "TITLE"
        << setw(15) << "MPAA(rating)"
        << setw(15) << "MOVIE TYPE"
        << setw(15) << "RENTAL FEE($)"
        << setw(15) << "LATE FEE($)"
        << setw(15) << "TOTAL COST($)"
        << endl
        << endl;

   for(int index = 0; index < size; index++)
   {
      cout << setw(20) << moviePointer[index] -> getCompany()
           << setw(15) << moviePointer[index] -> getId()
           << setw(50) << moviePointer[index] -> getMovie()
           << setw(15) << moviePointer[index] -> getRating()
           << setw(15) << genrePointer[index]
           << fixed << showpoint << setprecision(2)
           << setw(15) << moviePointer[index] -> calculateCharge()
           << setw(15) << moviePointer[index] -> calculateLateFee(days_late[index])
           << setw(15) << moviePointer[index] -> calculateCharge() + moviePointer[index] -> calculateLateFee(days_late[index])
           << endl;
   }  // end of for loop
   cout << endl;
}  // outputData function






void orderData(MoviePointerArray moviePointer, GenrePointerArray genrePointer, int size, int* days_late)
/**
   precondition: none

   postcondition: movies are sorted in descending order based on total cost
**/
{
   int lowest_index;
   int first;
   int index;
   double total_cost1;
   double total_cost2;

   Movie* movie_temp;
   char* char_temp;
   int int_temp;

   for(index = 0; index < size - 1; index++)
   {
      lowest_index = index;

      for(first = index + 1; first < size; first++)
      {
         total_cost1 = moviePointer[lowest_index] -> calculateCharge() + moviePointer[lowest_index] -> calculateLateFee(days_late[lowest_index]);
         total_cost2 = moviePointer[first] -> calculateCharge() + moviePointer[first] -> calculateLateFee(days_late[first]);

         if(total_cost1  < total_cost2)
            lowest_index = first;
      }

      movie_temp = moviePointer[index];
      moviePointer[index] = moviePointer[lowest_index];
      moviePointer[lowest_index] = movie_temp;

      char_temp = genrePointer[index];
      genrePointer[index] = genrePointer[lowest_index];
      genrePointer[lowest_index] = char_temp;

      int_temp = days_late[index];
      days_late[index] = days_late[lowest_index];
      days_late[lowest_index] = int_temp;
   }  // end of for loop; selection sort
}  // orderData function
