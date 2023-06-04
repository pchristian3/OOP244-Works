#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

    void Bill::setEmpty() 
    {
        m_title[0] = char(0);
        m_items = nullptr;
    }

    bool Bill::isValid() const 
    {
        bool ok = true;
        if (m_items != nullptr && m_title != nullptr && m_title[0] != '\0')
        {
            for (int i = 0; i < m_noOfItems; i++)
            {
                if (!m_items[i].isValid())
                {
                    ok = false;
                    return ok;
                }
            }
            return ok;
        }
        ok = false;
        return ok;
    }

    double Bill::totalTax()const 
    {
        double sum = 0.0;

        for (int i = 0; i < m_noOfItems; i++) {

            sum = sum + m_items[i].tax();
        }
        return sum;
    }

    double Bill::totalPrice()const 
    {
        double sum = 0.0;

        for (int i = 0; i < m_noOfItems; i++)
        {
            sum = sum + m_items[i].price();
        }
        return sum;
    }

    void Bill::Title()const 
    {
        cout << "+--------------------------------------+" << endl;

        if (isValid() == true)
        {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(36);
            cout << m_title;
            cout << " |" << endl;
            cout.unsetf(ios::left);

        }
        
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer() const
    {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid() == true)
        {
            cout << "|                Total Tax: ";
            cout.setf(ios::fixed);
            cout.precision(2);
            cout.setf(ios::right);
            cout.width(10);
            cout << totalTax();
            cout.unsetf(ios::right);
            cout << " |" << endl;

            cout << "|              Total Price: ";
            cout.setf(ios::fixed);
            cout.precision(2);
            cout.setf(ios::right);
            cout.width(10);
            cout << totalPrice();
            cout.unsetf(ios::right);
            cout << " |" << endl;

            cout << "|          Total After Tax: ";
            cout.setf(ios::fixed);
            cout.precision(2);
            cout.setf(ios::right);
            cout.width(10);
            cout << totalTax() + totalPrice();
            cout.unsetf(ios::right);
            cout << " |" << endl;

        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }

    void Bill::init(const char* title, int noOfItems)
    {
        
        if (noOfItems <= 0 || title[0] == '\0')
        {
            setEmpty();
        }
        else
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_title[36] = '\0';
            m_items = new Item[m_noOfItems];
            for (int i = 0; i < m_noOfItems; i++)
            {
                m_items[i].setEmpty();
            }
        }
    }
    bool Bill::add(const char* item_name, double price, bool taxed) 
    {
        bool ok = false;
        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            ok = true;
            return ok;
        }
        return ok;
    }
    void Bill::display() const 
    {
        Title();
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }
    void Bill::deallocate() 
    {
        delete[] m_items;
        m_items = nullptr;
    }
}
