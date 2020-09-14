#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QString>
#include <QFont>
#include <QFileDialog>
#include <QFile>


QT_BEGIN_NAMESPACE
namespace Ui { class textEditor; }
QT_END_NAMESPACE

class textEditor : public QMainWindow
{
    Q_OBJECT

public:
    textEditor(QWidget *parent = nullptr);
    ~textEditor();

private slots:
    void on_actionSave_triggered();

    void on_actionBold_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_2_triggered();

    void on_actionRedo_2_triggered();

private:
    Ui::textEditor *ui;
    QString mFilepath;
    int weight;
};
#endif // TEXTEDITOR_H
