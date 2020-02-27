/**
 * @file BookDB.h
 * @author minghao {NetID:mtang64}  {mtang64@wisc.edu}
 * @brief define the functions here
 * @version 0.1
 * @date 2020-02-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef BOOKDB_H
#define BOOKDB_H

#include <string>
#include <vector>

/**
 * struct of Book 
 * 
 */
struct Book
{
    int ID;
    int year;
    double rating;
};
/**
 * @brief add new item
 * 
 * @param bookID 
 * @param year 
 * @param rating 
 * @param shelf 
 * @return int 
 */
int addBook(int bookID, int year, double rating, std::vector<Book> &shelf );

/**
 * @brief update existing information
 * 
 * @param bookID 
 * @param year 
 * @param rating 
 * @param db 
 * @return int 
 */
int updateBook(int bookID, int year, double rating, std::vector<Book> &db);
/**
 * @brief delete an existing item
 * 
 * @param bookID 
 * @param db 
 * @return int 
 */
int deleteBook(int bookID, std::vector<Book> &db);
/**
 * @brief print all the items
 * 
 * @param db 
 */
void print(const std::vector<Book> &db);
/**
 * @brief return a pointer of Books published in the year.
 * 
 * @param year 
 * @param db 
 * @return std::vector<Book>* 
 */
std::vector<Book>* findBooks(int year, const std::vector<Book> &db);
/**
 * @brief calculate the rating
 * 
 * @param db 
 * @return double 
 */
double calculateAverageRating(const std::vector<Book> &db);
/**
 * @brief sort
 * 
 * @param db 
 * @param sortingMethod 
 * @return int 
 */
int sortDB(std::vector<Book> &db, int sortingMethod);
/**
 * @brief used in sort
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool increasingID(Book a, Book b);
/**
 * @brief used in sort
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool increasingYear(Book a, Book b);
/**
 * @brief used in sort
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool increasingRating(Book a, Book b);
#endif 