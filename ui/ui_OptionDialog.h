/********************************************************************************
** Form generated from reading UI file 'OptionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONDIALOG_H
#define UI_OPTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_OptionDialog
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *checkBox;
    QLabel *label;

    void setupUi(QDialog *OptionDialog)
    {
        if (OptionDialog->objectName().isEmpty())
            OptionDialog->setObjectName(QString::fromUtf8("OptionDialog"));
        OptionDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(OptionDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        checkBox = new QCheckBox(OptionDialog);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(110, 30, 82, 23));
        label = new QLabel(OptionDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 54, 17));

        retranslateUi(OptionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), OptionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OptionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionDialog)
    {
        OptionDialog->setWindowTitle(QCoreApplication::translate("OptionDialog", "Dialog", nullptr));
        checkBox->setText(QCoreApplication::translate("OptionDialog", "on/off", nullptr));
        label->setText(QCoreApplication::translate("OptionDialog", "Music", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OptionDialog: public Ui_OptionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONDIALOG_H
