using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstLesson
{
    class Report
    {
        private  string name;
        private string date;
        public Report( string name, string date, string type)
        {
            Name = name;
            Date = date;
            Type = type;
        }
        public string Name
        {
            get
            {
                return name;
        
            }
            set
            {
                name = value;
            }

        }
        public string Date
        {
            get
            {
                return date;
            }
            set
            {
                date = value;
            }

        }
        public string Type
        {
            get;
            set;
        }
        public void print() {

            Console.WriteLine("the Name is {0} , the date id {1} ,and the type is {2} ", Name, Date, Type );
        }
        public void ReportType()
        {

            Console.WriteLine("this is a {0} report",Type);
        }
        public string CreateReport()
        {
            return string.Format("I am creating the {0} report", Name);
        }
        public void ReportCount(int number)
        {
            Console.WriteLine("the are {0} lines in the report", number);

        }
    }
}
