/**
 * @file SummarizeGrades.h
 * @author minghao {NetID:mtang64}  {mtang64@wisc.edu}
 * @brief 
 * @version 0.1
 * @date 2020-03-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <string>
#include <map>
#include <vector>
using namespace std;


//map< int, vector<int> >;
struct Name
{
   string firstName;
   string lastName;
};

/**
 * @brief 
 * 
 * @param inputFilepath 
 * @param numberOfStudents 
 * @param numberOfAssignments 
 * @param studentNames 
 * @param studentScore 
 */
void readGradeFile(const string inputFilepath, int *numberOfStudents, int *numberOfAssignments, map<int, Name> &studentNames, map<int, vector <int> > &studentScore);

/**
 * @brief change the format of students' names
 * 
 * @param names 
 */
void formatCaseOfNames(map<int, Name> &names);

/**
 * @brief compute average and total socre 
 * 
 * @param score 
 * @param total 
 * @param percent 
 */
void computeTotalAndPercent(map<int, vector<int> > &score, map<int, int>&total, map<int,float> &percent);

/**
 * @brief output the data to file
 * 
 * @param outPutFilepath 
 * @param names 
 * @param total 
 * @param percent 
 */
void writeFormattedGrades(const string outPutFilepath, map<int, Name> &names, map <int, int>& total,
map<int, float> &percent);

