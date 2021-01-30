#ifndef HELP_DECODE_H
#define HELP_DECODE_H

#include <QDialog>

namespace Ui {
class help_decode;
}

class help_decode : public QDialog
{
    Q_OBJECT

public:
    explicit help_decode(QWidget *parent = nullptr);
    ~help_decode();

private:
    Ui::help_decode *ui;
};

#endif // HELP_DECODE_H
