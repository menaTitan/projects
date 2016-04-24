// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Quadrilateral {
protected :
	double side1, side2, side3, side4;
	
public:
	Quadrilateral(double s1, double s2, double s3, double s4){
		side1 = s1;
		side2 = s2;
		side3 = s3;
		side4 = s4;
	}
		void display(){
		
			cout << "Quadrilateral with  sides: " << side1 << " " << side2 << " " << side3 << " " << side4 << endl;

		
		}


};
class Trapezoid : public  Quadrilateral{
public:
	Trapezoid(double s1, double s2, double s3, double s4) :
		Quadrilateral(s1, s2, s3, s4){

	}
	
};
class Square : public Quadrilateral {
public:
	Square(double side) :
		Quadrilateral(side, side, side, side){}

};

int _tmain(int argc, _TCHAR* argv[])

{
	Trapezoid t1(3, 4, 5, 6);
	Square s1(4);
	t1.display();
	s1.display();
	return 0;
}

