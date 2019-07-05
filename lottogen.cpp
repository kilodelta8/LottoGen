#include "lottogen.h"
#include <string>
#include <iomanip>
#include <iostream>
using namespace std;

//string commonNums = "", averageNums = "";

//add and averages each column
void setAverages(int (&first)[ROW][COL], int (&totals)[COL]){
    int j = 0, temp = 0;
    while (j < COL){//<-------------------go through each column
        for (int i = 0; i < ROW; i++){//<-go through each row down a column
            temp = temp + first[i][j];//<-add the contents
            totals[j] = (temp / ROW);//<--calc the average and store in totals[]
        }
        j++;//<---------------------------increment to next column
        temp = 0;//<----------------------reset the temporary variable
    }
}


void mostCommonOccurrence(int (&arrayBig)[ROW], int (&first)[ROW][COL], int arraySmall[COL], int arraySmallTwo[COL]){
    int topCount=0, count, topElement;//variables for the most common element algorithm #89
//find the most common occurrence of each column
    //add data from 0th column to array[]
    int k = 0, tempOne = 0;
    while (k < COL){//starting at 0x0, 1x0, 2x0, 3x0, etc  (COL=7/ROW=52)
        for (int i = 0; i < ROW; ++i){//go down column k
            arrayBig[i] = first[i][k];//add column to arrayBig
        }
        //then, find the most common occurrence
        for (int g = 0; g < ROW; g++){
            count = 0;
            for (int v = 0; v < ROW; v++){
                if (arrayBig[g]==arrayBig[v]){ 
                    count++;
                }
            }
            if (count > topCount){
                topCount=count;
                topElement=arrayBig[g];
            }
        }
        //store the data elsewhere
        arraySmall[k] = topCount;
        arraySmallTwo[k] = topElement;
        //repeat for the last 6 columns
        k++;
        tempOne = 0;
        topCount = 0;
        topElement = 0;
    }
}


void setNumbersToGlobals(int (&totals)[COL], int (&arraySmallTwo)[COL], string (&averageNums), string (&commonNums)){
//add commonly drawn numbers to string variable
    for (int i = 0; i < COL; i++){
        averageNums = averageNums + (to_string(totals[i]) + " ");
    }
    //add common numbers to string variable for output
    for (int i = 0; i < COL; i++){
       commonNums = commonNums + (to_string(arraySmallTwo[i]) + " ");
    }
}