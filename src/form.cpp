#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(start()));
}

Form::~Form()
{
    delete ui;
}

void Form::start() {
    QString str = ui->str->text();
    QString sub_str = ui->sub_str->text();

    // Call the method to check if str contains sub_str
    checkSubstring();
}

void Form::checkSubstring() {
    QString str = ui->str->text();
    QString sub_str = ui->sub_str->text();

    if (containsSubstring(str, sub_str)) {
        ui->result->setText(str + " contains " + sub_str);
    } else {
        ui->result->setText(str + " does not contain " + sub_str);
    }
}

bool Form::containsSubstring(const QString &str, const QString &subStr) {
    // Use contains() method to check if subStr is present in str
    return str.contains(subStr);
}
