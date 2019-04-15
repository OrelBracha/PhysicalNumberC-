#include <iostream>
#include "Unit.h"
using std::istream,std::ostream ; 


namespace ariel 
{
    class PhysicalNumber
    {

    
         Unit type ;
         double number ;
       

    public:

        PhysicalNumber()=default ;

         //constructor
        PhysicalNumber(double, Unit) ;
         //copy consrtuctor
        PhysicalNumber(const PhysicalNumber& pn);

        //"+" onary
         PhysicalNumber operator+() const;
        
        //"-" onary
         PhysicalNumber operator-() const;
       
        // "+" operator
        PhysicalNumber operator+(const PhysicalNumber& num1 ) const ;
        
        // "-" operator
        PhysicalNumber operator-(const PhysicalNumber& num1 ) const;

        // "+=" operator
        PhysicalNumber& operator+=(const PhysicalNumber& size) ;
        // "-=" operator
        PhysicalNumber& operator-=(const PhysicalNumber& size) ;
        // "=" operator
        PhysicalNumber& operator=(const PhysicalNumber& size) ;

        // "==" operator
         const bool operator==(const PhysicalNumber& num1)  ;
        // "!=" operator
         const bool operator!=(const PhysicalNumber& num1) ;
        // ">=" operator
         const bool operator>=(const PhysicalNumber& num1)  ;
        // "<=" operator
         const bool operator<=(const PhysicalNumber& num1)  ;
        // ">" operator
         const bool operator>( const PhysicalNumber& num1)  ;
        // "<" operator
         const bool operator<( const PhysicalNumber& num1)  ;
        
        // "++" operator
        PhysicalNumber& operator++();
        //"--"  operator
        PhysicalNumber& operator--();
        PhysicalNumber& operator--(int num);
        PhysicalNumber& operator++(int num);
        //"<<" operator - output
         friend ostream& operator<<(ostream &os, const PhysicalNumber& num);

        //">>" operator - input
         friend istream& operator>>(istream &is, PhysicalNumber& num);
    };

    ostream& operator<<(ostream &os, const PhysicalNumber& num);
    istream& operator>>(istream &is, PhysicalNumber& num);

}
 
