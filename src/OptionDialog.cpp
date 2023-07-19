#include "./include/OptionDialog.h"
#include "./ui/ui_OptionDialog.h"
#include <QDir>


OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionDialog)
{
    ui->setupUi(this);

}

OptionDialog::~OptionDialog()
{
    delete ui;
}

// emits the boolean when the checkbox is checked.
void OptionDialog::on_checkBox_clicked(bool checked)
{
    emit(musicStateChanged(checked));

}
