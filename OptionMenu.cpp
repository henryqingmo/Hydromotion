#include "OptionMenu.h"
#include "ui_OptionMenu.h"

OptionMenu::OptionMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionMenu)
{
    ui->setupUi(this);
    ui->comboBox->addItem("1920 * 1080");
    ui->comboBox->addItem("1280 * 720");
    ui->comboBox->addItem("640 * 480");

}

OptionMenu::~OptionMenu()
{
    delete ui;
}
