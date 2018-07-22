#include "tab.hpp"

TAB::TAB()
{
   FOOD_Label =new QLabel;
   FOOD_Label->setStyleSheet("border:2px solid black;");
   FOOD_Label->setFixedSize(255,41);
   FOOD_Label->setStyleSheet("background:#AEB2A2;border:2px solid black");


   Yess=new QLabel("Yes");
   Yess->setStyleSheet("border:2px solid black;");
   Yess->setFixedSize(200,41);

   Noo=new QLabel("No");
   Noo->setStyleSheet("border:2px solid black;");
   Noo->setFixedSize(200,41);

   Maybe=new QLabel("May be");
   Maybe->setStyleSheet("border:2px solid black;");
   Maybe->setFixedSize(405,41);

   gridforTable=new QGridLayout;
   gridforTable->addWidget(FOOD_Label,0,0);
   gridforTable->addWidget(Yess,0,1);
   gridforTable->addWidget(Noo,0,2);
   gridforTable->addWidget(Maybe,0,3);

   widgetofTable=new QWidget;
   widgetofTable->setLayout(gridforTable);

}

void TAB::setAnotherText(QString Foodname)
{
    FOOD_Label->setText(Foodname);

}

QWidget* TAB::getwidgeter()
{
    return widgetofTable;
}

void TAB::setMarkYES()
{
    Yess->setStyleSheet("background:#2EA666;border:2px solid black");
}


void TAB::setMarkNo()
{

    Noo->setStyleSheet("background:#E55151;border:2px solid black");
}

void TAB::setMarkMaybe(QString DomaybeLabel)
{
    Maybe->setStyleSheet("background:#E0EBBD;border:2px solid black");

    Maybe->setText(DomaybeLabel);
}




/*this is only for the top of the table */
void TAB::setTEXTforMaybe(QString maybeText)
{
    Maybe->setText(maybeText);
}

void TAB::setTEXTforNo(QString noText)
{
    Noo->setText(noText);
}

void TAB::setTEXTforyes(QString yesText)
{
    Yess->setText(yesText);
}

void TAB::SetDefault(){
    Yess->setStyleSheet("background:#E0E0E0;border:2px solid black");
    Noo->setStyleSheet("background:#E0E0E0;border:2px solid black");
    Maybe->setStyleSheet("background:#E0E0E0;border:2px solid black");
    setTEXTforMaybe("May be");
}
