#include "./include/game.h"
#include "./ui/ui_game.h"
#include <QVBoxLayout>
#include <QDebug>


/* This file is a responsible for connecting the slider value to the MyOpenGLWidget class
 * This is done through the signal slot feature in QT. A signal can be connected to a class
 * via a slot. In this example, glwidget which is an instance of MyOpenGLWidget has slots that
 * recieve the slider values from the Game class, and it also emits signals of the projectionData
 * to the Game class.
 */




Game::Game(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Game)
{

    ui->setupUi(this);
    glwidget = ui->openGLWidget;
    createOpenGLWidget(glwidget);
    connect(glwidget, &MyOpenGLWidget::projectileDataUpdate, this, [this](QVector3D projectileData) {
        on_ProjectileDataUpdate(projectileData);
    });

}

Game::~Game()
{
    delete ui;
}

void Game::createOpenGLWidget(MyOpenGLWidget *glwidget)
{
    connect(ui->pushButton_fire, &QPushButton::clicked, glwidget, &MyOpenGLWidget::on_pushButton_fire_clicked);
    connect(ui->horizontalSlider_time, &QSlider::valueChanged, glwidget, [=](int value){glwidget->on_sliderValueChanged(51 - value, Time);});
    connect(ui->horizontalSlider_speed, &QSlider::valueChanged, glwidget, [=](int value){glwidget->on_sliderValueChanged(value, Speed);});
    connect(ui->horizontalSlider_angle, &QSlider::valueChanged, glwidget, [=](int value){glwidget->on_sliderValueChanged(value, Angle);});
    connect(ui->horizontalSlider_height, &QSlider::valueChanged, glwidget, [=](int value){glwidget->on_sliderValueChanged(value, Height);});

    //lambda function emitting value and an enum value that's defined in MyOpenGL class
    ui->horizontalSlider_speed->setRange(0, 7);
    ui->horizontalSlider_angle->setRange(-90, 90);
    ui->horizontalSlider_height->setRange(0, 100);
    ui->horizontalSlider_time->setRange(1, 50);
    ui->spinBox_angle->setRange(-90, 90);
    on_pushButton_reset_clicked();


}

// Displaying to the textEdit
void Game::on_ProjectileDataUpdate(QVector3D projectileDate)
{
    QString durationString = QString::number(projectileDate[0]);
    QString maxHeightString = QString::number(projectileDate[1]);
    QString rangeString = QString::number(projectileDate[2]);

    ui->textEdit->clear();
    ui->textEdit->append("Note: The values are inaccurate\n");
    ui->textEdit->append("Time: " + durationString);
    ui->textEdit->append("Max Height: " + maxHeightString);
    ui->textEdit->append("Range: " + rangeString);

}


void Game::on_pushButton_exit_clicked()
{
    this->close();
}


// Setting the initial value of the slider

void Game::on_pushButton_reset_clicked()
{
    ui->horizontalSlider_speed->setValue(5);
    ui->horizontalSlider_angle->setValue(45);
    ui->horizontalSlider_height->setValue(0);
    ui->horizontalSlider_time->setValue(30);
    ui->textEdit->clear();

}
