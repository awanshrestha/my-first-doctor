#include "firstaid.hpp"

FirstAid::FirstAid(QWidget *parent) : QMainWindow(parent) {
    CreateWidget();
}

QWidget* FirstAid::getWidget() {
    return this->mainWidget;
}

void FirstAid::CreateWidget() {

    mainWidget = new QWidget;
    mainLayout = new QGridLayout;
//Left Side
    Label = new QLabel;
    EmptyLabel = new QLabel;
    EmptyLabel->setText("  ");
    EmptyLabel->setFixedHeight(50);
    Label->setText("<h1>FIRST AID</h1>");

    sideBarWidget = new QWidget;
    sideBarLayout = new QGridLayout;
    QScrollArea *SideBarScroll = new QScrollArea;
    SideBarScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    SideBarScroll->setFixedWidth(230);

    QLabel *IconLabel[10];
    QGridLayout *IconLayout[10];
    for(int i=0; i<10; i++){
        IconLabel[i] = new QLabel;
        IconLayout[i] = new QGridLayout;
    }
    IconLabel[0]->setStyleSheet("border-image: url(://Images/Icons/Burns.jpg) 0 0 0 0 stretch stretch;");
    IconLabel[1]->setStyleSheet("border-image: url(://Images/Icons/drowning.jpg) 0 0 0 0 stretch stretch;");
    IconLabel[2]->setStyleSheet("border-image: url(://Images/Icons/electric shock.jpg) 0 0 0 0 stretch stretch;");
    IconLabel[3]->setStyleSheet("border-image: url(://Images/Icons/hypothermia.jpg) 0 0 0 0 stretch stretch;");
    IconLabel[4]->setStyleSheet("border-image: url(://Images/Icons/leech bite.jpg) 0 0 0 0 stretch stretch;");
    IconLabel[5]->setStyleSheet("border-image: url(://Images/Icons/snake bite.jpg) 0 0 0 0 stretch stretch;");
    IconLabel[6]->setStyleSheet("border-image: url(://Images/Icons/SPRAIN.jpg) 0 0 0 0 stretch stretch;");
    IconLabel[7]->setStyleSheet("border-image: url(://Images/Icons/Stroke.jpg) 0 0 0 0 stretch stretch;");
    IconLabel[8]->setStyleSheet("border-image: url(://Images/Icons/Toothache.jpg) 0 0 0 0 stretch stretch;");
    IconLabel[9]->setStyleSheet("border-image: url(://Images/Icons/Wound.jpg) 0 0 0 0 stretch stretch;");

    for(int i=0; i<10; i++){
        IconLayout[i]->addWidget(IconLabel[i]);
    }

    for (int i = 0 ; i < 10 ; i++ ){
        this->Btn[i] = new Button;
        this->Btn[i]->setFixedSize(180,140);
        this->Btn[i]->setLayout(IconLayout[i]);
    }

    Btn[0]->setText("Burns");
    Btn[1]->setText("Drowning");
    Btn[2]->setText("Electric Shock");
    Btn[3]->setText("Hypothermia");
    Btn[4]->setText("Leech Bite");
    Btn[5]->setText("Snake Bite");
    Btn[6]->setText("Sprain");
    Btn[7]->setText("Stroke");
    Btn[8]->setText("Toothache");
    Btn[9]->setText("Wound");

for (int i = 0 ; i < 10 ; i++ ){
        sideBarLayout->addWidget(Btn[i],(i+1),0);
        sideBarLayout->setAlignment(Btn[i],Qt::AlignTop);
        connect(Btn[i], SIGNAL(clicked()),this,SLOT(clickListener()) );
}
    sideBarWidget->setLayout(sideBarLayout);
    SideBarScroll->setWidget(sideBarWidget);
//Left Side End


 //Right Side
    displayWidget = new QWidget;
    displayLayout = new QGridLayout;

    displayLabel = new QLabel;
    displayLabel->setAlignment(Qt::AlignTop);
    displayLabel->setMinimumSize(790,700);


    displayLayout->addWidget(displayLabel);
    displayWidget->setLayout(displayLayout);

    displayScrollArea = new QScrollArea;
    displayScrollArea->setStyleSheet("background:#D3D3D3;");
    displayScrollArea->setWidget(displayWidget);
//Right Side End
    mainLayout->addWidget(Label,0,0,1,1);
    mainLayout->setAlignment(Label,Qt::AlignTop);
    mainLayout->addWidget(EmptyLabel,0,1,1,1);
    mainLayout->addWidget(SideBarScroll,1,0,12,1);
    mainLayout->addWidget(displayScrollArea,1,1,12,1);
    mainWidget->setLayout(mainLayout);

}

void FirstAid::clickListener() {
    QPushButton *FAbutton = (QPushButton*)sender();
    if(FAbutton->text()=="Burns"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Burns.txt" );
        displayLabel->setText(lbl);
    }
    if(FAbutton->text()=="Drowning"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Drowning.txt" );
        displayLabel->setText(lbl);
    }
    if(FAbutton->text()=="Electric Shock"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\ElectricShock.txt" );
        displayLabel->setText(lbl);
    }
    if(FAbutton->text()=="Hypothermia"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Hypothermia.txt" );
        displayLabel->setText(lbl);
    }
    if(FAbutton->text()=="Leech Bite"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\LeechBite.txt" );
        displayLabel->setText(lbl);
    }
    if(FAbutton->text()=="Snake Bite"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\SnakeBite.txt" );
        displayLabel->setText(lbl);
    }
    if(FAbutton->text()=="Sprain"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Sprain.txt" );
        displayLabel->setText(lbl);
    }
    if(FAbutton->text()=="Stroke"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Stroke.txt" );
        displayLabel->setText(lbl);
    }
    if(FAbutton->text()=="Toothache"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Toothache.txt" );
        displayLabel->setText(lbl);
    }
    if(FAbutton->text()=="Wound"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Wound.txt" );
        displayLabel->setText(lbl);
    }
}
