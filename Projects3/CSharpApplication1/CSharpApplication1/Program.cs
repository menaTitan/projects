using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace test
{
    class Program
    {
        static void Main(string[] args)
        {
            decimal total = 0;
            string numMinutes;
            decimal Minutes = 0;
            bool flag = true;
            while (flag)
            {
                // promt the user for minutes execised
                Console.Write("Enter the number of minutes execised or type  'Quit' to  exit :");
                numMinutes = Console.ReadLine();
          
                if (numMinutes.ToLower() == "quit")
                {
                    flag = false;
                }
                else
                {
                    try
                    {
                        Minutes = decimal.Parse(numMinutes);
                    }
                    catch (Exception)
                    {

                        Console.WriteLine(numMinutes +" is  not accesptable vale");
                        continue;
                    }
                   
                    if (Minutes <= 0)
                    {
                        Console.WriteLine(numMinutes + " is not accesptable value");
                        continue;
                    }
                    else if (Minutes <= 10)
                        Console.WriteLine("Better than nothing am i right");
                    else if (Minutes <= 30)
                        Console.WriteLine("Way to go, hot stuff");
                    else if (Minutes <= 60)
                        Console.WriteLine("You Must be a Nijnja Warrior in training");
                    else
                        Console.WriteLine("OKEY NOW YOU ARE JUST SHOWING OFF");

                    total += Minutes;
                    Console.WriteLine(" the total  of the minutes is " + total + "\n");
                    
                }
            }
            // add minutes exercised to total
            // display total minutes exercised to  the screen

        }
    }
}