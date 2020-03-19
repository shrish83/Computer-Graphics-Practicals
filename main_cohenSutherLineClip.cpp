#include<iostream>
#include<graphics.h>
#include<conio.h>

//defining region points
const int inside = 0;
const int left = 1;
const int right = 2;
const int bottom = 4;
const int top = 8;

//defining window region
const int xMin = 4;
const int xMax = 10;
const int yMin = 4;
const int yMax = 8;

//compute region codes for the line segment
int computeCode(double x, double y)
{
	int lineCode = inside;
	
	if(x < xMin)
	lineCode |= left;
	if(x > xMax)
	lineCode |= right;
	if(y < yMin)
	lineCode |= bottom;
	if(y > yMax)
	lineCode |= top;
	
	return lineCode;
} 

//Clipping Algorithm Function
void lineClipping(double x1,double y1, double x2, double y2)
{
	//computing codes for P1 and P2
	int codeP1 = computeCode(x1,y1);
	int codeP2 = computeCode(x2,y2);
	bool accept = false;
	
	int gd = DETECT,gm;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	
	while(true)
	{
		if((codeP1 == 0) & (codeP2 == 0))
		{
			//trivially accept the line segment as it is inside the window region
			accept = true;
			break;
		}
		else if(codeP1 & codeP2)
		{
			//reject the line segment as it is outside the window region
			break;
		}
		else
		{
			double x,y; //for intersection
			int codeOut;
			
			if(codeP1 !=0)
			codeOut = codeP1;
			else
			codeOut = codeP2;
			
			//intersection points
			if(codeOut & top)
			{
				x = x1 + (x2-x1)*(yMax-y1)/(y2 -y1);
				y = yMax;
			}
			if(codeOut & bottom)
			{
				x = x1 + (x2-x1)*(yMin-y1)/(y2 -y1);
				y = yMin;
			}
			if(codeOut &  right)
			{
				y = y1 + (y2-y1)*(xMax-x1)/(x2 -x1);
				x = xMax;
			}
			if(codeOut & left)
			{
				y = y1 + (y2-y1)*(xMin-x1)/(x2 -x1);
				x = xMin;
			}
			
			//replacing points outside the window by the intersection points
			if(codeOut = codeP1)
			{
				x1 = x; y1 = y;
				codeP1 = computeCode(x1,y1);
			}
			else
			{
				x2 = x; y2 = y;
				codeP1 = computeCode(x2,y2);
			}
		}
	}
	using namespace std;
	if(accept)
	{
		cout<<" Line Segment accepted from "<<x1<<" , "<<y1<<" to "<<x2<<" , "<<y2<<"\n";
	}
	else
	{
		cout<<" Line Rejected! "<<endl;
	}
}

int main()
{
	using namespace std;
	double x1, y1, x2, y2;
	//line segment 1 with P1(x1,y1) and P2(x2,y2)
	//P1(5,5) and P2(7,7)
	//P1(7,9) and P2(11,4)
	//P1(1,5) and P2(4,1)
	//P1(7.8,8) and P2(10,5.25)
	cout<<" Enter the start and end points of a line segment: "<<endl;
	cin>>x1>>y1>>x2>>y2;
	
	//passing points to accept,clip or reject
	lineClipping(x1,y1,x2,y2);
	
	getch();
	return 0;
}
