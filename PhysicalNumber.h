#include <iostream>
#include "Unit.h"
using std::istream,std::ostream ; 


namespace ariel 
{
    class PhysicalNumber
    {

        public:
         Unit type ;
         double number ;
       
         //constructor
        PhysicalNumber(double number , Unit type) ;
         //copy consrtuctor
        PhysicalNumber(const PhysicalNumber& pn);

        //"+" onary
        const PhysicalNumber operator+() const;
        
        //"-" onary
        const PhysicalNumber operator-() const;
       
        // "+" operator
        PhysicalNumber operator+(const PhysicalNumber& num1 ) ;
        
        // "-" operator
        PhysicalNumber operator-(const PhysicalNumber& num1 ) ;

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
 
