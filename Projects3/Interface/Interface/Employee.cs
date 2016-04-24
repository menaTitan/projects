using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interface
{
    class  Employee:IPayable
    {

        protected string firstName{set;get;}
        protected string lastName { set; get;}
        protected string phoneNumber { set; get; }
        public Employee(string FirstName, string LastName, string PhoneNumber, decimal Salary)
        { 
            firstName = FirstName;
            lastName = LastName;
            phoneNumber = PhoneNumber;
            salary = Salary;
        }

        public decimal salary { set; get; }
        public decimal GetPaymentAmount()
        {

            return salary;
        }
        //public abstract void RunPayroll();
         
    }
}