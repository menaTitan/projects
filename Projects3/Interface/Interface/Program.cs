using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interface
{
    class Program
    {
        static void Main(string[] args)
        {
            IPayable[] payableObject = new IPayable[4];
            payableObject[0] = new Invoice("2222", "Nail", 10, 9.99m);
            payableObject[1] = new Invoice("4545", "ladder", 2, 29.99m);
            payableObject[2] = new Employee("Sara", "Jones", "555-555-5555", 45000m);
            payableObject[3] = new Employee("john", "Brown", "545-555-3456", 60000m);
            foreach (var currentPayable in payableObject)
            {
                Console.WriteLine("Payment due: {0:C} ",currentPayable.GetPaymentAmount());
            }
        }
    }
}
