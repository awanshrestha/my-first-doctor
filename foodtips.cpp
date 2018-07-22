#include "foodtips.hpp"

FoodTips::FoodTips(QWidget *parent) : QMainWindow(parent){
    CreateWidget();
}

QWidget* FoodTips::getWidget(){
    return this->mainWidget;
}

void FoodTips::CreateWidget() {

    mainWidget = new QWidget;   mainWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed) ;

    mainLayout = new QGridLayout;

    PushDiarrhoea   =new QRadioButton("Diarrhoea");
    RadioCommonCold  =new QRadioButton("Common Cold");
    RadioFracture    =new QRadioButton("Fracture");
    RadioGastric     =new QRadioButton("Gastric");

        QPushButton *pushbuttonCheck=new QPushButton("Check");
        pushbuttonCheck->setFixedSize(200,37);
        pushbuttonCheck->setStyleSheet("border-radius:15px;border:4px solid orange;");

        table_upper=new TAB;
        table_meat=new TAB;
        table_Dairy=new TAB;
        table_Oil=new TAB;
        table_Fruits=new TAB;
        table_FastFoods=new TAB;
        table_Vegatables=new TAB;

        table_meat->setAnotherText("<p style=font-size:20px;><b>Meat</b></p>");
        table_Dairy->setAnotherText("<p style=font-size:20px;><b>Dairy</b></p>");
        table_Oil->setAnotherText("<p style=font-size:20px;><b>Oil</b></p>");
        table_Fruits->setAnotherText("<p style=font-size:20px;><b>Fruits</b></p>");
        table_FastFoods->setAnotherText("<p style=font-size:20px;><b>Fast Foods</b></p>");
        table_Vegatables->setAnotherText("<p style=font-size:20px;><b>Vegetables</b></p>");

        /*this is for upper heading of table only*/

        table_upper->setAnotherText("<p style=font-size:20px;>_________<b>Food</b>___________</p>");
        table_upper->setMarkNo();
        table_upper->setMarkYES();
        table_upper->setMarkMaybe("");

        table_upper->setTEXTforMaybe("<p style=font-size:20px;>_______________<b>Tips</b>__________________</p>");
        table_upper->setTEXTforyes("<p style=font-size:20px;>_______<b>Yes</b>___________</p>");
        table_upper->setTEXTforNo("<p style=font-size:20px;>_______<b>NO</b>__________</p>");



        QWidget *Table_Meat_Widget=new QWidget;
        QWidget *Table_upper_Widget=new QWidget;
        QWidget *Table_DAIRY_Widget=new QWidget;
        QWidget *Table_OIL_Widget=new QWidget;
        QWidget *Table_FRUITS_Widget=new QWidget;
        QWidget *Table_FASTFOODS_Widget=new QWidget;
        QWidget *Table_Vegetables_Widget=new QWidget;


        Table_Meat_Widget=table_meat->getwidgeter();
        Table_upper_Widget=table_upper->getwidgeter();
        Table_DAIRY_Widget=table_Dairy->getwidgeter();
        Table_OIL_Widget=table_Oil->getwidgeter();
        Table_FRUITS_Widget=table_Fruits->getwidgeter();
        Table_FASTFOODS_Widget=table_FastFoods->getwidgeter();
        Table_Vegetables_Widget=table_Vegatables->getwidgeter();


        gridforMainWidget=new QGridLayout;
        gridforMainWidget->addWidget(Table_upper_Widget);
        gridforMainWidget->addWidget(Table_Meat_Widget);
        gridforMainWidget->addWidget(Table_DAIRY_Widget);
        gridforMainWidget->addWidget(Table_OIL_Widget);
        gridforMainWidget->addWidget(Table_FRUITS_Widget);
        gridforMainWidget->addWidget(Table_FASTFOODS_Widget);
        gridforMainWidget->addWidget(Table_Vegetables_Widget);

        gridforMainWidget->addWidget(PushDiarrhoea);
        gridforMainWidget->addWidget(RadioCommonCold);
        gridforMainWidget->addWidget(RadioFracture);
        gridforMainWidget->addWidget(RadioGastric);
       gridforMainWidget->addWidget(pushbuttonCheck);

        connect(pushbuttonCheck,SIGNAL(released()),this,SLOT(showmark())); /*THIS IS FOR DIARRHOEA RADIOBUTTON*/

       mainWidget->setLayout(gridforMainWidget);

}

void FoodTips::showmark(){
    table_meat->SetDefault();
    table_Dairy->SetDefault();
    table_Oil->SetDefault();
    table_Fruits->SetDefault();
    table_FastFoods->SetDefault();
    table_Vegatables->SetDefault();

     if(PushDiarrhoea->isChecked())
    {
        table_meat->setMarkNo();                 /*coz*/ table_meat->setMarkMaybe("Meat is hard to digest.");
        table_Dairy->setMarkNo();           /*coz*/ table_Dairy->setMarkMaybe("Unhealthy in consumption when weak.");
        table_Oil->setMarkNo();              /*coz*/ table_Oil->setMarkMaybe("Oil requires lots of time for digestion.");
        table_Fruits->setMarkYES();
        table_FastFoods->setMarkNo();         /*coz*/ table_FastFoods->setMarkMaybe("Fastfood is the unhealthiest food.");
        table_Vegatables->setMarkYES();
    }

    if(RadioCommonCold->isChecked())
    {
        table_meat->setMarkMaybe("Too spicy meat is bad.");
        table_Dairy->setMarkYES();
        table_Oil->setMarkMaybe("Small amount is ok.");
        table_Fruits->setMarkNo();                       /*coz*/ table_Fruits->setMarkMaybe("Fruits can drop body temperature.");
        table_FastFoods->setMarkNo();                  /*coz*/ table_FastFoods->setMarkMaybe("Avoid fastfoods such as cold drink, as it is unhealthy. ");
        table_Vegatables->setMarkYES();
    }

    if(RadioFracture->isChecked())
    {
        table_meat->setMarkYES();
        table_Dairy->setMarkYES();
        table_Oil->setMarkMaybe("Difficult to digest.");
        table_Fruits->setMarkYES();
        table_FastFoods->setMarkNo();                /*coz*/ table_FastFoods->setMarkMaybe("MSG and sodium salts of fastfood decays bone.");
        table_Vegatables->setMarkYES();
    }

    if(RadioGastric->isChecked())
    {
        table_meat->setMarkNo();                  /*coz*/ table_meat->setMarkMaybe("Cholestrol level increases when meat is consumed.");
        table_Dairy->setMarkMaybe("hard to digest");
        table_Oil->setMarkNo();              /*coz*/ table_Oil->setMarkMaybe("Oil and fatty acids takes lots of time for digestion.");
        table_Fruits->setMarkYES();
        table_FastFoods->setMarkNo();            /*coz*/ table_FastFoods->setMarkMaybe("Fast Food is the Unhealthiest food.");
        table_Vegatables->setMarkYES();
    }
}


