/********************************************************************************
** Form generated from reading UI file 'restaurantview.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTAURANTVIEW_H
#define UI_RESTAURANTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RestaurantView
{
public:
    QHBoxLayout *mainLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *rightPanelLayout;
    QLCDNumber *lcdDateTime;
    QHBoxLayout *buttonLayout;
    QPushButton *btnPlayStop;
    QPushButton *btnSpeedUp;
    QTabWidget *tabWidget;

    void setupUi(QWidget *RestaurantView)
    {
        if (RestaurantView->objectName().isEmpty())
            RestaurantView->setObjectName("RestaurantView");
        RestaurantView->resize(1448, 966);
        mainLayout = new QHBoxLayout(RestaurantView);
        mainLayout->setObjectName("mainLayout");
        graphicsView = new QGraphicsView(RestaurantView);
        graphicsView->setObjectName("graphicsView");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);

        mainLayout->addWidget(graphicsView);

        rightPanelLayout = new QVBoxLayout();
        rightPanelLayout->setObjectName("rightPanelLayout");
        lcdDateTime = new QLCDNumber(RestaurantView);
        lcdDateTime->setObjectName("lcdDateTime");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lcdDateTime->sizePolicy().hasHeightForWidth());
        lcdDateTime->setSizePolicy(sizePolicy1);

        rightPanelLayout->addWidget(lcdDateTime);

        buttonLayout = new QHBoxLayout();
        buttonLayout->setObjectName("buttonLayout");
        btnPlayStop = new QPushButton(RestaurantView);
        btnPlayStop->setObjectName("btnPlayStop");

        buttonLayout->addWidget(btnPlayStop);

        btnSpeedUp = new QPushButton(RestaurantView);
        btnSpeedUp->setObjectName("btnSpeedUp");

        buttonLayout->addWidget(btnSpeedUp);


        rightPanelLayout->addLayout(buttonLayout);

        tabWidget = new QTabWidget(RestaurantView);
        tabWidget->setObjectName("tabWidget");
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);

        rightPanelLayout->addWidget(tabWidget);


        mainLayout->addLayout(rightPanelLayout);


        retranslateUi(RestaurantView);

        QMetaObject::connectSlotsByName(RestaurantView);
    } // setupUi

    void retranslateUi(QWidget *RestaurantView)
    {
        RestaurantView->setWindowTitle(QCoreApplication::translate("RestaurantView", "Restaurant Management", nullptr));
        btnPlayStop->setText(QCoreApplication::translate("RestaurantView", "Pause", nullptr));
        btnPlayStop->setStyleSheet(QCoreApplication::translate("RestaurantView", "\n"
"                 font-weight: bold;\n"
"                 font-size: 14px;\n"
"                 height: 50px;\n"
"               ", nullptr));
        btnSpeedUp->setText(QCoreApplication::translate("RestaurantView", "Accelerate", nullptr));
        btnSpeedUp->setStyleSheet(QCoreApplication::translate("RestaurantView", "\n"
"                 font-weight: bold;\n"
"                 font-size: 14px;\n"
"                 height: 50px;\n"
"               ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RestaurantView: public Ui_RestaurantView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTAURANTVIEW_H
