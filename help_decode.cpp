#include "help_decode.h"
#include "ui_help_decode.h"

help_decode::help_decode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help_decode)
{
    ui->setupUi(this);
}

help_decode::~help_decode()
{
    delete ui;
}
