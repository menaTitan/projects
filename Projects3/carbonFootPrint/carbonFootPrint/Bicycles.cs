using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace carbonFootPrint
{
    class Bicycles:IcarbanFootPrint
    {
        public decimal CarbonAmount { set; get; } 
       public  Bicycles(decimal Carbon)
        {
            CarbonAmount = Carbon;
        }
        public void  carbonFootPrint() {

            Console.WriteLine("zer is the number");
        }
    }
}
