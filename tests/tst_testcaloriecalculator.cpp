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
    void test_addDuplicateEntry();
    void test_removeEntry();
    void test_getEntries();
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

void TestCalorieCalculator::test_addDuplicateEntry()
{
    CalorieCalculator calculator;

    calculator.addEntry("Яблоко", 100, EntryType::Food);
    calculator.addEntry("Яблоко", 200, EntryType::Food);

    calculator.addEntry("Бег", 100, EntryType::Activity);
    calculator.addEntry("Бег", 200, EntryType::Activity);

    QCOMPARE(calculator.calculateTotal(EntryType::Food), 300);
    QCOMPARE(calculator.calculateTotal(EntryType::Activity), 300);
}

void TestCalorieCalculator::test_removeEntry()
{
    CalorieCalculator calculator;

    calculator.addEntry("Банан", 150, EntryType::Food);
    calculator.addEntry("Бег", 200, EntryType::Activity);

    QVERIFY(calculator.removeEntry("Банан", EntryType::Food) == true);
    QVERIFY(calculator.removeEntry("Бег", EntryType::Activity) == true);

    // удаление уже удаленных записей
    QVERIFY(calculator.removeEntry("Банан", EntryType::Food) == false);
    QVERIFY(calculator.removeEntry("Бег", EntryType::Activity) == false);
}

void TestCalorieCalculator::test_getEntries()
{
    CalorieCalculator calculator;

    calculator.addEntry("Яблоко", 100, EntryType::Food);
    calculator.addEntry("Бег", 200, EntryType::Activity);

    QMap<QString, int> food = calculator.getEntries(EntryType::Food);
    QMap<QString, int> activities = calculator.getEntries(EntryType::Activity);

    // проверка размера словарей
    QCOMPARE(food.size(), 1);
    QCOMPARE(activities.size(), 1);

    // проверка содержимого еды
    QCOMPARE(food["Яблоко"], 100);

    // проверка содержимого активностей
    QCOMPARE(activities["Бег"], 200);
}

QTEST_APPLESS_MAIN(TestCalorieCalculator)
#include "tst_testcaloriecalculator.moc"
