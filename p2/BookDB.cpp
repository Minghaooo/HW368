/**
 * @file BookDB.cpp
 * @author minghao {NetID:mtang64}  {mtang64@wisc.edu}
 * @brief the mainbody of the poj
 * @version 0.1
 * @date 2020-02-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "BookDB.h"
#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief add a new book 
 * 
 * @param bookID 
 * @param year 
 * @param rating 
 * @param db 
 * @return int 1 if fail, else 0
 */
int addBook(int bookID, int year, double rating, std::vector<Book> &db)
{
  for (auto &i : db)
  {
    if(i.ID == bookID )
    return 1;
  }
    Book harry;
    harry.ID = bookID;
    harry.year = year;
    harry.rating = rating;
    db.push_back(harry);
    return 0;
}

/**
 * @brief update an existing book's information
 * 
 * @param bookID 
 * @param year 
 * @param rating 
 * @param db 
 * @return int 1 if cannot find.
 */
int updateBook(int bookID, int year, double rating, std::vector<Book> &db){
  
  for (auto &i : db)
  {
    if (i.ID == bookID){
      i.year = year;
      i.rating = rating;
      return 0;
    }
  }
  return 1;
}

/**
 * @brief delete the book through the ID
 * 
 * @param bookID 
 * @param db 
 * @return int 1 if cannot find 
 */
int deleteBook(int bookID, std::vector<Book> &db)
{
  for (std::vector<Book>::iterator iter = db.begin(); iter != db.end();){
   if ((*iter).ID ==bookID ){
     db.erase(iter);
     return 0;
   }else
   {
     iter++;
   }  
  }
  return 1;
}
/**
 * @brief print the contect of the structure 
 * 
 * @param db 
 */
void print(const std::vector<Book> &db)
{

  for (auto &i : db){
    std::cout << i.ID << ", "<<i.year<<", "<<i.rating << std::endl;
    //std::cout << i.year << std::endl;
    //std::cout << i.rating << std::endl;
  }

}

/**
 * @brief return a pointer to a new vector with items matching the year
 * 
 * @param year 
 * @param db 
 * @return std::vector<Book>* 
 */
std::vector<Book> *findBooks(int year, const std::vector<Book> &db){

  static std::vector<Book> Booksaddr;
   std::vector<Book> *pointer = new std::vector<Book> ;
  Book harry;

  Booksaddr.clear();

  for (auto &i : db)
  {
    if (i.year == year ){
    
    harry.ID = i.ID;
    harry.year = i.year;
    harry.rating = i.rating;
    Booksaddr.push_back(harry);
    }

  }
  *pointer = Booksaddr;
return pointer;
}


/**
 * @brief  calculate the average rating
 * 
 * @param db 
 * @return double 
 */

double calculateAverageRating(const std::vector<Book> &db){
  int count = 0;
  double sum =0;

  if(db.empty()){
    return -1.0;
  }

  for (auto &i : db)
  {
    sum = sum + i.rating;
    count++;
  }

  return sum/count;
}
/**
 * @brief  sort with 3 methods.
 * 
 * @param db 
 * @param sortingMethod 
 * @return int 
 */

int sortDB(std::vector<Book> &db, int sortingMethod){

  if (sortingMethod ==1 ){
      std::sort(db.begin(), db.end(),increasingID);
      return 0;
  }
  else if (sortingMethod == 2){
    std::sort(db.begin(), db.end(), increasingID);
    std::sort(db.begin(), db.end(), increasingYear);
    return 0;
  }
  else if (sortingMethod == 3)
  {
    std::sort(db.begin(), db.end(), increasingID);
    std::sort(db.begin(), db.end(), increasingRating);
    return 0;
  }

  return 1;
}

/**
 * @brief compare the ID, used in the sort()
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool increasingID (Book a, Book b){

  return (a.ID < b.ID);
}

/**
 * @brief compare the year, uesd in sort
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */

bool increasingYear(Book a, Book b)
{

  return (a.year < b.year);
}

/**
 * @brief compare  the rating, used in sort
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool increasingRating(Book a, Book b)
{

  return (a.rating < b.rating);
}
