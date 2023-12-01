#include <QtTest/QtTest>
<<<<<<< HEAD
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
=======
#include "../src/mycode.h"

#include <sstream>
using namespace std;

class TestMyCode: public QObject {
    Q_OBJECT
private slots:
    void testIvan();
};

void TestMyCode::testIvan() {
    std::stringstream sstr;
    stringstream isst;
    isst << "Ivan";

    hello(isst, sstr);

    string str;
    getline(sstr, str);

    QCOMPARE(str == "hello Ivan", true);
>>>>>>> 0c71cda4bbb7ceab9f7a979f8cd41dd6a4968037
}

QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
