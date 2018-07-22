#ifndef FIRSTAID_HPP
#define FIRSTAID_HPP

#include "button.hpp"
#include "filehandler.hpp"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QScrollArea>
#include <QApplication>
#include <QDebug>

class FirstAid :public QMainWindow {
    Q_OBJECT
public:
    FirstAid(QWidget *parent = 0);
    QWidget *getWidget();

private:
    Button *Btn[10];
    QLabel *Label;
    QLabel *EmptyLabel;

    QGridLayout *sideBarLayout;
    QWidget *sideBarWidget;

    QGridLayout *mainLayout;
    QWidget *mainWidget;

    QGridLayout *displayLayout;
    QWidget *displayWidget;
    QScrollArea *displayScrollArea;

    QLabel *displayLabel;

    void CreateWidget();

private slots:
    void clickListener();
};

#endif // FIRSTAID_HPP
