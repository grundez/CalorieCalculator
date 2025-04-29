#ifndef CALORIECALCULATOR_H
#define CALORIECALCULATOR_H
#include <QString>
#include <QMap>

enum class EntryType {
    Food,
    Activity
};

class CalorieCalculator
{
public:
    CalorieCalculator();
    void addEntry(const QString& name, int calories, EntryType type);
    int calculateTotal(EntryType type) const;
    bool removeEntry(const QString& name, EntryType type);
    QMap<QString, int> getEntries(EntryType type) const;
    int calculateCalorieBalance() const;

private:
    QMap<QString, int> foodEntries;      // Словарь для еды
    QMap<QString, int> activityEntries;  // Словарь для активности

};

#endif // CALORIECALCULATOR_H
