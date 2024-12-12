/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *leftColumn;
    QVBoxLayout *verticalLayout;
    QWidget *restaurantArea;
    QWidget *rightColumn;
    QVBoxLayout *rightLayout;
    QLabel *titleLabel;
    QWidget *buttonArea;
    QHBoxLayout *buttonLayout;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QWidget *emptyArea;
    QLabel *timeLabel;
    QLabel *statusLabel;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 650);
        MainWindow->setMinimumSize(QSize(1200, 650));
        MainWindow->setMaximumSize(QSize(1200, 650));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: white;"));
        horizontalLayout = new QHBoxLayout(MainWindow);
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        leftColumn = new QWidget(MainWindow);
        leftColumn->setObjectName("leftColumn");
        leftColumn->setStyleSheet(QString::fromUtf8("background-color: white;"));
        leftColumn->setMinimumSize(QSize(1000, 620));
        verticalLayout = new QVBoxLayout(leftColumn);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        restaurantArea = new QWidget(leftColumn);
        restaurantArea->setObjectName("restaurantArea");
        restaurantArea->setStyleSheet(QString::fromUtf8("background-color: grey; border: 2px solid black; border-radius: 15px;"));
        restaurantArea->setMinimumSize(QSize(0, 0));

        verticalLayout->addWidget(restaurantArea);


        horizontalLayout->addWidget(leftColumn);

        rightColumn = new QWidget(MainWindow);
        rightColumn->setObjectName("rightColumn");
        rightColumn->setStyleSheet(QString::fromUtf8("background-color: white;"));
        rightColumn->setMinimumSize(QSize(170, 620));
        rightLayout = new QVBoxLayout(rightColumn);
        rightLayout->setObjectName("rightLayout");
        rightLayout->setContentsMargins(0, 0, 0, 0);
        titleLabel = new QLabel(rightColumn);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignCenter);
        titleLabel->setStyleSheet(QString::fromUtf8("color: black; font-size: 20px; font-weight: bold; border: 1px solid black; padding: 5px;"));
        titleLabel->setFixedHeight(30);

        rightLayout->addWidget(titleLabel);

        buttonArea = new QWidget(rightColumn);
        buttonArea->setObjectName("buttonArea");
        buttonArea->setFixedHeight(30);
        buttonLayout = new QHBoxLayout(buttonArea);
        buttonLayout->setObjectName("buttonLayout");
        buttonLayout->setContentsMargins(0, 0, 0, 0);
        button1 = new QPushButton(buttonArea);
        button1->setObjectName("button1");

        buttonLayout->addWidget(button1);

        button2 = new QPushButton(buttonArea);
        button2->setObjectName("button2");

        buttonLayout->addWidget(button2);

        button3 = new QPushButton(buttonArea);
        button3->setObjectName("button3");

        buttonLayout->addWidget(button3);


        rightLayout->addWidget(buttonArea);

        emptyArea = new QWidget(rightColumn);
        emptyArea->setObjectName("emptyArea");
        emptyArea->setStyleSheet(QString::fromUtf8("border: 1px solid black;"));

        rightLayout->addWidget(emptyArea);

        timeLabel = new QLabel(rightColumn);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setAlignment(Qt::AlignCenter);
        timeLabel->setStyleSheet(QString::fromUtf8("color: black; font-size: 18px; border: 1px solid black; padding: 5px; height: 50px"));
        timeLabel->setFixedHeight(30);

        rightLayout->addWidget(timeLabel);

        statusLabel = new QLabel(rightColumn);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setAlignment(Qt::AlignCenter);
        statusLabel->setStyleSheet(QString::fromUtf8("color: black; font-size: 18px; border: 1px solid black; padding: 5px; height: 50px"));
        statusLabel->setFixedHeight(30);

        rightLayout->addWidget(statusLabel);


        horizontalLayout->addWidget(rightColumn);


        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Restauration", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "Ouvert", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
