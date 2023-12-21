#include <QtTest/QtTest>
#include "../src/levelfacade.h"

class TestMyCode: public QObject {
    Q_OBJECT
private slots:
    void testGetAllLevels() {
        LevelFacade levelsFacade;
        QStringList levels = levelsFacade.get_all_levels();
        QVERIFY(!levels.empty());
    }

    void testLevelsSize() {
        LevelFacade levelsFacade;
        QStringList levels = levelsFacade.get_all_levels();
        QVERIFY(levels.size() > 0);
    }

};

QTEST_MAIN(TestMyCode)
#include "test_mycode.moc"
