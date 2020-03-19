/**
 * @file SummarizeGrades.cpp
 * @author minghao {NetID:mtang64}  {mtang64@wisc.edu}
 * @brief this is the function of the project
 * @version 0.1
 * @date 2020-03-15
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "SummarizeGrades.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>


/**
 * @brief read from inputFilePath and read all the data 
 * 
 * @param inputFilepath 
 * @param numberOfStudents 
 * @param numberOfAssignments 
 * @param studentNames 
 * @param studentScore 
 */

void readGradeFile(const string inputFilepath, int *numberOfStudents, int *numberOfAssignments, 
map<int, Name> &studentNames, map<int, vector <int> > &studentScore){

    Name temp_name;
    int score_temp [10];
    vector <int> socre_vec;

    fstream fp(inputFilepath,ios::in);

    if (!fp){
            std::cout << "Open file failed"<< std::endl; 
    } 

    string line;
    string words;

    getline(fp, line, '\n');
  //  cout << line<<endl;
    std::stringstream line_cin (line);
    if (words.compare("number_of_students"))
    {
    //    cout <<"right "<<endl;
       line_cin.ignore(19,' ');
       line_cin >> *numberOfStudents;
    //   cout << *numberOfStudents<<endl;
       line_cin.clear();
    }
    else return ;

    getline(fp, line, '\n');
   // cout << line << endl;
     line_cin.str (line);
    if (words.compare("number_of_assignments"))
    {
    //    cout << "right " << endl;
        line_cin.ignore(100, ' ');
        line_cin >> *numberOfAssignments;
   //     cout << *numberOfAssignments << endl;
        line_cin.clear();
    }
    else return ;

    getline(fp, line, '\n');
   // cout << line << endl;
    line_cin.str(line);
    int test_temp;
    int count_n=0;
    if (words.compare("student_number"))
    { 
        line_cin.ignore(30, ' ');
        line_cin.ignore(30, ' ');
        line_cin.ignore(30, ' ');
        while (line_cin >> test_temp){
        if(test_temp == 10)
            count_n++;
    
        }
    }
    else return ;

    line_cin.clear();
    
    while (!fp.eof()){
        getline(fp, line,'\n');
        line_cin.str(line);

        line_cin>>score_temp[0];
        line_cin>>temp_name.firstName >> temp_name.lastName;
        for (int i =0; i<count_n;i++){
            line_cin>>score_temp[i+1];
        }
       // socre_vec.swap(vector <int>());
       vector <int>().swap(socre_vec);
        studentNames.insert(pair<int, Name>(score_temp[0],temp_name));
        for (int i=0; i<count_n;i++){
            socre_vec.push_back(score_temp[i+1]);
        
        }
        studentScore.insert(pair<int, vector<int> >(score_temp[0], socre_vec));
    }
    

    fp.close();

}
/**
 * @brief convert all the name to the ideal sate (the first is uppare and with next lowers)
 * 
 * 
 * @param names 
 */
void formatCaseOfNames(map<int, Name> &names)
{
    map<int,Name> ::iterator iter;
    string::iterator sitr;
    iter = names.begin();

    for (iter = names.begin(); iter!= names.end(); iter++){
    int nsize = iter->second.firstName.size() ;
        for (int i=0; i<nsize;i++){
            if (i==0)
            iter->second.firstName[i] = toupper(iter->second.firstName[i]);
            else  
            iter->second.firstName[i] = tolower(iter->second.firstName[i]); 
        }

       // cout<<iter->second.firstName;
        int xsize = iter->second.lastName.size();
        for (int i = 0; i < xsize; i++)
        {
            if (i == 0)
                iter->second.lastName[i] = toupper(iter->second.lastName[i]);
            else

                iter->second.lastName[i] = tolower(iter->second.lastName[i]);
        }
      //  cout<<" "<<iter->second.firstName<<endl;
    }

}
/**
 * @brief compute the total and percent of all the scores
 * 
 * @param score 
 * @param total 
 * @param percent 
 */
void computeTotalAndPercent(map<int, vector<int> > &score, map<int, int>&total, map<int,float> &percent)
{

map<int, vector<int> >::iterator iter;
iter = score.begin();

int sum=0;
float average;

for (iter = score.begin(); iter!= score.end(); iter++){
    for (int i=0; i< iter->second.size();i++){
            sum+= iter->second[i];
           // cout << sum<< iter->second[i]<<endl;
    }
  //  sum = iter->second[0]+iter->second[1]+iter->second[2];
   total.insert(pair<int, int>(iter->first, sum));
   average = ((sum)/(10.0*iter->second.size()))*100.0;
  //cout << "average is "<< average<< "sum is " <<sum << endl; 
   percent.insert(pair<int, float>(iter->first, average));
   sum = 0;

}

}
/**
 * @brief out put the neecessary data to file,the path is 
 * 
 * @param outPutFilepath this is the putput file path
 * @param names 
 * @param total 
 * @param percent 
 */
void writeFormattedGrades(const string outPutFilepath, map<int, Name> &names, map<int, int> &total,
map<int, float> &percent)
{

    ofstream fw(outPutFilepath);

    map<int,Name> ::iterator iter;
    iter = names.begin();

    for (iter = names.begin(); iter!= names.end(); iter++){
 //   fw << iter->first<<setw(22) << ' ' << iter->second.firstName << endl;
 fw << iter->second.lastName
    << ", "
    << iter->second.firstName
    << setw(20 - iter->second.firstName.length() - iter->second.lastName.length())
    << total[iter->first]
    << setw(7)
    << fixed
    << setprecision(1)
    << percent[iter->first]
    << endl;
    }

fw.close();

}