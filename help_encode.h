#ifndef HELP_ENCODE_H
#define HELP_ENCODE_H

#include <QDialog>

namespace Ui {
class help_encode;
}

class help_encode : public QDialog
{
    Q_OBJECT

public:
    explicit help_encode(QWidget *parent = nullptr);
    ~help_encode();

private:
    Ui::help_encode *ui;
};

#endif // HELP_ENCODE_H
