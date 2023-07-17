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
    ui->horizontalSlider_speed->setValue(5);
    ui->horizontalSlider_angle->setRange(0, 90);
    ui->horizontalSlider_angle->setValue(45);

    //connect(this, &Game::pushButton_fire_clicked, glwidget, &MyOpenGLWidget::on_pushButton_fire_clicked);
    connect(ui->pushButton_fire, &QPushButton::clicked, glwidget, &MyOpenGLWidget::on_pushButton_fire_clicked);


    connect(this, &Game::sliderValueChanged, glwidget, &MyOpenGLWidget::on_sliderValueChanged);

    emit sliderValueChanged(ui->horizontalSlider_speed->value(), Speed);
    emit sliderValueChanged(ui->horizontalSlider_speed->value(), Angle);
    emit sliderValueChanged(ui->horizontalSlider_height->value(), Height);

}

//void Game::createAnimationThread(AnimationThread* animationThread)
//{
//    // ...
//  //  ui->horizontalSlider_mass->setSingleStep()
//    ui->horizontalSlider_speed->setValue(5);
//    ui->horizontalSlider_angle->setRange(0, 90);
//    ui->horizontalSlider_angle->setValue(0);

//    //connect(this, &Game::sliderValueChanged, glwidget, &MyOpenGLWidget::on_sliderValueChanged);
////    connect(this, &Game::sliderValueChanged, glwidget, &AnimationThread::on_sliderValueChanged);
//    connect(this, &Game::pushButton_fire_clicked, animationThread, &AnimationThread::on_pushButton_fire_clicked);

//    connect(this, &Game::sliderValueChanged, animationThread, &AnimationThread::on_sliderValueChanged);
//    emit sliderValueChanged(ui->horizontalSlider_speed->value(), Speed);
//    emit sliderValueChanged(ui->horizontalSlider_speed->value(), Angle);
//    emit sliderValueChanged(ui->horizontalSlider_height->value(), Height);


////    connect(this, &Game::sliderValueChanged, glwidget, &MyOpenGLWidget::on_horizontalSlider_speed_valueChanged);
////    emit sliderValueChanged(ui->horizontalSlider_speed->value());

////    connect(this, &Game::sliderValueChanged, glwidget, &MyOpenGLWidget::on_horizontalSlider_angle_valueChanged);
////    emit sliderValueChanged(ui->horizontalSlider_angle->value());

////    emit sliderValueChanged(ui->horizontalSlider_height->value());

//}


void Game::on_pushButton_exit_clicked()
{
    this->close();
}


//void Game::on_horizontalSlider_mass_valueChanged(int value)
//{

//}


