#include<iostream>
#include<graphics.h>
#include<conio.h>
using namespace std;

//Use points 150,250 and r=70
void graphCircle(int x1,int x,int y1, int y)
{
	putpixel(x1+x,y1+y,RED);
	putpixel(x1+x,y1-y,RED);
	putpixel(x1-x,y1-y,RED);
	putpixel(x1-x,y1+y,RED);
	putpixel(x1+y,y1+x,RED);
	putpixel(x1+y,y1-x,RED);
	putpixel(x1-y,y1+x,RED);
	putpixel(x1-y,y1-x,RED);
}
void drawCircle(int x1, int y1, int radius)
{
	int x=0; int y=radius;
	int pi=0;

	//initial points
	cout<<" Initial points: "<<x<" , ";
	cout<<y<<endl;
	graphCircle(x1,x,y1,y);
	//decision parameter
	pi = (5/4) - radius;
	
	int gd = DETECT,gm;
	initgraph(&gd, &gm,"C:\\TC\\BGI");
	
	while(x<y)
	{
	if(pi >= 0)
	{
	    y--;
		pi = pi + (2*(x-y))+ 5;
	}
	else
	{
		pi = pi + (2*x) + 3;
	}
	x++;
	graphCircle(x1,x,y1,y);
	//printing points of 1st octant
	cout<<x<<" , "<<y<<endl;
}
}
int main()
{
	int r;
	cout<<" Enter the radius of the circle to be drawn ";
	cin>>r;
	
	int a,b;
	cout<<" Enter the center of the circle: ";
	cin>>a>>b;
	
	//Function to compute the points of a circle
	drawCircle(a,b,r);
	getch();
	return 0;
}

