#include <string>
using namespace std;

#ifndef LOTTOGEN_H
#define LOTTOGEN_H


const int ROW = 52;
const int COL = 7;

//string commonNums = "", averageNums = "";


//sets the averages of each column and stores totals in a different array
void setAverages(int (&first)[ROW][COL], int (&totals)[COL]);

//sets the most common occurrence
void mostCommonOccurrence(int (&arrayBig)[ROW], int (&first)[ROW][COL], int arraySmall[COL], int arraySmallTwo[COL]);

//sets winning/most often numbers globals in lgGtk.cpp
void setNumbersToGlobals(int (&totals)[COL], int (&arraySmallTwo)[COL], string (&averageNums), string (&commonNums));


#endif