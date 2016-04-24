using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HardWareStore
{
    class Program
    {
        static void Main(string[] args)
        {

            Invoice invObj = new Invoice("1234", "Hammer", 2, 15.95m);
            Console.WriteLine("Qriginal invoice information");
            Console.WriteLine("Part Number: {0}",invObj.partNumber);
            Console.WriteLine("Description: {0}", invObj.partDescription);
            Console.WriteLine("Quantity: {0}", invObj.Quantity);
            Console.WriteLine("Price: {0:C}", invObj.Price);
            Console.WriteLine("Invoice {0:C}", invObj.getInvoiceAmount());
        }
    }
}
