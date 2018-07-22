#ifndef DISEASES_HPP
#define DISEASES_HPP

#include "button.hpp"
#include "filehandler.hpp"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QScrollArea>
#include <QApplication>
#include <QDebug>
#include <QLineEdit>
#include <QKeyEvent>


class Diseases :public QMainWindow{
        Q_OBJECT
public:
    Diseases(QWidget *parent = 0);
    QWidget *getWidget();
protected:
    bool eventFilter(QObject *obj, QEvent *event);//for mapping keyboard
private:
    Button *Btn[8];
    QLabel *HeaderLabel;
    QLabel *EmptyLabel;
    QLabel *Which;

    QGridLayout *sideBarLayout;
    QWidget *sideBarWidget;

    QGridLayout *mainLayout;
    QWidget *mainWidget;

    QGridLayout *displayLayout;
    QWidget *displayWidget;
    QScrollArea *displayScrollArea;

    QLabel *displayLabel;

    Button *topPushButton1;
    Button *topPushButton2;
    Button *topPushButton3;
    Button *topPushButton4;

    QLineEdit *SearchBox;
    Button *SearchButton;

    void CreateWidget();

private slots:
    void CheckSystem();
    void CheckDisease();
    void SearchDisease();
 };

#endif // DISEASES_HPP
