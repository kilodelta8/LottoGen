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
#include <vector>
#include <string>//<-----?????
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
    int first[COL][ROW] = {};
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
        for (int i = 0; i < COL; i++){//<---------ROWS
            for (int j = 0; j < ROW; j++){//<-----COLS
                data >> first[i][j];
            }
        }
        //close the test data file
        data.close();
    }
    /*
    //Display contents of array
    for (int i = 0; i < COL; i++){//<------------ROWS
        for (int j = 0; j < ROW; j++){//<--------COLS
            cout << first[i][j] << " ";
        }
        cout << "\n";
    }*/
//=============================================================================================<<
//<><><><><><><><><><><><->The above code, I am set on.  Don't delete above this<-><><><><><><><>
//=============================================================================================<<

    //Sum each column and store in variable
    for(x = 0; x < COL; ++x){//<-------------------------------ROWS
        for(y = 0; y < ROW; ++y){//<---------------------------COLS
            totals[x] = totals[x] + first[x][y];
        }
    }
    //Display the sum of each COL
    for (int i = 0; i < COL; i ++){
        cout << "Column " << i << " total is: " << totals[i] << " \n";//<<------<<<<-Needs verified
    }
    //Display the average of each COL
    cout << "Winning numbers are:  ";
    for (int i = 0; i < COL; i ++){
        cout << (totals[i] / ROW) << "  ";//<<---------<<<<<- Something is off here
    }
    cout << "\n";
    //So endeth thy joke

    return 0;
}