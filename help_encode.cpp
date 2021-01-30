#include "help_encode.h"
#include "ui_help_encode.h"

help_encode::help_encode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help_encode)
{
    ui->setupUi(this);
}

help_encode::~help_encode()
{
    delete ui;
}
