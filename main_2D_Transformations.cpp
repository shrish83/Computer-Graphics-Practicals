#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <bits/stdc++.h> 
using namespace std;

// Using macros to convert degree to radian 
// and call sin() and cos() as these functions 
// take input in radians 
#define SIN(x) sin((x * 3.14)/180) 
#define COS(x) cos((x * 3.14)/180)   

//Translation
void translate(int xt[], int yt[])
{
	int translate_factor[2];
	//Enter m and n translation factors; 0 as input for no translation
	cout<<" Enter m and n translation factors: \n";
	for(int i=0;i<2;i++)
	{
		cin>>translate_factor[i];
	}
	
	//Translation process
	for(int i=0;i<3;i++)
	{
		xt[i] += translate_factor[0];
		yt[i] += translate_factor[1];
	}
	
	setcolor(CYAN);
/*	//Triangle after translation
	line(xt[0],yt[0],xt[1],yt[1]);
	line(xt[1],yt[1],xt[2],yt[2]);
	line(xt[2],yt[2],xt[0],yt[0]);
*/	
}

void scale(int xt[], int yt[])
{
	int scale_choice;
	int xa, yd;
	int a,d;
	cout<<" Enter: \n";
	cout<<" 1. Along x component. \n";
	cout<<" 2. Along y component. \n";
	cout<<" 3. In both directions. \n";
	cin>>scale_choice;
	
	if(scale_choice == 1)
	{
		cout<<" Enter the scaling factor: \n";
		cin>>xa;
		for(int i=0;i<3;i++)
		{
			xt[i] *= xa; 
		}
	}
	else if(scale_choice == 2)
	{
		cout<<" Enter the scaling factor: \n";
		cin>>yd;
		for(int i=0;i<3;i++)
		{
			yt[i] *= yd; 
		}
	}
	else
	{
		cout<<" Enter the scaling factors along both the directions: \n";
		cin>>a>>d;
		for(int i=0;i<3;i++)
		{
			xt[i] *= a; 
			yt[i] *= d;
		}
	}
	
	for(int i=0;i<3;i++)
	{
		cout<<xt[i]<<", "<<yt[i]<<"\n";
	}
	
	setcolor(CYAN);
/*	//Triangle after scaling
	line(xt[0],yt[0],xt[1],yt[1]);
	line(xt[1],yt[1],xt[2],yt[2]);
	line(xt[2],yt[2],xt[0],yt[0]);
*/
}

void rotate(int xt[], int yt[])
{
	cout<<" Enter the angle theta: \n";
	int theta;
	cin>>theta;
	
	//To rotate about which pivot point whether origin or not
	cout<<" Enter x and y pivot points \n";
	int x_pivot, y_pivot;
	cin>>x_pivot>>y_pivot;
	
	//Rotation Process
	for(int i=0;i<3;i++)
	{
		// Shifting the pivot point to the origin 
        // and the given points accordingly 
        int x_shifted = xt[i] - x_pivot; 
        int y_shifted = yt[i] - y_pivot; 
       
	    // Calculating the rotated point co-ordinates 
        // and shifting it back 
        xt[i] = x_pivot + (x_shifted*COS(theta)  
                          - y_shifted*SIN(theta)); 
        yt[i] = y_pivot + (x_shifted*SIN(theta)  
                          + y_shifted*COS(theta)); 
	}
	
	for(int i=0;i<3;i++)
	{
		cout<<xt[i]<<", "<<yt[i]<<"\n";
	}
	
		setcolor(CYAN);
	/*//Triangle after rotation
	line(xt[0],yt[0],xt[1],yt[1]);
	line(xt[1],yt[1],xt[2],yt[2]);
	line(xt[2],yt[2],xt[0],yt[0]);
*/
}

void reflect(int xt[], int yt[])
{
	int reflect_choice;
	int temp=0;
	cout<<" Enter: \n";
	cout<<" 1. Y=0 \n";
	cout<<" 2. X=0 \n";
	cout<<" 3. Y=X \n";
	cout<<" 4. Y=-X \n";
	cin>>reflect_choice;
	
	if(reflect_choice == 1)
	{
		for(int i=0;i<3;i++)
		{
			yt[i] *= -1;
		}
	}
	else if(reflect_choice == 2)
	{
		for(int i=0;i<3;i++)
		{
			xt[i] *= -1;
		}
	}
	else if(reflect_choice == 3)
	{
		for(int i=0;i<3;i++)
		{
			swap(xt[i],yt[i]);
		}
	}
	else
	{
		for(int i=0;i<3;i++)
		{
			swap(xt[i],yt[i]);
		}
		for(int i=0;i<3;i++)
		{
			xt[i] *= -1;
			yt[i] *= -1;
		}
	}
	
	for(int i=0;i<3;i++)
	{
		cout<<xt[i]<<", "<<yt[i]<<"\n";
	}
	
		setcolor(CYAN);
	/*//Triangle after reflection
	line(xt[0],yt[0],xt[1],yt[1]);
	line(xt[1],yt[1],xt[2],yt[2]);
	line(xt[2],yt[2],xt[0],yt[0]);
	*/
}

//Driver Program
int main()
{
	int gd = DETECT, gm;
	//detectgraph(&gd, &gm); 
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    
	int x[3]; int y[3];
	char ch = 'y';
	int choice;
	
	cout<<" Enter x and y coordinates of a 2D triangle: "<<"\n";
	//Enter x and y coordinates of a 2D triangle
	for(int i = 0; i<3;i++)
	{
		cin>>x[i];
		cin>>y[i];
	}
	
/*	//Drawing original triangle
	line(x[0],y[0],x[1],y[1]);
	line(x[1],y[1],x[2],y[2]);
	line(x[2],y[2],x[0],y[0]);
*/	
	
	//Various transformations
	 while(ch=='y'|| ch=='Y')
	 {
	 	cout<<" Enter: \n";
	 	cout<<" 1. Translation \n";
	 	cout<<" 2. Scaling \n";
	 	cout<<" 3. Rotation \n";
	 	cout<<" 4. Reflection \n";
	 	cin>>choice;
	 	
	 	switch(choice)
		 {
		 	case 1:
		 		translate(x,y);
		 		break;
		 	case 2:
		 		scale(x,y);
		 		break;
		 	case 3:
		 		rotate(x,y);
		 		break;
		 	case 4:
		 		reflect(x,y);
		 		break;
		 	default:
		 		cout<<" Wrong choice! \n";
		 		break;
		 }
		cout<<"\n Do you want to continue? y/n? \n";
		cin>>ch;
	 }
	
	getch();
	
   return 0;
}
