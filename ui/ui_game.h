/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "./include/MyOpenGLWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Game
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    MyOpenGLWidget *openGLWidget;
    QLabel *label_2;
    QSpinBox *spinBox_velocity;
    QSlider *horizontalSlider_speed;
    QLabel *label_3;
    QSpinBox *spinBox_angle;
    QSlider *horizontalSlider_angle;
    QLabel *label_4;
    QSpinBox *spinBox_height;
    QSlider *horizontalSlider_height;
    QTextEdit *textEdit;
    QPushButton *pushButton_exit;
    QLabel *label_5;
    QSlider *horizontalSlider_time;
    QLabel *label;
    QPushButton *pushButton_reset;
    QPushButton *pushButton_fire;

    void setupUi(QWidget *Game)
    {
        if (Game->objectName().isEmpty())
            Game->setObjectName(QString::fromUtf8("Game"));
        Game->resize(915, 614);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Game->sizePolicy().hasHeightForWidth());
        Game->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(Game);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 40, 881, 531));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(16);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(layoutWidget->sizePolicy().hasHeightForWidth());
        layoutWidget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        openGLWidget = new MyOpenGLWidget(layoutWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(16);
        sizePolicy2.setVerticalStretch(9);
        sizePolicy2.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(openGLWidget, 0, 0, 7, 4);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(16);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_2, 0, 4, 1, 1);

        spinBox_velocity = new QSpinBox(layoutWidget);
        spinBox_velocity->setObjectName(QString::fromUtf8("spinBox_velocity"));
        sizePolicy3.setHeightForWidth(spinBox_velocity->sizePolicy().hasHeightForWidth());
        spinBox_velocity->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(spinBox_velocity, 0, 5, 1, 1);

        horizontalSlider_speed = new QSlider(layoutWidget);
        horizontalSlider_speed->setObjectName(QString::fromUtf8("horizontalSlider_speed"));
        sizePolicy3.setHeightForWidth(horizontalSlider_speed->sizePolicy().hasHeightForWidth());
        horizontalSlider_speed->setSizePolicy(sizePolicy3);
        horizontalSlider_speed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_speed, 1, 4, 1, 2);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_3, 2, 4, 1, 1);

        spinBox_angle = new QSpinBox(layoutWidget);
        spinBox_angle->setObjectName(QString::fromUtf8("spinBox_angle"));
        sizePolicy3.setHeightForWidth(spinBox_angle->sizePolicy().hasHeightForWidth());
        spinBox_angle->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(spinBox_angle, 2, 5, 1, 1);

        horizontalSlider_angle = new QSlider(layoutWidget);
        horizontalSlider_angle->setObjectName(QString::fromUtf8("horizontalSlider_angle"));
        sizePolicy3.setHeightForWidth(horizontalSlider_angle->sizePolicy().hasHeightForWidth());
        horizontalSlider_angle->setSizePolicy(sizePolicy3);
        horizontalSlider_angle->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_angle, 3, 4, 1, 2);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy3.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_4, 4, 4, 1, 1);

        spinBox_height = new QSpinBox(layoutWidget);
        spinBox_height->setObjectName(QString::fromUtf8("spinBox_height"));
        sizePolicy3.setHeightForWidth(spinBox_height->sizePolicy().hasHeightForWidth());
        spinBox_height->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(spinBox_height, 4, 5, 1, 1);

        horizontalSlider_height = new QSlider(layoutWidget);
        horizontalSlider_height->setObjectName(QString::fromUtf8("horizontalSlider_height"));
        sizePolicy3.setHeightForWidth(horizontalSlider_height->sizePolicy().hasHeightForWidth());
        horizontalSlider_height->setSizePolicy(sizePolicy3);
        horizontalSlider_height->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_height, 5, 4, 1, 2);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        sizePolicy3.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(textEdit, 6, 4, 1, 2);

        pushButton_exit = new QPushButton(layoutWidget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        sizePolicy3.setHeightForWidth(pushButton_exit->sizePolicy().hasHeightForWidth());
        pushButton_exit->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(pushButton_exit, 7, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy3.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label_5, 7, 1, 1, 1);

        horizontalSlider_time = new QSlider(layoutWidget);
        horizontalSlider_time->setObjectName(QString::fromUtf8("horizontalSlider_time"));
        sizePolicy3.setHeightForWidth(horizontalSlider_time->sizePolicy().hasHeightForWidth());
        horizontalSlider_time->setSizePolicy(sizePolicy3);
        horizontalSlider_time->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_time, 7, 2, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(label, 7, 3, 1, 1);

        pushButton_reset = new QPushButton(layoutWidget);
        pushButton_reset->setObjectName(QString::fromUtf8("pushButton_reset"));
        sizePolicy3.setHeightForWidth(pushButton_reset->sizePolicy().hasHeightForWidth());
        pushButton_reset->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(pushButton_reset, 7, 4, 1, 1);

        pushButton_fire = new QPushButton(layoutWidget);
        pushButton_fire->setObjectName(QString::fromUtf8("pushButton_fire"));
        sizePolicy3.setHeightForWidth(pushButton_fire->sizePolicy().hasHeightForWidth());
        pushButton_fire->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(pushButton_fire, 7, 5, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 2);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 3);
        gridLayout->setRowStretch(4, 1);
        gridLayout->setRowStretch(5, 3);
        gridLayout->setRowStretch(6, 3);
        gridLayout->setRowStretch(7, 1);
        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 1);
        gridLayout->setColumnStretch(2, 3);
        gridLayout->setColumnStretch(3, 1);
        gridLayout->setColumnStretch(4, 1);
        gridLayout->setColumnStretch(5, 1);
        gridLayout->setColumnMinimumWidth(0, 1);
        gridLayout->setColumnMinimumWidth(1, 1);
        gridLayout->setColumnMinimumWidth(2, 3);
        gridLayout->setColumnMinimumWidth(3, 1);
        gridLayout->setColumnMinimumWidth(4, 1);
        gridLayout->setColumnMinimumWidth(5, 1);
        gridLayout->setRowMinimumHeight(0, 1);
        gridLayout->setRowMinimumHeight(1, 2);
        gridLayout->setRowMinimumHeight(2, 1);
        gridLayout->setRowMinimumHeight(3, 3);
        gridLayout->setRowMinimumHeight(4, 1);
        gridLayout->setRowMinimumHeight(5, 3);
        gridLayout->setRowMinimumHeight(6, 3);
        gridLayout->setRowMinimumHeight(7, 1);

        retranslateUi(Game);
        QObject::connect(horizontalSlider_speed, SIGNAL(valueChanged(int)), spinBox_velocity, SLOT(setValue(int)));
        QObject::connect(spinBox_velocity, SIGNAL(valueChanged(int)), horizontalSlider_speed, SLOT(setValue(int)));
        QObject::connect(spinBox_angle, SIGNAL(valueChanged(int)), horizontalSlider_angle, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_height, SIGNAL(valueChanged(int)), spinBox_height, SLOT(setValue(int)));
        QObject::connect(spinBox_angle, SIGNAL(valueChanged(int)), horizontalSlider_angle, SLOT(setValue(int)));
        QObject::connect(horizontalSlider_angle, SIGNAL(valueChanged(int)), spinBox_angle, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(Game);
    } // setupUi

    void retranslateUi(QWidget *Game)
    {
        Game->setWindowTitle(QCoreApplication::translate("Game", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Game", "Initial speed", nullptr));
        label_3->setText(QCoreApplication::translate("Game", "Angle", nullptr));
        label_4->setText(QCoreApplication::translate("Game", "Height (divide 100)", nullptr));
        pushButton_exit->setText(QCoreApplication::translate("Game", "Exit", nullptr));
        label_5->setText(QCoreApplication::translate("Game", "slow", nullptr));
        label->setText(QCoreApplication::translate("Game", "Fast", nullptr));
        pushButton_reset->setText(QCoreApplication::translate("Game", "Reset", nullptr));
        pushButton_fire->setText(QCoreApplication::translate("Game", "Fire", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Game: public Ui_Game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
