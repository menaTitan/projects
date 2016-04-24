using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace carbonFootPrint
{
    class Car : IcarbanFootPrint
    {
        public int numberGallons { set; get; }
       public  Car (int  numGal)
        {

            numberGallons = numGal;
        }
        const int pounds = 20;

        public void  carbonFootPrint()
        {
            decimal total = numberGallons * pounds;
            Console.WriteLine("carbon footprint for a car  of {0} Gallons is: {1}", numberGallons,total);
        }
    }
}
