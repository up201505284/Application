#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent, QList<LinearActuator*> _listOfActuators)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setListOfActuators(_listOfActuators);
    ui->setupUi(this);
    setCurrentTab(BASIC_TAB);
    setManagerTab();
    setStatusBasicTab();
}

MainWindow::~MainWindow()
{
    delete ui;
}


QList<LinearActuator*> MainWindow::getListOfActuators(void)
{
    return  listOfActuators;
}

void MainWindow::setListOfActuators(QList<LinearActuator*> _listOfActuators)
{
    listOfActuators = _listOfActuators;
}

void MainWindow::clearInsertTab(void)
{
    ui->model               ->clear();
    ui->maxCurrent          ->clear();
    ui->maxLoadPull         ->clear();
    ui->maxLoadPush         ->clear();
    ui->powerRating         ->clear();
    ui->dutyCycle           ->clear();
    ui->strokeLenght        ->clear();
    ui->numberHallSensors   ->clear();

    ui->accelarationRate    ->clear();
    ui->accelarationTime    ->clear();

    ui->channel             ->clear();
}

void MainWindow::clearManagerTab(void)
{
    ui->modelManager            ->clear();
    ui->maxCurrentManager       ->clear();
    ui->maxLoadPullManager      ->clear();
    ui->maxLoadPushManager      ->clear();
    ui->powerRatingManager      ->clear();
    ui->dutyCycleManager        ->clear();
    ui->strokeLenghtManager     ->clear();
    ui->numberHallSensorsManager->clear();

    ui->accelarationRateManager ->clear();
    ui->accelarationTimeManager ->clear();

    ui->channelManager          ->clear();
}

void MainWindow::clearStatusBasicTab(void)
{
    ui->statusDriveBasic        ->clear();
    ui->statusConnectionBasic   ->clear();
    ui->statusActuatorBasic     ->clear();
    ui->motorCurrentBasic       ->clear();
}

void MainWindow::setReadOnlyManager(bool _state)
{
    ui->strokeLenghtManager     ->setReadOnly(_state);
    ui->maxCurrentManager       ->setReadOnly(_state);
    ui->maxLoadPullManager      ->setReadOnly(_state);
    ui->maxLoadPushManager      ->setReadOnly(_state);
    ui->powerRatingManager      ->setReadOnly(_state);
    ui->modelManager            ->setReadOnly(_state);
    ui->dutyCycleManager        ->setReadOnly(_state);
    ui->numberHallSensorsManager->setReadOnly(_state);

    ui->channelManager          ->setReadOnly(_state);

    ui->accelarationRateManager ->setReadOnly(_state);
    ui->accelarationTimeManager ->setReadOnly(_state);
}

void MainWindow::setReadOnlyBasic (bool _state)
{
    ui->motorCurrentBasic       ->setReadOnly(_state);
    ui->statusDriveBasic        ->setReadOnly(_state);
    ui->statusConnectionBasic   ->setReadOnly(_state);
    ui->statusActuatorBasic     ->setReadOnly(_state);
}

void MainWindow::setManagerTab(void)
{
    setReadOnlyBasic(true);
    clearManagerTab();

    if (ui->comboBoxManager->currentText().isEmpty())
        return;
    else {
        LinearActuator* _linearActuator = getLinearActuator(ui->comboBoxManager->currentText().toStdString());
        ui->modelManager            ->setText(QString::fromStdString    (_linearActuator->getSpecifications()->getModel             ()));
        ui->maxCurrentManager       ->setText(QString::number           (_linearActuator->getSpecifications()->getMaxCurrent        ()));
        ui->strokeLenghtManager     ->setText(QString::number           (_linearActuator->getSpecifications()->getStrokeLenght      ()));
        ui->powerRatingManager      ->setText(QString::number           (_linearActuator->getSpecifications()->getPowerRating       ()));
        ui->numberHallSensorsManager->setText(QString::number           (_linearActuator->getSpecifications()->getNumberHallSensors ()));


        if (_linearActuator->getSpecifications()->getDutyCycle()     > 0)
            ui->dutyCycleManager    ->setText(QString::number           (_linearActuator->getSpecifications()->getDutyCycle          ()));

        if (_linearActuator->getSpecifications()->getMaxLoadPull()   > 0)
            ui->maxLoadPullManager  ->setText(QString::number           (_linearActuator->getSpecifications()->getMaxLoadPull        ()));

        if (_linearActuator->getSpecifications()->getMaxLoadPush()   > 0)
            ui->maxLoadPushManager  ->setText(QString::number           (_linearActuator->getSpecifications()->getMaxLoadPush        ()));

        ui->accelarationRateManager ->setText(QString::number           (_linearActuator->getControl()->getAccelarationRate          ()));
        ui->accelarationTimeManager ->setText(QString::number           (_linearActuator->getControl()->getAccelarationTime          ()));

        ui->channelManager          ->setText(QString::number           (_linearActuator->getConnection()->getChannel                ()));
    }
}

void MainWindow::setStatusBasicTab(void)
{
    setReadOnlyManager(true);
    clearStatusBasicTab();

    if (ui->comboBoxManager->currentText().isEmpty())
        return;
    else {
        LinearActuator* _linearActuator = getLinearActuator(ui->comboBoxManager->currentText().toStdString());

        ui->statusActuatorBasic     ->setText(QString::fromStdString    (_linearActuator->getStatusBasic()      ->getState          ()));
        ui->statusConnectionBasic   ->setText(QString::fromStdString    (_linearActuator->getConnection()       ->getStauts         ()));
        ui->motorCurrentBasic       ->setText(QString::number           (_linearActuator->getStatusAdvanced()   ->getMotorCurrent   ()));
    }

}

LinearActuator* MainWindow::getInsertTab(void)
{

    LinearActuatorSpecifications* _specifications = new LinearActuatorSpecifications(
                ui->strokeLenght        ->text().toFloat    (),
                ui->maxCurrent          ->text().toFloat    (),
                ui->powerRating         ->text().toInt      (),
                ui->numberHallSensors   ->text().toInt      (),
                ui->model               ->text().toStdString());

    if (!ui->maxLoadPull->text().isEmpty())
        _specifications->setMaxLoadPull(ui->maxLoadPull->text().toInt());
    if (!ui->maxLoadPush->text().isEmpty())
        _specifications->setMaxLoadPush(ui->maxLoadPush->text().toInt());
    if (!ui->dutyCycle->text().isEmpty())
        _specifications->setDutyCycle(ui->dutyCycle->text().toInt());

    LinearActuatorStatusBasic* _statusBasic = new LinearActuatorStatusBasic();

    ControlSystem* _control = new ControlSystem(
                ui->accelarationRate    ->text().toFloat(),
                ui->accelarationTime    ->text().toFloat());

    Connection* _connection = new Connection(
                ui->channel             ->text().toInt());

    LinearActuatorStatusAdvanced* _statusAdvaned = new LinearActuatorStatusAdvanced();

    LinearActuator* _linearActuator = new LinearActuator(
                _specifications,
                _statusAdvaned,
                _statusBasic,
                _control,
                _connection);

    return _linearActuator;
}

LinearActuator* MainWindow::getLinearActuator (string model   ) {
    for (LinearActuator* actuator : listOfActuators) {
        if (actuator->getSpecifications()->getModel() == model)
            return actuator;
    }
    return nullptr;
}

void MainWindow::setCurrentTab(int index)
{
    ui->Tab->setCurrentIndex(index);
}

void MainWindow::updateComboBoxBasic()
{
    ui->comboBoxStatusBasic->clear();
    for (LinearActuator* _actuator : listOfActuators)
        ui->comboBoxStatusBasic->addItem(QString::fromStdString(_actuator->getSpecifications()->getModel()));
}

void MainWindow::updateComboBoxManager()
{
    ui->comboBoxManager->clear();
    for (LinearActuator* _actuator : listOfActuators)
        ui->comboBoxManager->addItem(QString::fromStdString(_actuator->getSpecifications()->getModel()));
}

void MainWindow::on_comboBoxManager_activated(const QString &model)
{
    setManagerTab();
}

void MainWindow::on_comboBoxStatusBasic_activated(const QString &model)
{
    setStatusBasicTab();
}

void MainWindow::on_pushButtonInsert_clicked()
{
    listOfActuators.append(getInsertTab());
    clearInsertTab();
    updateComboBoxBasic();
    updateComboBoxManager();
    setManagerTab();
    setStatusBasicTab();
}

void MainWindow::on_pushButtonUpdateStatusBasic_clicked()
{
    setStatusBasicTab();
}
