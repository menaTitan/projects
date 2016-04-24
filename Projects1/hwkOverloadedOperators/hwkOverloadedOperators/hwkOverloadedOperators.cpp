// Example of overloaded operator functions
// Original authors: Brenda Parker & Hyrum Carroll
// Extended by: Mena Sergeyous
#include <iostream>
#include<string>
using namespace std;

/* Class to represent a fraction (with it's numerator and denominator stored
 * separately) and corresponding operations on a fraction (e.g., adding another
 * fraction to this one, etc.).
 */
class Fraction{
private:
	int numerator;
	int denominator;
public:
	Fraction(){numerator=0; denominator=1;}
	Fraction (int nume, int demn){numerator=nume; denominator= demn;}
	int num() const { return numerator; }
    int den() const { return denominator; }
   
	Fraction operator++(int number);
	const Fraction operator++();
	
	
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs)
   {
     Fraction result(lhs.num() * rhs.den()
        + rhs.num() * lhs.den(),
         lhs.den() * rhs.den());
     
	 return result;
 }
Fraction operator-(const Fraction& lhs, const Fraction& rhs){

	Fraction result(lhs.num() * rhs.den()- rhs .num() * lhs.den(),
		lhs.den() * rhs.den());
	return  result;
}
Fraction Fraction ::  operator++ (int number){

	Fraction result (numerator , denominator);
	return result;


}
 

const Fraction Fraction :: operator++(){
	numerator+=denominator;
	return *this;
}

ostream& operator<<(std::ostream& out, const Fraction& f){
		return out << f.num() << '/' << f.den() ;
}

 istream& operator>>(istream& is, Fraction& rhs)
 {
    int num, den;
     // Read the top
     is >> num;
     // If there is a slash, read the next number
     char get;
     is >> get;
     if (get == '/')
        is  >> den;
     else
    {
        is.putback(get);
        den = 1;
     }
     rhs = Fraction(num, den);
     return is;
  }

 bool operator==(const Fraction& lhs, const Fraction& rhs) {
    
	 
	 return lhs.num() == rhs.num() && lhs.den() == rhs.den();
}


 bool operator>(const Fraction& lhs, const Fraction& rhs) {
    return lhs.num() > rhs.num() && lhs.den() > rhs.den();

 }

bool operator<(const Fraction& lhs, const Fraction& rhs) {
    
	return lhs.num() < rhs.num() && lhs.den() < rhs.den();
}


int main(){
	
    Fraction aFraction(2,3);
    Fraction bFraction(3,8);
    Fraction cFraction;

    cout << "aFraction: " << aFraction << endl;
    cout << "bFraction: " << bFraction << endl;
    
    cFraction = aFraction + bFraction;
    cout << aFraction << " + " << bFraction << " = " << cFraction << endl;
    
    cFraction = bFraction - aFraction;
    cout << bFraction << " - " << aFraction << " = " << cFraction << endl;
    
    cout << "++(" << aFraction << ") = ";
    cFraction = ++aFraction;
    cout << cFraction << endl;
   
    cout << "(" << bFraction << ")++ = ";
    cFraction = bFraction++;
    cout << cFraction << endl;
    
    cin >> aFraction;
    cout << "You entered: " << aFraction << endl;
    
    cin >> bFraction;
    cout << "You entered: " << bFraction << endl;
    
    if( aFraction == bFraction){
        cout <<"The fractions are equal\n";
		
    }else{
        if( aFraction > bFraction){
            cout << aFraction << " is larger than " << bFraction << endl;
        }else if( aFraction < bFraction){
            cout << aFraction << " is smaller than " << bFraction << endl;
        }else{
            cout << "ERROR: " << aFraction << " is not ==, > nor < than " << bFraction << endl;
        }
    }
    return 0;
}

