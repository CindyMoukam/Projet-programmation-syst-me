/********************************************************************************
** Form generated from reading UI file 'plat.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAT_H
#define UI_PLAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_plat
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;

    void setupUi(QWidget *plat)
    {
        if (plat->objectName().isEmpty())
            plat->setObjectName("plat");
        plat->resize(800, 600);
        verticalLayout = new QVBoxLayout(plat);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(plat);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 780, 1200));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(30);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(plat);

        QMetaObject::connectSlotsByName(plat);
    } // setupUi

    void retranslateUi(QWidget *plat)
    {
        plat->setWindowTitle(QCoreApplication::translate("plat", "Plats", nullptr));
    } // retranslateUi

};

namespace Ui {
    class plat: public Ui_plat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAT_H
