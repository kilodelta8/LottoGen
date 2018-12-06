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
using namespace std;

const int ROW = 52;
const int COL = 7;

//no, you
int main(){

    //init name for fstream
    ifstream data;
    //open the file with test data
    data.open("/home/kd8/cpp/LottoGen/testData.txt", ios::in);

    //init array
    int first[ROW][COL] = {};//[row][col]
    int totals[COL] = {};
    
    //init BS/Junk variables
    int a, b, c, x, y, z, counter;
    int *p1, *p2;

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
        //cout << x << " " << y << " \n";//<---how may times i and j stack up
        //close the test data file
        data.close();
    }
    /*
    //Display contents of array
    for (int i = 0; i < ROW; i++){//<------------ROWS
        for (int j = 0; j < COL; j++){//<--------COLS
            cout << first[i][j] << " ";
        }
        cout << "\n";
    }*/
//=============================================================================================<<
//<><><><><><><><><><><><->The above code, I am set on.  Don't delete above this<-><><><><><><><>
//=============================================================================================<<
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

    //print averages in totals[]
    cout << "\n";
    cout << "Winning numbers based on the last 180 draws: ";
    for (int i = 0; i < COL; i++){
        cout << totals[i] << " ";
    }
    cout << "\n";
//=============================================================================================<<
//<><><><><><><><><><><><->The above code, I am set on.  Don't delete above this<-><><><><><><><>
//=============================================================================================<<
   
    //==================================================================================

    cout << "\n";
    //So endeth thy joke
    

    return 0;
}