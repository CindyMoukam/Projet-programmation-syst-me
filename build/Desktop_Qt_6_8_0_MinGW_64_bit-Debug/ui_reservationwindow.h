/********************************************************************************
** Form generated from reading UI file 'reservationwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERVATIONWINDOW_H
#define UI_RESERVATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReservationWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *questionLabel;
    QHBoxLayout *buttonLayout;
    QPushButton *yesButton;
    QPushButton *noButton;

    void setupUi(QWidget *ReservationWindow)
    {
        if (ReservationWindow->objectName().isEmpty())
            ReservationWindow->setObjectName("ReservationWindow");
        ReservationWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(ReservationWindow);
        verticalLayout->setObjectName("verticalLayout");
        questionLabel = new QLabel(ReservationWindow);
        questionLabel->setObjectName("questionLabel");
        questionLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(questionLabel);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        yesButton = new QPushButton(ReservationWindow);
        yesButton->setObjectName("yesButton");

        buttonLayout->addWidget(yesButton);

        noButton = new QPushButton(ReservationWindow);
        noButton->setObjectName("noButton");

        buttonLayout->addWidget(noButton);


        verticalLayout->addLayout(buttonLayout);


        retranslateUi(ReservationWindow);

        QMetaObject::connectSlotsByName(ReservationWindow);
    } // setupUi

    void retranslateUi(QWidget *ReservationWindow)
    {
        ReservationWindow->setWindowTitle(QCoreApplication::translate("ReservationWindow", "R\303\251servation", nullptr));
        questionLabel->setText(QCoreApplication::translate("ReservationWindow", "Avez-vous une r\303\251servation ?", nullptr));
        yesButton->setText(QCoreApplication::translate("ReservationWindow", "Oui", nullptr));
        noButton->setText(QCoreApplication::translate("ReservationWindow", "Non", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReservationWindow: public Ui_ReservationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERVATIONWINDOW_H
