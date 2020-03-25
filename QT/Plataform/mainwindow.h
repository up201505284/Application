#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "/home/anabela/Desktop/TESE/Application/VSCode/LinearActuator.h"
#include <QList>
#include <QString>
#include <QDebug>

#define INSERT_TAB  0
#define MANAGER_TAB 1
#define BASIC_TAB   2

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Construtor
    MainWindow(QWidget *parent = nullptr, QList<LinearActuator*> _listOfActuators = {});

    // Destructor
    ~MainWindow();

    // set methods
    void setListOfActuators(QList<LinearActuator*> _listOfActuators);

    // get methods
    QList<LinearActuator*> getListOfActuators(void);

    // clear functions
    void clearInsertTab         (void);
    void clearManagerTab        (void);
    void clearStatusBasicTab    (void);

    // set funtions
    void setManagerTab          (void       );
    void setStatusBasicTab      (void       );
    void setCurrentTab          (int index  );
    void updateComboBoxManager  (void       );
    void updateComboBoxBasic    (void       );

    // get functions
    LinearActuator* getInsertTab        (void           );
    LinearActuator* getLinearActuator   (string model   );


    // enable functions
    void setReadOnlyManager (bool _state);
    void setReadOnlyBasic   (bool _state);


    QList<LinearActuator*> listOfActuators;


private slots:


    void on_comboBoxManager_activated       (const QString &model);
    void on_comboBoxStatusBasic_activated   (const QString &model);

    void on_pushButtonInsert_clicked();

    void on_pushButtonUpdateStatusBasic_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
