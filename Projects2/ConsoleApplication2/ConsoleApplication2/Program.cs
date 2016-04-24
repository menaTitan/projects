using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {
        static void Main(string[] args)
        {
           

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
    }
}
