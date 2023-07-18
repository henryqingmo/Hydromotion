#include "game.h"
#include "ui_game.h"
#include <QVBoxLayout>
#include <QDebug>


Game::Game(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Game)
{
    ui->setupUi(this);
    glwidget = ui->openGLWidget;
    createOpenGLWidget(glwidget);

}

Game::~Game()
{
    delete ui;
}

void Game::createOpenGLWidget(MyOpenGLWidget *glwidget)
{
    connect(ui->pushButton_fire, &QPushButton::clicked, glwidget, &MyOpenGLWidget::on_pushButton_fire_clicked);
    connect(ui->horizontalSlider_dt, &QSlider::valueChanged, glwidget, [=](int value){glwidget->on_sliderValueChanged(value, Time);});
    connect(ui->horizontalSlider_speed, &QSlider::valueChanged, glwidget, [=](int value){glwidget->on_sliderValueChanged(value, Speed);});
    connect(ui->horizontalSlider_angle, &QSlider::valueChanged, glwidget, [=](int value){glwidget->on_sliderValueChanged(value, Angle);});
    connect(ui->horizontalSlider_height, &QSlider::valueChanged, glwidget, [=](int value){glwidget->on_sliderValueChanged(value, Height);});
    //lambda function emitting value and an enum value that's defined in MyOpenGL class
    ui->horizontalSlider_speed->setRange(0, 7);
    ui->horizontalSlider_speed->setValue(5);
    ui->horizontalSlider_angle->setRange(-90, 90);
    ui->horizontalSlider_angle->setValue(45);
    ui->horizontalSlider_dt->setRange(1, 50);
    ui->horizontalSlider_dt->setValue(10);
    ui->spinBox_angle->setRange(-90, 90);


}


void Game::on_pushButton_exit_clicked()
{
    this->close();
}



