//TODO - 1. break each action down into manageable function calls, then add to lottogen.h
//TODO - 2. add "other" code to lgGtk.cpp, as the main cpp file

/*=====================================================================================
@                                     LottoGen v1
@"LottoGen" is STRICTLY free and for entertainment purposes ONLY!  There is absolutely
@no guarantee and no one is responsible for anything whatsoever that may or may not
@come of using this code.  Compile and dream at your own risk.
@--------------------------------------------------------------------------------------
@LottoGen is a program that calculates "winning numbers" for whichever lottery data
@that YOU provide via a text file. 
@
@kilo.kilo.delta8@gmail.com
@======================================================================================*/
//begin you
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

//Constant integer values to array sizes based on 180 day draw (7x52 number table)
const int ROW = 52;
const int COL = 7;

//Feeble attempt at a pitiful TUI
void menu(string average, string common);


//no, begin you
int main(){

    //initialize fstream object
    ifstream data;
    //open the file with test data
    data.open("/home/kd8/cpp/LottoGen/testData.txt", ios::in);

    //init array
    int first[ROW][COL] = {};//[row][col]<----main 2d array
    int totals[COL] = {};//<------------------array to hold total/ROW of each column
    int arrayBig[ROW] = {};//<----------------array to hold one column at a time from first[]
    int arraySmall[COL] = {};//<--------------holds the tally of most common occurred number in a col
    int arraySmallTwo[COL] = {};//<-----------holds the most common number from each column
    
    //initialize BS/Junk variables<<-----Need to go through these and remove unused
    int x, y;//<----not sure what these are for?????
    int topCount=0, count, topElement;//variables for the most common element algorithm #89
    string commonNums = "", averageNums = "";//variables to print string in TUI #78, #113, #118
    char ans;

//==============================================================================================
    //Test for file open
    if (!data.is_open()){
        cout << "File failed to open.  Exiting program...\n";
        exit(1);
    }else if (data.is_open()){//<<------<<<<- Add file to 2D array
        for (int i = 0; i < ROW; i++){//<---------ROWS
            for (int j = 0; j < COL; j++){//<-----COLS
                data >> first[i][j];//<-----------add data to array
                x = j;//<-------------------------No clue what this is for<<<<<<<<......
            }
        y = i;//<---------------------------------No clue what this is for either<<<<<<.....
        }
        data.close();//<--------------------------close the data file object
    }

    //add and averages each column
    int j = 0, temp = 0;
    while (j < COL){//<-------------------go through each column
        for (int i = 0; i < ROW; i++){//<-go through each row down a column
            temp = temp + first[i][j];//<-add the contents
            totals[j] = (temp / ROW);//<--calc the average and store in totals[]
        }
        j++;//<---------------------------increment to next column
        temp = 0;//<----------------------reset the temporary variable
    }
    
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
   
    //add commonly drawn numbers to string variable
    for (int i = 0; i < COL; i++){
        averageNums = averageNums + (to_string(totals[i]) + " ");
    }
    //add common numbers to string variable for output
    for (int i = 0; i < COL; i++){
       commonNums = commonNums + (to_string(arraySmallTwo[i]) + " ");
    }

    //Display the menu
    menu(averageNums, commonNums);
    


    //So endeth thy joke
    return 0;
}


//###########FUNCTIONS###########FUNCTIONS################FUNCTIONS################
//Displays the main menu
void menu(string average, string common){
    cout << "\n";
    cout << "##############################################################################\n";
    cout << "|                                LottoGen v1.0                               |\n";
    cout << "==============================================================================\n";
    cout << "|                                                                            |\n";
    cout << "|                      Average of wins:  " << average << "" << "                |\n";
    cout << "|             Numbers most often drawn:  " << common << "" << "                 |\n";
    cout << "|                                                                            |\n";
    cout << "|                                                                            |\n";
    cout << "==============================================================================\n";
    cout << "                                                                    \n";
    cout << "\n";
}

