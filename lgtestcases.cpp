#include <iostream>
#include <fstream>
using namespace std;

const int ROW = 52, COL = 7;

int main(){

    int data[ROW][COL] = {};
    int x, y;
    ifstream inputFile;
    inputFile.open("MegaMillions_2018_11_29.csv", ios::in);

    if (!inputFile.is_open()){
        cout << "File failed to open.  Exiting program...\n";
        exit(1);
    }else if (inputFile.is_open()){
        for (int i = 0; i < ROW; i++){//<---------ROWS
            for (int j = 0; j < COL; j++){//<-----COLS
                inputFile >> data[i][j];
                x = j;
            }
        y = i;
        }
    }
    inputFile.close();

    //Display contents of array
    for (int i = 0; i < ROW; i++){//<------------ROWS
        cout << "Numbers for week " << (i + 1) << " ";
        for (int j = 0; j < COL; j++){//<--------COLS
            cout << data[i][j] << " ";
            if (ROW / 7 == 0){
                cout << "\n";
            }
        }
        cout << "\n";
    }

    return 0;
}