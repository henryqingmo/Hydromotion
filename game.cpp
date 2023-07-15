#include "game.h"
#include "ui_game.h"
#include <QVBoxLayout>
#include <QDebug>


Game::Game(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Game), glwidget(nullptr)
{
    ui->setupUi(this);
    glwidget = ui->openGLWidget;
    createOpenGLWidget(glwidget);
}

Game::~Game()
{
    delete ui;
}

void Game::createOpenGLWidget(MyOpenGLWidget* glwidget)
{
    // ...
    ui->horizontalSlider_mass->setRange(0, 50);
  //  ui->horizontalSlider_mass->setSingleStep()
    ui->horizontalSlider_speed->setValue(5);

    ui->horizontalSlider_angle->setRange(0, 90);
    ui->horizontalSlider_angle->setValue(0);


    connect(this, &Game::sliderValueChanged, glwidget, &MyOpenGLWidget::on_sliderValueChanged);

    emit sliderValueChanged(ui->horizontalSlider_mass->value(), Mass);
    emit sliderValueChanged(ui->horizontalSlider_speed->value(), Speed);
    emit sliderValueChanged(ui->horizontalSlider_speed->value(), Angle);
    emit sliderValueChanged(ui->horizontalSlider_height->value(), Height);
//    emit sliderValueChanged(ui->horizontalSlider_mass->value());


//    connect(this, &Game::sliderValueChanged, glwidget, &MyOpenGLWidget::on_horizontalSlider_speed_valueChanged);
//    emit sliderValueChanged(ui->horizontalSlider_speed->value());

//    connect(this, &Game::sliderValueChanged, glwidget, &MyOpenGLWidget::on_horizontalSlider_angle_valueChanged);
//    emit sliderValueChanged(ui->horizontalSlider_angle->value());

//    emit sliderValueChanged(ui->horizontalSlider_height->value());

}


void Game::on_pushButton_exit_clicked()
{
    this->close();
}


//void Game::on_horizontalSlider_mass_valueChanged(int value)
//{

//}

