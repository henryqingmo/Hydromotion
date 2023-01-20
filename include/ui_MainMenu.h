#ifndef HYDROMOTION_UI_MAINMENU_H
#define HYDROMOTION_UI_MAINMENU_H

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
    QPushButton *selectButton;
    QPushButton *loadButton;
    QPushButton *optionButton;
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
        selectButton = new QPushButton(verticalLayoutWidget);
        selectButton->setObjectName(QString::fromUtf8("selectButton"));

        verticalLayout->addWidget(selectButton);

        loadButton = new QPushButton(verticalLayoutWidget);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));

        verticalLayout->addWidget(loadButton);

        optionButton = new QPushButton(verticalLayoutWidget);
        optionButton->setObjectName(QString::fromUtf8("optionButton"));

        verticalLayout->addWidget(optionButton);

        quitButton = new QPushButton(verticalLayoutWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        verticalLayout->addWidget(quitButton);

        label = new QLabel(MainMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 210, 342, 78));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);

        retranslateUi(MainMenu);

        QMetaObject::connectSlotsByName(MainMenu);
    } // setupUi

    void retranslateUi(QWidget *MainMenu)
    {
        MainMenu->setWindowTitle(QCoreApplication::translate("MainMenu", "MainMenu", nullptr));
        selectButton->setText(QCoreApplication::translate("MainMenu", "SELECT MODULE", nullptr));
        loadButton->setText(QCoreApplication::translate("MainMenu", "LOAD SAVE", nullptr));
        optionButton->setText(QCoreApplication::translate("MainMenu", "OPTIONS", nullptr));
        quitButton->setText(QCoreApplication::translate("MainMenu", "QUIT", nullptr));
        label->setText(QCoreApplication::translate("MainMenu", "HYDROMOTION", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainMenu: public Ui_MainMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif //HYDROMOTION_UI_MAINMENU_H
