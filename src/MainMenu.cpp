#include "../include/MainMenu.h"
#include "../include/ui_MainMenu.h"
#include "../include/Log.h"

MainMenu::MainMenu(QWidget *parent)
        : QWidget(parent)
        , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(on_quitButton_click()));
}

MainMenu::~MainMenu()
{
    delete ui;
}
void MainMenu::on_selectButton_click()
{
}

void MainMenu::on_quitButton_click()
{
   this->~MainMenu();
}

void MainMenu::setTexture(const char *path)
{
    QPixmap texture(path);
    ui->label->setPixmap(texture);
};


