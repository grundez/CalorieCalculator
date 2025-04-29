#include <QtTest>
#include "caloriecalculator.h"

class TestCalorieCalculator : public QObject
{
    Q_OBJECT

public:
    TestCalorieCalculator();
    ~TestCalorieCalculator();

private slots:
    void test_createInstance();
    void test_addFoodEntry();
};

TestCalorieCalculator::TestCalorieCalculator() {}
TestCalorieCalculator::~TestCalorieCalculator() {}

void TestCalorieCalculator::test_createInstance()
{
    CalorieCalculator calculator; // Пытаемся создать объект
}

void TestCalorieCalculator::test_addFoodEntry()
{
    CalorieCalculator calculator;
    calculator.addEntry("Яблоко", 50, EntryType::Food);
    calculator.addEntry("Бег", 100, EntryType::Activity);
}

QTEST_APPLESS_MAIN(TestCalorieCalculator)
#include "tst_testcaloriecalculator.moc"
