#ifndef FOODTIPS_HPP
#define FOODTIPS_HPP

#include "tab.hpp"

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QScrollArea>
#include <QApplication>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QPushButton>

class FoodTips : public QMainWindow {
    Q_OBJECT
public:
    FoodTips(QWidget *parent = 0);
    QWidget *getWidget();

private:
    void CreateWidget();
    void CreateFoodTipsWidget();

    QWidget *mainWidget;
    QGridLayout *mainLayout;

    QGridLayout *gridforHealthTips,*gridforMainWidget;

    TAB *table_meat,*table_Dairy,*table_Oil,*table_Fruits,
        *table_FastFoods,*table_Vegatables,*table_upper;
    QWidget *widgetforMain;
    QLabel *labelinMainwidget;
    QRadioButton *PushDiarrhoea,*RadioCommonCold,*RadioFracture,
                    *RadioGastric;

private slots:
    void showmark();
};

#endif // FOODTIPS_HPP
