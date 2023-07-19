#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <game.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_startButton_clicked();

    void on_quitButton_clicked();

    void on_optionButton_clicked();

    void on_helpButton_clicked();

private:
    Ui::MainMenu *ui;
    Game *game;

};
#endif // MAINMENU_H
