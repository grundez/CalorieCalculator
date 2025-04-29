#include "caloriecalculator.h"

CalorieCalculator::CalorieCalculator()
{

}

void CalorieCalculator::addEntry(const QString& name, int calories, EntryType type)
{
    if (type == EntryType::Food) {
        // еда
        if (foodEntries.contains(name)) {
            foodEntries[name] += calories; // если еда уже есть, суммируем калории
        } else {
            foodEntries.insert(name, calories); // если еды нет, добавляем новый элемент
        }
    } else {
        // активность
        if (activityEntries.contains(name)) {
            activityEntries[name] += calories; // если активность уже есть, суммируем калории
        } else {
            activityEntries.insert(name, calories); // если активности нет, добавляем новый элемент
        }
    }
}

int CalorieCalculator::calculateTotal(EntryType type) const
{
    int totalCalories = 0;
    if (type == EntryType::Food) {
        // Суммируем калории из еды
        for (auto it = foodEntries.begin(); it != foodEntries.end(); ++it) {
            totalCalories += it.value();
        }
    } else {
        // Суммируем калории из активности
        for (auto it = activityEntries.begin(); it != activityEntries.end(); ++it) {
            totalCalories += it.value();
        }
    }
    return totalCalories;
}
