using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace leapYear
{
    class Program
    {
        static void Main(string[] args)
        {
            
            int  year;
            int  month;
            int day;
            //int Pause = 50000;
            string answer = null;
            


            do
            {
                Console.WriteLine("Enter the Year ");
                year = int.Parse(Console.ReadLine());
                Console.WriteLine("Enter the month ");
                month = int.Parse(Console.ReadLine());
                Console.WriteLine("Enter the day ");
                day = int.Parse(Console.ReadLine());

                Date01 local = new Date01(year, month, day);
                local.Display();
                //System.Threading.Thread.Sleep(Pause);
                Console.WriteLine("Input YES to check another YEAR");
               answer=Console.ReadLine();
            } while (answer == "yes");
        }
    }
}
