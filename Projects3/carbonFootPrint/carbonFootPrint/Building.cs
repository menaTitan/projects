using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace carbonFootPrint
{
    class Building:IcarbanFootPrint
    {
        private int v;

        public int  sqft { set; get;}
        public Building(int Sqft)
        {

            sqft = Sqft;
        }

      

        public void  carbonFootPrint()
        {
            Console.WriteLine("carbon footprint for a building of {0} square feet is: {1}",sqft, sqft*134 );
        }
    }
}
