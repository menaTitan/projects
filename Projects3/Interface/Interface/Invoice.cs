using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interface
{
    class Invoice:IPayable
    {
        private int quantity;
        private decimal price;

        public Invoice(string part, string desc, int qty, decimal price)
        {
            partNumber = part;
            partDescription = desc;
            Quantity = qty;
            Price = price;

        }
        public string partNumber { set; get; }
        public string partDescription { set; get; }

        public int Quantity
        {
            get
            {
                return quantity;
            }
            set
            {
                if (value >= 0)
                {

                    quantity = value;
                }
            }
        }
        public decimal Price
        {
            get
            {
                return price;
            }

            set
            {
                if (value >= 0)
                {
                    price = value;
                }
            }

        }

        public decimal GetPaymentAmount()
        {
            return (Quantity * Price);
        }
    }
}
