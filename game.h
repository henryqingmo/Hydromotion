#ifndef GAME_H
#define GAME_H

#include "MyOpenGLWidget.h"


namespace Ui {
class Game;
}

class Game : public QWidget
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
    void createOpenGLWidget(MyOpenGLWidget* glwidget);

signals:
    void sliderValueChanged(int value, const SliderType sliderName);

private slots:
    void on_pushButton_exit_clicked();


private:
    Ui::Game *ui;
    MyOpenGLWidget* glwidget;

};



#endif // GAME_H
