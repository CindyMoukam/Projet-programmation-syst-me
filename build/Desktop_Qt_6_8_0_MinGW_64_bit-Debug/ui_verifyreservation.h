/********************************************************************************
** Form generated from reading UI file 'verifyreservation.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFYRESERVATION_H
#define UI_VERIFYRESERVATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VerifyReservation
{
public:
    QPushButton *backButton;
    QVBoxLayout *mainLayout;
    QHBoxLayout *hboxLayout;
    QLabel *iconLabel;
    QLabel *label;
    QHBoxLayout *hboxLayout1;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLabel *errorLabel;
    QPushButton *validateButton;

    void setupUi(QWidget *VerifyReservation)
    {
        if (VerifyReservation->objectName().isEmpty())
            VerifyReservation->setObjectName("VerifyReservation");
        VerifyReservation->resize(400, 300);
        backButton = new QPushButton(VerifyReservation);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 10, 50, 30));
        mainLayout = new QVBoxLayout(VerifyReservation);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setAlignment(Qt::AlignHCenter);
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        hboxLayout->setAlignment(Qt::AlignCenter);
        iconLabel = new QLabel(VerifyReservation);
        iconLabel->setObjectName("iconLabel");
        iconLabel->setPixmap(QPixmap(QString::fromUtf8(":static/search_icon.png")));
        iconLabel->setScaledContents(true);
        iconLabel->setMinimumSize(QSize(50, 50));
        iconLabel->setMaximumSize(QSize(50, 50));

        hboxLayout->addWidget(iconLabel);


        mainLayout->addLayout(hboxLayout);

        label = new QLabel(VerifyReservation);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(label);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName("hboxLayout1");
        comboBox = new QComboBox(VerifyReservation);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        hboxLayout1->addWidget(comboBox);

        lineEdit = new QLineEdit(VerifyReservation);
        lineEdit->setObjectName("lineEdit");

        hboxLayout1->addWidget(lineEdit);


        mainLayout->addLayout(hboxLayout1);

        errorLabel = new QLabel(VerifyReservation);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(errorLabel);

        validateButton = new QPushButton(VerifyReservation);
        validateButton->setObjectName("validateButton");

        mainLayout->addWidget(validateButton);


        retranslateUi(VerifyReservation);

        QMetaObject::connectSlotsByName(VerifyReservation);
    } // setupUi

    void retranslateUi(QWidget *VerifyReservation)
    {
        VerifyReservation->setWindowTitle(QCoreApplication::translate("VerifyReservation", "V\303\251rification de la r\303\251servation", nullptr));
        backButton->setText(QCoreApplication::translate("VerifyReservation", "\342\254\205", nullptr));
        label->setText(QCoreApplication::translate("VerifyReservation", "Veuillez v\303\251rifier votre r\303\251servation :", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("VerifyReservation", "Id", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("VerifyReservation", "Nom", nullptr));

        errorLabel->setText(QString());
        errorLabel->setStyleSheet(QCoreApplication::translate("VerifyReservation", "color: red;", nullptr));
        validateButton->setText(QCoreApplication::translate("VerifyReservation", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VerifyReservation: public Ui_VerifyReservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFYRESERVATION_H
