using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace inheritanceInScharp
{
    abstract class  Employee
    {

        protected string firstName{set;get;}
        protected string lastName { set; get;}
        protected string phoneNumber { set; get; }
        public Employee(string FirstName, string LastName, string PhoneNumber)
        { 
            firstName = FirstName;
            lastName = LastName;
            phoneNumber = PhoneNumber;
        }

        public abstract void RunPayroll();
         
    }
}