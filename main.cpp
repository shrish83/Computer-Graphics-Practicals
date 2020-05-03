#include<iostream>
#include<Windows.h>
#include<Math.h>
#include <graphics.h>
#include <conio.h>   
using namespace std;
class dda
{
	public:
int x, y;
void input_point()
{
	cout<<" Enter x coordinate: "<<endl;
	cin>>x;
	cout<<" Enter y coordinate: "<<endl;
	cin>>y;
}
void compute(dda d1, dda d2)
{
	int gd = DETECT, gm;      
	initgraph(&gd, &gm, "C:\\TC\\BGI");     
	int step;
	//calculate dx, dy
	int dx = d2.x - d1.x;
	int dy = d2.y - d1.y;
	
	if(abs(dx) >= abs(dy))
	 step = dx;
	 else
	 step = dy;
	 
	 float xinc = dx/step;
	 float yinc = dy/step;
	 
	 float a, b;
	 a = d1.x;
	 b = d1.y;
	 
	 for (int i = 0; i <= step; i++) 
    { 
        cout<<a<<" "<<b<<"\n";
        putpixel(a, b, RED); 
        a += xinc;            
        b += yinc;            
        Sleep(100);          
    } 
}
};
int main()
{
	dda d1,d2,d;
	cout<<" Enter the starting point: ";
	d1.input_point();
	cout<<" Enter the end point: ";
	d2.input_point();
	d.compute(d1, d2);
	getch(); 
}
