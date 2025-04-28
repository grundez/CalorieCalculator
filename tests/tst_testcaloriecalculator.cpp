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
};

TestCalorieCalculator::TestCalorieCalculator() {}
TestCalorieCalculator::~TestCalorieCalculator() {}

void TestCalorieCalculator::test_createInstance()
{
    CalorieCalculator calculator; // Пытаемся создать объект
}


QTEST_APPLESS_MAIN(TestCalorieCalculator)
#include "tst_testcaloriecalculator.moc"
