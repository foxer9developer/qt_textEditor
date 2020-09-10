#include "texteditor.h"
#include "ui_texteditor.h"

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


void textEditor::on_actionSave_triggered()
{

}

void textEditor::on_actionBold_triggered()
{
    weight = ui->textEdit->fontWeight();
    if(weight<75){
        ui->textEdit->setFontWeight(75);
    }
    else{
        ui->textEdit->setFontWeight(50);
    }

}

void textEditor::on_actionNew_triggered()
{

}

void textEditor::on_actionOpen_triggered()
{

}

void textEditor::on_actionSave_as_triggered()
{

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
