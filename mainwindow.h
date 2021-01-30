#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"help_encode.h"
#include"help_decode.h"
#include"about.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_choose_file_clicked();

    void on_read_content_clicked();


    void on_encode_now_clicked();

    void on_choose_filed_clicked();

    void on_decode_now_clicked();

    void on_action_exit_triggered();

    void on_help_encode_triggered();

    void on_help_decode_triggered();

    void on_actionAbout_Cipher_Forge_triggered();

private:
    Ui::MainWindow *ui;
    help_encode *he;
    help_decode *hd;
    about *a;
};
#endif // MAINWINDOW_H
