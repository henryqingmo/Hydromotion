#ifndef MAINMENU_H
#define MAINMENU_H

#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include "./include/OptionDialog.h"
#include <QWidget>
#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

public slots:
    void handleMusicStateChanged(bool checked);

private slots:
    void on_startButton_clicked();

    void on_quitButton_clicked();

    void on_optionButton_clicked();

    void on_helpButton_clicked();

private:
    Ui::MainMenu *ui;
    Game *game;
    OptionDialog* option_dialog;
    QMediaPlayer *musicPlayer;
    QMediaPlaylist *playlist;

};
#endif // MAINMENU_H
