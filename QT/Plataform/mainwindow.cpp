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
void MainWindow::addLinearActuator(LinearActuatorSpecifications* _specifications, ControlSystem* _control)
{
    _specifications->setModel(ui->model->text().toStdString());
    _specifications->setMaxCurrent(ui->maxCurrent->text().toFloat());
    _specifications->setMaxLoadPull(ui->maxLoadPush->text().toFloat());
    _specifications->setMaxLoadPush(ui->maxLoadPull->text().toFloat());
    _specifications->setStrokeLenght(ui->strokeLenght->text().toFloat());
    _specifications->setPowerRating(ui->powerRating->text().toInt());
    _specifications->setDutyCycle(ui->dutyCycle->text().toInt());

    _control->setPwmFrequency(ui->pwmFrequency->text().toInt());
    _control->setAccelarationRate(ui->accelarationRate->text().toFloat());
    _control->setAccelarationTime(ui->accelarationTime->text().toFloat());
}

void MainWindow::editLinearActuator ()
{
    for ( LinearActuator _linearActautor : listOfActuators) {
        if (QString::fromStdString(_linearActautor.getSpecifications()->getModel()) == ui->chooseModelEdit->currentText()) {
            _linearActautor.getSpecifications()->setModel(ui->model_edit->text().toStdString());
            _linearActautor.getSpecifications()->setMaxCurrent(ui->maxCurrent_edit->text().toFloat());
            _linearActautor.getSpecifications()->setMaxLoadPull(ui->maxLoadPush_edit->text().toFloat());
            _linearActautor.getSpecifications()->setMaxLoadPush(ui->maxLoadPull_edit->text().toFloat());
            _linearActautor.getSpecifications()->setStrokeLenght(ui->strokeLenght_edit->text().toFloat());
            _linearActautor.getSpecifications()->setPowerRating(ui->powerRating_edit->text().toInt());
            _linearActautor.getSpecifications()->setDutyCycle(ui->dutyCycle_edit->text().toInt());

            _linearActautor.getControl()->setPwmFrequency(ui->pwmFrequency_edit->text().toInt());
            _linearActautor.getControl()->setAccelarationRate(ui->accelarationRate_edit->text().toFloat());
            _linearActautor.getControl()->setAccelarationTime(ui->accelarationTime_edit->text().toFloat());
        }
    }
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

void MainWindow::setStatus(void)
{
    for ( LinearActuator _linearActuator : listOfActuators) {
        if (QString::fromStdString(_linearActuator.getSpecifications()->getModel()) == ui->chooseModelStatus->currentText()) {
            ui->status->setText(QString::fromStdString(_linearActuator.getStatus()->getState()));
            ui->position->setText(QString::number(_linearActuator.getStatus()->getPosition()));
            ui->rotorSpeed->setText(QString::number(_linearActuator.getStatus()->getRotorSpeed()));
            ui->linearSpeed->setText(QString::number(_linearActuator.getStatus()->getLinearSpeed()));
            ui->pulseRate->setText(QString::number(_linearActuator.getSpecifications()->getPulseRate()));
            break;
        }

    }
}

void MainWindow::setEdit(void)
{
    for ( LinearActuator _linearActuator : listOfActuators) {
        if (QString::fromStdString(_linearActuator.getSpecifications()->getModel()) == ui->chooseModelStatus->currentText()) {
            ui->model_edit->setText(QString::fromStdString(_linearActuator.getSpecifications()->getModel()));
            ui->maxCurrent_edit->setText(QString::number(_linearActuator.getSpecifications()->getMaxCurrent()));
            ui->maxLoadPull_edit->setText(QString::number(_linearActuator.getSpecifications()->getMaxLoadPull()));
            ui->maxLoadPush_edit->setText(QString::number(_linearActuator.getSpecifications()->getMaxLoadPush()));
            ui->powerRating_edit->setText(QString::number(_linearActuator.getSpecifications()->getPowerRating()));
            ui->dutyCycle_edit->setText(QString::number(_linearActuator.getSpecifications()->getDutyCycle()));
            ui->strokeLenght_edit->setText(QString::number(_linearActuator.getSpecifications()->getStrokeLenght()));

            ui->accelarationRate_edit->setText(QString::number(_linearActuator.getControl()->getAccelarationRate()));
            ui->accelarationTime_edit->setText(QString::number(_linearActuator.getControl()->getAccelarationRate()));
            ui->pwmFrequency_edit->setText(QString::number(_linearActuator.getControl()->getPwmFrequency()));

            break;
        }

    }
}

void MainWindow::on_pushButtonInsert_clicked()
{
    LinearActuatorSpecifications* _specifications = new LinearActuatorSpecifications();
    LinearActuatorStatus* _status = new LinearActuatorStatus();
    ControlSystem* _control = new ControlSystem();


    addLinearActuator(_specifications, _control);
    qDebug()<<QString::fromStdString(_specifications->getModel());

    LinearActuator _linearActuator =  LinearActuator(_specifications, _status, _control);

    listOfActuators.append(_linearActuator);
    ui->chooseModelStatus->addItem(QString::fromStdString(_linearActuator.getSpecifications()->getModel()));
    ui->chooseModelEdit->addItem(QString::fromStdString(_linearActuator.getSpecifications()->getModel()));

    ui->Tab->setCurrentIndex(STATUS_TAB);
    ui->chooseModelStatus->setCurrentText(QString::fromStdString(_linearActuator.getSpecifications()->getModel()));

    clearInsert();

}



void MainWindow::on_chooseModelStatus_currentIndexChanged(const QString &model)
{
    setStatus();
}

void MainWindow::on_chooseModelEdit_currentIndexChanged(const QString &model)
{

   setEdit();

}

void MainWindow::on_pushButtonInsert_update_clicked()
{
    setStatus();
}

void MainWindow::on_pushButtonEdit_clicked()
{
    editLinearActuator();


    ui->Tab->setCurrentIndex(STATUS_TAB);
    ui->chooseModelStatus->setCurrentText(ui->chooseModelEdit->currentText());

}
