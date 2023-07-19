#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QDialog>

namespace Ui {
class OptionDialog;
}

class OptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionDialog(QWidget *parent = nullptr);
    ~OptionDialog();

private slots:
    void on_checkBox_clicked(bool checked);

private:
    Ui::OptionDialog *ui;
    QMediaPlayer *musicPlayer;
    QMediaPlaylist *playlist;

};

#endif // OPTIONDIALOG_H
