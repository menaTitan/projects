using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CsharpTest
{
    class Program
    {
        static void Main(string[] args)

        {
            string name;
            Console.WriteLine("what is your name?");
            name = Console.ReadLine();
            Console.WriteLine("Hi {0} !!", name);
        }
    }
}
