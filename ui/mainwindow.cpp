#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include<QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionImport_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(),
                                                 tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

     if (!fileName.isEmpty()) {
         QFile file(fileName);
         if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
             return;
         }
         QTextStream in(&file);
         ui->sourcetext->setText(in.readAll());
         file.close();
     }
}

void MainWindow::on_actionExport_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), QString(),
                                                  tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

    if (!fileName.isEmpty()) {
      QFile file(fileName);
      if (!file.open(QIODevice::WriteOnly)) {
          // error message
      } else {
          QTextStream stream(&file);
          stream << ui->output->toPlainText();
          stream.flush();
          file.close();
      }
    }

}

void MainWindow::on_sourcetext_textChanged()
{
    //ui->targettext->setText(ui->sourcetext->toPlainText());
}

void MainWindow::on_actionNew_triggered()
{
    ui->sourcetext->setText("");
    ui->statusBar->showMessage("Ready");
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msgBox;
    msgBox.setText("Created by tachyons creations");
    msgBox.exec();
}

void MainWindow::on_actionTranslate_triggered()
{
    ui->statusBar->showMessage("Translating ...");
    QProcess p;
    QProcess source;
    QProcess target;
    QString sourcetext=ui->sourcetext->toPlainText();
    //working directory
    QString workdir=QDir::homePath();
    source.setWorkingDirectory(workdir.append("/apertium-mal-eng"));
    target.setWorkingDirectory(workdir);
    //sync
    source.setStandardOutputProcess(&target);
    //run
    source.start(sourcetext.prepend("echo \""));
    source.waitForFinished(-1);
    target.start("apertium -d /home/tachyons/apertium-mal-eng mal-eng\"");
    target.waitForFinished(-1);
    //get output
    QString p_stdout = target.readAllStandardOutput();
    QString p_stderr = target.readAllStandardError();
    ui->output->setText(p_stdout.append(p_stderr));
    ui->statusBar->showMessage("Translated");
}
