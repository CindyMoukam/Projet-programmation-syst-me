/********************************************************************************
** Form generated from reading UI file 'taketable.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAKETABLE_H
#define UI_TAKETABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_taketable
{
public:
    QPushButton *backButton;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *iconLabel;
    QLabel *label;
    QHBoxLayout *hboxLayout1;
    QLabel *responsableLabel;
    QLineEdit *responsableLineEdit;
    QHBoxLayout *hboxLayout2;
    QLabel *personLabel;
    QSpinBox *personSpinBox;
    QLabel *errorLabel;
    QPushButton *validateButton;

    void setupUi(QWidget *taketable)
    {
        if (taketable->objectName().isEmpty())
            taketable->setObjectName("taketable");
        taketable->resize(400, 350);
        backButton = new QPushButton(taketable);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 10, 50, 30));
        vboxLayout = new QVBoxLayout(taketable);
        vboxLayout->setObjectName("vboxLayout");
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        hboxLayout->setAlignment(Qt::AlignCenter);
        iconLabel = new QLabel(taketable);
        iconLabel->setObjectName("iconLabel");
        iconLabel->setPixmap(QPixmap(QString::fromUtf8(":static/search_icon.png")));
        iconLabel->setScaledContents(true);
        iconLabel->setMinimumSize(QSize(50, 50));
        iconLabel->setMaximumSize(QSize(50, 50));

        hboxLayout->addWidget(iconLabel);


        vboxLayout->addLayout(hboxLayout);

        label = new QLabel(taketable);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        vboxLayout->addWidget(label);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName("hboxLayout1");
        responsableLabel = new QLabel(taketable);
        responsableLabel->setObjectName("responsableLabel");

        hboxLayout1->addWidget(responsableLabel);

        responsableLineEdit = new QLineEdit(taketable);
        responsableLineEdit->setObjectName("responsableLineEdit");

        hboxLayout1->addWidget(responsableLineEdit);


        vboxLayout->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName("hboxLayout2");
        personLabel = new QLabel(taketable);
        personLabel->setObjectName("personLabel");

        hboxLayout2->addWidget(personLabel);

        personSpinBox = new QSpinBox(taketable);
        personSpinBox->setObjectName("personSpinBox");
        personSpinBox->setMinimum(1);
        personSpinBox->setMaximum(12);

        hboxLayout2->addWidget(personSpinBox);


        vboxLayout->addLayout(hboxLayout2);

        errorLabel = new QLabel(taketable);
        errorLabel->setObjectName("errorLabel");
        errorLabel->setAlignment(Qt::AlignCenter);

        vboxLayout->addWidget(errorLabel);

        validateButton = new QPushButton(taketable);
        validateButton->setObjectName("validateButton");

        vboxLayout->addWidget(validateButton);


        retranslateUi(taketable);

        QMetaObject::connectSlotsByName(taketable);
    } // setupUi

    void retranslateUi(QWidget *taketable)
    {
        taketable->setWindowTitle(QCoreApplication::translate("taketable", "Prendre une table", nullptr));
        backButton->setText(QCoreApplication::translate("taketable", "\342\254\205", nullptr));
        label->setText(QCoreApplication::translate("taketable", "Veuillez ins\303\251rer les informations n\303\251cessaires :", nullptr));
        responsableLabel->setText(QCoreApplication::translate("taketable", "Nom du responsable :", nullptr));
        personLabel->setText(QCoreApplication::translate("taketable", "Nombre de personnes :", nullptr));
        errorLabel->setText(QString());
        errorLabel->setStyleSheet(QCoreApplication::translate("taketable", "color: red;", nullptr));
        validateButton->setText(QCoreApplication::translate("taketable", "Valider", nullptr));
    } // retranslateUi

};

namespace Ui {
    class taketable: public Ui_taketable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAKETABLE_H
