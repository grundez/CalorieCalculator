#include <QtTest>

// add necessary includes here

class TestCalorieCalculatoro : public QObject
{
    Q_OBJECT

public:
    TestCalorieCalculatoro();
    ~TestCalorieCalculatoro();

private slots:
    void test_case1();
};

TestCalorieCalculatoro::TestCalorieCalculatoro() {}

TestCalorieCalculatoro::~TestCalorieCalculatoro() {}

void TestCalorieCalculatoro::test_case1() {}

QTEST_APPLESS_MAIN(TestCalorieCalculatoro)

#include "tst_testcaloriecalculatoro.moc"
