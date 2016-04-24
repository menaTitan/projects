using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace carbonFootPrint
{
    class Program
    {
        static void Main(string[] args)
        {
            IcarbanFootPrint [] objct = new IcarbanFootPrint[3];
           
            objct[0] = new Car(15);
            objct[1] = new Building(2500);
            objct[2] = new Bicycles(0);
            foreach(var items in objct)
            {
                items.carbonFootPrint();

            }

        }
    }
}
