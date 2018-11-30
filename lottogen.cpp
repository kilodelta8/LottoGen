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
#include <fstream>
#include <vector>
#include <string>//<-----?????
using namespace std;

//no, you
int main(){

    //init name for fstream
    ifstream data;
    //init vector
    vector<int> first, second, third, fourth, fifth, power, plier;
    //init BS/Junk variables
    int tmp, temp1, temp2, counter;
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sumPow = 0, sumPLi = 0;
    int total1 = 0, total2 = 0, total3 = 0, total4 = 0, total5 = 0, totalPow = 0, totalPli = 0;




    //open the file with test data
    data.open("/home/kd8/cpp/LottoGen/testData.txt", ios::in);
    

    //Remove this, for dev purposes
    cout << "\n";


    //error check
    if (data.is_open()){
        cout << "Data file is open\n";
        //get the file count
        int line_count = 0;
        string line;/*
        while(getline(data, line)){
            cout << "Out from While loop: " << line << endl;
            line_count += line.length();
        }*/
        while(!data.eof())
        {
            getline(data,line);

                int numofChars = line.length();
                for (unsigned int n = 0; n<line.length();n++)
                { 
                if (line.at(n) == ' ')
                {
                numofChars--;
                }
                }
            line_count += numofChars;
        }
        cout << "Character spaces in file: " << line_count << "\n";

        
        //add data to each respective vector
        for (int i = 0; i < 14; i+=6){
            data >> tmp;
            first.push_back(tmp);
            sum1 += first[i];
        }
        for (int i = 1; i < 14; i+=6){
            data >> tmp;
            second.push_back(tmp);
            sum2 += second[i];
        }
    }
    else if (!(data.is_open())){
        cout << "ERROR opening file\n";
    }
    //get size of vector
    temp1 = first.size();

    /*
    //display vector contents
    for (vector<int>::iterator i = first.begin() ; i != first.end(); i++){
        cout << *i << "\n";
    }
    for (vector<int>::iterator i = second.begin() ; i != second.end(); i++){
        cout << *i << "\n";
    }*/
    //display the sum of first vector and average
    total1 = sum1 / temp1;
    total2 = sum2 / temp1;
    cout << "Sum: " << sum1 << " total " << total1 << "\n";
    cout << "Sum: " << sum2 << " total " << total2 << "\n";
    




    //Remove this, for dev purposes
    cout << "\n";



    //close the test data file
    data.close();

    //Clean up, Clean up
    first.clear();
    second.clear();
    third.clear();
    fourth.clear();
    fifth.clear();
    power.clear();
    plier.clear();
    //So endeth thy joke

    return 0;
}