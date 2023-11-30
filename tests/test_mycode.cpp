#include <QtTest/QtTest>
#include <sstream>
#include "../src/mycode.h"

class TestMyCode : public QObject {
    Q_OBJECT

private slots:
    void testHelloWithName();
    void testHelloWithEmptyName();
    void testHelloWithMultiWordName();
};

void TestMyCode::testHelloWithName() {
    std::stringstream input("John");
    std::stringstream output;

    hello(input, output);

    QCOMPARE(output.str(), std::string("hello John"));
}

void TestMyCode::testHelloWithEmptyName() {
    std::stringstream input("");
    std::stringstream output;

    hello(input, output);

    QCOMPARE(output.str(), std::string("hello "));
}

void TestMyCode::testHelloWithMultiWordName() {
    std::stringstream input("John Doe");
    std::stringstream output;

    hello(input, output);

    QCOMPARE(output.str(), std::string("hello John"));
}

QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
