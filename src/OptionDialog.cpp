#include "./include/OptionDialog.h"
#include "./ui/ui_OptionDialog.h"
#include <QDir>


OptionDialog::OptionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OptionDialog)
{
    ui->setupUi(this);
    musicPlayer = new QMediaPlayer(this);
    playlist = new QMediaPlaylist(this);
    QString currentDir = QDir::currentPath();
    playlist->addMedia(QUrl(currentDir + "/" + "./res/audio/bgm.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    musicPlayer->setPlaylist(playlist);
    musicPlayer->setVolume(50);




}

OptionDialog::~OptionDialog()
{
    delete ui;
}

void OptionDialog::on_checkBox_clicked(bool checked)
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
