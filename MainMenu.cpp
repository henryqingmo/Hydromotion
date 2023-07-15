#include "MainMenu.h"
#include "ui_MainMenu.h"
#include "OptionMenu.h"
#include "game.h"
#include <iostream>

MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}


void MainMenu::on_selectButton_clicked()
{
    game = new Game();
    game->show();
}



void MainMenu::on_quitButton_clicked()
{
    this->~MainMenu();
}


void MainMenu::on_creditButton_clicked()
{

}



void MainMenu::on_optionButton_clicked()
{
    OptionMenu option_menu;
    option_menu.setModal(true);
    option_menu.exec();
}

