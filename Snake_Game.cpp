#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
using namespace std;
const int height=30;
const int width=70;
bool gameOver=false;
int x,y,eatx,eaty,score;
int ntail,tailX[100],tailY[100];
int flag;

void Setup()
{
	gameOver=false;
	x=width/2;
	y=height/2;
	eatx=rand()%width;
	eaty=rand()%height;
}

void Draw()
{
	system("CLS");
	cout<<"\n\t\t\t\t\t\t\t\t\t\t-----------------Welcome To Snake Game---------------\n";
	cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t-Created By Ayush\n";
	cout<<"\t\t\t\t\t\t\t\t\t";
	for(int i=0;i<width;i++)
	{
		cout<<"#";
	}
	cout<<"\n";
	
	for(int i=0;i<height;i++)
	{	cout<<"\t\t\t\t\t\t\t\t\t";
		for(int j=0;j<width;j++)
		{	
			if(j==0 || j==width-1)
			cout<<"#";
			else if(i==y && j==x)
			cout<<"O";
			else if(i==eaty && j==eatx)
			cout<<"*";
			else{
				bool print=false;
				for(int k=0;k<ntail;k++)
				{
					if(i==tailY[k] and j==tailX[k]){
					cout<<"o";
					print=true;
				}
			}
				if(!print)
				cout<<" ";
			}
			
		}
		cout<<"\n";
	}
	cout<<"\t\t\t\t\t\t\t\t\t";
	for(int i=0;i<width;i++)
	{
		cout<<"#";
	}
	cout<<"\n";
	cout<<"\n";
	cout<<"\t\t\t\t\t\t\t\t\tScore: "<<score<<endl;
	
}



void Input()
{   
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'w':
			flag=1;break;
			case 'a':
			flag=2;break;
			case 's':
			flag=3;break;
			case 'd':
			flag=4;break;
			default: break;
		}
	}
}

void Logic()
{
	
	int prevX,prevY,prev2X,prev2Y;
	prevX=tailX[0];
	prevY=tailY[0];
	tailX[0]=x;
	tailY[0]=y;
	
	for(int i=1;i<ntail;i++)
	{
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	
	switch(flag)
	{
		case 1:y--;break;
		case 3:y++;break;
		case 2:x--;break;
		case 4:x++;break;
		default:break;
	}
	if(x<0 || x>width ||y<0 || y>height)
	gameOver=true;
	
	for(int i=0;i<ntail;i++)
	{
		if(x==tailX[i] && y==tailY[i])
		gameOver=true;
	}
	
	if(x==eatx && y==eaty){
	score+=10;
	eatx=rand()%width;
	eaty=rand()%height;
	ntail++;
}
}

int main()
{
	Setup();
	while(!gameOver){
		Draw();
		Input();
		Logic();
		Sleep(50);
	}
	return 0;
}
