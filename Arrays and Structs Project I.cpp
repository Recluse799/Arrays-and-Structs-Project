// 
/*  Immanuel Braxton
//  5//7/24
// Arrays and Structs Project I.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Function prototypes

////void calculateTotalsAndAverage(const string runners[], const double mil[][NUM_DAYS], int numRunners, int total[], double average[]);
//void outputResults(const string runners[], const int miles[][NUM_DAYS], int numRunners, const int total[], const double average[]);
//// Function prototypes
//Precondition - expects reference to names array and run time for each day, all are empty, has maxium capactiy of rows)
//Post conditon- return actual number of files, and store the data in the arrays in memory);;

*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;


const int MAXROWS = 50;// max rows, runners
const int NUM_DAYS = 8;  // times columns 
const string filename = "marathon_data.txt";  //File containing the marathon data
int getData(string names[], double mile[][NUM_DAYS], int MaxRows);

//Preconditon send names and data to caltotal avg
void calTotalAvg(double mile[][NUM_DAYS], int numRunners);

void outputResults(const string runners[], double mile[][NUM_DAYS], int numRunners);


int main() 
{
    
        string runners[MAXROWS];
        double Miles[MAXROWS][NUM_DAYS];
        int numRecords;
        

        numRecords = getData(runners, Miles, MAXROWS);

        cout << "numRecords = " << numRecords << endl;
        for (int i = 0; i < numRecords; i++)
        {
            cout << runners[i] << " ";
            for (int j = 0; j < NUM_DAYS; j++)
                cout << Miles[i][j] << " ";
            cout << endl;
        }
       
      
    return 0;
}



int getData(string names[], double mile[][NUM_DAYS], int MaxRows)
{
    ifstream inFile;
    int rows = 0;
    inFile.open(filename);
    if (!inFile.is_open())
    {
        cout << "Error opening file\n";
        return -1;
    }

    inFile >> names[rows];

    while (!inFile.eof() && !(rows >= MaxRows))
    {
        cout << rows << " " << names[rows] << " " << endl;

        for (int i = 0; i < NUM_DAYS - 1; i++)
        {
            inFile >> mile[rows][i];
            cout << mile[rows][i] << " ";
        }
        cout << endl;
        rows++;
        cout << "rows = " << rows;
        inFile >> names[rows];

    }
    inFile.close();
    return rows;
}



  void calTotalAvg(double mile[][NUM_DAYS], int numRunners) // int tot[], double avg[])
  { 
   
        double sum = 0;
       

        for (int i = 0; i < numRunners; i++)
        {
            sum = 0;
            for (int j = 0; j < NUM_DAYS - 1; j++)
            {
                sum += mile[i][j];
            }
            mile[i][NUM_DAYS - 1];

            mile[i][NUM_DAYS - 1] = sum / (NUM_DAYS - 1);


        }
  }

      void outputResults(const string runners[], double mile[][NUM_DAYS], int numRunners) // const int total[], const double average[]) 
      {
          double sum = 0;
          cout << setw(10) << "Name" << setw(6) << "Mon" << setw(6) << "Tue" << setw(6) << "Wed" << setw(6) << "Thu" << setw(6) << "Fri" << setw(6) << "Sat" << setw(6) << "Sun" << setw(12) << "Daily Avg" << endl;

               
               for (int i = 0; i < numRunners; ++i) 
               {
                   cout << setw(10) << runners[i];
                   sum = 0;
                   for (int j = 0; j < NUM_DAYS; ++j) 
                   {
                       cout << setw(6) << mile[i][j];
                   }   
                
                     cout << setw(10) << mile[i][NUM_DAYS - 1] << setw(12) << fixed << setprecision(2) << mile[i][NUM_DAYS - 1] << endl;
               }
      }