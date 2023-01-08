#include "../include/MenuScreen.h"
#include "../include/ui_MenuScreen.h"
#include "../include/Log.h"

MenuScreen::MenuScreen(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::MenuScreen)
{
    ui->setupUi(this);
}

MenuScreen::~MenuScreen()
{
    delete ui;
}

void MenuScreen::on_selectButton_click()
{
    //
}

void MenuScreen::on_quitButton_click()
{

};

