#ifndef HYDROMOTION_MainMenu_H
#define HYDROMOTION_MainMenu_H

#include <QWidget>
#include <QPixmap>


QT_BEGIN_NAMESPACE
namespace Ui { class MainMenu; }
QT_END_NAMESPACE

class MainMenu : public QWidget {
Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();
    void setTexture(const char* path);

private slots:
    void on_selectButton_click();

    void on_quitButton_click();

private:
    Ui::MainMenu *ui;

};
#endif //HYDROMOTION_MainMenu_H
