// LevelFacade.cpp

#include "levelfacade.h"
#include <QDir>
#include <QGraphicsRectItem>
#include <vector>

LevelFacade::LevelFacade(QObject *parent)
    : QObject(parent),
    directoryPath("D:/lect7/levels/") {
    // Соединяем сигнал выбора уровня из MainMenu со слотом обработки выбора уровня

}



void LevelFacade::onLevelSelected(const QString& levelName) {
    // Передаем выбранный уровень для загрузки в GameView через сигнал
    emit levelSelected(levelName);
}

QStringList LevelFacade::get_all_levels(){
    QDir directory(QString::fromStdString(directoryPath));

    // Фильтр для выбора только файлов с расширением .txt
    QStringList filters;
    filters << "*.txt";
    directory.setNameFilters(filters);

    // Получаем список файлов уровней в директории
    return directory.entryList();
}

std::vector<std::vector<qreal>> LevelFacade::getArrayOfBricks(const QString& levelName) {
    std::vector<std::vector<qreal>> bricksArray;
    QFile file("D:/lect7/levels/" + levelName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return bricksArray;
    }
    std::vector<qreal> brickItem;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList brickData = line.split(",");
        if (brickData.size() >= 4) {
            qreal x = brickData[0].toDouble();
            qreal y = brickData[1].toDouble();
            qreal width = brickData[2].toDouble();
            qreal height = brickData[3].toDouble();

            brickItem = {x, y, width, height};
            bricksArray.push_back(brickItem);
        }
    }
    file.close();
    return bricksArray;

}





