/********************************************************************************
** Form generated from reading UI file 'MainMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENU_H
#define UI_MAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenu
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *startButton;
    QPushButton *optionButton;
    QPushButton *helpButton;
    QPushButton *quitButton;
    QLabel *label;

    void setupUi(QWidget *MainMenu)
    {
        if (MainMenu->objectName().isEmpty())
            MainMenu->setObjectName(QString::fromUtf8("MainMenu"));
        MainMenu->resize(800, 600);
        verticalLayoutWidget = new QWidget(MainMenu);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(110, 360, 160, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        startButton = new QPushButton(verticalLayoutWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));

        verticalLayout->addWidget(startButton);

        optionButton = new QPushButton(verticalLayoutWidget);
        optionButton->setObjectName(QString::fromUtf8("optionButton"));

        verticalLayout->addWidget(optionButton);

        helpButton = new QPushButton(verticalLayoutWidget);
        helpButton->setObjectName(QString::fromUtf8("helpButton"));

        verticalLayout->addWidget(helpButton);

        quitButton = new QPushButton(verticalLayoutWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        verticalLayout->addWidget(quitButton);

        label = new QLabel(MainMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 210, 363, 66));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "MenuScreen", nullptr));
        startButton->setText(QCoreApplication::translate("MainMenu", "START", nullptr));
        optionButton->setText(QCoreApplication::translate("MainMenu", "OPTIONS", nullptr));
        helpButton->setText(QCoreApplication::translate("MainMenu", "HELP", nullptr));
        quitButton->setText(QCoreApplication::translate("MainMenu", "QUIT", nullptr));
        label->setText(QCoreApplication::translate("MainMenu", "HYDROMOTION", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENU_H
