using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace inheritanceInScharp
{
    class Program
    {
        static void Main(string[] args)
        {
            //employee1
            string firstName = "John";
            string lastName = "Smith";
            string phone = "555-767-3456";
            decimal salary = 50000m;
            int vacationDays = 10;
            FullTimeEmployee FullEmObj = new FullTimeEmployee(firstName, lastName, phone, salary, vacationDays);
           
            //employee2
            string firstName2 = "Sara";
            string lastName2 = "Jones";
            string phone2 = "656-555-9999";
            decimal rate = 15.00m;
            PartTimeEmployee partEmObj = new PartTimeEmployee(firstName2, lastName2, phone2, rate);

            List<Employee> lists = new List<Employee>();
            lists.Add(FullEmObj);
            lists.Add(partEmObj);
            foreach (Employee emp in lists)
            {
                Console.WriteLine(emp.ToString());
                emp.RunPayroll();
            }
            
        }
    }
}
