#include "testsomething.h"

void TestSomething::testSomething_data()
{
    QTest::addColumn<int>("a");
    QTest::addColumn<int>("b");
    QTest::addColumn<int>("expectation");

    QTest::newRow("a + b")
        << 1
        << 2
        << 3;
}

void TestSomething::testSomething()
{
    QFETCH(int, a);
    QFETCH(int, b);
    QFETCH(int, expectation);
    
    int real = a + b;
    QString message = QString("\nExpected:\n\"%1\"\n\nReal:\n\"%2\"\n")
        .arg(expectation)
        .arg(real);

    QVERIFY2(expectation == real, message.toStdString().c_str());
}