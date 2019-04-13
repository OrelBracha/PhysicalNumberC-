#include <iostream>
#include <string>
#include "PhysicalNumber.h"
#include "Unit.h"

using namespace std;
using namespace ariel;

	//double number ;
        //Unit type ;
	PhysicalNumber::PhysicalNumber(double num, Unit t)
	{
		number = num;
		type = t;
	}

	//"+" onary
	const PhysicalNumber PhysicalNumber::operator+() const
	{
		return PhysicalNumber(0, Unit::KM);
	}

	//"-" onary
	const PhysicalNumber PhysicalNumber::operator-() const
	{
		return PhysicalNumber(0, Unit::KM);
	}

	// "+" operator
	PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& num)
	{
		int groupTypeNum1 = this->type/3 ;
		int groupTypeNum2 = num.type/3 ;

		if (groupTypeNum1 != groupTypeNum2)
		{
			throw std::invalid argument("ERROR : can't add two numbers with different types");
		}
                
                if(groupTypeNum1 == groupTypeNum2)
                {
                        return PhysicalNumber(this->number+num.number, this->type);
                }
                else
                {
                        if(groupTypeNum2 > groupTypeNum1)
                        {
                           if(groupTypeNum2 = 2 && groupTypeNum1 = 1)
                           return PhysicalNumber(num.number+(this.number/1000),num.type);
                           if(groupTypeNum2 = 2 && groupTypeNum1 = 0)
                           return PhysicalNumber(num.number+(this.number/100000),num.type);
                           if(groupTypeNum2 = 1 && groupTypeNum1 = 0)
                           return PhysicalNumber(num.number+(this.number/100),num.type);
                        }
                return PhysicalNumber(0, Unit::KM);
	}

	// "-" operator
	PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& num1)
	{
		return PhysicalNumber(0, Unit::KM);

	}

	// "+=" operator
	PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& size)
	{
		return *this;

	}
	// "-=" operator
	PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& size)
	{
		return *this;

	}
	// "=" operator
	PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& size)
	{
		return *this;

	}

	// "==" operator
	const bool PhysicalNumber::operator==(const PhysicalNumber& num1)
	{
		return false;

	}
	// "!=" operator
	const bool PhysicalNumber::operator!=(const PhysicalNumber& num1)
	{
		return false;

	}
	// ">=" operator
	const bool PhysicalNumber::operator>=(const PhysicalNumber& num1)
	{
		return false;

	}
	// "<=" operator
	const bool PhysicalNumber::operator<=(const PhysicalNumber& num1)
	{
		return false;

	}
	// ">" operator
	const bool PhysicalNumber::operator>(const PhysicalNumber& num1)
	{
		return false;

	}
	// "<" operator
	const bool PhysicalNumber::operator<(const PhysicalNumber& num1)
	{
		return false;

	}

	// "++" operator
	PhysicalNumber& PhysicalNumber::operator++()
	{
		return *this;

	}
	//"--"  operator
	PhysicalNumber& PhysicalNumber::operator--(int num)
	{
             --this->number;
             return *this;

	}
        // "++" operator
	PhysicalNumber& PhysicalNumber::operator++(int num)
	{
	     ++this->number;
             return *this;

	}
	//"--"  operator
	PhysicalNumber& PhysicalNumber::operator--()
	{
		return *this;

	}
	//"<<" operator - output stream
	ostream& ariel::operator<<(ostream& os,const PhysicalNumber& num)
	{
		return os;
	}

	//">>" operator - input stream
	istream& ariel::operator>>(istream& is,PhysicalNumber& num)
	{
		return is;

	}

   



