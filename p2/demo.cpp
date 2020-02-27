/**
 * @file demo.cpp
 * @author minghao {NetID:mtang64}  {mtang64@wisc.edu}
 * @brief this is the test running demo of the project
 * @version 0.1
 * @date 2020-02-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>
#include "BookDB.h"
#include <string.h>
//using namespace std;
#include <vector>

std::vector<Book> shelf;
std::vector<Book> shelf_address;

/**
 * @brief the main funcion of 
 * 
 * @return int 
 */

int main()
{
  //double average_rating;
  char instruction;

  int argv0 = 0;
  int argv1 = 0;
  double argv2 = 0;
  int status = 1;

  std::vector<Book> *address;

  address = &shelf_address;

  //addBook(123, 1995, 22.2, shelf);

  do
  {
    std::cout << '>' << ' ';

    std::cin >> instruction;

    if (instruction == 'p')
    { // print

      if (shelf.empty())
      {
        //std::cout << calculateAverageRating(shelf) << std::endl;
        std::cout << "No entries" << std::endl;
      }
      else
        print(shelf);
    }

    else if (instruction == 'a')
    { //add

      std::cin >> argv0 >> argv1 >> argv2;

      if (addBook(argv0, argv1, argv2, shelf))
        std::cout << "Error processing command" << std::endl;
      else
        std::cout << "Book " << argv0 << " added" << std::endl;
    }

    else if (instruction == 'd')
    { //delete
      std::cin >> argv0;
      if (deleteBook(argv0, shelf))
        std::cout << "Error processing command" << std::endl;
      else
        std::cout << "Book " << argv0 << " removed" << std::endl;
    }

    else if (instruction == 'u')
    { //update
      std::cin >> argv0 >> argv1 >> argv2;
      if (updateBook(argv0, argv1, argv2, shelf))
        std::cout << "Error processing command" << std::endl;
      else
        std::cout << "Book " << argv0 << " updated" << std::endl;
    }

    else if (instruction == 'c')
    { // calculate the average
      if (shelf.empty())
      {
        std::cout << "Error processing command" << std::endl;
      }
      else
        std::cout << "Average rating = " << calculateAverageRating(shelf) << std::endl;
    }
    // else if (instruction == 'f');

    else if (instruction == 's')
    { //sort
      std::cin >> argv0;
      if (sortDB(shelf, argv0))
        std::cout << "Error processing command" << std::endl;
    }

    else if (instruction == 'q')
    { //quit
      status = 0;
      std::cout << "quit" << std::endl;
    }

    else if (instruction == 'f') //find books of the year
    {
      std::cin >> argv0;
      address = findBooks(argv0, shelf);

      if ((*address).empty())
      {
        std::cout << "No entries" << std::endl;
      }
      else
      {
        print((*address));
      }
    }

    else
    {
      std::cout << "Error processing command" << std::endl;
    }

  } while (status);
  return 0;
}
