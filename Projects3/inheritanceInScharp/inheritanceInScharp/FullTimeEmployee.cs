using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace inheritanceInScharp
{
    class FullTimeEmployee:Employee
    {
        private decimal salaryRate;
        private int numberVacationDay;

        public FullTimeEmployee(string FirstName, string LastName, string PhoneNumber, decimal SalaryRate, int NumberVacationDay)
            : base(FirstName, LastName, PhoneNumber)
        {
            salaryRate = SalaryRate;
            numberVacationDay = NumberVacationDay;
        }
        public decimal SalaryRate {
            set
            {
                if (value > 0)
                {
                    salaryRate = value;
                }

            }
            get
            {

                return salaryRate;
            }
        }
        public int NumberVacationDay { set; get; }

        public override string ToString()
        {
            return (firstName + " " + lastName + "" + phoneNumber + " " + salaryRate + " " + numberVacationDay + " THIS IS FULL TIME EMPLOYEE");
        }

        public override void RunPayroll()
        {
            Console.WriteLine("This employee's salary is {0:C}",salaryRate);
        }
    }
}
