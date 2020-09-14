#include "texteditor.h"
#include "ui_texteditor.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QActionGroup>

textEditor::textEditor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::textEditor)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

textEditor::~textEditor()
{
    delete ui;
}

void textEditor::on_actionBold_triggered()
{
    weight = ui->textEdit->fontWeight();
    if(weight<75){
//        actionBold;
        ui->textEdit->setFontWeight(75);
    }
    else{
        ui->textEdit->setFontWeight(50);
    }

}

void textEditor::on_actionNew_triggered()
{
    mFilepath = "";
    ui->textEdit->setPlainText("");
}

void textEditor::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "open the file");
    QFile file(filename);
    mFilepath = filename;
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"..", "File not open");
        return;
    }

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void textEditor::on_actionSave_triggered()
{
    QFile file(mFilepath);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        textEditor::on_actionSave_as_triggered();
    }

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}

void textEditor::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "open the file");
    QFile file(filename);
    mFilepath = filename;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"..", "File not open");
        return;
    }

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}

void textEditor::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void textEditor::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void textEditor::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void textEditor::on_actionUndo_2_triggered()
{
    ui->textEdit->undo();
}

void textEditor::on_actionRedo_2_triggered()
{
    ui->textEdit->redo();
}
