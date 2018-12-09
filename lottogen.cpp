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

const int ROW = 52;
const int COL = 7;

char menu(string average, string common);
void displayNumbersRead(void);

//no, you
int main(){

    //init name for fstream
    ifstream data;
    //open the file with test data
    data.open("/home/kd8/cpp/LottoGen/testData.txt", ios::in);

    //init array
    int first[ROW][COL] = {};//[row][col]
    int totals[COL] = {};
    int arrayBig[ROW] = {};
    int arraySmall[COL] = {};
    int arraySmallTwo[COL] = {};
    
    //init BS/Junk variables
    int a, b, c, x, y, z, counter;
    int *p1, *p2;
    int topCount=0, count, topElement;
    string commonNums = "", averageNums = "";
    char ans;

//==============================================================================================
    //Test for file open
    if (!data.is_open()){
        cout << "File failed to open.  Exiting program...\n";
        exit(1);
    }else if (data.is_open()){//<<------<<<<- Add file to 2D array
        for (int i = 0; i < ROW; i++){//<---------ROWS
            for (int j = 0; j < COL; j++){//<-----COLS
                data >> first[i][j];
                x = j;
            }
        y = i;
        }
        data.close();
    }

    /*
    //Display contents of array
    for (int i = 0; i < ROW; i++){//<------------ROWS
        cout << "Numbers for week " << (i+1) << " ";
        for (int j = 0; j < COL; j++){//<--------COLS
            cout << first[i][j] << " ";
            if (ROW / 7 == 0){
                cout << "\n";
            }
        }
        cout << "\n";
    }*/

    //Outputs each column
    /*int l = 0;//counts the while loop(per each column)
    while (l < 7){
        for(int i=0; i<ROW; i++){    //This loops on the rows.
	    cout << first[i][l]  << "\n";//Prints column by column
	    }
        l++;

    }*/

    //add and averages each column
    int j = 0, temp = 0;
    while (j < COL){
        for (int i = 0; i < ROW; i++){
            temp = temp + first[i][j];
            totals[j] = (temp / ROW);
        }
        j++;
        temp = 0;
    }
    
    //add commonly drawn numbers to string variable
    for (int i = 0; i < COL; i++){
        averageNums = averageNums + (to_string(totals[i]) + " ");
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
   
   //add common numbers to string variable for output
   for (int i = 0; i < COL; i++){
       commonNums = commonNums + (to_string(arraySmallTwo[i]) + " ");
   }
//=============================================================================================<<
//<><><><><><><><><><><><->The above code, I am set on.  Don't delete above this<-><><><><><><><>
//=============================================================================================<<
  
//-------------------------loop the main menu/TUI-----------------------------------
    do{
        ans = menu(averageNums, commonNums);
        if (ans != 'Q'){
            ans = 'Q';
        }
    }while(ans != 'Q');
//==================================================================================

    cout << "\n";
    //So endeth thy joke
    

    return 0;
}

//###########FUNCTIONS###########FUNCTIONS################FUNCTIONS################
//Displays the main menu
char menu(string average, string common){
    char answer;
    cout << "##############################################################################\n";
    cout << "|                                LottoGen v1.0                               |\n";
    cout << "==============================================================================\n";
    cout << "|              Average of wins:  " << average << "" << "                        |\n";
    cout << "|     Numbers most often drawn:  " << common << "" << "                         |\n";
    cout << "|                                                                            |\n";
    cout << "|                                                                            |\n";
    cout << "==============================================================================\n";
    cout << "                                  Q to quit                                   \n";
    cin >> answer;
    return answer;
}

//Displays the numbers read into the 2d array
void displayNumbersRead(void){
    /*cout << "The past winning numbers loaded are: \n";
    for (int i = 0; i < ROW; i++){//<------------ROWS
        cout << "Numbers for week " << i << " ";
        for (int j = 0; j < COL; j++){//<--------COLS
            cout << first[i][j] << " ";
            if (ROW / 7 == 0){
                cout << "\n";
            }
        }
        cout << "\n";
    }*/
}