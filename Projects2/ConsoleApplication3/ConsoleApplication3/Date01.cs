
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Date01
    {
      
       
       private  int Month
       {
           get
           {
               return this. Month;
           }
            set
           {
               Month = value;

           }
       }
       private int Day
       {
          get
            {
           return this. Day;
            
             }
            set
             {
                Day = value;
             }
       }

       private int Year
       {
           get
           {
               return this.Year;

           }

           set
           {
               Year = value;
           }
       
       }


       
       
       }  
    

       
    }


static bool Date.calcLeapYear()
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
