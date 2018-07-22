#include "diseases.hpp"
#include "searchfunction.hpp"

Diseases::Diseases(QWidget *parent) : QMainWindow(parent) {
    CreateWidget();
}

QWidget* Diseases::getWidget() {
    return this->mainWidget;
}

void Diseases::CreateWidget(){
    mainWidget = new QWidget;
    mainLayout = new QGridLayout;
//  top header
    HeaderLabel = new QLabel;
    HeaderLabel->setText("<h1>DISEASES</h1>");

    SearchButton = new Button("Search");     SearchButton->setFixedWidth(100);
    SearchBox = new QLineEdit;               SearchBox->setFixedWidth(200);
    qApp->installEventFilter(this);
    EmptyLabel = new QLabel;                  EmptyLabel->setFixedWidth(530);
    QWidget *HeaderWidget = new QWidget;
    QGridLayout *HeaderLayout= new QGridLayout;
    HeaderLayout->addWidget(HeaderLabel,0,0);    HeaderLayout->setAlignment(HeaderLabel,Qt::AlignLeft);
    HeaderLayout->addWidget(SearchBox,0,2);       HeaderLayout->setAlignment(SearchBox,Qt::AlignRight);
    HeaderLayout->addWidget(SearchButton,0,3);    HeaderLayout->setAlignment(SearchButton,Qt::AlignRight);
    HeaderLayout->addWidget(EmptyLabel,0,1);     HeaderLayout->setAlignment(EmptyLabel,Qt::AlignRight);
    HeaderWidget->setLayout(HeaderLayout);
// top header end

//  down header
    QWidget *HeaderWidget2 = new QWidget;
    QGridLayout *HeaderLayout2 = new QGridLayout;
    Which = new QLabel;    Which->setFixedWidth(250);   Which->setText("<h2>BRAIN</h2>");
    Which->setAlignment(Qt::AlignLeft);

    topPushButton1 = new Button;    topPushButton1->setText("Parkinsons");    topPushButton1->setFixedWidth(190);
    topPushButton2 = new Button;    topPushButton2->setText("Meningitis");    topPushButton2->setFixedWidth(190);
    topPushButton3 = new Button;    topPushButton3->setText("Encephalitis");    topPushButton3->setFixedWidth(190);
    topPushButton4 = new Button;    topPushButton4->setText("Alzeimer");    topPushButton4->setFixedWidth(190);

    HeaderLayout2->addWidget(Which,0,0);
    HeaderLayout2->addWidget(topPushButton1,0,2);
    HeaderLayout2->addWidget(topPushButton2,0,3);
    HeaderLayout2->addWidget(topPushButton3,0,4);
    HeaderLayout2->addWidget(topPushButton4,0,5);
    HeaderWidget2->setLayout(HeaderLayout2);
//  down header end

//side bar
    sideBarLayout = new QGridLayout;
    sideBarWidget = new QWidget;


    for (int i = 0 ; i < 8 ; i++ ){
        this->Btn[i] = new Button;
        Btn[i]->setFixedSize(200,40);
    }

    Btn[0]->setText("BRAIN");
    Btn[1]->setText("HEAD");
    Btn[2]->setText("EYES");
    Btn[3]->setText("TEETH AND GUMS");
    Btn[4]->setText("HEART");
    Btn[5]->setText("RESPIRATORY");
    Btn[6]->setText("DIGESTIVE");
    Btn[7]->setText("KIDNEY");

    for (int i = 0 ; i < 8 ; i++ ){
            sideBarLayout->addWidget(Btn[i],(i),0);
            sideBarLayout->setAlignment(Btn[i],Qt::AlignTop);
            sideBarLayout->setAlignment(Btn[i],Qt::AlignLeft);
            connect(Btn[i], SIGNAL(clicked()),this,SLOT(CheckSystem()) );
    }

    sideBarWidget->setLayout(sideBarLayout);
//side bar end

//display area
    displayWidget = new QWidget;
    displayLayout = new QGridLayout;

    displayLabel = new QLabel;
    displayLabel->setAlignment(Qt::AlignTop);
    displayLabel->setMinimumSize(770,700);

    displayLayout->addWidget(displayLabel);
    displayWidget->setLayout(displayLayout);

    displayScrollArea = new QScrollArea;
    displayScrollArea->setStyleSheet("background:#D3D3D3;");
    displayScrollArea->setWidget(displayWidget);
//display area end
    QGridLayout *DownLayout = new QGridLayout;
    QWidget *DownWidget = new QWidget;
    DownLayout->addWidget(sideBarWidget,0,0);
    DownLayout->addWidget(displayScrollArea,0,1);
    DownWidget->setLayout(DownLayout);

    mainLayout->addWidget(HeaderWidget,0,0,1,1);     mainLayout->setAlignment(HeaderWidget,Qt::AlignTop);
    mainLayout->addWidget(HeaderWidget2,1,0,1,1);   mainLayout->setAlignment(HeaderWidget2,Qt::AlignTop);
    mainLayout->addWidget(DownWidget,2,0,1,7);
    mainWidget->setLayout(mainLayout);

    connect(topPushButton1,SIGNAL(clicked()),this,SLOT(CheckDisease()));
    connect(topPushButton2,SIGNAL(clicked()),this,SLOT(CheckDisease()));
    connect(topPushButton3,SIGNAL(clicked()),this,SLOT(CheckDisease()));
    connect(topPushButton4,SIGNAL(clicked()),this,SLOT(CheckDisease()));
    connect(SearchButton,SIGNAL(clicked()),this,SLOT(SearchDisease()));
}

void Diseases::CheckSystem() {
    QPushButton *FAbutton = (QPushButton*)sender();
    displayLabel->setText("");
    if(FAbutton->text()=="BRAIN"){
        Which->setText("<h2>BRAIN</h2>");
        topPushButton1->setText("Parkinsons");
        topPushButton2->setText("Meningitis");
        topPushButton3->setText("Encephalitis");
        topPushButton4->setText("Alzeimer");
    }
    if(FAbutton->text()=="HEAD"){
        Which->setText("<h2>HEAD</h2>");
        topPushButton1->setText("Cluster Headache");
        topPushButton2->setText("Tension Headache");
        topPushButton3->setText("Migraine");
        topPushButton4->setText("Sinus Headache");
    }
    if(FAbutton->text()=="EYES"){
        Which->setText("<h2>EYES</h2>");
        topPushButton1->setText("Cataract");
        topPushButton2->setText("Conjunctivitis");
        topPushButton3->setText("Dry Eye Syndrome");
        topPushButton4->setText("Glaucoma");
    }
    if(FAbutton->text()=="TEETH AND GUMS"){
        Which->setText("<h2>TEETH & GUMS</h2>");
        topPushButton1->setText("Gingivitis");
        topPushButton2->setText("Decay");
        topPushButton3->setText("Periodontal");
        topPushButton4->setText("Sensitivity");
    }
    if(FAbutton->text()=="HEART"){
        Which->setText("<h2>HEART</h2>");
        topPushButton1->setText("Cardiomypathy");
        topPushButton2->setText("Myocardial Infarction");
        topPushButton3->setText("Coronary Heart Disease");
        topPushButton4->setText("Congenital Heart Disease");
    }
    if(FAbutton->text()=="RESPIRATORY"){
        Which->setText("<h2>RESPIRATORY</h2>");
        topPushButton1->setText("Tuberculosis");
        topPushButton2->setText("Pneumonia");
        topPushButton3->setText("COPD");
        topPushButton4->setText("Asthma");
    }
    if(FAbutton->text()=="DIGESTIVE"){
        Which->setText("<h2>DIGESTIVE</h2>");
        topPushButton1->setText("Appendicitis");
        topPushButton2->setText("Cholera");
        topPushButton3->setText("Jaundice");
        topPushButton4->setText("Hepatitis B");
    }
    if(FAbutton->text()=="KIDNEY"){
        Which->setText("<h2>KIDNEY</h2>");
        topPushButton1->setText("Uremia");
        topPushButton2->setText("Kidney Stone");
        topPushButton3->setText("Kidney Cancer");
        topPushButton4->setText("Kidney Injury");
    }
}
void Diseases::CheckDisease() {
        QPushButton *FAbutton = (QPushButton*)sender();
        if(FAbutton->text()=="Parkinsons"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Parkinsons.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Meningitis"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Meningitis.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Encephalitis"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Encephalitis.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Alzeimer"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Alzheimer.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Cluster Headache"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\ClusterHeadache.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Tension Headache"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\TensionHeadache.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Migraine"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Migraine.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Sinus Headache"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\SinusHeadache.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Cataract"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Cataract.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Conjunctivitis"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Conjuctivitis.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Dry Eye Syndrome"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\DryEyes.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Glaucoma"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Glaucoma.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Gingivitis"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Gingivitis.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Decay"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\ToothDecay.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Periodontal"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Periodontitis.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Sensitivity"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\ToothSensitivity.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Cardiomypathy"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Cardiomyopathy.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Myocardial Infarction"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\HeartAttack.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Coronary Heart Disease"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\CoronaryArteryDisease.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Congenital Heart Disease"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Congenital.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Tuberculosis"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Tuberculosis.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Pneumonia"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Pnemonia.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="COPD"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\COPD.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Asthma"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Asthma.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Appendicitis"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Appendicitis.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Cholera"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Cholera.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Jaundice"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Jaundice.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Hepatitis B"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\HepatitisB.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Uremia"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\Uremia.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Kidney Stone"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\KidneyStone.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Kidney Cancer"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\KidneyCancer.txt" );
            displayLabel->setText(lbl);
        }
        if(FAbutton->text()=="Kidney Injury"){
            QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\KidneyInjury.txt" );
            displayLabel->setText(lbl);
        }

}

void Diseases::SearchDisease(){
    QString file = DiseaseFinder::find(SearchBox->text());

    if (file.length() > 0){
        displayLabel->setText(file);
    }
}
bool Diseases::eventFilter(QObject *obj, QEvent *event){
    if (obj == SearchBox && event->type() == QEvent::KeyPress){
            QKeyEvent *key = static_cast<QKeyEvent *>(event);
            switch (key->key()) {
            case 16777220:
                SearchDisease();
                break;
            }
    }
 return QObject::eventFilter(obj, event);

}
