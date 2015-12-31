#ifndef TESTRUNNER_H
#define TESTRUNNER_H

#include <QTest>
#include <QSharedPointer>
#include <algorithm>
#include <list>
#include <iostream>

// Use this macro after your test declaration.
#define DECLARE_TEST(className) \
    static char test_##className = TestRunner::Instance().RegisterTest<className>(#className);

// Use this macro to execute all tests.
#define RUN_ALL_TESTS(argc, argv) \
    TestRunner::Instance().RunAll(argc, argv);

class TestRunner
{
public:
    static TestRunner& Instance()
    {
        static TestRunner instance;
        return instance;
    }

    template <typename T>
    char RegisterTest(char *name)
    {
        if (std::find_if(begin(tests), end(tests), [&name](QSharedPointer<QObject> &elem) {
            return elem->objectName() == name;
        }) == end(tests))
        {
            QSharedPointer<QObject> test(new T());
            test->setObjectName(name);
            tests.push_back(test);
        }

        return char(1);
    }

    int RunAll(int argc, char *argv[])
    {
        int errorCode = 0;
        std::for_each(begin(tests), end(tests), [&](QSharedPointer<QObject>& test)
        {
            errorCode |= QTest::qExec(test.data(), argc, argv);
            std::cout << std::endl;
        });

        return errorCode;
    }

private:
    std::list<QSharedPointer<QObject>> tests;
};

#endif // TESTRUNNER_H
