// LevelFacade.h

#ifndef LEVELFACADE_H
#define LEVELFACADE_H

#include <QObject>
#include <string>
#include <vector>

using namespace std;

class LevelFacade : public QObject {
    Q_OBJECT
public:
    explicit LevelFacade(QObject *parent = nullptr);

    void setupGame(); // Функция для настройки игры
    QStringList get_all_levels();
    vector<vector<qreal>> getArrayOfBricks(const QString& filename);
signals:
    void levelSelected(const QString& levelName);

private slots:
    void onLevelSelected(const QString& levelName);

private:
    const string directoryPath;
};

#endif // LEVELFACADE_H
