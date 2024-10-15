/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *berdiri;
    QPushButton *lambaikan;
    QPushButton *kuda2;
    QPushButton *pukul;
    QPushButton *bonus;
    QPushButton *jalan;
    QPushButton *senamTgn;
    QPushButton *jalanTempat;
    QLabel *label;
    QLabel *labelSetting;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(800, 600);
        berdiri = new QPushButton(Dialog);
        berdiri->setObjectName("berdiri");
        berdiri->setGeometry(QRect(70, 60, 80, 23));
        lambaikan = new QPushButton(Dialog);
        lambaikan->setObjectName("lambaikan");
        lambaikan->setGeometry(QRect(210, 60, 80, 23));
        kuda2 = new QPushButton(Dialog);
        kuda2->setObjectName("kuda2");
        kuda2->setGeometry(QRect(340, 60, 80, 23));
        pukul = new QPushButton(Dialog);
        pukul->setObjectName("pukul");
        pukul->setGeometry(QRect(460, 60, 80, 23));
        bonus = new QPushButton(Dialog);
        bonus->setObjectName("bonus");
        bonus->setGeometry(QRect(460, 110, 80, 23));
        jalan = new QPushButton(Dialog);
        jalan->setObjectName("jalan");
        jalan->setGeometry(QRect(210, 110, 80, 23));
        senamTgn = new QPushButton(Dialog);
        senamTgn->setObjectName("senamTgn");
        senamTgn->setGeometry(QRect(70, 110, 80, 23));
        jalanTempat = new QPushButton(Dialog);
        jalanTempat->setObjectName("jalanTempat");
        jalanTempat->setGeometry(QRect(340, 110, 80, 23));
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 170, 121, 16));
        labelSetting = new QLabel(Dialog);
        labelSetting->setObjectName("labelSetting");
        labelSetting->setGeometry(QRect(280, 170, 211, 16));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        berdiri->setText(QCoreApplication::translate("Dialog", "Berdiri", nullptr));
        lambaikan->setText(QCoreApplication::translate("Dialog", "Dadah..", nullptr));
        kuda2->setText(QCoreApplication::translate("Dialog", "Kuda kuda", nullptr));
        pukul->setText(QCoreApplication::translate("Dialog", "Pukul", nullptr));
        bonus->setText(QCoreApplication::translate("Dialog", "Bonus", nullptr));
        jalan->setText(QCoreApplication::translate("Dialog", "Jalan", nullptr));
        senamTgn->setText(QCoreApplication::translate("Dialog", "Senam tgn", nullptr));
        jalanTempat->setText(QCoreApplication::translate("Dialog", "Jalan tetap", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Gerakan Terkini    :", nullptr));
        labelSetting->setText(QCoreApplication::translate("Dialog", "APA hayo", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
