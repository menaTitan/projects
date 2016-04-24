using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstLesson
{
    class Program
    {
        static void Main(string[] args)
        {

            int num1 = 5;
            decimal price = 15.30m;
            string output = string.Format("The current price is {0:C} per ounce ", price);
            Console.WriteLine(output);
            Console.WriteLine("\a");
            Console.WriteLine(MathOperataions.Double(num1));
            /*----------------------------------------------------*/
            string name = "July Quarterly Report";
            string data = "July";
            string type = "Quarterly";

            Report obj = new Report (name, data, type);
            obj.print();
            obj.ReportType();
            Console.WriteLine(obj.CreateReport());
            obj.ReportCount(100);
        }
    }
    public static class MathOperataions
    {
        public static int Double (int number)
        {

            return number * 2;
            
         }
        public static int Triple(int number)
        {
            return number * 3;

        }

    }
   
}
