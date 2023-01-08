#ifndef HYDROMOTION_MENUSCREEN_H
#define HYDROMOTION_MENUSCREEN_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MenuScreen; }
QT_END_NAMESPACE

class MenuScreen : public QWidget {
Q_OBJECT

public:
    MenuScreen(QWidget *parent = nullptr);
    ~MenuScreen();

private slots:
    void on_selectButton_click();

    void on_quitButton_click();

private:
    Ui::MenuScreen *ui;

};
#endif //HYDROMOTION_MENUSCREEN_H
