#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QDir>
#include<QFile>
#include"toole.h"
#include<string>
#include"toold.h"
//#include<bits/stdc++.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString src;
QString dest;
void MainWindow::on_choose_file_clicked()
{
    QString filter = "Text File (*.txt) ;; PDF File (*.pdf) ;; Cpp File (*.cpp)";
    QString file_name = QFileDialog::getOpenFileName(this, "choose a file", QDir::homePath(), filter);
    ui->chosen_edit->setText(file_name);
    QMessageBox::information(this, "Chosen File", file_name);
    QFile source_file(file_name);
    if(! source_file.open( QFile::ReadOnly )){
        QMessageBox::warning(this, "Error", "Cannot Open file");
    }
    QTextStream in(&source_file);
    src = in.readAll();
    source_file.flush();
    source_file.close();
    //ui->dest_name->setText(src);
}

void MainWindow::on_read_content_clicked()
{
    src = ui->get_message->toPlainText();

}


void MainWindow::on_encode_now_clicked()
{
    dest = ui->dest_name->text();
    //ui->dest_name->setText(src);
    if(encodeBuffer(src, dest)){
        QMessageBox::information(this, "Success", "Data Encoded successfully!");
    }
}
QString df_name;
void MainWindow::on_choose_filed_clicked()
{
    QString filter = "Text File (*.txt) ;; PDF File (*.pdf)";
    df_name = QFileDialog::getOpenFileName(this, "choose a file", QDir::homePath(), filter);
    ui->show_chosen->setText(df_name);
    QMessageBox::information(this, "Chosen File", df_name);
    QFile source_file(df_name);
    if(! source_file.open( QFile::ReadOnly )){
        QMessageBox::warning(this, "Error", "Cannot Open file");
    }
}
QString msg;
void MainWindow::on_decode_now_clicked()
{   ui->show_chosen->setText("begining of function");
    QFile source_file(df_name);
    if(! source_file.open( QIODevice::ReadOnly )){
        QMessageBox::warning(this, "Error", "Cannot Open file");
    }
    //QTextStream in(&source_file);
    QString ans{""};
    string out="";
//    ui->show_chosen->setText("mid of function");
//    while(!source_file.atEnd()){
//        QString msg = in.readLine();
//        string smsg= msg.toLocal8Bit().constData();
//        out =  decode(smsg);
//        QString qout= QString::fromUtf8(out.data(), int(out.size()));
//        ui->decoded->appendPlainText(qout);
//    }
    //clear previous text from the text edit
    ui->decoded->clear();
    QFile inputFile(df_name);

    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString msg = in.readLine();
          string smsg= msg.toLocal8Bit().constData();
          out =  decode(smsg);
                  QString qout= QString::fromUtf8(out.data(), int(out.size()));
//                  ui->decoded->appendPlainText(qout);
                    ui->decoded->moveCursor(QTextCursor::End);
                    ui->decoded->insertPlainText(qout);
                    ui->decoded->moveCursor(QTextCursor::End);
       }
       inputFile.close();
    }
//     msg= in.readAll();
//    string smsg= msg.toStdString();
//    out =  decode(smsg);
//    QString qout= QString::fromStdString(out);
//    ui->decoded->appendPlainText(qout);
//    ui->show_chosen->setText("end of function");
//    source_file.flush();
//    source_file.close();
}

void MainWindow::on_action_exit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_help_encode_triggered()
{
    he = new help_encode(this);
    he->show();
}

void MainWindow::on_help_decode_triggered()
{
    hd = new help_decode(this);
    hd->show();
}

void MainWindow::on_actionAbout_Cipher_Forge_triggered()
{
    a = new about(this);
    a->show();
}
