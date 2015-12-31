#ifndef TESTSOMETHING_H
#define TESTSOMETHING_H

#include <QObject>
#include <QTest>
#include "testsrunner.h"

class TestSomething : public QObject
{
    Q_OBJECT

private slots:
    void testSomething_data();
    void testSomething();
};

DECLARE_TEST(TestSomething);

#endif // TESTSOMETHING_H