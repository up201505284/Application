/********************************************************************************
** Form generated from reading UI file 'addnewlinearactuator.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWLINEARACTUATOR_H
#define UI_ADDNEWLINEARACTUATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addNewLinearActuator
{
public:
    QWidget *formLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLabel *label_3;
    QFrame *line_2;
    QLabel *label;
    QLineEdit *pwmFreq;
    QLineEdit *accelRate;
    QLineEdit *dutyCycle;
    QLabel *label_9;
    QFrame *line;
    QLabel *label_12;
    QLabel *label_5;
    QLineEdit *maxLoadPush;
    QLineEdit *powerRating;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *maxLoadPull;
    QLabel *label_2;
    QLabel *label_6;
    QLineEdit *model;
    QSpacerItem *verticalSpacer;
    QLabel *label_11;
    QLabel *label_10;
    QLabel *label_8;
    QLineEdit *maxCurrent;
    QLabel *label_4;
    QLineEdit *strokeLenght;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *accelTime;
    QPushButton *add;

    void setupUi(QWidget *addNewLinearActuator)
    {
        if (addNewLinearActuator->objectName().isEmpty())
            addNewLinearActuator->setObjectName(QString::fromUtf8("addNewLinearActuator"));
        addNewLinearActuator->resize(1206, 721);
        formLayoutWidget = new QWidget(addNewLinearActuator);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(100, 110, 571, 441));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(formLayoutWidget->sizePolicy().hasHeightForWidth());
        formLayoutWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(formLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        line_2 = new QFrame(formLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 17, 0, 1, 2);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 6, 0, 1, 1);

        pwmFreq = new QLineEdit(formLayoutWidget);
        pwmFreq->setObjectName(QString::fromUtf8("pwmFreq"));
        sizePolicy.setHeightForWidth(pwmFreq->sizePolicy().hasHeightForWidth());
        pwmFreq->setSizePolicy(sizePolicy);

        gridLayout->addWidget(pwmFreq, 13, 1, 1, 1);

        accelRate = new QLineEdit(formLayoutWidget);
        accelRate->setObjectName(QString::fromUtf8("accelRate"));
        sizePolicy.setHeightForWidth(accelRate->sizePolicy().hasHeightForWidth());
        accelRate->setSizePolicy(sizePolicy);

        gridLayout->addWidget(accelRate, 11, 1, 1, 1);

        dutyCycle = new QLineEdit(formLayoutWidget);
        dutyCycle->setObjectName(QString::fromUtf8("dutyCycle"));
        sizePolicy.setHeightForWidth(dutyCycle->sizePolicy().hasHeightForWidth());
        dutyCycle->setSizePolicy(sizePolicy);

        gridLayout->addWidget(dutyCycle, 7, 1, 1, 1);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 10, 0, 1, 2);

        line = new QFrame(formLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 9, 0, 1, 2);

        label_12 = new QLabel(formLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_12, 12, 0, 1, 1);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        maxLoadPush = new QLineEdit(formLayoutWidget);
        maxLoadPush->setObjectName(QString::fromUtf8("maxLoadPush"));
        sizePolicy.setHeightForWidth(maxLoadPush->sizePolicy().hasHeightForWidth());
        maxLoadPush->setSizePolicy(sizePolicy);

        gridLayout->addWidget(maxLoadPush, 3, 1, 1, 1);

        powerRating = new QLineEdit(formLayoutWidget);
        powerRating->setObjectName(QString::fromUtf8("powerRating"));
        sizePolicy.setHeightForWidth(powerRating->sizePolicy().hasHeightForWidth());
        powerRating->setSizePolicy(sizePolicy);

        gridLayout->addWidget(powerRating, 6, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 8, 0, 1, 1);

        maxLoadPull = new QLineEdit(formLayoutWidget);
        maxLoadPull->setObjectName(QString::fromUtf8("maxLoadPull"));
        sizePolicy.setHeightForWidth(maxLoadPull->sizePolicy().hasHeightForWidth());
        maxLoadPull->setSizePolicy(sizePolicy);

        gridLayout->addWidget(maxLoadPull, 4, 1, 1, 1);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 3, 0, 1, 1);

        model = new QLineEdit(formLayoutWidget);
        model->setObjectName(QString::fromUtf8("model"));
        sizePolicy.setHeightForWidth(model->sizePolicy().hasHeightForWidth());
        model->setSizePolicy(sizePolicy);

        gridLayout->addWidget(model, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 1, 1, 1);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_11, 11, 0, 1, 1);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 13, 0, 1, 1);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 0, 0, 1, 2);

        maxCurrent = new QLineEdit(formLayoutWidget);
        maxCurrent->setObjectName(QString::fromUtf8("maxCurrent"));
        sizePolicy.setHeightForWidth(maxCurrent->sizePolicy().hasHeightForWidth());
        maxCurrent->setSizePolicy(sizePolicy);

        gridLayout->addWidget(maxCurrent, 5, 1, 1, 1);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        strokeLenght = new QLineEdit(formLayoutWidget);
        strokeLenght->setObjectName(QString::fromUtf8("strokeLenght"));
        sizePolicy.setHeightForWidth(strokeLenght->sizePolicy().hasHeightForWidth());
        strokeLenght->setSizePolicy(sizePolicy);

        gridLayout->addWidget(strokeLenght, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 14, 0, 1, 1);

        accelTime = new QLineEdit(formLayoutWidget);
        accelTime->setObjectName(QString::fromUtf8("accelTime"));
        sizePolicy.setHeightForWidth(accelTime->sizePolicy().hasHeightForWidth());
        accelTime->setSizePolicy(sizePolicy);

        gridLayout->addWidget(accelTime, 12, 1, 1, 1);

        add = new QPushButton(formLayoutWidget);
        add->setObjectName(QString::fromUtf8("add"));
        sizePolicy.setHeightForWidth(add->sizePolicy().hasHeightForWidth());
        add->setSizePolicy(sizePolicy);

        gridLayout->addWidget(add, 16, 0, 1, 2);


        retranslateUi(addNewLinearActuator);

        QMetaObject::connectSlotsByName(addNewLinearActuator);
    } // setupUi

    void retranslateUi(QWidget *addNewLinearActuator)
    {
        addNewLinearActuator->setWindowTitle(QCoreApplication::translate("addNewLinearActuator", "Form", nullptr));
        label_7->setText(QCoreApplication::translate("addNewLinearActuator", "Duty Cycle (%)", nullptr));
        label_3->setText(QCoreApplication::translate("addNewLinearActuator", "Max. current (A)", nullptr));
        label->setText(QCoreApplication::translate("addNewLinearActuator", "Power rating (V)", nullptr));
        label_9->setText(QCoreApplication::translate("addNewLinearActuator", "Control System", nullptr));
        label_12->setText(QCoreApplication::translate("addNewLinearActuator", "Accelaration time (ms)", nullptr));
        label_5->setText(QCoreApplication::translate("addNewLinearActuator", "Stroke lenght (mm)", nullptr));
        label_2->setText(QCoreApplication::translate("addNewLinearActuator", "Model", nullptr));
        label_6->setText(QCoreApplication::translate("addNewLinearActuator", "Max. load in push (N)", nullptr));
        label_11->setText(QCoreApplication::translate("addNewLinearActuator", "<html><head/><body><p>Accelaration rate (mm/s<span style=\" vertical-align:super;\">2</span>)</p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("addNewLinearActuator", "PWM frequency (kHz)", nullptr));
        label_8->setText(QCoreApplication::translate("addNewLinearActuator", "LInear Actuator Specifications", nullptr));
        label_4->setText(QCoreApplication::translate("addNewLinearActuator", "Max. load in pull (N)", nullptr));
        add->setText(QCoreApplication::translate("addNewLinearActuator", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addNewLinearActuator: public Ui_addNewLinearActuator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWLINEARACTUATOR_H
