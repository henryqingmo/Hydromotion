#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H
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

signals:
    void musicStateChanged(bool checked);

private slots:
    void on_checkBox_clicked(bool checked);

private:
    Ui::OptionDialog *ui;


};

#endif // OPTIONDIALOG_H
