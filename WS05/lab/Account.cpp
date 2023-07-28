/*
Name : Prarthan Dhaval Christian
Id   : 175063213
Email: pchristian3@myseneca.ca
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;

namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   Account::operator bool() const
   {
       bool ok = false;

       if (m_number >= 10000 && m_number <= 99999 && m_balance >= 0.0)
       {
           ok = true;
       }
       return ok;
   }
 
   Account::operator int() const 
   {
       return m_number;
   }

   Account::operator double() const 
   {
       return m_balance;
   }

   bool Account::operator~() const
   {
       bool ok = false;
       if (m_number == 0) 
       {
           ok = true;
       }
       return ok;
   }


   Account& Account::operator=(const int account) 
   {
       if (m_number == 0)
       {
           m_number = account;
       }
       else if (account < 0)
       {
           setEmpty();
       }
       return *this;
   }

   Account& Account::operator=(Account &another) 
   {
       if (this->m_number == 0 && another.m_number > 0) 
       {
           this->m_number = another.m_number;
           this->m_balance = another.m_balance;

           another.m_number = 0;
           another.m_balance = 0;
       }
       return *this;
   }



   Account &Account::operator+=(const double moneyIn) 
   {
       if (m_number > 0 && m_balance >= 0.0 && moneyIn > 0.0)
       {
           m_balance += moneyIn;
       }
       return *this;
   }

   Account& Account::operator-=(const double withdraw) 
   {
       if (m_number > 0 && m_balance >= withdraw && withdraw >= 0.0)
       {
           m_balance -= withdraw;
       }
       return *this;
   }

   Account& Account::operator<<(Account &leftSift) 
   {
       if (this->m_number > 0 && leftSift.m_number > 0 && this->m_number != leftSift.m_number)
       {
           this->m_balance += leftSift.m_balance;
           leftSift.m_balance = 0;
       }
       return *this;
   }
    
   Account& Account::operator>>(Account &rightSift) 
   {
       if (this->m_number > 0 && rightSift.m_number > 0 && this->m_number != rightSift.m_number)
       {
           rightSift.m_balance += this->m_balance;
           this->m_balance = 0;
       }
       return *this;
   }

   double operator+(const Account& left, const Account& right) 
   {
       double total = 0;

       if (left.m_number > 0 && right.m_number > 0)
       {
           total = left.m_balance + right.m_balance;
       }

       else
       {
           total = 0;
       }
       return total;
   }

   double operator+=(double& left, const Account& right)
   {
       if (right.m_number > 0) 
       {
           left += right.m_balance;
       }
       return left;
   }

}