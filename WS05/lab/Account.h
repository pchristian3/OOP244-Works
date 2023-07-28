#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      operator bool() const;
      operator int() const;
      operator double() const;
     
      bool operator~() const;

      Account& operator=(const int account);
      Account& operator=(Account &another);


      Account& operator+=(const double moneyIn);
      Account& operator-=(const double withdraw);
      Account& operator<<(Account &leftSift);
      Account& operator>>(Account& rightSift);

      friend double operator+(const Account &left, const Account &right);
      friend double operator+=(double& left, const Account& right);

   };
   
   
}
#endif // SDDS_ACCOUNT_H_