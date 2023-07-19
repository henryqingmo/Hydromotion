#ifndef GAME_H
#define GAME_H

#include "MyOpenGLWidget.h"




namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT


private:
    Ui::Game *ui;
    MyOpenGLWidget* glwidget;

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
    void createOpenGLWidget(MyOpenGLWidget* glwidget);

signals:
    void sliderValueChanged(int value, const SliderType sliderName);
    void pushButton_fire_clicked();
    void set_ScrollArea(float value);


public slots:
    void on_ProjectileDataUpdate(QVector3D projectileDate);

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_reset_clicked();
//protected:
//    void resizeEvent(QResizeEvent* event) override;

};



#endif // GAME_H
