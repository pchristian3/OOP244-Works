#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_

namespace sdds {
    class Food {
        char foodName[31];
        int calorieNo;
        int timeConsumption;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int calories, int consumptionTime);
        void setCalories(int calories);
        void setTOC(int consumptionTime);
        void display()const;
        bool isValid()const;
        int getCalories();
    };
}

#endif // !SDDS_FOOD_H
