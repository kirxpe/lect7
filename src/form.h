#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget {
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:
    void start();
    void checkSubstring();

private:
    Ui::Form *ui;
    bool containsSubstring(const QString &str, const QString &subStr);
};

#endif // FORM_H
