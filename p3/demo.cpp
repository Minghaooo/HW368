/**
 * @file demo.cpp
 * @author minghao {NetID:mtang64}  {mtang64@wisc.edu}
 * @brief the demo of project 3
 * @version 0.1
 * @date 2020-03-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "SummarizeGrades.h"

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;



map<int, Name> studentNames;
map<int, vector<int> > studentScore;
map<int, int> total;
map<int, float> percent;

/**
 * @brief call all the function once 
 * 
 * @return int 
 */
int main()
{
    int numberOfStudents;
    int numberOfAssignments;

    string inputFilepath = "unformatted_grades.txt";
    string outPutFilepath = "tmh_test.txt";
/**
 * @brief Construct a new read Grade File object
 * 
 */
    readGradeFile(inputFilepath, &numberOfStudents, &numberOfAssignments, studentNames, studentScore);

/**
 * @brief Construct a new format Case Of Names object
 * 
 */
    formatCaseOfNames(studentNames);

/**
 * @brief Construct a new compute Total And Percent object
 * 
 */
    computeTotalAndPercent(studentScore, total,percent);
/**
 * @brief Construct a new write Formatted Grades object
 * 
 */
    writeFormattedGrades(outPutFilepath, studentNames, total, percent);
}
