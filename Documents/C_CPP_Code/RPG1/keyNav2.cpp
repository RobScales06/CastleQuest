#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int posPrint(string mapStr, int xPos, int yPos, int lwn, int xDim, int yDim){
	string scanLine;
    for(int i = 0; i < yDim; i++){
    scanLine = mapStr.substr(yPos+xPos+(lwn*i),xDim);   
	if(i == yDim/2){
		scanLine[scanLine.length()/2] = 'o';
	true;
	}
	cout << scanLine << "\n";
	}
    return 0;
}

int main()
{
//string mapStr = 
//"................................."
//"...|   |.................|   |..."
//"....| |___________________| |...."
//"...|                         |..."
//"...|          _____          |..."
//"...|,,.,,.,,.,|.|.|,.,,.,,.,,|..."
//"..............|~~~|.............."
//"..............|~~~|.............."
//"..............|~~~|.............."
//"..............|~~~|.............."
//"..............|~~~|.............."
//"..............|~~~|.............."
//"..............|~~~|.............."
//"..............|~~~|..............";

string s;
string sTotal;

ifstream in;
in.open("BigMap.txt");

while(!in.eof()) {
	getline(in, s);
	sTotal += s + "\n";
}

//cout << sTotal;

in.close();	

sTotal.erase(remove(sTotal.begin(), sTotal.end(), '\n'), sTotal.end());


string mapStr = sTotal;
int lwn = 101; //line width number (for line jumps)
int xPos = 0;
int yPos = 0;
int xDim = 30;
int yDim = 12;

cout << "[press a key to begin]";

	unsigned char a;
	while(1)
	{		
		//system("cls");
		a=getch();
		//for detect the function\arrow keys 
		//we must call the getch() again
		//testing if a is '0' or '0xE0'
		if (a==0 || a==0xE0) a=getch();
		
		if (a==27) //ESC for exit the 'while'
			break;
		else if (a==72){ //UP
            system("cls");
            yPos-=lwn;
    }
		else if (a==80){ //DOWN
            system("cls");
            yPos+=lwn;
    }
		else if (a==75){ //LEFT
            system("cls");
            xPos-=1;
    }
		else if (a==77){ //RIGHT
            system("cls");
            xPos+=1;		
        }
		//else
		//	printf("%d",(int) a);	

		if(xPos < 0)
			xPos = 0;
		if(yPos < 0)
			yPos = 0;
		if(xPos > lwn)
			xPos = lwn;
        posPrint(mapStr,xPos,yPos,lwn,xDim,yDim);
        cout << "(" << xPos << ", " << yPos/101 << ")\n";
        cout << "[press esc to exit]";
        if(yPos == 0 && xPos == 35){
            system(".\\game.exe");
            system(".\\congrats.exe");
            break;
            return 0;
        }
	}
	return 0;
}