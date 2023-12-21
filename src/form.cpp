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

    if (str.contains(sub_str)) {
        ui->result->setText(str + " содержит " + sub_str);
    } else {
        ui->result->setText(str + " не содержит " + sub_str);
    }
}
