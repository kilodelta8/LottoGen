#include <iostream>
#include <gtk/gtk.h>
#include "lgGtkFuncs.h"
#include "lottogen.h"

#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


string commonNums = "", averageNums = "";//variables to print string

/* Constant integer values to array sizes based on 180 day draw (7x52 number table)
const int ROW = 52;  DECLARED IN lottogen.h
const int COL = 7;*/


int main(int argc, char *argv[])
{
    //TODO - 1. Organzise code so it is manageable and easy to read
    //TODO - 2. Add code from lottogen.cpp (i.e. array inits, etc)
    //init gtk
    gtk_init(&argc, &argv);


    //-----------------------------------------------------------------
    //initialize fstream object
    ifstream data;

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

    //open the file with test data
    data.open("/home/kd8/cpp/LottoGen/resources/testData.txt", ios::in);
    //Test for file open
    if (!data.is_open())
    {
        cout << "File failed to open.  Exiting program...\n";  //TODO - 3. display in label without exit
        exit(1);
    }
    else if (data.is_open())//Add file to 2D array
    {
        for (int i = 0; i < ROW; i++)//<---------ROWS
        {
            for (int j = 0; j < COL; j++)//<-----COLS
            {
                data >> first[i][j];//add data to array
            }
        }
        data.close();//close the data file object
    }


    //-----------------------------------------------------------------create widgets
    //create the main window
    GtkWidget *mainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    //Create a button
	GtkWidget *btn = gtk_button_new_with_label("Show Numbers");

    //create a label and a vbox
	GtkWidget *lbl = gtk_label_new("Winning Numbers");

    //when X is clicked
	g_signal_connect(mainWindow, "delete_event", G_CALLBACK(end_program), NULL);



    //-----------------------------------------------------------place widgets
    //make a gtk vbox
	GtkWidget *box = gtk_vbox_new(FALSE, 5);

    //place the widgets into the box(es)
	gtk_box_pack_start(GTK_BOX(box), btn, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(box), lbl, TRUE, TRUE, 0);

	//add the box(es) to the main window
	gtk_container_add(GTK_CONTAINER(mainWindow), box);



    //-------------------------------------------------------------------main loop stuff
    //run and show the main window
    gtk_widget_show_all(mainWindow);

    //run the main window loop
    gtk_main();

    return 0;
}