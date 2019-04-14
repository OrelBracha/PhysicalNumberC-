#include <iostream>
#include <string>
#include<stdexcept>
#include<exception>
#include "PhysicalNumber.h"
#include "Unit.h"


using namespace std;
using namespace ariel;
double unitsArr[] = {1,100,100000,1,60,3600,1,1000,1000000};

PhysicalNumber::PhysicalNumber(double num, Unit t)
{
    number = num;
    type = t;
}

PhysicalNumber::PhysicalNumber(const PhysicalNumber&  pn)
{
    this->number = pn.number ;
    this->type = pn.type ;

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
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& other)
{
    int groupTypeNum1 = (int)this->type/3 ;
    int groupTypeNum2 = (int)other.type/3 ;
    double conversion , ans ;
    if (groupTypeNum1 != groupTypeNum2)
        throw std::invalid_argument("ERROR : can't add two numbers with different types");

    conversion = (double) other.number * (unitsArr[(int)other.type] / unitsArr[(int)this->type]) ;
    ans = this->number + conversion ;

    return PhysicalNumber(ans , this->type);



    }

    // "-" operator
    PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& other)
    {
        int thisGroupType =  (int)this->type/3 ;
        int otherGroupType = (int)other.type/3 ;
        double conversion , ans ;

        if(thisGroupType != otherGroupType)
            throw std::invalid_argument("ERROR : can't decrement two numbers with different types") ;

        conversion = (double) other.number * (unitsArr[(int)other.type] / unitsArr[(int)this->type]) ;
        ans = this->number - conversion ;

        return PhysicalNumber(ans , this->type) ;
    }


    

    // "+=" operator
    PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& other)
    {
        PhysicalNumber copy(other);
        int thisGroupType = (int)this->type/3 ;
        int otherGroupType=(int)other.type/3 ;
        
        double conversion , ans ;
        if(thisGroupType != otherGroupType)
            throw std::invalid_argument("ERROR : can't decrement two numbers with different types") ;

            conversion = (double) other.number * (unitsArr[(int)other.type] / unitsArr[(int)this->type]) ;
        ans = this->number + conversion ;
        this->number = ans;
        return *this;

    }
    // "-=" operator
    PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other)
    {
        
        PhysicalNumber copy(other);
        int thisGroupType = (int)this->type/3 ;
        int otherGroupType = (int)other.type/3 ;
       double conversion , ans ;

        if(thisGroupType != otherGroupType)
            throw std::invalid_argument("ERROR : can't decrement two numbers with different types") ;
        conversion = (double) other.number * (unitsArr[(int)other.type] / unitsArr[(int)this->type]) ;
        ans = this->number + conversion ;
        this->number = ans;
        return *this;

    }
    // "=" operator
    PhysicalNumber& PhysicalNumber::operator=(const PhysicalNumber& other)
    {
        this->number = other.number ;
        this->type = other.type;
        return *this ;
    }

    // "==" operator
    const bool PhysicalNumber::operator==(const PhysicalNumber& num1)
    {

        double conversion;
        PhysicalNumber num3(num1);
        conversion = (double)(unitsArr[(int)num3.type]/unitsArr[(int)num1.type])*(num3.number);
        num3.number = num3.number*conversion;
        num3.type = num1.type;
        if(num1.number==num3.number)
            return true ;

        return false ;

    }
    // "!=" operator
    const bool PhysicalNumber::operator!=(const PhysicalNumber& num1)
    {
        double conversion;
        PhysicalNumber num3(num1);
        conversion = (double)(unitsArr[(int)num3.type]/unitsArr[(int)num1.type])*(num3.number);
        num3.number = num3.number*conversion;
        num3.type = num1.type;

        if(num1.number!=num3.number)
            return true ;

        return false ;

    }
    // ">=" operator
    const bool PhysicalNumber::operator>=(const PhysicalNumber& num1)
    {
        double conversion;
        PhysicalNumber num3(num1);
        conversion = (double)(unitsArr[(int)num3.type]/unitsArr[(int)num1.type])*(num3.number);
        num3.number = num3.number*conversion;
        num3.type = num1.type;

        if(num1.number>=num3.number)
            return true ;

        return false ;

    }

   
    // "<=" operator
    const bool PhysicalNumber::operator<=(const PhysicalNumber& num1)
    {
        double conversion;
        PhysicalNumber num3(num1);
        conversion = (double)(unitsArr[(int)num3.type]/unitsArr[(int)num1.type])*(num3.number);
        num3.number = num3.number*conversion;
        num3.type = num1.type;

        if(num1.number<=num3.number)
            return true ;

        return false ;


    }
    // ">" operator
    const bool PhysicalNumber::operator>(const PhysicalNumber& num1)
    {
        double conversion;
        PhysicalNumber num3(num1);
        conversion = (double)(unitsArr[(int)num3.type]/unitsArr[(int)num1.type])*(num3.number);
        num3.number = num3.number*conversion;
        num3.type = num1.type;

        if(num1.number>num3.number)
            return true ;

        return false ;


    }
    // "<" operator
    const bool PhysicalNumber::operator<(const PhysicalNumber& num1)
    {
        double conversion;
        PhysicalNumber num3(num1);
        conversion = (double)(unitsArr[(int)num3.type]/unitsArr[(int)num1.type])*(num3.number);
        num3.number = num3.number*conversion;
        num3.type = num1.type;

        if(num1.number<num3.number)
            return true ;

        return false ;

    }

    // "++" operator
    PhysicalNumber& PhysicalNumber::operator++()
    {
       ++this->number ;
       return *this ;

    }

    //"--"  operator
    PhysicalNumber& PhysicalNumber::operator--()
    {
        --this->number ;
        return *this ;

    }
    //"--"  operator
    PhysicalNumber& PhysicalNumber::operator--(int num)
    {
       PhysicalNumber pn(*this);
       this->number-- ;
       return pn  ;
    }
    // "++" operator
    PhysicalNumber& PhysicalNumber::operator++(int num)
    {
        PhysicalNumber pn(*this);
        this->number++           ;
        return pn   ;
    }

    //"<<" operator - output stream
    ostream& ariel::operator<<(ostream& os,const PhysicalNumber& pn)
    {
        string unitStr[9]={"cm" , "m" , "km" , "sec" , "min" , "hour" , "g" , "kg" , "ton"};

        return os<<pn.number << "[" << unitStr[(int)pn.type] << "]";
    }

    //">>" operator - input stream
    istream& ariel::operator>>(istream& is,PhysicalNumber& pn)
    {
        string str = "";
        is>>str;//25.2[kg]
        string unitStr[9]={"CM" , "M" , "KM" , "SEC" , "MIN" , "HOUR" , "G" , "KG" , "TON"};
        int find1=str.find('[');
        int find2 = str.find(']');
        bool ans=true; 
        string myUnit="";
        int checkUnit=0;
        double myValue=0;
        
        if(find1!=-1 && find2!=-1 && ans ) {
            myUnit = str.substr(find1 + 1, find2 - find1 - 1);

            for (int i = 0; i < 9; ++i) {
                if (myUnit == unitStr[i]) {
                    checkUnit = i;
                    ans = false;
                }
            }

            string value = str.substr(0, find1);

            if (!ans) {
                try {
                    myValue = stod(value);
                }
                catch (exception) {
                    auto error = is.rdstate();
                    return is;
                }

                pn.number = myValue;
                pn.type = (Unit)(stod(myUnit));
            } else {
                auto error = is.rdstate();
            }
        }
        else
        {
          auto error= is.rdstate();
        }
       
        return is;
    }


