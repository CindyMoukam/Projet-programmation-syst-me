/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuPage
{
public:
    QPushButton *invoiceButton;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *titleLayout;
    QLabel *iconLabel;
    QLabel *titleLabel;
    QSpacerItem *verticalSpacer1;
    QPushButton *dishButton;
    QHBoxLayout *dishButtonLayout;
    QLabel *dishIcon;
    QLabel *dishText;
    QLabel *dishArrow;
    QSpacerItem *verticalSpacer2;
    QPushButton *drinkButton;
    QHBoxLayout *drinkButtonLayout;
    QLabel *drinkIcon;
    QLabel *drinkText;
    QLabel *drinkArrow;

    void setupUi(QWidget *MenuPage)
    {
        if (MenuPage->objectName().isEmpty())
            MenuPage->setObjectName("MenuPage");
        MenuPage->resize(400, 350);
        invoiceButton = new QPushButton(MenuPage);
        invoiceButton->setObjectName("invoiceButton");
        invoiceButton->setGeometry(QRect(340, 10, 50, 50));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":static/search_icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        invoiceButton->setIcon(icon);
        invoiceButton->setIconSize(QSize(30, 30));
        verticalLayout = new QVBoxLayout(MenuPage);
        verticalLayout->setObjectName("verticalLayout");
        titleLayout = new QHBoxLayout();
        titleLayout->setSpacing(0);
        titleLayout->setObjectName("titleLayout");
        iconLabel = new QLabel(MenuPage);
        iconLabel->setObjectName("iconLabel");
        iconLabel->setPixmap(QPixmap(QString::fromUtf8(":static/search_icon.png")));
        iconLabel->setScaledContents(true);
        iconLabel->setMaximumSize(QSize(30, 30));

        titleLayout->addWidget(iconLabel);

        titleLabel = new QLabel(MenuPage);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

        titleLayout->addWidget(titleLabel);


        verticalLayout->addLayout(titleLayout);

        verticalSpacer1 = new QSpacerItem(0, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer1);

        dishButton = new QPushButton(MenuPage);
        dishButton->setObjectName("dishButton");
        dishButtonLayout = new QHBoxLayout(dishButton);
        dishButtonLayout->setObjectName("dishButtonLayout");
        dishIcon = new QLabel(dishButton);
        dishIcon->setObjectName("dishIcon");
        dishIcon->setPixmap(QPixmap(QString::fromUtf8(":static/search_icon.png")));
        dishIcon->setScaledContents(true);
        dishIcon->setMaximumSize(QSize(50, 50));

        dishButtonLayout->addWidget(dishIcon);

        dishText = new QLabel(dishButton);
        dishText->setObjectName("dishText");
        dishText->setAlignment(Qt::AlignCenter);

        dishButtonLayout->addWidget(dishText);

        dishArrow = new QLabel(dishButton);
        dishArrow->setObjectName("dishArrow");
        dishArrow->setPixmap(QPixmap(QString::fromUtf8(":static/search_icon.png")));
        dishArrow->setScaledContents(true);
        dishArrow->setMaximumSize(QSize(30, 30));

        dishButtonLayout->addWidget(dishArrow);


        verticalLayout->addWidget(dishButton);

        verticalSpacer2 = new QSpacerItem(0, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer2);

        drinkButton = new QPushButton(MenuPage);
        drinkButton->setObjectName("drinkButton");
        drinkButtonLayout = new QHBoxLayout(drinkButton);
        drinkButtonLayout->setObjectName("drinkButtonLayout");
        drinkIcon = new QLabel(drinkButton);
        drinkIcon->setObjectName("drinkIcon");
        drinkIcon->setPixmap(QPixmap(QString::fromUtf8(":static/search_icon.png")));
        drinkIcon->setScaledContents(true);
        drinkIcon->setMaximumSize(QSize(50, 50));

        drinkButtonLayout->addWidget(drinkIcon);

        drinkText = new QLabel(drinkButton);
        drinkText->setObjectName("drinkText");
        drinkText->setAlignment(Qt::AlignCenter);

        drinkButtonLayout->addWidget(drinkText);

        drinkArrow = new QLabel(drinkButton);
        drinkArrow->setObjectName("drinkArrow");
        drinkArrow->setPixmap(QPixmap(QString::fromUtf8(":static/search_icon.png")));
        drinkArrow->setScaledContents(true);
        drinkArrow->setMaximumSize(QSize(30, 30));

        drinkButtonLayout->addWidget(drinkArrow);


        verticalLayout->addWidget(drinkButton);


        retranslateUi(MenuPage);

        QMetaObject::connectSlotsByName(MenuPage);
    } // setupUi

    void retranslateUi(QWidget *MenuPage)
    {
        MenuPage->setWindowTitle(QCoreApplication::translate("MenuPage", "Menu", nullptr));
        titleLabel->setText(QCoreApplication::translate("MenuPage", "Menu", nullptr));
        titleLabel->setStyleSheet(QCoreApplication::translate("MenuPage", "font-size: 20px; font-weight: bold; margin-left: 8px;", nullptr));
        dishText->setText(QCoreApplication::translate("MenuPage", "Plats", nullptr));
        dishText->setStyleSheet(QCoreApplication::translate("MenuPage", "font-size: 24px; font-weight: bold;", nullptr));
        drinkText->setText(QCoreApplication::translate("MenuPage", "Boissons", nullptr));
        drinkText->setStyleSheet(QCoreApplication::translate("MenuPage", "font-size: 24px; font-weight: bold;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuPage: public Ui_MenuPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
