#include "encode_menu.h"
#include "ui_encode_menu.h"

encode_menu::encode_menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::encode_menu)
{
    ui->setupUi(this);
}

encode_menu::~encode_menu()
{
    delete ui;
}
