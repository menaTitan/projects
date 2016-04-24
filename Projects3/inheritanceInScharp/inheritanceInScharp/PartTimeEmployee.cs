using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace inheritanceInScharp
{
    class PartTimeEmployee:Employee
    {
        private decimal harlyRate;

       public PartTimeEmployee(string ftName, string lName,string phone, decimal HarlyRate)
            :base(ftName, lName,phone)
            {
            harlyRate = HarlyRate;
            }

        public decimal HarlyRate {

            set
            {
                if (value > 0)
                {
                    harlyRate = value;
                }

            }
            get
            {
                return harlyRate;
            }


        }

        public override string ToString()
        {
            return(firstName+ " "+ lastName+" "+phoneNumber+" "+HarlyRate+"THIS IS PART TIME EMPLOYEE ");
            
        }
        public override void RunPayroll() {
            Console.WriteLine("This employee's gets {0:C} per hour", harlyRate);
        }
    }
}
