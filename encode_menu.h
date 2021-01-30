#ifndef ENCODE_MENU_H
#define ENCODE_MENU_H

#include <QMainWindow>

namespace Ui {
class encode_menu;
}

class encode_menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit encode_menu(QWidget *parent = nullptr);
    ~encode_menu();

private:
    Ui::encode_menu *ui;
};

#endif // ENCODE_MENU_H
