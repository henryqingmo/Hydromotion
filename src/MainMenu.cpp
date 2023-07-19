#include "./include/MainMenu.h"
#include "./ui/ui_MainMenu.h"
#include "./include/OptionDialog.h"
#include "./include/HelpDialog.h"
#include "./include/game.h"
#include <iostream>

MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
   // player = new QMediaPlayer(this);
//    player->setMedia(QUrl::fromLocalFile("path/to/your/audio/file.mp3")); // Replace with your audio file's path
//    player->setVolume(50); // Set the volume (0 - 100)
//    player->play();

}

MainMenu::~MainMenu()
{
    delete ui;
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
    OptionDialog option_dialog;
    option_dialog.setModal(true);
    option_dialog.exec();
}


void MainMenu::on_helpButton_clicked()
{
    HelpDialog help_dialog;
    help_dialog.setModal(true);
    help_dialog.exec();

}

