/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *Tab;
    QWidget *insertTab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelMaxPull;
    QLabel *labelMaxPush;
    QLineEdit *strokeLenght;
    QLabel *labelControlSystem;
    QFrame *line_6;
    QLabel *labelPowerRating;
    QLineEdit *maxCurrent;
    QFrame *line_12;
    QLineEdit *model;
    QLineEdit *dutyCycle;
    QLabel *labelSpecifications;
    QFrame *line_4;
    QLabel *labelAccelTime;
    QLabel *strokeLabel;
    QSpacerItem *horizontalSpacer;
    QLabel *labelAccelRate;
    QFrame *line_2;
    QFrame *line_7;
    QLineEdit *maxLoadPush;
    QFrame *line_8;
    QLabel *labelModel;
    QPushButton *pushButtonInsert;
    QFrame *line;
    QLineEdit *accelarationTime;
    QLabel *labelMaxCurrent;
    QFrame *line_5;
    QFrame *line_9;
    QFrame *line_10;
    QFrame *line_3;
    QLineEdit *accelarationRate;
    QFrame *line_11;
    QLineEdit *maxLoadPull;
    QLabel *labelDutyCycle;
    QLineEdit *powerRating;
    QLabel *labelPwmFrewq;
    QLineEdit *pwmFrequency;
    QSpacerItem *verticalSpacer;
    QWidget *editTab;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *labelMaxCurrent_2;
    QFrame *line_17;
    QFrame *line_15;
    QFrame *line_18;
    QLineEdit *powerRating_edit;
    QLineEdit *dutyCycle_edit;
    QLineEdit *accelarationTime_edit;
    QLabel *labelSpecifications_2;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_16;
    QLineEdit *maxCurrent_edit;
    QFrame *line_19;
    QLineEdit *model_edit;
    QLabel *labelPowerRating_2;
    QLabel *labelAccelTime_2;
    QLineEdit *accelarationRate_edit;
    QFrame *line_24;
    QLabel *labelDutyCycle_2;
    QLabel *labelMaxPull_2;
    QFrame *line_20;
    QLabel *labelMaxPush_2;
    QLineEdit *maxLoadPush_edit;
    QLabel *labelAccelRate_2;
    QPushButton *pushButtonInsert_2;
    QLabel *labelModel_2;
    QFrame *line_22;
    QFrame *line_21;
    QFrame *line_14;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_23;
    QFrame *line_13;
    QLabel *labelPwmFrewq_2;
    QLineEdit *maxLoadPull_edit;
    QLineEdit *strokeLenght_edit;
    QLabel *labelControlSystem_2;
    QLabel *strokeLabel_2;
    QLineEdit *pwmFrequency_edit;
    QComboBox *chooseModelEdit;
    QWidget *statusTab;
    QComboBox *chooseModelStatus;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *labelSpecifications_3;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line_32;
    QFrame *line_34;
    QFrame *line_26;
    QPushButton *pushButtonInsert_3;
    QLabel *strokeLabel_3;
    QFrame *line_30;
    QLabel *labelMaxPush_3;
    QLineEdit *strokeLenght_3;
    QLabel *labelDutyCycle_3;
    QLabel *labelModel_3;
    QFrame *line_29;
    QLabel *labelPwmFrewq_3;
    QLineEdit *pwmFrequency_3;
    QLineEdit *model_3;
    QLineEdit *accelarationRate_3;
    QLabel *labelMaxPull_3;
    QLineEdit *maxLoadPush_3;
    QFrame *line_31;
    QFrame *line_33;
    QSpacerItem *verticalSpacer_3;
    QLabel *labelControlSystem_3;
    QLineEdit *accelarationTime_3;
    QFrame *line_27;
    QLabel *labelPwmFrewq_4;
    QFrame *line_36;
    QLineEdit *maxLoadPull_3;
    QLineEdit *dutyCycle_3;
    QFrame *line_28;
    QFrame *line_35;
    QLabel *labelPwmFrewq_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(826, 438);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Tab = new QTabWidget(centralwidget);
        Tab->setObjectName(QString::fromUtf8("Tab"));
        Tab->setGeometry(QRect(20, 20, 751, 391));
        Tab->setTabPosition(QTabWidget::North);
        Tab->setTabShape(QTabWidget::Rounded);
        insertTab = new QWidget();
        insertTab->setObjectName(QString::fromUtf8("insertTab"));
        gridLayoutWidget = new QWidget(insertTab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(70, 30, 621, 311));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelMaxPull = new QLabel(gridLayoutWidget);
        labelMaxPull->setObjectName(QString::fromUtf8("labelMaxPull"));
        labelMaxPull->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout->addWidget(labelMaxPull, 6, 0, 1, 1);

        labelMaxPush = new QLabel(gridLayoutWidget);
        labelMaxPush->setObjectName(QString::fromUtf8("labelMaxPush"));
        labelMaxPush->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout->addWidget(labelMaxPush, 5, 0, 1, 1);

        strokeLenght = new QLineEdit(gridLayoutWidget);
        strokeLenght->setObjectName(QString::fromUtf8("strokeLenght"));

        gridLayout->addWidget(strokeLenght, 3, 2, 1, 1);

        labelControlSystem = new QLabel(gridLayoutWidget);
        labelControlSystem->setObjectName(QString::fromUtf8("labelControlSystem"));
        labelControlSystem->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelControlSystem, 0, 4, 1, 3);

        line_6 = new QFrame(gridLayoutWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_6, 7, 1, 1, 1);

        labelPowerRating = new QLabel(gridLayoutWidget);
        labelPowerRating->setObjectName(QString::fromUtf8("labelPowerRating"));
        labelPowerRating->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout->addWidget(labelPowerRating, 8, 0, 1, 1);

        maxCurrent = new QLineEdit(gridLayoutWidget);
        maxCurrent->setObjectName(QString::fromUtf8("maxCurrent"));

        gridLayout->addWidget(maxCurrent, 7, 2, 1, 1);

        line_12 = new QFrame(gridLayoutWidget);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setFrameShape(QFrame::VLine);
        line_12->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_12, 4, 5, 1, 1);

        model = new QLineEdit(gridLayoutWidget);
        model->setObjectName(QString::fromUtf8("model"));

        gridLayout->addWidget(model, 2, 2, 1, 1);

        dutyCycle = new QLineEdit(gridLayoutWidget);
        dutyCycle->setObjectName(QString::fromUtf8("dutyCycle"));

        gridLayout->addWidget(dutyCycle, 4, 2, 1, 1);

        labelSpecifications = new QLabel(gridLayoutWidget);
        labelSpecifications->setObjectName(QString::fromUtf8("labelSpecifications"));
        labelSpecifications->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelSpecifications, 0, 0, 1, 3);

        line_4 = new QFrame(gridLayoutWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_4, 5, 1, 1, 1);

        labelAccelTime = new QLabel(gridLayoutWidget);
        labelAccelTime->setObjectName(QString::fromUtf8("labelAccelTime"));
        labelAccelTime->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout->addWidget(labelAccelTime, 3, 4, 1, 1);

        strokeLabel = new QLabel(gridLayoutWidget);
        strokeLabel->setObjectName(QString::fromUtf8("strokeLabel"));
        strokeLabel->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout->addWidget(strokeLabel, 3, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 3, 1, 1);

        labelAccelRate = new QLabel(gridLayoutWidget);
        labelAccelRate->setObjectName(QString::fromUtf8("labelAccelRate"));
        labelAccelRate->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout->addWidget(labelAccelRate, 2, 4, 1, 1);

        line_2 = new QFrame(gridLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 3, 1, 1, 1);

        line_7 = new QFrame(gridLayoutWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_7, 8, 1, 1, 1);

        maxLoadPush = new QLineEdit(gridLayoutWidget);
        maxLoadPush->setObjectName(QString::fromUtf8("maxLoadPush"));

        gridLayout->addWidget(maxLoadPush, 5, 2, 1, 1);

        line_8 = new QFrame(gridLayoutWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_8, 1, 0, 1, 3);

        labelModel = new QLabel(gridLayoutWidget);
        labelModel->setObjectName(QString::fromUtf8("labelModel"));
        labelModel->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout->addWidget(labelModel, 2, 0, 1, 1);

        pushButtonInsert = new QPushButton(gridLayoutWidget);
        pushButtonInsert->setObjectName(QString::fromUtf8("pushButtonInsert"));

        gridLayout->addWidget(pushButtonInsert, 10, 0, 1, 7);

        line = new QFrame(gridLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 1, 1, 1);

        accelarationTime = new QLineEdit(gridLayoutWidget);
        accelarationTime->setObjectName(QString::fromUtf8("accelarationTime"));

        gridLayout->addWidget(accelarationTime, 3, 6, 1, 1);

        labelMaxCurrent = new QLabel(gridLayoutWidget);
        labelMaxCurrent->setObjectName(QString::fromUtf8("labelMaxCurrent"));
        labelMaxCurrent->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout->addWidget(labelMaxCurrent, 7, 0, 1, 1);

        line_5 = new QFrame(gridLayoutWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_5, 6, 1, 1, 1);

        line_9 = new QFrame(gridLayoutWidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_9, 1, 4, 1, 3);

        line_10 = new QFrame(gridLayoutWidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_10, 2, 5, 1, 1);

        line_3 = new QFrame(gridLayoutWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 4, 1, 1, 1);

        accelarationRate = new QLineEdit(gridLayoutWidget);
        accelarationRate->setObjectName(QString::fromUtf8("accelarationRate"));

        gridLayout->addWidget(accelarationRate, 2, 6, 1, 1);

        line_11 = new QFrame(gridLayoutWidget);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_11, 3, 5, 1, 1);

        maxLoadPull = new QLineEdit(gridLayoutWidget);
        maxLoadPull->setObjectName(QString::fromUtf8("maxLoadPull"));

        gridLayout->addWidget(maxLoadPull, 6, 2, 1, 1);

        labelDutyCycle = new QLabel(gridLayoutWidget);
        labelDutyCycle->setObjectName(QString::fromUtf8("labelDutyCycle"));
        labelDutyCycle->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout->addWidget(labelDutyCycle, 4, 0, 1, 1);

        powerRating = new QLineEdit(gridLayoutWidget);
        powerRating->setObjectName(QString::fromUtf8("powerRating"));

        gridLayout->addWidget(powerRating, 8, 2, 1, 1);

        labelPwmFrewq = new QLabel(gridLayoutWidget);
        labelPwmFrewq->setObjectName(QString::fromUtf8("labelPwmFrewq"));
        labelPwmFrewq->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout->addWidget(labelPwmFrewq, 4, 4, 1, 1);

        pwmFrequency = new QLineEdit(gridLayoutWidget);
        pwmFrequency->setObjectName(QString::fromUtf8("pwmFrequency"));

        gridLayout->addWidget(pwmFrequency, 4, 6, 1, 1);

        verticalSpacer = new QSpacerItem(20, 108, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 9, 0, 1, 1);

        Tab->addTab(insertTab, QString());
        editTab = new QWidget();
        editTab->setObjectName(QString::fromUtf8("editTab"));
        gridLayoutWidget_2 = new QWidget(editTab);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(180, 10, 551, 331));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        labelMaxCurrent_2 = new QLabel(gridLayoutWidget_2);
        labelMaxCurrent_2->setObjectName(QString::fromUtf8("labelMaxCurrent_2"));
        labelMaxCurrent_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelMaxCurrent_2, 7, 0, 1, 1);

        line_17 = new QFrame(gridLayoutWidget_2);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setFrameShape(QFrame::VLine);
        line_17->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_17, 8, 1, 1, 1);

        line_15 = new QFrame(gridLayoutWidget_2);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setFrameShape(QFrame::VLine);
        line_15->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_15, 5, 1, 1, 1);

        line_18 = new QFrame(gridLayoutWidget_2);
        line_18->setObjectName(QString::fromUtf8("line_18"));
        line_18->setFrameShape(QFrame::HLine);
        line_18->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_18, 1, 0, 1, 3);

        powerRating_edit = new QLineEdit(gridLayoutWidget_2);
        powerRating_edit->setObjectName(QString::fromUtf8("powerRating_edit"));

        gridLayout_2->addWidget(powerRating_edit, 8, 2, 1, 1);

        dutyCycle_edit = new QLineEdit(gridLayoutWidget_2);
        dutyCycle_edit->setObjectName(QString::fromUtf8("dutyCycle_edit"));

        gridLayout_2->addWidget(dutyCycle_edit, 4, 2, 1, 1);

        accelarationTime_edit = new QLineEdit(gridLayoutWidget_2);
        accelarationTime_edit->setObjectName(QString::fromUtf8("accelarationTime_edit"));

        gridLayout_2->addWidget(accelarationTime_edit, 3, 6, 1, 1);

        labelSpecifications_2 = new QLabel(gridLayoutWidget_2);
        labelSpecifications_2->setObjectName(QString::fromUtf8("labelSpecifications_2"));
        labelSpecifications_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelSpecifications_2, 0, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 108, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 9, 0, 1, 1);

        line_16 = new QFrame(gridLayoutWidget_2);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setFrameShape(QFrame::VLine);
        line_16->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_16, 3, 1, 1, 1);

        maxCurrent_edit = new QLineEdit(gridLayoutWidget_2);
        maxCurrent_edit->setObjectName(QString::fromUtf8("maxCurrent_edit"));

        gridLayout_2->addWidget(maxCurrent_edit, 7, 2, 1, 1);

        line_19 = new QFrame(gridLayoutWidget_2);
        line_19->setObjectName(QString::fromUtf8("line_19"));
        line_19->setFrameShape(QFrame::VLine);
        line_19->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_19, 2, 1, 1, 1);

        model_edit = new QLineEdit(gridLayoutWidget_2);
        model_edit->setObjectName(QString::fromUtf8("model_edit"));

        gridLayout_2->addWidget(model_edit, 2, 2, 1, 1);

        labelPowerRating_2 = new QLabel(gridLayoutWidget_2);
        labelPowerRating_2->setObjectName(QString::fromUtf8("labelPowerRating_2"));
        labelPowerRating_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelPowerRating_2, 8, 0, 1, 1);

        labelAccelTime_2 = new QLabel(gridLayoutWidget_2);
        labelAccelTime_2->setObjectName(QString::fromUtf8("labelAccelTime_2"));
        labelAccelTime_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelAccelTime_2, 3, 4, 1, 1);

        accelarationRate_edit = new QLineEdit(gridLayoutWidget_2);
        accelarationRate_edit->setObjectName(QString::fromUtf8("accelarationRate_edit"));

        gridLayout_2->addWidget(accelarationRate_edit, 2, 6, 1, 1);

        line_24 = new QFrame(gridLayoutWidget_2);
        line_24->setObjectName(QString::fromUtf8("line_24"));
        line_24->setFrameShape(QFrame::VLine);
        line_24->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_24, 3, 5, 1, 1);

        labelDutyCycle_2 = new QLabel(gridLayoutWidget_2);
        labelDutyCycle_2->setObjectName(QString::fromUtf8("labelDutyCycle_2"));
        labelDutyCycle_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelDutyCycle_2, 4, 0, 1, 1);

        labelMaxPull_2 = new QLabel(gridLayoutWidget_2);
        labelMaxPull_2->setObjectName(QString::fromUtf8("labelMaxPull_2"));
        labelMaxPull_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelMaxPull_2, 6, 0, 1, 1);

        line_20 = new QFrame(gridLayoutWidget_2);
        line_20->setObjectName(QString::fromUtf8("line_20"));
        line_20->setFrameShape(QFrame::VLine);
        line_20->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_20, 6, 1, 1, 1);

        labelMaxPush_2 = new QLabel(gridLayoutWidget_2);
        labelMaxPush_2->setObjectName(QString::fromUtf8("labelMaxPush_2"));
        labelMaxPush_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelMaxPush_2, 5, 0, 1, 1);

        maxLoadPush_edit = new QLineEdit(gridLayoutWidget_2);
        maxLoadPush_edit->setObjectName(QString::fromUtf8("maxLoadPush_edit"));

        gridLayout_2->addWidget(maxLoadPush_edit, 5, 2, 1, 1);

        labelAccelRate_2 = new QLabel(gridLayoutWidget_2);
        labelAccelRate_2->setObjectName(QString::fromUtf8("labelAccelRate_2"));
        labelAccelRate_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelAccelRate_2, 2, 4, 1, 1);

        pushButtonInsert_2 = new QPushButton(gridLayoutWidget_2);
        pushButtonInsert_2->setObjectName(QString::fromUtf8("pushButtonInsert_2"));

        gridLayout_2->addWidget(pushButtonInsert_2, 10, 0, 1, 7);

        labelModel_2 = new QLabel(gridLayoutWidget_2);
        labelModel_2->setObjectName(QString::fromUtf8("labelModel_2"));
        labelModel_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelModel_2, 2, 0, 1, 1);

        line_22 = new QFrame(gridLayoutWidget_2);
        line_22->setObjectName(QString::fromUtf8("line_22"));
        line_22->setFrameShape(QFrame::VLine);
        line_22->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_22, 2, 5, 1, 1);

        line_21 = new QFrame(gridLayoutWidget_2);
        line_21->setObjectName(QString::fromUtf8("line_21"));
        line_21->setFrameShape(QFrame::HLine);
        line_21->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_21, 1, 4, 1, 3);

        line_14 = new QFrame(gridLayoutWidget_2);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setFrameShape(QFrame::VLine);
        line_14->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_14, 4, 5, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 4, 3, 1, 1);

        line_23 = new QFrame(gridLayoutWidget_2);
        line_23->setObjectName(QString::fromUtf8("line_23"));
        line_23->setFrameShape(QFrame::VLine);
        line_23->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_23, 4, 1, 1, 1);

        line_13 = new QFrame(gridLayoutWidget_2);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setFrameShape(QFrame::VLine);
        line_13->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_13, 7, 1, 1, 1);

        labelPwmFrewq_2 = new QLabel(gridLayoutWidget_2);
        labelPwmFrewq_2->setObjectName(QString::fromUtf8("labelPwmFrewq_2"));
        labelPwmFrewq_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(labelPwmFrewq_2, 4, 4, 1, 1);

        maxLoadPull_edit = new QLineEdit(gridLayoutWidget_2);
        maxLoadPull_edit->setObjectName(QString::fromUtf8("maxLoadPull_edit"));

        gridLayout_2->addWidget(maxLoadPull_edit, 6, 2, 1, 1);

        strokeLenght_edit = new QLineEdit(gridLayoutWidget_2);
        strokeLenght_edit->setObjectName(QString::fromUtf8("strokeLenght_edit"));

        gridLayout_2->addWidget(strokeLenght_edit, 3, 2, 1, 1);

        labelControlSystem_2 = new QLabel(gridLayoutWidget_2);
        labelControlSystem_2->setObjectName(QString::fromUtf8("labelControlSystem_2"));
        labelControlSystem_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(labelControlSystem_2, 0, 4, 1, 3);

        strokeLabel_2 = new QLabel(gridLayoutWidget_2);
        strokeLabel_2->setObjectName(QString::fromUtf8("strokeLabel_2"));
        strokeLabel_2->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_2->addWidget(strokeLabel_2, 3, 0, 1, 1);

        pwmFrequency_edit = new QLineEdit(gridLayoutWidget_2);
        pwmFrequency_edit->setObjectName(QString::fromUtf8("pwmFrequency_edit"));

        gridLayout_2->addWidget(pwmFrequency_edit, 4, 6, 1, 1);

        chooseModelEdit = new QComboBox(editTab);
        chooseModelEdit->setObjectName(QString::fromUtf8("chooseModelEdit"));
        chooseModelEdit->setGeometry(QRect(10, 140, 161, 25));
        Tab->addTab(editTab, QString());
        statusTab = new QWidget();
        statusTab->setObjectName(QString::fromUtf8("statusTab"));
        chooseModelStatus = new QComboBox(statusTab);
        chooseModelStatus->setObjectName(QString::fromUtf8("chooseModelStatus"));
        chooseModelStatus->setGeometry(QRect(0, 10, 161, 25));
        gridLayoutWidget_3 = new QWidget(statusTab);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(40, 60, 621, 271));
        gridLayoutWidget_3->setMouseTracking(false);
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        labelSpecifications_3 = new QLabel(gridLayoutWidget_3);
        labelSpecifications_3->setObjectName(QString::fromUtf8("labelSpecifications_3"));
        labelSpecifications_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelSpecifications_3, 0, 0, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 5, 3, 1, 1);

        line_32 = new QFrame(gridLayoutWidget_3);
        line_32->setObjectName(QString::fromUtf8("line_32"));
        line_32->setFrameShape(QFrame::VLine);
        line_32->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_32, 7, 1, 1, 1);

        line_34 = new QFrame(gridLayoutWidget_3);
        line_34->setObjectName(QString::fromUtf8("line_34"));
        line_34->setFrameShape(QFrame::VLine);
        line_34->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_34, 3, 5, 1, 1);

        line_26 = new QFrame(gridLayoutWidget_3);
        line_26->setObjectName(QString::fromUtf8("line_26"));
        line_26->setFrameShape(QFrame::VLine);
        line_26->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_26, 5, 5, 1, 1);

        pushButtonInsert_3 = new QPushButton(gridLayoutWidget_3);
        pushButtonInsert_3->setObjectName(QString::fromUtf8("pushButtonInsert_3"));

        gridLayout_3->addWidget(pushButtonInsert_3, 10, 0, 1, 7);

        strokeLabel_3 = new QLabel(gridLayoutWidget_3);
        strokeLabel_3->setObjectName(QString::fromUtf8("strokeLabel_3"));
        strokeLabel_3->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_3->addWidget(strokeLabel_3, 4, 0, 1, 1);

        line_30 = new QFrame(gridLayoutWidget_3);
        line_30->setObjectName(QString::fromUtf8("line_30"));
        line_30->setFrameShape(QFrame::HLine);
        line_30->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_30, 1, 0, 1, 3);

        labelMaxPush_3 = new QLabel(gridLayoutWidget_3);
        labelMaxPush_3->setObjectName(QString::fromUtf8("labelMaxPush_3"));
        labelMaxPush_3->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_3->addWidget(labelMaxPush_3, 6, 0, 1, 1);

        strokeLenght_3 = new QLineEdit(gridLayoutWidget_3);
        strokeLenght_3->setObjectName(QString::fromUtf8("strokeLenght_3"));
        strokeLenght_3->setEnabled(false);
        strokeLenght_3->setMouseTracking(false);

        gridLayout_3->addWidget(strokeLenght_3, 4, 2, 1, 1);

        labelDutyCycle_3 = new QLabel(gridLayoutWidget_3);
        labelDutyCycle_3->setObjectName(QString::fromUtf8("labelDutyCycle_3"));
        labelDutyCycle_3->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_3->addWidget(labelDutyCycle_3, 5, 0, 1, 1);

        labelModel_3 = new QLabel(gridLayoutWidget_3);
        labelModel_3->setObjectName(QString::fromUtf8("labelModel_3"));
        labelModel_3->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_3->addWidget(labelModel_3, 3, 0, 1, 1);

        line_29 = new QFrame(gridLayoutWidget_3);
        line_29->setObjectName(QString::fromUtf8("line_29"));
        line_29->setFrameShape(QFrame::VLine);
        line_29->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_29, 8, 1, 1, 1);

        labelPwmFrewq_3 = new QLabel(gridLayoutWidget_3);
        labelPwmFrewq_3->setObjectName(QString::fromUtf8("labelPwmFrewq_3"));
        labelPwmFrewq_3->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_3->addWidget(labelPwmFrewq_3, 5, 4, 1, 1);

        pwmFrequency_3 = new QLineEdit(gridLayoutWidget_3);
        pwmFrequency_3->setObjectName(QString::fromUtf8("pwmFrequency_3"));
        pwmFrequency_3->setEnabled(false);
        pwmFrequency_3->setMouseTracking(false);

        gridLayout_3->addWidget(pwmFrequency_3, 5, 6, 1, 1);

        model_3 = new QLineEdit(gridLayoutWidget_3);
        model_3->setObjectName(QString::fromUtf8("model_3"));
        model_3->setEnabled(false);
        model_3->setMouseTracking(false);

        gridLayout_3->addWidget(model_3, 3, 2, 1, 1);

        accelarationRate_3 = new QLineEdit(gridLayoutWidget_3);
        accelarationRate_3->setObjectName(QString::fromUtf8("accelarationRate_3"));
        accelarationRate_3->setEnabled(false);
        accelarationRate_3->setMouseTracking(false);

        gridLayout_3->addWidget(accelarationRate_3, 3, 6, 1, 1);

        labelMaxPull_3 = new QLabel(gridLayoutWidget_3);
        labelMaxPull_3->setObjectName(QString::fromUtf8("labelMaxPull_3"));
        labelMaxPull_3->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_3->addWidget(labelMaxPull_3, 7, 0, 1, 1);

        maxLoadPush_3 = new QLineEdit(gridLayoutWidget_3);
        maxLoadPush_3->setObjectName(QString::fromUtf8("maxLoadPush_3"));
        maxLoadPush_3->setEnabled(false);
        maxLoadPush_3->setMouseTracking(false);

        gridLayout_3->addWidget(maxLoadPush_3, 6, 2, 1, 1);

        line_31 = new QFrame(gridLayoutWidget_3);
        line_31->setObjectName(QString::fromUtf8("line_31"));
        line_31->setFrameShape(QFrame::VLine);
        line_31->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_31, 3, 1, 1, 1);

        line_33 = new QFrame(gridLayoutWidget_3);
        line_33->setObjectName(QString::fromUtf8("line_33"));
        line_33->setFrameShape(QFrame::HLine);
        line_33->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_33, 1, 4, 1, 3);

        verticalSpacer_3 = new QSpacerItem(20, 108, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 9, 0, 1, 1);

        labelControlSystem_3 = new QLabel(gridLayoutWidget_3);
        labelControlSystem_3->setObjectName(QString::fromUtf8("labelControlSystem_3"));
        labelControlSystem_3->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(labelControlSystem_3, 0, 4, 1, 3);

        accelarationTime_3 = new QLineEdit(gridLayoutWidget_3);
        accelarationTime_3->setObjectName(QString::fromUtf8("accelarationTime_3"));
        accelarationTime_3->setEnabled(false);
        accelarationTime_3->setMouseTracking(false);

        gridLayout_3->addWidget(accelarationTime_3, 4, 6, 1, 1);

        line_27 = new QFrame(gridLayoutWidget_3);
        line_27->setObjectName(QString::fromUtf8("line_27"));
        line_27->setFrameShape(QFrame::VLine);
        line_27->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_27, 6, 1, 1, 1);

        labelPwmFrewq_4 = new QLabel(gridLayoutWidget_3);
        labelPwmFrewq_4->setObjectName(QString::fromUtf8("labelPwmFrewq_4"));
        labelPwmFrewq_4->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_3->addWidget(labelPwmFrewq_4, 4, 4, 1, 1);

        line_36 = new QFrame(gridLayoutWidget_3);
        line_36->setObjectName(QString::fromUtf8("line_36"));
        line_36->setFrameShape(QFrame::VLine);
        line_36->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_36, 4, 5, 1, 1);

        maxLoadPull_3 = new QLineEdit(gridLayoutWidget_3);
        maxLoadPull_3->setObjectName(QString::fromUtf8("maxLoadPull_3"));
        maxLoadPull_3->setEnabled(false);
        maxLoadPull_3->setMouseTracking(false);

        gridLayout_3->addWidget(maxLoadPull_3, 7, 2, 1, 1);

        dutyCycle_3 = new QLineEdit(gridLayoutWidget_3);
        dutyCycle_3->setObjectName(QString::fromUtf8("dutyCycle_3"));
        dutyCycle_3->setEnabled(false);
        dutyCycle_3->setMouseTracking(false);

        gridLayout_3->addWidget(dutyCycle_3, 5, 2, 1, 1);

        line_28 = new QFrame(gridLayoutWidget_3);
        line_28->setObjectName(QString::fromUtf8("line_28"));
        line_28->setFrameShape(QFrame::VLine);
        line_28->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_28, 4, 1, 1, 1);

        line_35 = new QFrame(gridLayoutWidget_3);
        line_35->setObjectName(QString::fromUtf8("line_35"));
        line_35->setFrameShape(QFrame::VLine);
        line_35->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_35, 5, 1, 1, 1);

        labelPwmFrewq_5 = new QLabel(gridLayoutWidget_3);
        labelPwmFrewq_5->setObjectName(QString::fromUtf8("labelPwmFrewq_5"));
        labelPwmFrewq_5->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout_3->addWidget(labelPwmFrewq_5, 3, 4, 1, 1);

        Tab->addTab(statusTab, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        Tab->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelMaxPull->setText(QCoreApplication::translate("MainWindow", "Max. load in pull (N)", nullptr));
        labelMaxPush->setText(QCoreApplication::translate("MainWindow", "Max. load in push (N)", nullptr));
        labelControlSystem->setText(QCoreApplication::translate("MainWindow", "Control System Configuration", nullptr));
        labelPowerRating->setText(QCoreApplication::translate("MainWindow", "Power rating (V)", nullptr));
        labelSpecifications->setText(QCoreApplication::translate("MainWindow", "Linear Acuator Specifications", nullptr));
        labelAccelTime->setText(QCoreApplication::translate("MainWindow", "Aceelaration time (ms)", nullptr));
        strokeLabel->setText(QCoreApplication::translate("MainWindow", "Stroke lenght (mm)", nullptr));
        labelAccelRate->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Accelaration rate (mm/s<span style=\" vertical-align:super;\">2</span>)</p></body></html>", nullptr));
        labelModel->setText(QCoreApplication::translate("MainWindow", "Model", nullptr));
        pushButtonInsert->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        labelMaxCurrent->setText(QCoreApplication::translate("MainWindow", "Max. current (A)", nullptr));
        labelDutyCycle->setText(QCoreApplication::translate("MainWindow", "Duty cycle (%)", nullptr));
        labelPwmFrewq->setText(QCoreApplication::translate("MainWindow", "PWM Frequency (kHz)", nullptr));
        Tab->setTabText(Tab->indexOf(insertTab), QCoreApplication::translate("MainWindow", "Insert", nullptr));
        labelMaxCurrent_2->setText(QCoreApplication::translate("MainWindow", "Max. current (A)", nullptr));
        labelSpecifications_2->setText(QCoreApplication::translate("MainWindow", "Linear Acuator Specifications", nullptr));
        labelPowerRating_2->setText(QCoreApplication::translate("MainWindow", "Power rating (V)", nullptr));
        labelAccelTime_2->setText(QCoreApplication::translate("MainWindow", "Aceelaration time (ms)", nullptr));
        labelDutyCycle_2->setText(QCoreApplication::translate("MainWindow", "Duty cycle (%)", nullptr));
        labelMaxPull_2->setText(QCoreApplication::translate("MainWindow", "Max. load in pull (N)", nullptr));
        labelMaxPush_2->setText(QCoreApplication::translate("MainWindow", "Max. load in push (N)", nullptr));
        labelAccelRate_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Accelaration rate (mm/s<span style=\" vertical-align:super;\">2</span>)</p></body></html>", nullptr));
        pushButtonInsert_2->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        labelModel_2->setText(QCoreApplication::translate("MainWindow", "Model", nullptr));
        labelPwmFrewq_2->setText(QCoreApplication::translate("MainWindow", "PWM Frequency (kHz)", nullptr));
        labelControlSystem_2->setText(QCoreApplication::translate("MainWindow", "Control System Configuration", nullptr));
        strokeLabel_2->setText(QCoreApplication::translate("MainWindow", "Stroke lenght (mm)", nullptr));
        Tab->setTabText(Tab->indexOf(editTab), QCoreApplication::translate("MainWindow", "Edit", nullptr));
        labelSpecifications_3->setText(QCoreApplication::translate("MainWindow", "Linear Acuator ", nullptr));
        pushButtonInsert_3->setText(QCoreApplication::translate("MainWindow", "UPDATE", nullptr));
        strokeLabel_3->setText(QCoreApplication::translate("MainWindow", "Linear speed (mm/s)", nullptr));
        labelMaxPush_3->setText(QCoreApplication::translate("MainWindow", "Position (mm)", nullptr));
        labelDutyCycle_3->setText(QCoreApplication::translate("MainWindow", "Rotor speed (rad/s)", nullptr));
        labelModel_3->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        labelPwmFrewq_3->setText(QCoreApplication::translate("MainWindow", "Eample 1", nullptr));
        labelMaxPull_3->setText(QCoreApplication::translate("MainWindow", "Pulse rate (#imp/mm)", nullptr));
        labelControlSystem_3->setText(QCoreApplication::translate("MainWindow", "Drive", nullptr));
        labelPwmFrewq_4->setText(QCoreApplication::translate("MainWindow", "Eample 1", nullptr));
        labelPwmFrewq_5->setText(QCoreApplication::translate("MainWindow", "Eample 1", nullptr));
        Tab->setTabText(Tab->indexOf(statusTab), QCoreApplication::translate("MainWindow", "Status", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
