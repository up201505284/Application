#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#define INSERT_TAB  0
#define EDIT_TAB    1
#define STATUS_TAB  2

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    QList<LinearActuator> _listoOfActuator;
    setListOfActuators(_listoOfActuator);
    ui->setupUi(this);
    ui->Tab->setCurrentIndex(STATUS_TAB);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setListOfActuators (QList<LinearActuator> _listOfActuators)
{
    listOfActuators = _listOfActuators;

}
void MainWindow::setInsert(LinearActuatorSpecifications* _specifications, ControlSystem* _control)
{
    _specifications->setModel(ui->model->text().toStdString());
    _specifications->setMaxCurrent(ui->maxCurrent->text().toFloat());
    _specifications->setMaxLoadPull(ui->maxLoadPush->text().toFloat());
    _specifications->setMaxLoadPush(ui->maxLoadPull->text().toFloat());
    _specifications->setStrokeLenght(ui->strokeLenght->text().toFloat());
    _specifications->setPowerRating(ui->powerRating->text().toInt());
    _specifications->setDutyCycle(ui->model->text().toInt());

    _control->setPwmFrequency(ui->pwmFrequency->text().toInt());
    _control->setAccelarationRate(ui->accelarationRate->text().toFloat());
    _control->setAccelarationTime(ui->accelarationTime->text().toFloat());
}

void MainWindow::clearInsert (void)
{
    ui->model->clear();
    ui->maxCurrent->clear();
    ui->maxLoadPull->clear();
    ui->maxLoadPush->clear();
    ui->powerRating->clear();
    ui->dutyCycle->clear();
    ui->strokeLenght->clear();

    ui->accelarationRate->clear();
    ui->accelarationTime->clear();
    ui->pwmFrequency->clear();

}

void MainWindow::on_pushButtonInsert_clicked()
{
    LinearActuatorSpecifications* _specifications = new LinearActuatorSpecifications();
    LinearActuatorStatus* _status = new LinearActuatorStatus();
    ControlSystem* _control = new ControlSystem();


    setInsert(_specifications, _control);
    qDebug()<<QString::fromStdString(_specifications->getModel());

    LinearActuator _linearActuator =  LinearActuator(_specifications, _status, _control);

    listOfActuators.append(_linearActuator);
    ui->chooseModelStatus->addItem(QString::fromStdString(_linearActuator.getSpecifications()->getModel()));
    ui->chooseModelEdit->addItem(QString::fromStdString(_linearActuator.getSpecifications()->getModel()));

    ui->Tab->setCurrentIndex(STATUS_TAB);
    ui->chooseModelStatus->setCurrentText(QString::fromStdString(_linearActuator.getSpecifications()->getModel()));


}



void MainWindow::on_chooseModelStatus_currentIndexChanged(const QString &model)
{
    ui->model_edit->setText( model);
}

void MainWindow::on_chooseModelEdit_currentIndexChanged(const QString &model)
{
    for ( LinearActuator _linearActuator : listOfActuators) {
        if (QString::fromStdString(_linearActuator.getSpecifications()->getModel()) == model) {
            ui->model_edit->setText( model);
            ui->dutyCycle_edit->setText(QString::number(_linearActuator.getSpecifications()->getDutyCycle()));
            ui->strokeLenght_edit->setText(QString::number(_linearActuator.getSpecifications()->getStrokeLenght()));
            ui->maxLoadPull_edit->setText(QString::number(_linearActuator.getSpecifications()->getMaxLoadPull()));
            ui->maxLoadPush_edit->setText(QString::number(_linearActuator.getSpecifications()->getMaxLoadPush()));
            ui->maxCurrent_edit->setText(QString::number(_linearActuator.getSpecifications()->getMaxCurrent()));
            ui->powerRating_edit->setText(QString::number(_linearActuator.getSpecifications()->getPowerRating()));
        }

    }
    ui->model_edit->setText(model);

}
