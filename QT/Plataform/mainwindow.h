#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "/home/anabela/Desktop/TESE/Application/VSCode/LinearActuator.h"
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
    void addLinearActuator (LinearActuatorSpecifications* _specifications, ControlSystem* _control);
    void editLinearActuator ();
    void setEdit(void);
    void setStatus();

    QList<LinearActuator> listOfActuators;




private slots:
    void on_pushButtonInsert_clicked();
    void on_chooseModelStatus_currentIndexChanged(const QString &model);
    void on_chooseModelEdit_currentIndexChanged(const QString &arg1);
    void on_pushButtonInsert_update_clicked();

    void on_pushButtonEdit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
