#include <iostream>
#include "include/graphics.h"
#include <conio.h>
#include <sstream>
#define BORDER__BG BLACK
using namespace std;

string toString(int num){
    stringstream string_stream;
    string_stream << num;
    string convertedString;
    string_stream >> convertedString;
    return convertedString;
}

main(){
    int result = 0;

    WINDOW:

    initwindow(400, 494, "Calculator - GUI");

    // to draw background
    int bgPoints[] = {0, 0, 400, 0, 400, 500, 0, 500};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillpoly(4, bgPoints);

    // to draw result background
    int reultBgPointsBorder[] = {15, 15, 385, 15, 385, 110, 15, 110};
    setcolor(BORDER__BG);
    setfillstyle(SOLID_FILL, BORDER__BG);
    fillpoly(4, reultBgPointsBorder);

    int reultBgPoints[] = {20, 20, 380, 20, 380, 105, 20, 105};
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillpoly(4, reultBgPoints);

    setcolor(GREEN);
    setbkcolor(WHITE);
    settextstyle(10, 0, 5);
    outtextxy(35, 44, &toString(result)[0]);


    // to draw options
    string options[] = {"1:  For Addition", "2:  For Subtraction", "3:  To Multiplication", "4:  For Division", "5:  For Modulus", "6:  For Raised-To-Power"};
    int optionsBgColors[] = {9, 10, 11, 12, 13, 14};
    for(int i = 0, height = 0, offset = 0 ; i < 6 ; i++){
        // for background
        int optionsBgPointsBorder[] = {15, 125 + height, 385, 125 + height, 385, 175 + height, 15, 175 + height};
        setcolor(BORDER__BG);
        setfillstyle(SOLID_FILL, BORDER__BG);
        fillpoly(4, optionsBgPointsBorder);

        int optionsBgPoints[] = {18, 128 + height, 382, 128 + height, 382, 172 + height, 18, 172 + height};
        setcolor(optionsBgColors[i]);
        setfillstyle(SOLID_FILL, optionsBgColors[i]);
        fillpoly(4, optionsBgPoints);

        // for options
        settextstyle(10, 0, 2);
        setcolor(BLACK);
        setbkcolor(optionsBgColors[i]);
        outtextxy(30, 140 + height, &options[i][0]);

        height += 60;
    }

    char option = getch();
    closegraph(CURRENT_WINDOW);

    // functioning block
    if(option == '1'){
        int num_1 = 0, num_2 = 0;
        cout << "Addition" << endl;
        cout << "  Number 01:\t";
        cin >> num_1;
        cout << "  Number 02:\t";
        cin >> num_2;
        result = num_1 + num_2;
    } else if(option == '2'){
        int num_1 = 0, num_2 = 0;
        cout << "Substraction" << endl;
        cout << "  Number 01:\t";
        cin >> num_1;
        cout << "  Number 02:\t";
        cin >> num_2;
        result = num_1 - num_2;
    } else if(option == '3'){
        int num_1 = 0, num_2 = 0;
        cout << "Multiplication" << endl;
        cout << "  Number 01:\t";
        cin >> num_1;
        cout << "  Number 02:\t";
        cin >> num_2;
        result = num_1 * num_2;
    } else if(option == '4'){
        int num_1 = 0, num_2 = 0;
        cout << "Division" << endl;
        cout << "  Number 01:\t";
        cin >> num_1;
        cout << "  Number 02:\t";
        cin >> num_2;
        result = num_1 / num_2;
    } else if(option == '5'){
        int num_1 = 0, num_2 = 0;
        cout << "Modulus" << endl;
        cout << "  Number 01:\t";
        cin >> num_1;
        cout << "  Number 02:\t";
        cin >> num_2;
        result = num_1 % num_2;
    } else if(option == '6'){
        int num_1 = 0, num_2 = 0;
        cout << "Raised-To-Power" << endl;
        cout << "  Number:\t";
        cin >> num_1;
        cout << "  Power:\t";
        cin >> num_2;
        result = num_1 * num_2;
    } else {
        result = 0;
        INVALID:
        cout << "Invalid Selection...!!!" << endl;
        cout << "Enter 0 to continue..." << endl;
        cout << "Enter x to exit..." << endl;
        char oo = ' ';
        cin >> oo;
        if(oo == '0'){
            goto CONTINUE;
        } else if (oo == 'x'){
            exit(0);
        } else {
            goto INVALID;
        }
    }

    CONTINUE:
    goto WINDOW;
}
