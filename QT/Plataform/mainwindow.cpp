#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent, QList<LinearActuator*> _listOfActuators)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setListOfActuators(_listOfActuators);
    readJsonFile();
    updateComboBoxBasic();
    updateComboBoxManager();
    updateComboBoxAdvanced();
    setCurrentTab(BASIC_TAB);
    setManagerTab();
    setStatusBasicTab();
    setStatusAdvancedTab();
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

void MainWindow::clearStatusAdvancedTab(void)
{
    ui->statusActuatorAdvanced          ->clear();
    ui->motorCurrentAdvanced            ->clear();
    ui->position                        ->clear();
    ui->linearSpeed                     ->clear();
    ui->rotorSpeed                      ->clear();
    ui->pulseRate                       ->clear();

    ui->statusConnectionAdvanced        ->clear();
    ui->statusDriveAdvanced             ->clear();

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

void MainWindow::setReadOnlyAdvanced(bool _state)
{
    ui->statusActuatorAdvanced          ->setReadOnly(_state);
    ui->motorCurrentAdvanced            ->setReadOnly(_state);
    ui->position                        ->setReadOnly(_state);
    ui->linearSpeed                     ->setReadOnly(_state);
    ui->rotorSpeed                      ->setReadOnly(_state);
    ui->pulseRate                       ->setReadOnly(_state);

    ui->statusConnectionAdvanced        ->setReadOnly(_state);
    ui->statusDriveAdvanced             ->setReadOnly(_state);
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
    setReadOnlyBasic(true);
    clearStatusBasicTab();

    if (ui->comboBoxManager->currentText().isEmpty())
        return;
    else {
        LinearActuator* _linearActuator = getLinearActuator(ui->comboBoxManager->currentText().toStdString());

        ui->statusActuatorBasic     ->setText(QString::fromStdString    (_linearActuator->getStatusBasic()      ->getState          ()));
        ui->statusConnectionBasic   ->setText(QString::fromStdString    (_linearActuator->getConnection()       ->getStauts         ()));
        ui->motorCurrentBasic       ->setText(QString::number           (_linearActuator->getStatusBasic()      ->getMotorCurrent   ()));
    }

}

void MainWindow::setStatusAdvancedTab(void)
{
    setReadOnlyAdvanced(true);
    clearStatusAdvancedTab();

    if (ui->comboBoxStatusAdvanced->currentText().isEmpty())
        return;
    else {
        LinearActuator* _linearActuator = getLinearActuator(ui->comboBoxStatusAdvanced->currentText().toStdString());

        ui->statusActuatorAdvanced  ->setText(QString::fromStdString    (_linearActuator->getStatusAdvanced()   ->getState          ()));
        ui->motorCurrentAdvanced    ->setText(QString::number           (_linearActuator->getStatusAdvanced()   ->getMotorCurrent   ()));
        ui->position                ->setText(QString::number           (_linearActuator->getStatusAdvanced()   ->getPosition       ()));
        ui->linearSpeed             ->setText(QString::number           (_linearActuator->getStatusAdvanced()   ->getLinearSpeed    ()));
        ui->rotorSpeed              ->setText(QString::number           (_linearActuator->getStatusAdvanced()   ->getRotorSpeed     ()));
        ui->pulseRate               ->setText(QString::number           (_linearActuator->getSpecifications()   ->getPulseRate      ()));

        ui->statusConnectionAdvanced  ->setText(QString::fromStdString    (_linearActuator->getConnection()       ->getStauts         ()));
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

    updateJson(_linearActuator);

    return _linearActuator;
}

LinearActuator* MainWindow::getManagerTab(void)
{
    LinearActuatorSpecifications* _specifications = new LinearActuatorSpecifications(
                ui->strokeLenghtManager     ->text().toFloat    (),
                ui->maxCurrentManager       ->text().toFloat    (),
                ui->powerRatingManager      ->text().toInt      (),
                ui->numberHallSensorsManager->text().toInt      (),
                ui->modelManager            ->text().toStdString());

    if (!ui->maxLoadPullManager->text().isEmpty())
        _specifications->setMaxLoadPull(ui->maxLoadPullManager->text().toInt());
    if (!ui->maxLoadPushManager->text().isEmpty())
        _specifications->setMaxLoadPush(ui->maxLoadPushManager->text().toInt());
    if (!ui->dutyCycleManager ->text().isEmpty())
        _specifications->setDutyCycle(ui->dutyCycleManager->text().toInt());

    LinearActuatorStatusBasic* _statusBasic = new LinearActuatorStatusBasic();

    ControlSystem* _control = new ControlSystem(
                ui->accelarationRateManager     ->text().toFloat(),
                ui->accelarationTimeManager     ->text().toFloat());

    Connection* _connection = new Connection(
                ui->channelManager              ->text().toInt());

    LinearActuatorStatusAdvanced* _statusAdvaned = new LinearActuatorStatusAdvanced();

    LinearActuator* _linearActuator = new LinearActuator(
                _specifications,
                _statusAdvaned,
                _statusBasic,
                _control,
                _connection);

    updateJson(_linearActuator);

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

void MainWindow::updateComboBoxBasic(void)
{
    if (ui->comboBoxStatusBasic->count() > 0)
        ui->comboBoxStatusBasic->clear();

    for (LinearActuator* _actuator : listOfActuators)
        ui->comboBoxStatusBasic->addItem(QString::fromStdString(_actuator->getSpecifications()->getModel()));
    ui->comboBoxStatusBasic->setDisabled(false);
}

void MainWindow::updateComboBoxManager(void)
{
    if (ui->comboBoxStatusBasic->count() > 0)
        ui->comboBoxManager->clear();
    for (LinearActuator* _actuator : listOfActuators)
        ui->comboBoxManager->addItem(QString::fromStdString(_actuator->getSpecifications()->getModel()));
}

void MainWindow::updateComboBoxAdvanced (void)
{
    if (ui->comboBoxStatusAdvanced->count() > 0)
        ui->comboBoxStatusAdvanced->clear();
    for (LinearActuator* _actuator : listOfActuators)
        ui->comboBoxStatusAdvanced->addItem(QString::fromStdString(_actuator->getSpecifications()->getModel()));
}


void MainWindow::on_comboBoxManager_activated(const QString &model)
{
    setManagerTab();
}

void MainWindow::on_comboBoxStatusBasic_activated(const QString &model)
{
    setStatusBasicTab();
}

void MainWindow::on_comboBoxStatusAdvanced_activated(const QString &arg1)
{
    setStatusAdvancedTab();
}

void MainWindow::on_pushButtonInsert_clicked()
{
    listOfActuators.append(getInsertTab());
    clearInsertTab();
    createJsonFile();
    updateComboBoxBasic();
    updateComboBoxManager();
    updateComboBoxAdvanced();
    setManagerTab();
    setStatusBasicTab();
    setStatusAdvancedTab();
}

void MainWindow::on_pushButtonUpdateStatusBasic_clicked()
{
    setStatusBasicTab();
}

void MainWindow::on_pushButtonUpdateStatusAdvanced_clicked()
{
    setStatusAdvancedTab();
}

void MainWindow::on_pushButtonEdit_clicked()
{
    if (ui->pushButtonEdit->text() == "Edit") {
        setReadOnlyManager(false);
        ui->modelManager->setReadOnly(true);
        ui->pushButtonEdit->setText("Submit");
    }

    else if (ui->pushButtonEdit->text() == "Submit") {
        LinearActuator* _updateActuator = getManagerTab();
        listOfActuators.removeOne(getLinearActuator(ui->comboBoxManager->currentText().toStdString()));
        listOfActuators.append(_updateActuator);

        while(!recordActuators.empty())
            recordActuators.removeLast();

        for (LinearActuator* _actuator : listOfActuators)
            updateJson(_actuator);

        createJsonFile();
        setReadOnlyManager(true);
        setManagerTab();
        ui->pushButtonEdit->setText("Edit");
    }

    else
        return;
}


void MainWindow::updateJson(LinearActuator *_linearActuator)
{
    QJsonObject _specifications;
    QJsonObject _connection;
    QJsonObject _control;
    QJsonObject _basicStatus;
    QJsonObject _advancedStatus;

    _specifications.insert("Model"                  , QJsonValue::fromVariant(QString::fromStdString(_linearActuator->getSpecifications()->getModel())              ));
    _specifications.insert("Number of hall sensors" , QJsonValue::fromVariant                       (_linearActuator->getSpecifications()->getNumberHallSensors()   ));
    _specifications.insert("Max. current"           , QJsonValue::fromVariant                       (_linearActuator->getSpecifications()->getMaxCurrent()          ));
    _specifications.insert("Max. load in push"      , QJsonValue::fromVariant                       (_linearActuator->getSpecifications()->getMaxLoadPush()         ));
    _specifications.insert("Max. load in pull"      , QJsonValue::fromVariant                       (_linearActuator->getSpecifications()->getMaxLoadPull()         ));
    _specifications.insert("Power rating"           , QJsonValue::fromVariant                       (_linearActuator->getSpecifications()->getPowerRating()         ));
    _specifications.insert("Duty cycle"             , QJsonValue::fromVariant                       (_linearActuator->getSpecifications()->getDutyCycle()           ));
    _specifications.insert("Pulse rate"             , QJsonValue::fromVariant                       (_linearActuator->getSpecifications()->getPulseRate()           ));
    _specifications.insert("Stroke lenght"          , QJsonValue::fromVariant                       (_linearActuator->getSpecifications()->getStrokeLenght()        ));

    _connection.insert("Channel", QJsonValue::fromVariant(                      _linearActuator->getConnection()->getChannel()));
    _connection.insert("Status" , QJsonValue::fromVariant(QString::fromStdString(_linearActuator->getConnection()->getStauts())));

    _control.insert("Accelaration rate", QJsonValue::fromVariant(_linearActuator->getControl()->getAccelarationRate()));
    _control.insert("Accelaration time", QJsonValue::fromVariant(_linearActuator->getControl()->getAccelarationTime()));

    _basicStatus.insert("Motor current" , QJsonValue::fromVariant(                       _linearActuator->getStatusBasic()->getMotorCurrent()    ));
    _basicStatus.insert("State"         , QJsonValue::fromVariant(QString::fromStdString(  _linearActuator->getStatusBasic()->getState())        ));

    _advancedStatus.insert("State"          , QJsonValue::fromVariant(QString::fromStdString(   _linearActuator->getStatusAdvanced()->getState())       ));
    _advancedStatus.insert("Motor current"  , QJsonValue::fromVariant(                          _linearActuator->getStatusAdvanced()->getMotorCurrent() ));
    _advancedStatus.insert("Position"       , QJsonValue::fromVariant(                          _linearActuator->getStatusAdvanced()->getPosition()     ));
    _advancedStatus.insert("Linear speed"   , QJsonValue::fromVariant(                          _linearActuator->getStatusAdvanced()->getLinearSpeed()  ));
    _advancedStatus.insert("Rotor speed"    , QJsonValue::fromVariant(                          _linearActuator->getStatusAdvanced()->getRotorSpeed()   ));



    QJsonObject _actuator;

    _actuator.insert("Specifications"   , _specifications   );
    _actuator.insert("Connection"       , _connection       );
    _actuator.insert("Control System"   , _control          );
    _actuator.insert("Status Basic"     , _basicStatus      );
    _actuator.insert("Status Advanced"  , _advancedStatus   );

    recordActuators.push_back(_actuator);

}

void MainWindow::readJsonFile(void)
{
    QFile jsonFile("/home/anabela/Desktop/TESE/Application/QT/Plataform/records.js");
    jsonFile.open(QFile::ReadOnly);
    QJsonDocument _records = QJsonDocument().fromJson(jsonFile.readAll());
    jsonFile.close();

    QJsonArray _actuators = _records.array();

    for (QJsonValue _actuator : _actuators) {
            QJsonObject _actuatorObject = _actuator.toObject();

            QJsonObject _controlObject = _actuatorObject.value("Control System").toObject();
            ControlSystem*  _control = new ControlSystem(_controlObject.value("Accelaration rate").toDouble(), _controlObject.value("Accelaration time").toInt());

            QJsonObject _connectionObject = _actuatorObject.value("Connection").toObject();
            Connection*     _connection = new Connection(_connectionObject.value("Channel").toInt());
            _connection->setStatus(_connectionObject.value("Status").toString().toStdString());

            QJsonObject _basicObject = _actuatorObject.value("Status Basic").toObject();
            LinearActuatorStatusBasic* _basic = new LinearActuatorStatusBasic();
            _basic->setState(_basicObject.value("State").toString().toStdString());
            _basic->setMotorCurrent(_basicObject.value("Motor current").toDouble());

            QJsonObject _advancedObject = _actuatorObject.value("Status Advanced").toObject();
            LinearActuatorStatusAdvanced* _advanced = new LinearActuatorStatusAdvanced();
            _advanced->setState(_advancedObject.value("State").toString().toStdString());
            _advanced->setPosition(_advancedObject.value("Position").toDouble());
            _advanced->setRotorSpeed(_advancedObject.value("Rotor speed").toDouble());
            _advanced->setLinearSpeed(_advancedObject.value("Linear speed").toDouble());
            _advanced->setMotorCurrent(_advancedObject.value("Motor current").toDouble());


            QJsonObject _specificationsObject = _actuatorObject.value("Specifications").toObject();
            LinearActuatorSpecifications* _specifications = new LinearActuatorSpecifications(
                        _specificationsObject.value("Stroke lenght").toDouble(),
                        _specificationsObject.value("Max. current").toDouble(),
                        _specificationsObject.value("Power rating").toDouble(),
                        _specificationsObject.value("Number of hall sensors").toInt(),
                        _specificationsObject.value("Model").toString().toStdString()
                    );
            _specifications->setDutyCycle(_specificationsObject.value("Duty cycle").toInt());
            _specifications->setMaxLoadPull(_specificationsObject.value("Max. load in pull").toInt());
            _specifications->setMaxLoadPush(_specificationsObject.value("Max. load in push").toInt());
            _specifications->setPulseRate(_specificationsObject.value("Pulse rate").toDouble());


            LinearActuator* lineaActuator = new LinearActuator (_specifications, _advanced, _basic, _control, _connection);
            listOfActuators.append(lineaActuator);

    }
}

void MainWindow::createJsonFile(void)
{
    QJsonDocument report(recordActuators);
    QFile jsonFile("/home/anabela/Desktop/TESE/Application/QT/Plataform/records.js");
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(report.toJson());
    jsonFile.close();
}




