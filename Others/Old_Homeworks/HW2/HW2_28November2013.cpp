#include <stdio.h>
#include <stdlib.h>
#include "graphics2.h"
#include <time.h>

// Abstract base class
class GenericShape{

	public:
		int x,y;
		int color;
		int xvelocity,yvelocity;
		GenericShape(int x_in,int y_in,int col , int xvel, int yvel){x=x_in;y=y_in , color = col, xvelocity = xvel, yvelocity = yvel;}  // Constructor
		GenericShape();//default constructor
		virtual void draw() =0;// pure virtual function
};
GenericShape::GenericShape(){
	int a,b;
	a = -10;
	b = 10;
	x = 320;
	y = 240;
	srand(time(NULL));

	xvelocity = a+(rand()%(b-a+1));
	yvelocity = a+(rand()%(b-a+1));
	color = 1 +(rand()%(15));
};
//end of abstract class

// Line class//
class Line:public GenericShape{       
	protected:
		int x2,y2;             
	public:
		Line(int x_in,int y_in,int col,int xvel, int yvel ,int x2_in,int y2_in):GenericShape(x_in,y_in,col,xvel,yvel),
												  x2(x2_in),y2(y2_in)
	{ }
		void draw();      // virtual draw function
		Line();			  //default constructor
};
Line::Line(){
	int a,b;
	a = 50;
	b = 100;
	srand(time(NULL));

	x2 = a+(rand()%(b-a+1));
	y2 = a+(rand()%(b-a+1));
}
void Line::draw(){ 
	setcolor(color);
    setfillstyle(SOLID_FILL, BLUE);

	x+= xvelocity;
	x2 +=xvelocity;
	y += yvelocity;
	y2 += yvelocity;
	if((x > 640) || (x2 > 640)){
        xvelocity = xvelocity*-1;
    }
    if((x < 0) || (x2 < 0)){
        xvelocity = xvelocity*-1;
    }
	if((y > 480) || (y2 >480)){
		yvelocity = yvelocity*-1;
	}
	if((y < 0) || (y2 < 0)){
		yvelocity = yvelocity*-1;
	}
    line(x, y, x2,y2);
	floodfill(x, y, color);
} 
//end of line class//

//Rectangle class//
class Rectangle:public GenericShape{       
 protected:
  int x2,y2;
 public:
  Rectangle(int x_in,int y_in,int col,int xvel,int yvel,int x2_in,int y2_in):GenericShape(x_in,y_in,col,xvel,yvel),
	                                          x2(x2_in),y2(y2_in)
	{ }
	void draw();// virtual draw
	Rectangle();//default constructor
};
Rectangle::Rectangle(){
	int a,b;
	a = 50;
	b = 100;
	srand(time(NULL));

	x2 = a+(rand()%(b-a+1));
	y2 = a+(rand()%(b-a+1));
}
void Rectangle::draw(){ 
	setcolor(color);
	setfillstyle(SOLID_FILL,BLUE);

	x += xvelocity;
	y += yvelocity;
	x2 += xvelocity;
	y2 += yvelocity;

	if((x > 640) || (x2 > 640)){
        xvelocity = xvelocity*-1;
    }
    if((x < 0) || (x2 < 0)){
        xvelocity = xvelocity*-1;
    }
	if((y > 480) || (y2 >480)){
		yvelocity = yvelocity*-1;
	}
	if((y < 0) || (y2 < 0)){
		yvelocity = yvelocity*-1;
	}
	bar(x,y,x2,y2);
//	floodfill(x, y, color);
} 
//end of Rectangle class//

//Circle class
class Circle:public GenericShape{   
 protected:
	int radius;
 public:
	Circle(int x_cen,int y_cen,int col,int xvel, int yvel, int r):GenericShape(x_cen,y_cen,col,xvel,yvel),
										radius(r)
	{	}
	void draw();//virtual draw
	Circle();//default constructor
};
Circle::Circle(){
	int a,b;
	a = 20;
	b = 80;
	srand(time(NULL));

	radius = a+(rand()%(b-a+1));
};
void Circle::draw(){ 
	setcolor(color);
	setfillstyle(SOLID_FILL, BLUE);
	x += xvelocity;
	y += yvelocity;

	if((x+radius)>640){
		xvelocity = xvelocity * -1;
	}
	if((x-radius) < 0){
		xvelocity = xvelocity * -1;
	}
	if((y-radius) < 0){
		yvelocity = yvelocity * -1;
	}
	if((y+radius)>480){
		yvelocity = yvelocity * -1;
	}
	circle(x,y,radius);
	floodfill(x,y,color);
} 
//end of Circle Class//


//Triangle Class//
class Triangle:public GenericShape{      
	protected:
	int x2,y2,x3,y3;            
	public:
	Triangle(int x_in,int y_in,int col,int xvel,int yvel,int x2_in,int y2_in,int x3_in,int y3_in):GenericShape(x_in,y_in,col,xvel,yvel),
		x2(x2_in),y2(y2_in),x3(x3_in),y3(y3_in)
	{ }
	void draw();// virtual draw
	Triangle();//default constructor
};
Triangle::Triangle(){
	int a,b;
	a = 50;
	b = 100;
	srand(time(NULL));

	x2 = a+(rand()%(b-a+1));
	y2 = a+(rand()%(b-a+1));
	x3 = a+(rand()%(b-a+1));
	y3 = a+(rand()%(b-a+1));
}
void Triangle::draw(){ 
	int poly[8] = {x,y,x2,y2,x3,y3,x,y};
	setcolor(color);
	setfillstyle(SOLID_FILL,BLUE);

	x += xvelocity;
	y += yvelocity;
	x2 += xvelocity;
	y2 += yvelocity;
	x3 += xvelocity;
	y3 += yvelocity;


	if((x > 640) || (x2 > 640) || (x3 > 640)){
		xvelocity = xvelocity*-1;
	}
	if((x < 0) || (x2 < 0) || (x3 < 0)){
		xvelocity = xvelocity*-1;
	}
	if((y > 480) || (y2 >480) || (y3 > 480)){
		yvelocity = yvelocity*-1;
	}
	if((y < 0) || (y2 < 0) || (y3 < 0)){
		yvelocity = yvelocity*-1;
	}

	fillpoly(4,poly);
} 
//end of Triangle class//

int main()
{
	int GraphDriver=0,GraphMode=0,timer_count = 0,timer = 1,timer2 = 1,timer2_count = 0,keyboard;
	initgraph( &GraphDriver, &GraphMode, "", 640, 480 ); 
	Line line1(50,150,4,2,-3,180,60);
	Circle circle1(400,200,1,-3,6,50);
	Rectangle rectangle1(150,200,4,5,4,250,260);
	Triangle triangle1(100,150,2,4,4,200,150,175,80);
	Line line2;
	Circle circle2;
	Rectangle rectangle2;
	Triangle triangle2;

	setbkcolor(BLACK);
	while(true){
		cleardevice();
		while(!kbhit()){
			while(timer){
				line1.color = 4;
				circle1.color = 1;
				rectangle1.color = 4;
				triangle1.color = 2;

				cleardevice();
				line1.draw();
				circle1.draw();
				rectangle1.draw();
				triangle1.draw();
				delay(50);
				if(timer_count ==50){
					timer = 0;
					timer_count = 0;
				}
				timer_count++;
			}
	
				cleardevice();
				line1.color = BLACK;
				circle1.color = BLACK;
				rectangle1.color = BLACK;
				triangle1.color = BLACK;
				line1.draw();
				circle1.draw();
				rectangle1.draw();
				triangle1.draw();
				delay(300);
				timer = 1;
		}
		getch();
		while(timer2){
			cleardevice();
			line2.draw();
			rectangle2.draw();
			circle2.draw();
			triangle2.draw();
			delay(50);
			if(timer2_count == 50){
				timer2 = 0;
				timer2_count = 0;
			}
			timer2_count++;
		}
		timer2 = 1;
	}
	closegraph();
	return 0;
}