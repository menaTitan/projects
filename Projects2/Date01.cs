using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace leapYear
{

    class Date01
    {
        public Date01(int year, int month, int day)
        {
            Year = year;
            Day = day;
            Month = month;
        }

        private int year;
        private int month;
        private int day;

        public int Month
        {
            get
            {
                return this.month;
            }
            set
            {
                month = value;

            }
        }
        public  int Day
        {
            get
            {
                return this.day;

            }
            set
            {
                day = value;
            }
        }

        public int Year
        {
            get
            {
                return this.year;

            }

            set
            {
                year = value;
            }

        }





        public bool calcLeapYear()
        {

            bool isLeapYear;

            if (Year % 400 == 0)
            {
                isLeapYear = true;
            }
            else if (Year % 100 == 0)
            {
                isLeapYear = false;
            }

            else if (Year % 4 == 0)
            {
                isLeapYear = true;
            }
            else
            {
                isLeapYear = false;

            }
            return isLeapYear;
        }
        public void Display()
        {
            Console.WriteLine("          ");

            Console.WriteLine("Month is : " + Month);
            Console.WriteLine("Day is    : " + Day);
            Console.WriteLine("Year is    :" + Year);
            if (calcLeapYear() == true)
            {
                Console.WriteLine(Year + " This is Leap Year");
            }
            else
            {
                Console.WriteLine(Year + "this is not Leap Year");
            }

        }
    }
}


    
/*
bool Date.calcLeapYear()

{
    bool isLeapYear;
   
   if(getYear() % 400 == 0 ) 
   {
       isLeapYear = true;
   }
   else if( getYear() % 100 == 0) 
   { 
  		isLeapYear= false;
   } 
  
  else if ( getYear() %4==0) 
   {
 	isLeapYear=true;
   }
else 
   { 
	isLeapYear=false;

   }
     return isLeapYear;
} 

void Dispplay(){
             Console.WriteLine("          ");

            Console.WriteLine("Month is : " + getMonth());
            Console.WriteLine("Day is    : " + getDay());
            Console.WriteLine("Year is    :" + getYear());
            if (calcLeapYear() == true)
            {
                Console.WriteLine(getYear() + " This is Leap Year");
            }
            else
            {
                Console.WriteLine(getYear() + "this is not Leap Year");
            }

 }
 
 
*/
 





       
      