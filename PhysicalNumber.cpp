#include <iostream>
#include <string>
#include<stdexcept>
#include<exception>
#include "PhysicalNumber.h"
#include "Unit.h"

//The Implementation
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
 PhysicalNumber PhysicalNumber::operator+()const 
{
    return *this;
}

//"-" onary
PhysicalNumber PhysicalNumber::operator-() const 
{
    return PhysicalNumber(-1*(this->number),this->type);
}

// "+" operator
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& other)const 
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
    PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& other)const 
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
        PhysicalNumber copy(num1);
        int thisGroupType = (int)this->type/3 ;
        int otherGroupType = (int)num1.type/3 ;
       double ans ;

        if(thisGroupType != otherGroupType)
            throw std::invalid_argument("ERROR : can't decrement two numbers with different types") ;
        double conversion;
        PhysicalNumber num3(num1);
        conversion = (double)(unitsArr[(int)num3.type]/unitsArr[(int)this->type])*(num3.number);
        num3.number = conversion;
        num3.type = this->type;
        if(this->number==num3.number)
            return true ;

        return false ;

    }
    // "!=" operator
    const bool PhysicalNumber::operator!=(const PhysicalNumber& num1)
    {
        PhysicalNumber copy(num1);
        int thisGroupType = (int)this->type/3 ;
        int otherGroupType = (int)num1.type/3 ;
       double ans ;

        if(thisGroupType != otherGroupType)
            throw std::invalid_argument("ERROR : can't decrement two numbers with different types") ;
        double conversion;
        PhysicalNumber num3(num1);
        conversion = (double)(unitsArr[(int)num3.type]/unitsArr[(int)this->type])*(num3.number);
        num3.number = conversion;
        num3.type = this->type;
        if(this->number!=num3.number)
            return true ;

        return false ;

    }
    // ">=" operator
    const bool PhysicalNumber::operator>=(const PhysicalNumber& num1)
    {   
        PhysicalNumber copy(num1);
        int thisGroupType = (int)this->type/3 ;
        int otherGroupType = (int)num1.type/3 ;
       double ans ;

        if(thisGroupType != otherGroupType)
            throw std::invalid_argument("ERROR : can't decrement two numbers with different types") ;
        double conversion;
        PhysicalNumber num3(num1);
        conversion = (double)(unitsArr[(int)num3.type]/unitsArr[(int)this->type])*(num3.number);
        num3.number = conversion;
        num3.type = this->type;
        if(this->number>=num3.number)
            return true ;

        return false ;

    }

   
    // "<=" operator
    const bool PhysicalNumber::operator<=(const PhysicalNumber& num1)
    {
        PhysicalNumber copy(num1);
        int thisGroupType = (int)this->type/3 ;
        int otherGroupType = (int)num1.type/3 ;
        double ans ;

        if(thisGroupType != otherGroupType)
            throw std::invalid_argument("ERROR : can't decrement two numbers with different types") ;
        double conversion;
        PhysicalNumber num3(num1);
        conversion = (double)(unitsArr[(int)num3.type]/unitsArr[(int)this->type])*(num3.number);
        num3.number = conversion;
        num3.type = this->type;
        if(this->number<=num3.number)
            return true ;

        return false ;
    }
    // ">" operator
    const bool PhysicalNumber::operator>(const PhysicalNumber& num1)
    {
       PhysicalNumber copy(num1);
        int thisGroupType = (int)this->type/3 ;
        int otherGroupType = (int)num1.type/3 ;
       double ans ;

        if(thisGroupType != otherGroupType)
            throw std::invalid_argument("ERROR : can't decrement two numbers with different types") ;
        double conversion;
        PhysicalNumber num3(num1);
        conversion = (double)(unitsArr[(int)num3.type]/unitsArr[(int)this->type])*(num3.number);
        num3.number = conversion;
        num3.type = this->type;
        if(this->number>num3.number)
            return true ;

        return false ;


    }
    // "<" operator
    const bool PhysicalNumber::operator<(const PhysicalNumber& num1)
    {
        PhysicalNumber copy(num1);
        int thisGroupType = (int)this->type/3 ;
        int otherGroupType = (int)num1.type/3 ;
        double ans ;

        if(thisGroupType != otherGroupType)
            throw std::invalid_argument("ERROR : can't decrement two numbers with different types") ;
        double conversion;
        PhysicalNumber num3(num1);
        conversion = (double)(unitsArr[(int)num3.type]/unitsArr[(int)this->type])*(num3.number);
        num3.number = conversion;
        num3.type = this->type;
        if(this->number<num3.number)
            return true ;

        return false ;

    }

    // "++" operator
    PhysicalNumber& PhysicalNumber::operator++()
    {
       this->number=this->number+1 ;
       return *this ;

    }

    //"--"  operator
    PhysicalNumber& PhysicalNumber::operator--()
    {
        this->number=this->number-1 ;
        return *this ;

    }
    //"--"  operator
    PhysicalNumber& PhysicalNumber::operator--(int num)
    {
       PhysicalNumber pn(*this);
       operator--();
       return pn  ;
    }
    // "++" operator
    PhysicalNumber& PhysicalNumber::operator++(int num)
    {
        PhysicalNumber pn(*this);
        operator++();           ;
        return pn   ;
    }

    //"<<" operator - output stream
    ostream& ariel::operator<<(ostream& os,const PhysicalNumber& pn)
    {
        string unitStr[9]={"cm" , "m" , "km" , "sec" , "min" , "hour" , "g" , "kg" , "ton"};
        os.precision(11);
        return os<<pn.number << "[" << unitStr[(int)pn.type] << "]";
    }


    //">>" operator - input stream
  /*  std::istream& ariel::operator>>(istream& is,PhysicalNumber& pn)
    {
        string str = "";
        double number;
        is>>number>>str;//25.2[kg]
        string unitStr[9]={"cm" , "m" , "km" , "sec" , "min" , "hour" , "g" , "kg" , "ton"};
        int find1=str.find('[');
        int find2 = str.find(']');
        bool ans=true; 
        string myUnit="";
        int checkUnit=0;
        double myValue=0;
        
        if(find1!=-1 && find2!=-1 && ans ) {
            myUnit = str.substr(find1 +1, find2 - find1 - 1);

            for (int i = 0; i < 9; i++) {
                if (myUnit == unitStr[i]) {
                    checkUnit = i;
                    ans = false;
                }
            }

            //string value = str.substr(0, find1);//

            if (!ans) {
                try {
                   // myValue = stod(value);//
                }
                catch (exception) {
                    auto error = is.rdstate();
                    return is;
                }

               //
                pn.type = (Unit)(stod(myUnit));
            } else {
                auto error = is.rdstate();
            }
        }
        else
        {
          auto error= is.rdstate();
        }
        
        pn.number = number;
        return is;
    }
    */
   istream& ariel::operator>>(std::istream& is, PhysicalNumber& ps) {
    std::string in;
    is >> in;

    string temp[] = {"cm", "m", "km", "g", "kg", "ton", "sec", "min", "hour"};
    int first = in.find('[');
    int last = in.find(']');

    if(first == -1 || last == -1 || first > last){
        throw std::invalid_argument("error");
    }
    bool isOk = false;
    string value = in.substr(0, first);
    string unit = in.substr(first+1, last - first - 1 );
    double val = stod(value);
    for(int i=0; i<9; i++){
        if(unit == temp[i]){
            isOk = true;
            ps.number = val;
            switch (i)
            {
                case 0: ps.type = Unit::CM; break;
                case 1: ps.type = Unit::M; break;
                case 2: ps.type = Unit::KM; break;
                case 3: ps.type = Unit::G; break;
                case 4: ps.type = Unit::KG; break;
                case 5: ps.type = Unit::TON; break;
                case 6: ps.type = Unit::SEC; break;
                case 7: ps.type = Unit::MIN; break;
                case 8: ps.type = Unit::HOUR; break;
            
            }
        }
    }
    if(isOk == false)
       throw std::invalid_argument("error");
return is;
}

