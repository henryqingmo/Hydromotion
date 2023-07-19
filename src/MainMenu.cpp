#include "./include/MainMenu.h"
#include "./ui/ui_MainMenu.h"
#include "./include/HelpDialog.h"
#include "./include/game.h"
#include <iostream>

/* This file basically connects all the click on startButton, optionButton etc
 * to a function that creates an instance of those windows.
 * It also recieve a signal from OptionDialog which contains a bool
 * variable for musicState. The music is played if it's true
 * and stopped if it's false.
 */


MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    option_dialog = new OptionDialog(this);
    musicPlayer = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    //QString currentDir = QDir::currentPath();
    playlist->addMedia(QUrl("qrc:/res/audio/bgm.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    musicPlayer->setPlaylist(playlist);

}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::handleMusicStateChanged(bool checked)
{
    if(checked == true)
    {
        musicPlayer->play();
    }
    else
    {
        musicPlayer->stop();
    }
}


void MainMenu::on_startButton_clicked()
{
    game = new Game();
    game->show();
}



void MainMenu::on_quitButton_clicked()
{
    this->~MainMenu();
}



void MainMenu::on_optionButton_clicked()
{
    option_dialog->setModal(true);
    connect(option_dialog, &OptionDialog::musicStateChanged, this, &MainMenu::handleMusicStateChanged);
    option_dialog->exec();
}


void MainMenu::on_helpButton_clicked()
{
    HelpDialog help_dialog;
    help_dialog.setModal(true);
    help_dialog.exec();

}

