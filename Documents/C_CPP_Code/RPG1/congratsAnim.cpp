#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h>
using namespace std;

int main(){
    int lwn = 23;
    int yDim = 10;
    int xDim = 0;
    int frameNo = 7;

    string s;
    string sTotal;

    ifstream in;
    in.open("Celebration.txt");

    while(!in.eof()) {
        getline(in, s);
        sTotal += s + "\n";
    }

    //cout << sTotal;

    in.close();	

    sTotal.erase(remove(sTotal.begin(), sTotal.end(), '\n'), sTotal.end());

    string mapStr = sTotal;

    //cout << mapStr;
    //while(true){
    for(int f = 0; f < frameNo; f++){
        system("cls");
        for(int i = 0; i < yDim; i++){
            cout << mapStr.substr((lwn*i)+(f*yDim*lwn),lwn); 
            cout << "\n";
        }
        //cout << "[Ctrl + C to exit]";
        Sleep(100);
    //}
    }
    Sleep(5000);
}