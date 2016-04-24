using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Display
    {

    }
}  
static void Main(string[] args)
        {

            Date holder;
            double year;
            double month;
            double day;

             year= Console.ReadLine("Enter the Year");
             month = Console.Read("Enter the month");
             day = Console.Read("Enter the day");

             holder.setMonth(month);
             holder.setYear(year);
             holder.setDay(day);
             holder.display();

        }
