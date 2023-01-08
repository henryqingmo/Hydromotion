#ifndef HYDROMOTION_UI_MENUSCREEN_H
#define HYDROMOTION_UI_MENUSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuScreen
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *selectButton;
    QPushButton *loadButton;
    QPushButton *optionButton;
    QPushButton *quitButton;
    QLabel *label;

    void setupUi(QWidget *MenuScreen)
    {
        if (MenuScreen->objectName().isEmpty())
            MenuScreen->setObjectName(QString::fromUtf8("MenuScreen"));
        MenuScreen->resize(800, 600);
        verticalLayoutWidget = new QWidget(MenuScreen);
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

        label = new QLabel(MenuScreen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 210, 342, 78));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);

        retranslateUi(MenuScreen);

        QMetaObject::connectSlotsByName(MenuScreen);
    } // setupUi

    void retranslateUi(QWidget *MenuScreen)
    {
        MenuScreen->setWindowTitle(QCoreApplication::translate("MenuScreen", "MenuScreen", nullptr));
        selectButton->setText(QCoreApplication::translate("MenuScreen", "SELECT MODULE", nullptr));
        loadButton->setText(QCoreApplication::translate("MenuScreen", "LOAD SAVE", nullptr));
        optionButton->setText(QCoreApplication::translate("MenuScreen", "OPTIONS", nullptr));
        quitButton->setText(QCoreApplication::translate("MenuScreen", "QUIT", nullptr));
        label->setText(QCoreApplication::translate("MenuScreen", "HYDROMOTION", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MenuScreen: public Ui_MenuScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif //HYDROMOTION_UI_MENUSCREEN_H
