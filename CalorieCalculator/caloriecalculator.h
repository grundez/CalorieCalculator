#ifndef CALORIECALCULATOR_H
#define CALORIECALCULATOR_H
#include <QString>

enum class EntryType {
    Food,
    Activity
};

class CalorieCalculator
{
public:
    CalorieCalculator();
    void addEntry(const QString& name, int calories, EntryType type);
};

#endif // CALORIECALCULATOR_H
