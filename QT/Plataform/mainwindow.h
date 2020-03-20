#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "/home/anabela/Desktop/TESE/application/VSCode/LinearActuator.h"
#include <QList>
#include <QListIterator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setListOfActuators (QList<LinearActuator> _listOfActuators);
    void clearInsert (void);
    void setInsert(LinearActuatorSpecifications* _specifications, ControlSystem* _control);
    QList<LinearActuator> listOfActuators;




private slots:
    void on_pushButtonInsert_clicked();

    void on_chooseModelStatus_currentIndexChanged(const QString &model);

    void on_chooseModelEdit_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
