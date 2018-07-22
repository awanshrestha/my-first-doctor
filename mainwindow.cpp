#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("My First Doctor");
    this->setFixedSize(1400,960);
    this->setWindowIcon(QIcon("://Images/Icons/MainIcon.jpg"));

    mainWidget = new QWidget;
    mainWidget->setStyleSheet("background:#4C4C4C;");
    mainLayout = new QGridLayout;

    CreateExceptDisplay();


    // display layout contents
        displayWidget = new QWidget;
        displayWidget->setStyleSheet("background:#E0E0E0;");
        displayLayout = new QGridLayout;

        theDisplayWidget = new QWidget;
        theDisplayLayout = new QGridLayout;
        theDisplayWidget->setStyleSheet("border-image: url(://Images/Images/Untitled.jpg) 0 0 0 0 stretch stretch;");

       displayLayout->addWidget(theDisplayWidget,0,0);
       displayLayout->addWidget(BottomBar,1,0);

       displayWidget->setLayout(displayLayout);
    // display layout contents end


       //main layout contents
       mainLayout->addWidget(headerWidget,      0,0,1,7);
       mainLayout->addWidget(SectionBarWidget,  1,0,10,1);
       mainLayout->addWidget(displayWidget,        1,1,10,6);
       mainWidget->setLayout(mainLayout);
       //main layout contents end
    setCentralWidget(mainWidget);

    CreateContactsWidget();
    CreateHospitalsWidget();
    CreateAmbulancesWidget();
    CreateBloodBanksWidget();
    CreateMedicalWidget();
    CreateBrainWidget();
    CreateHeadWidget();
    CreateEyesWidget();
    CreateTeethandGumsWidget();
    CreateHeartWidget();
    CreateRespiratoryWidget();
    CreateDigestiveWidget();
    CreateKidneyWidget();
}

void MainWindow::CreateExceptDisplay() {

    // Header layout contents
        headerWidget = new QWidget;
        headerLayout = new QGridLayout;

        Button *Home = new Button; Home->setFixedSize(345,75);
        Home->setStyleSheet("background:#424242; margin:0; padding:0;");

        QLabel *IconLabel = new QLabel;
        IconLabel->setFixedSize(351,74);
        IconLabel->setStyleSheet("background-image:url(://Images/Icons/TopLogo.JPG);"
                                 "background-repeat:no repeat;");
        QGridLayout *IconLayout = new QGridLayout;

        IconLayout->addWidget(IconLabel,0,0,1,1);

        Home->setLayout(IconLayout);
        headerLayout->addWidget(Home,0,0);
        headerLayout->setAlignment(Home,Qt::AlignLeft);
        headerWidget->setLayout(headerLayout);

    // Header layout contents end

    // Section bar layout contents
        SectionbarLayout = new QGridLayout;
        SectionBarWidget = new QWidget;
        SectionBarWidget->setStyleSheet("background:#1976D2;");
        SectionBarWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed) ;

        Button *medicalBtn      = new Button; medicalBtn->setFixedSize(160,120);
        Button *firstAidBtn     = new Button; firstAidBtn->setFixedSize(160,120);
        Button *contactsBtn     = new Button; contactsBtn->setFixedSize(160,120);
        Button *diseasesBtn     = new Button; diseasesBtn->setFixedSize(160,120);
        Button *TipsBtn         = new Button; TipsBtn->setFixedSize(160,120);
        QLabel *Invisible       = new QLabel; Invisible->setFixedSize(160,110);
        Button *aboutBtn = new Button("About");     aboutBtn->setStyleSheet("background:#E0E0E0;");


        QGridLayout *IconsLayout[5];
        QLabel *IconsLabel[5];

        for (int i = 0; i <5; i++){ IconsLabel[i] = new QLabel;
                                    IconsLayout[i] = new QGridLayout;}
        IconsLabel[0]->setStyleSheet("background-image:url(://Images/Icons/medicalIcon.jpg);"
                                      "background-repeat:no repeat;");
        IconsLabel[1]->setStyleSheet("background-image:url(://Images/Icons/FIrstAid.jpg);"
                                              "background-repeat:no repeat;");
        IconsLabel[2]->setStyleSheet("background-image:url(://Images/Icons/contactsIcon.jpg);"
                                              "background-repeat:no repeat;");
        IconsLabel[3]->setStyleSheet("background-image:url(://Images/Icons/DiseaseIcon.jpg);"
                                              "background-repeat:no repeat;");
        IconsLabel[4]->setStyleSheet("background-image:url(://Images/Icons/FoodIcon.JPG);"
                                      "background-repeat:no repeat;");


        for (int i = 0; i <5; i++){ IconsLayout[i]->addWidget(IconsLabel[i]);}

        medicalBtn->setLayout(IconsLayout[0]);
        firstAidBtn->setLayout(IconsLayout[1]);
        contactsBtn->setLayout(IconsLayout[2]);
        diseasesBtn->setLayout(IconsLayout[3]);
        TipsBtn->setLayout(IconsLayout[4]);

        SectionbarLayout->addWidget(medicalBtn,0,0);
        SectionbarLayout->addWidget(firstAidBtn,1,0);
        SectionbarLayout->addWidget(contactsBtn,2,0);
        SectionbarLayout->addWidget(diseasesBtn,3,0);
        SectionbarLayout->addWidget(TipsBtn,4,0);
        SectionbarLayout->addWidget(Invisible,5,0);
        SectionbarLayout->addWidget(aboutBtn);
        SectionbarLayout->setAlignment(aboutBtn,Qt::AlignBottom);

        SectionBarWidget->setLayout(SectionbarLayout);
    // Section bar layout contents end

        BottomBar = new QLabel(" An apple a day keeps a doctor away.");
        BottomBar->setFixedHeight(40);
        BottomBar->setStyleSheet("QLabel {  color : white; background-color:#4C4C4C;}");

        // connect
        connect(aboutBtn,SIGNAL(clicked()),this,SLOT(ShowAbout()));
        connect(medicalBtn,SIGNAL(clicked()),this,SLOT(ShowMedical()));
        connect(firstAidBtn,SIGNAL(clicked()),this,SLOT(ShowFirstAid()));
        connect(contactsBtn,SIGNAL(clicked()),this,SLOT(ShowContacts()));
        connect(diseasesBtn,SIGNAL(clicked()),this,SLOT(ShowDiseases()));
        connect(TipsBtn,SIGNAL(clicked()),this,SLOT(showFoodTips()));
        connect(Home, SIGNAL(clicked()), this, SLOT( ShowHome() ));

}

void MainWindow::CreateMedicalWidget(){
    MedicalWidget = new QWidget;
    MedicalLayout = new QGridLayout;

    QWidget *MedicalBarWidget = new QWidget;    MedicalBarWidget->setStyleSheet("background:#B0B0B0;");
    MedicalBarWidget->setFixedWidth(250);
    QGridLayout *MedicalBarLayout = new QGridLayout;
    QWidget *MDoctor = new QWidget;
    MDoctor->setStyleSheet("border-image: url(://Images/Images/Doctor.jpg) 0 0 0 0 stretch stretch;");

    Button *btnMedicals[8];
    for(int i =0; i<8; i++){
        btnMedicals[i]= new Button;
        btnMedicals[i]->setFixedSize(180,50);
        btnMedicals[i]->setStyleSheet("background: #A9A9A9; border-radius:15px;border:2px solid black ;");
    }
    btnMedicals[0]->setText("BRAIN");
    btnMedicals[1]->setText("HEAD");
    btnMedicals[2]->setText("EYES");
    btnMedicals[3]->setText("TEETH AND GUMS");
    btnMedicals[4]->setText("HEART");
    btnMedicals[5]->setText("RESPIRATORY");
    btnMedicals[6]->setText("DIGESTIVE");
    btnMedicals[7]->setText("KIDNEY");
    for(int i =0; i<8; i++){
        MedicalBarLayout->addWidget(btnMedicals[i],i,0);

    }


    MedicalBarWidget->setLayout(MedicalBarLayout);
    MedicalBarWidget->setStyleSheet("background: #d7dbdd ;");

    MedicalLayout->addWidget(MDoctor,0,0);
    MedicalLayout->addWidget(MedicalBarWidget,0,1);

    connect (btnMedicals[0],SIGNAL(clicked()),this,SLOT(ShowBrain()));
    connect (btnMedicals[1],SIGNAL(clicked()),this,SLOT(ShowHead()));
    connect (btnMedicals[2],SIGNAL(clicked()),this,SLOT(ShowEyes()));
    connect (btnMedicals[3],SIGNAL(clicked()),this,SLOT(ShowTeethandGums()));
    connect (btnMedicals[4],SIGNAL(clicked()),this,SLOT(ShowHeart()));
    connect (btnMedicals[5],SIGNAL(clicked()),this,SLOT(ShowRespiratory()));
    connect (btnMedicals[6],SIGNAL(clicked()),this,SLOT(ShowDigestive()));
    connect (btnMedicals[7],SIGNAL(clicked()),this,SLOT(ShowKidney()));

   MedicalWidget->setLayout(MedicalLayout);
   MedicalWidget->setStyleSheet("background:#4B0082;");
}
void MainWindow::CreateBrainWidget(){
    BrainWidget = new QWidget;
    QGridLayout *BrainLayout = new QGridLayout;

    QLabel *HeaderLabelBrain = new QLabel;
    HeaderLabelBrain->setText("<h3>Questions</h3>");

    QPushButton *pushButtonBrainBack = new QPushButton("Back");pushButtonBrainBack->setFixedSize(150,30);
    connect (pushButtonBrainBack,SIGNAL(clicked()),this,SLOT(ShowMedical()));

    QGridLayout *qnslayoutBrain = new QGridLayout;
    QWidget *qnsWidgetBrain = new QWidget;
    QScrollArea *qnsScrollBrain = new QScrollArea;
    qnsScrollBrain->setFixedHeight(380);

    QPushButton *check = new QPushButton("CHECK for Brain");check->setFixedSize(150,30);
    connect(check,SIGNAL(clicked()),this,SLOT(CheckDiseaseProbability()));

    QGridLayout *ProbabilityLayoutBrain = new QGridLayout;
    QGridLayout *ParkinsonsLayout = new QGridLayout;
    QGridLayout *MeningitisLayout = new QGridLayout;
    QGridLayout *EncephalitisLayout = new QGridLayout;
    QGridLayout *AlzeimerLayout = new QGridLayout;

    Parkinsons = new QLabel(" ");
    Meningitis = new QLabel(" ");
    Encephalitis = new QLabel(" ");
    Alzeimer = new QLabel(" ");

        ParkinsonsLayout = getProbabilityLayout(Parkinsons,"Parkinsons");
        MeningitisLayout = getProbabilityLayout(Meningitis,"Meningitis");
        EncephalitisLayout = getProbabilityLayout(Encephalitis,"Encephalitis");
        AlzeimerLayout = getProbabilityLayout(Alzeimer,"Alzheimer");

        ProbabilityLayoutBrain->addLayout(ParkinsonsLayout,0,0);
        ProbabilityLayoutBrain->addLayout(MeningitisLayout,1,0);
        ProbabilityLayoutBrain->addLayout(EncephalitisLayout,2,0);
        ProbabilityLayoutBrain->addLayout(AlzeimerLayout,3,0);


  QWidget *qBrain[18];
    QString quesBrain[18];
    quesBrain[0]="1.Do you feel tremors in head or hands?";
    quesBrain[1]="2.Do you feel stiffness in body?";
    quesBrain[2]="3.Any change in voice or speech?";
    quesBrain[3]="4.Is these recent change in handwriting?";
    quesBrain[4]="5.Any sign of dizziness or fainting?";
    quesBrain[5]="6.Imbalance body posture?";
    quesBrain[6]="7.Any sensitivity to bright light?";
    quesBrain[7]="8.Signs of fever and headache?";
    quesBrain[8]="9.Do you have weakened immune system?";
    quesBrain[9]="10.Are you always confused and irritated?";
    quesBrain[10]="11.Had there been nausea or vomiting?";
    quesBrain[11]="12.Any family member had Alzeimer?";
    quesBrain[12]="13.Do you feel sleepy and tired all day?";
    quesBrain[13]="14.Had there been change in personality?";
    quesBrain[14]="15.Poor judgement and Loss of memory?";
    quesBrain[15]="16.Any heart disease/head injury in past?";
    quesBrain[16]="17.Do you have high blood pressure?";
    quesBrain[17]="18.Are you over 65 years of age?";

    for(int i = 0; i < 18; i++ ) {
        QuestionBrain[i] = new Question;
        QuestionBrain[i]->setQuestion(quesBrain[i]);
        qBrain[i] = new QWidget;
        qBrain[i] = QuestionBrain[i]->getWidget();
    }

    qnslayoutBrain->addWidget(qBrain[0],0,0);
    qnslayoutBrain->addWidget(qBrain[1],1,0);
    qnslayoutBrain->addWidget(qBrain[2],2,0);
    qnslayoutBrain->addWidget(qBrain[3],3,0);
    qnslayoutBrain->addWidget(qBrain[4],4,0);
    qnslayoutBrain->addWidget(qBrain[5],5,0);
    qnslayoutBrain->addWidget(qBrain[6],0,1);
    qnslayoutBrain->addWidget(qBrain[7],1,1);
    qnslayoutBrain->addWidget(qBrain[8],2,1);
    qnslayoutBrain->addWidget(qBrain[9],3,1);
    qnslayoutBrain->addWidget(qBrain[10],4,1);
    qnslayoutBrain->addWidget(qBrain[11],5,1);
    qnslayoutBrain->addWidget(qBrain[12],0,2);
    qnslayoutBrain->addWidget(qBrain[13],1,2);
    qnslayoutBrain->addWidget(qBrain[14],2,2);
    qnslayoutBrain->addWidget(qBrain[15],3,2);
    qnslayoutBrain->addWidget(qBrain[16],4,2);
    qnslayoutBrain->addWidget(qBrain[17],5,2);

    qnsWidgetBrain->setLayout(qnslayoutBrain);
    qnsScrollBrain->setWidget(qnsWidgetBrain);

    BrainLayout->addWidget(HeaderLabelBrain,0,1,1,1);
    BrainLayout->addWidget(qnsScrollBrain,1,1,1,1);
    BrainLayout->addWidget(check,2,1);
    BrainLayout->addLayout(ProbabilityLayoutBrain,3,1,1,1);
    BrainLayout->addWidget(pushButtonBrainBack,4,1,1,1);
    BrainWidget->setLayout(BrainLayout);
}
void MainWindow::CreateHeadWidget(){
    HeadWidget = new QWidget;
        QGridLayout *HeadLayout = new QGridLayout;

        QLabel *HeaderLabelHead = new QLabel;
        HeaderLabelHead->setText("<h3>Questions</h3>");

        QPushButton *pushButtonHeadBack = new QPushButton("Back");pushButtonHeadBack->setFixedSize(150,30);
        connect (pushButtonHeadBack,SIGNAL(clicked()),this,SLOT(ShowMedical()));

        QGridLayout *qnslayoutHead = new QGridLayout;
        QWidget *qnsWidgetHead = new QWidget;
        QScrollArea *qnsScrollHead = new QScrollArea;
        qnsScrollHead->setFixedHeight(380);

        QPushButton *check = new QPushButton("CHECK for Head");check->setFixedSize(150,30);
        connect(check,SIGNAL(clicked()),this,SLOT(CheckDiseaseProbability()));

        QGridLayout *ProbabilityLayoutHead = new QGridLayout;
        QGridLayout *ClusterLayout = new QGridLayout;
        QGridLayout *TensionLayout = new QGridLayout;
        QGridLayout *SinusLayout = new QGridLayout;
        QGridLayout *MigraineLayout = new QGridLayout;

        Cluster = new QLabel(" ");
        Tension = new QLabel(" ");
        Sinus = new QLabel(" ");
        Migraine = new QLabel(" ");

            ClusterLayout = getProbabilityLayout(Cluster,"Cluster Headache");
            TensionLayout = getProbabilityLayout(Tension,"Tension Headache");
            SinusLayout = getProbabilityLayout(Sinus,"Sinus Headache");
            MigraineLayout = getProbabilityLayout(Migraine,"Migraine");

            ProbabilityLayoutHead->addLayout(ClusterLayout,0,0);
            ProbabilityLayoutHead->addLayout(TensionLayout,1,0);
            ProbabilityLayoutHead->addLayout(SinusLayout,2,0);
            ProbabilityLayoutHead->addLayout(MigraineLayout,3,0);

            QWidget *qHead[18];
            QString quesHead[18];
            quesHead[0]="1.Is there intense pain in one eye?";
            quesHead[1]="2.Do you feel restlessness?";
            quesHead[2]="3.Are there excessive tears in eyes?";
            quesHead[3]="4.Redness in affected eye?";
            quesHead[4]="5.Swelling around affected eye?";
            quesHead[5]="6.Is there dull head pain?";
            quesHead[6]="7.Tightness sensation in head?";
            quesHead[7]="8.Any sign of pressure in head";
            quesHead[8]="9.Do you feel irritable and unfocused?";
            quesHead[9]="10.Is there tenderness around scalp?";
            quesHead[10]="11.Is there pain on either or one side of head?";
            quesHead[11]="12.Is the head pain throbbing and pulsating?";
            quesHead[12]="13.Do you have sensitivity to light,smell and \ntouch?";
            quesHead[13]="14.Any sign of nausea and vomiting?";
            quesHead[14]="15.Is there pain in cheek and forehead?";
            quesHead[15]="16.Any sign of fatigue?";
            quesHead[16]="17.Any sign of stuffy nose?";
            quesHead[17]="18.Does head pain worsen if you lie down?";

            for(int i = 0; i < 18; i++ ) {
                QuestionHead[i] = new Question;
                QuestionHead[i]->setQuestion(quesHead[i]);
                qHead[i] = new QWidget;
                qHead[i] = QuestionHead[i]->getWidget();
            }

            qnslayoutHead->addWidget(qHead[0],0,0);
            qnslayoutHead->addWidget(qHead[1],1,0);
            qnslayoutHead->addWidget(qHead[2],2,0);
            qnslayoutHead->addWidget(qHead[3],3,0);
            qnslayoutHead->addWidget(qHead[4],4,0);
            qnslayoutHead->addWidget(qHead[5],5,0);
            qnslayoutHead->addWidget(qHead[6],0,1);
            qnslayoutHead->addWidget(qHead[7],1,1);
            qnslayoutHead->addWidget(qHead[8],2,1);
            qnslayoutHead->addWidget(qHead[9],3,1);
            qnslayoutHead->addWidget(qHead[10],4,1);
            qnslayoutHead->addWidget(qHead[11],5,1);
            qnslayoutHead->addWidget(qHead[12],0,2);
            qnslayoutHead->addWidget(qHead[13],1,2);
            qnslayoutHead->addWidget(qHead[14],2,2);
            qnslayoutHead->addWidget(qHead[15],3,2);
            qnslayoutHead->addWidget(qHead[16],4,2);
            qnslayoutHead->addWidget(qHead[17],5,2);

            qnsWidgetHead->setLayout(qnslayoutHead);
            qnsScrollHead->setWidget(qnsWidgetHead);

            HeadLayout->addWidget(HeaderLabelHead,0,1,1,1);
            HeadLayout->addWidget(qnsScrollHead,1,1,1,1);
            HeadLayout->addWidget(check,2,1);
            HeadLayout->addLayout(ProbabilityLayoutHead,3,1,1,1);
            HeadLayout->addWidget(pushButtonHeadBack,4,1,1,1);
            HeadWidget->setLayout(HeadLayout);
}
void MainWindow::CreateEyesWidget(){
    EyesWidget = new QWidget;
        QGridLayout *EyesLayout = new QGridLayout;

        QLabel *HeaderLabelEyes = new QLabel;
        HeaderLabelEyes->setText("<h3>Questions</h3>");

        QPushButton *pushButtonEyesBack = new QPushButton("Back");pushButtonEyesBack->setFixedSize(150,30);
        connect (pushButtonEyesBack,SIGNAL(clicked()),this,SLOT(ShowMedical()));

        QGridLayout *qnslayoutEyes = new QGridLayout;
        QWidget *qnsWidgetEyes = new QWidget;
        QScrollArea *qnsScrollEyes = new QScrollArea;
        qnsScrollEyes->setFixedHeight(380);

        QPushButton *check = new QPushButton("CHECK for Eyes");check->setFixedSize(150,30);
        connect(check,SIGNAL(clicked()),this,SLOT(CheckDiseaseProbability()));

        QGridLayout *ProbabilityLayoutEyes = new QGridLayout;
        QGridLayout *CataractLayout = new QGridLayout;
        QGridLayout *ConjunctivitisLayout = new QGridLayout;
        QGridLayout *DryEyeSyndromeLayout = new QGridLayout;
        QGridLayout *GlaucomaLayout = new QGridLayout;

        Cataract = new QLabel(" ");
        Conjunctivitis = new QLabel(" ");
        DryEyeSyndrome = new QLabel(" ");
        Glaucoma = new QLabel(" ");

            CataractLayout = getProbabilityLayout(Cataract,"Cataract");
            ConjunctivitisLayout = getProbabilityLayout(Conjunctivitis,"Conjunctivitis");
            DryEyeSyndromeLayout = getProbabilityLayout(DryEyeSyndrome,"Dry Eye Syndrome");
            GlaucomaLayout = getProbabilityLayout(Glaucoma,"Glaucoma");

            ProbabilityLayoutEyes->addLayout(CataractLayout,0,0);
            ProbabilityLayoutEyes->addLayout(ConjunctivitisLayout,1,0);
            ProbabilityLayoutEyes->addLayout(DryEyeSyndromeLayout,2,0);
            ProbabilityLayoutEyes->addLayout(GlaucomaLayout,3,0);

            QWidget *qEyes[18];
            QString quesEyes[18];
            quesEyes[0]="1.Do you have blurred,cloudy and dim vision?";
            quesEyes[1]="2.Any difficulty with vision at night?";
            quesEyes[2]="3.Are you obesed?";
            quesEyes[3]="4.Do you have high blood sugar level?";
            quesEyes[4]="5.Any sensitivity to light?";
            quesEyes[5]="6.Double vision in single eye?";
            quesEyes[6]="7.Do you see halos around light?";
            quesEyes[7]="8.Any sign of redness in eye?";
            quesEyes[8]="9.Any burning sensations in eye?";
            quesEyes[9]="10.Any itchy sensation in eye?";
            quesEyes[10]="11.Is there excessive tears?";
            quesEyes[11]="12.Signs of cough and cold?";
            quesEyes[12]="13.Do you have fever?";
            quesEyes[13]="14.Do you have sore eyes?";
            quesEyes[14]="15.Is there dryness in eye?";
            quesEyes[15]="16.Intense pain in the eyes?";
            quesEyes[16]="17.Is there a headache?";
            quesEyes[17]="18.Any sign of nausea or vomiting?";

            for(int i = 0; i < 18; i++ ) {
                QuestionEyes[i] = new Question;
                QuestionEyes[i]->setQuestion(quesEyes[i]);
                qEyes[i] = new QWidget;
                qEyes[i] = QuestionEyes[i]->getWidget();
            }

            qnslayoutEyes->addWidget(qEyes[0],0,0);
            qnslayoutEyes->addWidget(qEyes[1],1,0);
            qnslayoutEyes->addWidget(qEyes[2],2,0);
            qnslayoutEyes->addWidget(qEyes[3],3,0);
            qnslayoutEyes->addWidget(qEyes[4],4,0);
            qnslayoutEyes->addWidget(qEyes[5],5,0);
            qnslayoutEyes->addWidget(qEyes[6],0,1);
            qnslayoutEyes->addWidget(qEyes[7],1,1);
            qnslayoutEyes->addWidget(qEyes[8],2,1);
            qnslayoutEyes->addWidget(qEyes[9],3,1);
            qnslayoutEyes->addWidget(qEyes[10],4,1);
            qnslayoutEyes->addWidget(qEyes[11],5,1);
            qnslayoutEyes->addWidget(qEyes[12],0,2);
            qnslayoutEyes->addWidget(qEyes[13],1,2);
            qnslayoutEyes->addWidget(qEyes[14],2,2);
            qnslayoutEyes->addWidget(qEyes[15],3,2);
            qnslayoutEyes->addWidget(qEyes[16],4,2);
            qnslayoutEyes->addWidget(qEyes[17],5,2);


            qnsWidgetEyes->setLayout(qnslayoutEyes);
                qnsScrollEyes->setWidget(qnsWidgetEyes);

                EyesLayout->addWidget(HeaderLabelEyes,0,1,1,1);
                EyesLayout->addWidget(qnsScrollEyes,1,1,1,1);
                EyesLayout->addWidget(check,2,1);
                EyesLayout->addLayout(ProbabilityLayoutEyes,3,1,1,1);
                EyesLayout->addWidget(pushButtonEyesBack,4,1,1,1);
                EyesWidget->setLayout(EyesLayout);
}
void MainWindow::CreateTeethandGumsWidget(){
    TeethAndGumsWidget = new QWidget;
        QGridLayout *TeethAndGumsLayout = new QGridLayout;

        QLabel *HeaderLabelTeethAndGums = new QLabel;
        HeaderLabelTeethAndGums->setText("<h3>Questions</h3>");

        QPushButton *pushButtonTeethAndGumsBack = new QPushButton("Back");pushButtonTeethAndGumsBack->setFixedSize(150,30);
        connect (pushButtonTeethAndGumsBack,SIGNAL(clicked()),this,SLOT(ShowMedical()));

        QGridLayout *qnslayoutTeethAndGums = new QGridLayout;
        QWidget *qnsWidgetTeethAndGums = new QWidget;
        QScrollArea *qnsScrollTeethAndGums = new QScrollArea;
        qnsScrollTeethAndGums->setFixedHeight(380);

        QPushButton *check = new QPushButton("CHECK for Teeth and Gums");check->setFixedSize(250,30);
        connect(check,SIGNAL(clicked()),this,SLOT(CheckDiseaseProbability()));

        QGridLayout *ProbabilityLayoutTeethAndGums = new QGridLayout;
        QGridLayout *GingivitisLayout = new QGridLayout;
        QGridLayout *DecayLayout = new QGridLayout;
        QGridLayout *PeriodontalLayout = new QGridLayout;
        QGridLayout *SensitivityLayout = new QGridLayout;

        Gingivitis = new QLabel(" ");
        Decay = new QLabel(" ");
        Periodontal = new QLabel(" ");
        Sensitivity = new QLabel(" ");

            GingivitisLayout = getProbabilityLayout(Gingivitis,"Gingivitis");
            DecayLayout = getProbabilityLayout(Decay,"Decay");
            PeriodontalLayout = getProbabilityLayout(Periodontal,"Periodontal Disease");
            SensitivityLayout = getProbabilityLayout(Sensitivity,"Sensitivity");

            ProbabilityLayoutTeethAndGums->addLayout(GingivitisLayout,0,0);
            ProbabilityLayoutTeethAndGums->addLayout(DecayLayout,1,0);
            ProbabilityLayoutTeethAndGums->addLayout(PeriodontalLayout,2,0);
            ProbabilityLayoutTeethAndGums->addLayout(SensitivityLayout,3,0);

            QWidget *qTeethAndGums[18];
            QString quesTeethAndGums[18];
            quesTeethAndGums[0]="1.Do you have red and purple gums?";
            quesTeethAndGums[1]="2.Does gums pain when touched?";
            quesTeethAndGums[2]="3.Bleeding from gums when brushing?";
            quesTeethAndGums[3]="4.Is there bad breathing?";
            quesTeethAndGums[4]="5.Are the gums swollen?";
            quesTeethAndGums[5]="6.Are the gums soft?";
            quesTeethAndGums[6]="7.Do you smoke?";
            quesTeethAndGums[7]="8.You brush only once a day?";
            quesTeethAndGums[8]="9.Is there a toothache?";
            quesTeethAndGums[9]="10.Are your teeth sensitive?";
            quesTeethAndGums[10]="11.Is there any visible hole on the teeth?";
            quesTeethAndGums[11]="12.Sharp pain while eating?";
            quesTeethAndGums[12]="13.Black brown stain on tooth surface?";
            quesTeethAndGums[13]="14.Are your teeth loose?";
            quesTeethAndGums[14]="15.Are gums receding and teeth long appearing?";
            quesTeethAndGums[15]="16.Sensitive to hot or cold food?";
            quesTeethAndGums[16]="17.Dull ache and pressure in upper jaw?";
            quesTeethAndGums[17]="18.Breathing in cold makes teeth sensitive?";

            for(int i = 0; i < 18; i++ ) {
                QuestionTeethAndGums[i] = new Question;
                QuestionTeethAndGums[i]->setQuestion(quesTeethAndGums[i]);
                qTeethAndGums[i] = new QWidget;
                qTeethAndGums[i] = QuestionTeethAndGums[i]->getWidget();
            }

            qnslayoutTeethAndGums->addWidget(qTeethAndGums[0],0,0);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[1],1,0);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[2],2,0);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[3],3,0);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[4],4,0);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[5],5,0);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[6],0,1);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[7],1,1);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[8],2,1);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[9],3,1);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[10],4,1);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[11],5,1);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[12],0,2);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[13],1,2);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[14],2,2);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[15],3,2);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[16],4,2);
            qnslayoutTeethAndGums->addWidget(qTeethAndGums[17],5,2);


            qnsWidgetTeethAndGums->setLayout(qnslayoutTeethAndGums);
                qnsScrollTeethAndGums->setWidget(qnsWidgetTeethAndGums);

                TeethAndGumsLayout->addWidget(HeaderLabelTeethAndGums,0,1,1,1);
                TeethAndGumsLayout->addWidget(qnsScrollTeethAndGums,1,1,1,1);
                TeethAndGumsLayout->addWidget(check,2,1);
                TeethAndGumsLayout->addLayout(ProbabilityLayoutTeethAndGums,3,1,1,1);
                TeethAndGumsLayout->addWidget(pushButtonTeethAndGumsBack,4,1,1,1);
                TeethAndGumsWidget->setLayout(TeethAndGumsLayout);
}
void MainWindow::CreateHeartWidget(){
    HeartWidget = new QWidget;
        QGridLayout *HeartLayout = new QGridLayout;

        QLabel *HeaderLabelHeart = new QLabel;
        HeaderLabelHeart->setText("<h3>Questions</h3>");

        QPushButton *pushButtonHeartBack = new QPushButton("Back");pushButtonHeartBack->setFixedSize(150,30);
        connect (pushButtonHeartBack,SIGNAL(clicked()),this,SLOT(ShowMedical()));

        QGridLayout *qnslayoutHeart = new QGridLayout;
        QWidget *qnsWidgetHeart = new QWidget;
        QScrollArea *qnsScrollHeart = new QScrollArea;
        qnsScrollHeart->setFixedHeight(380);

        QPushButton *check = new QPushButton("CHECK for Heart");check->setFixedSize(150,30);
        connect(check,SIGNAL(clicked()),this,SLOT(CheckDiseaseProbability()));

        QGridLayout *ProbabilityLayoutHeart = new QGridLayout;
        QGridLayout *CardiomypathyLayout = new QGridLayout;
        QGridLayout *MyILayout = new QGridLayout;
        QGridLayout *CoronaryLayout = new QGridLayout;
        QGridLayout *CongenitalLayout = new QGridLayout;

        Cardiomypathy = new QLabel(" ");
        MyI = new QLabel(" ");
        Coronary = new QLabel(" ");
        Congenital = new QLabel(" ");

            CardiomypathyLayout = getProbabilityLayout(Cardiomypathy,"Cardiomypathy");
            MyILayout = getProbabilityLayout(MyI,"Myocardial Infarction");
            CoronaryLayout = getProbabilityLayout(Coronary,"Coronary Heart Disease");
            CongenitalLayout = getProbabilityLayout(Congenital,"Congenital Heart Disease");

            ProbabilityLayoutHeart->addLayout(CardiomypathyLayout,0,0);
            ProbabilityLayoutHeart->addLayout(MyILayout,1,0);
            ProbabilityLayoutHeart->addLayout(CoronaryLayout,2,0);
            ProbabilityLayoutHeart->addLayout(CongenitalLayout,3,0);

            QWidget *qHeart[18];
            QString quesHeart[18];
            quesHeart[0]="1.Do you feel breathelessness?";
            quesHeart[1]="2.Is there swelling in legs and ankles?";
            quesHeart[2]="3.Is there bloating of abdomen?";
            quesHeart[3]="4.Any sign of fatigue?";
            quesHeart[4]="5.Any sign of dizziness or fainting?";
            quesHeart[5]="6.Is there rapid heartbeat?";
            quesHeart[6]="7.Any discomfort in chest?";
            quesHeart[7]="8.Signs of nausea or vomiting?";
            quesHeart[8]="9.Pain in chest, back and uppper body?";
            quesHeart[9]="10.Do you sweat a lot?";
            quesHeart[10]="11.Is there presure and tightness in chest?";
            quesHeart[11]="12.Abnormal heart rhythms?";
            quesHeart[12]="13.Are your skin and nail blueish?";
            quesHeart[13]="14.Do you get tired quickly?";
            quesHeart[14]="15.Are you obesed?";
            quesHeart[15]="16.Anyone from family had heart diseases?";
            quesHeart[16]="17.Do you drink alcohol?";
            quesHeart[17]="18.Do you have high B.P. or diabetes?";

            for(int i = 0; i < 18; i++ ) {
                QuestionHeart[i] = new Question;
                QuestionHeart[i]->setQuestion(quesHeart[i]);
                qHeart[i] = new QWidget;
                qHeart[i] = QuestionHeart[i]->getWidget();
            }

            qnslayoutHeart->addWidget(qHeart[0],0,0);
            qnslayoutHeart->addWidget(qHeart[1],1,0);
            qnslayoutHeart->addWidget(qHeart[2],2,0);
            qnslayoutHeart->addWidget(qHeart[3],3,0);
            qnslayoutHeart->addWidget(qHeart[4],4,0);
            qnslayoutHeart->addWidget(qHeart[5],5,0);
            qnslayoutHeart->addWidget(qHeart[6],0,1);
            qnslayoutHeart->addWidget(qHeart[7],1,1);
            qnslayoutHeart->addWidget(qHeart[8],2,1);
            qnslayoutHeart->addWidget(qHeart[9],3,1);
            qnslayoutHeart->addWidget(qHeart[10],4,1);
            qnslayoutHeart->addWidget(qHeart[11],5,1);
            qnslayoutHeart->addWidget(qHeart[12],0,2);
            qnslayoutHeart->addWidget(qHeart[13],1,2);
            qnslayoutHeart->addWidget(qHeart[14],2,2);
            qnslayoutHeart->addWidget(qHeart[15],3,2);
            qnslayoutHeart->addWidget(qHeart[16],4,2);
            qnslayoutHeart->addWidget(qHeart[17],5,2);


            qnsWidgetHeart->setLayout(qnslayoutHeart);
                qnsScrollHeart->setWidget(qnsWidgetHeart);

                HeartLayout->addWidget(HeaderLabelHeart,0,1,1,1);
                HeartLayout->addWidget(qnsScrollHeart,1,1,1,1);
                HeartLayout->addWidget(check,2,1);
                HeartLayout->addLayout(ProbabilityLayoutHeart,3,1,1,1);
                HeartLayout->addWidget(pushButtonHeartBack,4,1,1,1);
                HeartWidget->setLayout(HeartLayout);
}
void MainWindow::CreateRespiratoryWidget(){
    RespiratoryWidget = new QWidget;
        QGridLayout *RespiratoryLayout = new QGridLayout;

        QLabel *HeaderLabelRespiratory = new QLabel;
        HeaderLabelRespiratory->setText("<h3>Questions</h3>");

        QPushButton *pushButtonRespiratoryBack = new QPushButton("Back");pushButtonRespiratoryBack->setFixedSize(150,30);
        connect (pushButtonRespiratoryBack,SIGNAL(clicked()),this,SLOT(ShowMedical()));

        QGridLayout *qnslayoutRespiratory = new QGridLayout;
        QWidget *qnsWidgetRespiratory = new QWidget;
        QScrollArea *qnsScrollRespiratory = new QScrollArea;
        qnsScrollRespiratory->setFixedHeight(380);

        QPushButton *check = new QPushButton("CHECK for Respiratory");check->setFixedSize(200,30);
        connect(check,SIGNAL(clicked()),this,SLOT(CheckDiseaseProbability()));

        QGridLayout *ProbabilityLayoutRespiratory = new QGridLayout;
        QGridLayout *TuberculosisLayout = new QGridLayout;
        QGridLayout *PneumoniaLayout = new QGridLayout;
        QGridLayout *COPDLayout = new QGridLayout;
        QGridLayout *AsthmaLayout = new QGridLayout;

        Tuberculosis = new QLabel(" ");
        Pneumonia = new QLabel(" ");
        COPD = new QLabel(" ");
        Asthma = new QLabel(" ");

            TuberculosisLayout = getProbabilityLayout(Tuberculosis,"Tuberculosis");
            PneumoniaLayout = getProbabilityLayout(Pneumonia,"Pneumonia");
            COPDLayout = getProbabilityLayout(COPD,"COPD");
            AsthmaLayout = getProbabilityLayout(Asthma,"Asthma");

            ProbabilityLayoutRespiratory->addLayout(TuberculosisLayout,0,0);
            ProbabilityLayoutRespiratory->addLayout(PneumoniaLayout,1,0);
            ProbabilityLayoutRespiratory->addLayout(COPDLayout,2,0);
            ProbabilityLayoutRespiratory->addLayout(AsthmaLayout,3,0);

            QWidget *qRespiratory[18];
            QString quesRespiratory[18];
            quesRespiratory[0]="1.Do you have fever?";
            quesRespiratory[1]="2.Have you been coughing for longer than \nthree weeks?";
            quesRespiratory[2]="3.Do you cough up blood?";
            quesRespiratory[3]="4.Do you have chest pain?";
            quesRespiratory[4]="5.Is there loss of appetite?";
            quesRespiratory[5]="6.Do you feel cold and chill?";
            quesRespiratory[6]="7.Any sign of fatigue and tiredness?";
            quesRespiratory[7]="8.Do you cough with greenish yellow mucus?";
            quesRespiratory[8]="9.Do you sweat a lot?";
            quesRespiratory[9]="10.Is there faster heartbeat and breathing?";
            quesRespiratory[10]="11.Are lips and fingertips turning blue?";
            quesRespiratory[11]="12.Do you smoke?";
            quesRespiratory[12]="13.Do you cough frequently?";
            quesRespiratory[13]="14.Any sign of edema or swollen \nextremities?";
            quesRespiratory[14]="15.Do you get sick frequently?";
            quesRespiratory[15]="16.Any sign of chest tightness?";
            quesRespiratory[16]="17.Any sign of cold and allergies?";
            quesRespiratory[17]="18.Do you have rapid shallow breaths?";

            for(int i = 0; i < 18; i++ ) {
                QuestionRespiratory[i] = new Question;
                QuestionRespiratory[i]->setQuestion(quesRespiratory[i]);
                qRespiratory[i] = new QWidget;
                qRespiratory[i] = QuestionRespiratory[i]->getWidget();
            }

            qnslayoutRespiratory->addWidget(qRespiratory[0],0,0);
            qnslayoutRespiratory->addWidget(qRespiratory[1],1,0);
            qnslayoutRespiratory->addWidget(qRespiratory[2],2,0);
            qnslayoutRespiratory->addWidget(qRespiratory[3],3,0);
            qnslayoutRespiratory->addWidget(qRespiratory[4],4,0);
            qnslayoutRespiratory->addWidget(qRespiratory[5],5,0);
            qnslayoutRespiratory->addWidget(qRespiratory[6],0,1);
            qnslayoutRespiratory->addWidget(qRespiratory[7],1,1);
            qnslayoutRespiratory->addWidget(qRespiratory[8],2,1);
            qnslayoutRespiratory->addWidget(qRespiratory[9],3,1);
            qnslayoutRespiratory->addWidget(qRespiratory[10],4,1);
            qnslayoutRespiratory->addWidget(qRespiratory[11],5,1);
            qnslayoutRespiratory->addWidget(qRespiratory[12],0,2);
            qnslayoutRespiratory->addWidget(qRespiratory[13],1,2);
            qnslayoutRespiratory->addWidget(qRespiratory[14],2,2);
            qnslayoutRespiratory->addWidget(qRespiratory[15],3,2);
            qnslayoutRespiratory->addWidget(qRespiratory[16],4,2);
            qnslayoutRespiratory->addWidget(qRespiratory[17],5,2);


            qnsWidgetRespiratory->setLayout(qnslayoutRespiratory);
                qnsScrollRespiratory->setWidget(qnsWidgetRespiratory);

                RespiratoryLayout->addWidget(HeaderLabelRespiratory,0,1,1,1);
                RespiratoryLayout->addWidget(qnsScrollRespiratory,1,1,1,1);
                RespiratoryLayout->addWidget(check,2,1);
                RespiratoryLayout->addLayout(ProbabilityLayoutRespiratory,3,1,1,1);
                RespiratoryLayout->addWidget(pushButtonRespiratoryBack,4,1,1,1);
                RespiratoryWidget->setLayout(RespiratoryLayout);
}
void MainWindow::CreateDigestiveWidget(){
    DigestiveWidget = new QWidget;
        QGridLayout *DigestiveLayout = new QGridLayout;

        QLabel *HeaderLabelDigestive = new QLabel;
        HeaderLabelDigestive->setText("<h3>Questions</h3>");

        QPushButton *pushButtonDigestiveBack = new QPushButton("Back");pushButtonDigestiveBack->setFixedSize(150,30);
        connect (pushButtonDigestiveBack,SIGNAL(clicked()),this,SLOT(ShowMedical()));

        QGridLayout *qnslayoutDigestive = new QGridLayout;
        QWidget *qnsWidgetDigestive = new QWidget;
        QScrollArea *qnsScrollDigestive = new QScrollArea;
        qnsScrollDigestive->setFixedHeight(380);

        QPushButton *check = new QPushButton("CHECK for Digestive");check->setFixedSize(180,30);
        connect(check,SIGNAL(clicked()),this,SLOT(CheckDiseaseProbability()));

        QGridLayout *ProbabilityLayoutDigestive = new QGridLayout;
        QGridLayout *AppendicitisLayout = new QGridLayout;
        QGridLayout *CholeraLayout = new QGridLayout;
        QGridLayout *JaundiceLayout = new QGridLayout;
        QGridLayout *HepatitisBLayout = new QGridLayout;

        Appendicitis = new QLabel(" ");
        Cholera = new QLabel(" ");
        Jaundice = new QLabel(" ");
        HepatitisB = new QLabel(" ");

            AppendicitisLayout = getProbabilityLayout(Appendicitis,"Appendicitis");
            CholeraLayout = getProbabilityLayout(Cholera,"Cholera");
            JaundiceLayout = getProbabilityLayout(Jaundice,"Jaundice");
            HepatitisBLayout = getProbabilityLayout(HepatitisB,"Hepatitis B");

            ProbabilityLayoutDigestive->addLayout(AppendicitisLayout,0,0);
            ProbabilityLayoutDigestive->addLayout(CholeraLayout,1,0);
            ProbabilityLayoutDigestive->addLayout(JaundiceLayout,2,0);
            ProbabilityLayoutDigestive->addLayout(HepatitisBLayout,3,0);

            QWidget *qDigestive[16];
            QString quesDigestive[16];
            quesDigestive[0]="1.Is there any abdominal pain?";
            quesDigestive[1]="2.Do you difficulty in passing urine?";
            quesDigestive[2]="3.Any change of fever?";
            quesDigestive[3]="4.Any sign of diarrhoea or constipation?";
            quesDigestive[4]="5.Has there been loss of appetite?";
            quesDigestive[5]="6.Is there sigm of nausea or vomiting?";
            quesDigestive[6]="7.Sudden pain in lower right abdomen?";
            quesDigestive[7]="8.Do you feel dehydrated?";
            quesDigestive[8]="9.Is there frequent diarrhoea with rice-water\n stool?";
            quesDigestive[9]="10.Are your skin and eyes yellowish?";
            quesDigestive[10]="11.Is the stool pale?";
            quesDigestive[11]="12.Is the urine dark?";
            quesDigestive[12]="13.Do you feel itchy sensation in the body?";
            quesDigestive[13]="14.Is there chronic fatigue and tiredness?";
            quesDigestive[14]="15.Is there muscle an joint pain?";
            quesDigestive[15]="16.Faster heart rate or lower B.P.?";

            for(int i = 0; i < 16; i++ ) {
                QuestionDigestive[i] = new Question;
                QuestionDigestive[i]->setQuestion(quesDigestive[i]);
                qDigestive[i] = new QWidget;
                qDigestive[i] = QuestionDigestive[i]->getWidget();
            }

            qnslayoutDigestive->addWidget(qDigestive[0],0,0);
            qnslayoutDigestive->addWidget(qDigestive[1],0,1);
            qnslayoutDigestive->addWidget(qDigestive[2],0,2);
            qnslayoutDigestive->addWidget(qDigestive[3],1,0);
            qnslayoutDigestive->addWidget(qDigestive[4],1,1);
            qnslayoutDigestive->addWidget(qDigestive[5],1,2);
            qnslayoutDigestive->addWidget(qDigestive[6],2,0);
            qnslayoutDigestive->addWidget(qDigestive[7],2,1);
            qnslayoutDigestive->addWidget(qDigestive[8],2,2);
            qnslayoutDigestive->addWidget(qDigestive[9],3,0);
            qnslayoutDigestive->addWidget(qDigestive[10],3,1);
            qnslayoutDigestive->addWidget(qDigestive[11],3,2);
            qnslayoutDigestive->addWidget(qDigestive[12],4,0);
            qnslayoutDigestive->addWidget(qDigestive[13],4,1);
            qnslayoutDigestive->addWidget(qDigestive[14],4,2);
            qnslayoutDigestive->addWidget(qDigestive[15],5,0);


            qnsWidgetDigestive->setLayout(qnslayoutDigestive);
                qnsScrollDigestive->setWidget(qnsWidgetDigestive);

                DigestiveLayout->addWidget(HeaderLabelDigestive,0,1,1,1);
                DigestiveLayout->addWidget(qnsScrollDigestive,1,1,1,1);
                DigestiveLayout->addWidget(check,2,1);
                DigestiveLayout->addLayout(ProbabilityLayoutDigestive,3,1,1,1);
                DigestiveLayout->addWidget(pushButtonDigestiveBack,4,1,1,1);
                DigestiveWidget->setLayout(DigestiveLayout);
}
void MainWindow::CreateKidneyWidget(){
    KidneyWidget = new QWidget;
        QGridLayout *KidneyLayout = new QGridLayout;

        QLabel *HeaderLabelKidney = new QLabel;
        HeaderLabelKidney->setText("<h3>Questions</h3>");

        QPushButton *pushButtonKidneyBack = new QPushButton("Back");pushButtonKidneyBack->setFixedSize(150,30);
        connect (pushButtonKidneyBack,SIGNAL(clicked()),this,SLOT(ShowMedical()));

        QGridLayout *qnslayoutKidney = new QGridLayout;
        QWidget *qnsWidgetKidney = new QWidget;
        QScrollArea *qnsScrollKidney = new QScrollArea;
        qnsScrollKidney->setFixedHeight(380);

        QPushButton *check = new QPushButton("CHECK for Kidney");check->setFixedSize(150,30);
        connect(check,SIGNAL(clicked()),this,SLOT(CheckDiseaseProbability()));

        QGridLayout *ProbabilityLayoutKidney = new QGridLayout;
        QGridLayout *UremiaLayout = new QGridLayout;
        QGridLayout *KidneyStoneLayout = new QGridLayout;
        QGridLayout *KidneyCancerLayout = new QGridLayout;
        QGridLayout *KidneyInjuryLayout = new QGridLayout;

        Uremia = new QLabel(" ");
        KidneyStone = new QLabel(" ");
        KidneyCancer = new QLabel(" ");
        KidneyInjury = new QLabel(" ");

            UremiaLayout = getProbabilityLayout(Uremia,"Uremia");
            KidneyStoneLayout = getProbabilityLayout(KidneyStone,"Kidney Stone");
            KidneyCancerLayout = getProbabilityLayout(KidneyCancer,"Kidney Cancer");
            KidneyInjuryLayout = getProbabilityLayout(KidneyInjury,"Kidney Injury");

            ProbabilityLayoutKidney->addLayout(UremiaLayout,0,0);
            ProbabilityLayoutKidney->addLayout(KidneyStoneLayout,1,0);
            ProbabilityLayoutKidney->addLayout(KidneyCancerLayout,2,0);
            ProbabilityLayoutKidney->addLayout(KidneyInjuryLayout,3,0);

            QWidget *qKidney[18];
            QString quesKidney[18];
            quesKidney[0]="1.Is there extreme fatigue and tiredness?";
            quesKidney[1]="2.Do you feel cramp in legs?";
            quesKidney[2]="3.Any loss of appetite?";
            quesKidney[3]="4.Any sign of headache?";
            quesKidney[4]="5.Any sign of nausea or vomiting?";
            quesKidney[5]="6.Severe pain in the back?";
            quesKidney[6]="7.Is there pain while urination?";
            quesKidney[7]="8.Red or brown urine?";
            quesKidney[8]="9.Do you urinate in small amount?";
            quesKidney[9]="10.Is there persistence to urinate?";
            quesKidney[10]="11.Foul smelling urine?";
            quesKidney[11]="12.Any blood seen in urine?";
            quesKidney[12]="13.Was there sudden loss of weight?";
            quesKidney[13]="14.Any lump on lower back?";
            quesKidney[14]="15.Is there shortness of breathe?";
            quesKidney[15]="16.Any swelling in legs?";
            quesKidney[16]="17.Do you have irregular heartbeat?";
            quesKidney[17]="18.Any chest pain?";

            for(int i = 0; i < 18; i++ ) {
                QuestionKidney[i] = new Question;
                QuestionKidney[i]->setQuestion(quesKidney[i]);
                qKidney[i] = new QWidget;
                qKidney[i] = QuestionKidney[i]->getWidget();
            }

            qnslayoutKidney->addWidget(qKidney[0],0,0);
            qnslayoutKidney->addWidget(qKidney[1],1,0);
            qnslayoutKidney->addWidget(qKidney[2],2,0);
            qnslayoutKidney->addWidget(qKidney[3],3,0);
            qnslayoutKidney->addWidget(qKidney[4],4,0);
            qnslayoutKidney->addWidget(qKidney[5],5,0);
            qnslayoutKidney->addWidget(qKidney[6],0,1);
            qnslayoutKidney->addWidget(qKidney[7],1,1);
            qnslayoutKidney->addWidget(qKidney[8],2,1);
            qnslayoutKidney->addWidget(qKidney[9],3,1);
            qnslayoutKidney->addWidget(qKidney[10],4,1);
            qnslayoutKidney->addWidget(qKidney[11],5,1);
            qnslayoutKidney->addWidget(qKidney[12],0,2);
            qnslayoutKidney->addWidget(qKidney[13],1,2);
            qnslayoutKidney->addWidget(qKidney[14],2,2);
            qnslayoutKidney->addWidget(qKidney[15],3,2);
            qnslayoutKidney->addWidget(qKidney[16],4,2);
            qnslayoutKidney->addWidget(qKidney[17],5,2);


            qnsWidgetKidney->setLayout(qnslayoutKidney);
                qnsScrollKidney->setWidget(qnsWidgetKidney);

                KidneyLayout->addWidget(HeaderLabelKidney,0,1,1,1);
                KidneyLayout->addWidget(qnsScrollKidney,1,1,1,1);
                KidneyLayout->addWidget(check,2,1);
                KidneyLayout->addLayout(ProbabilityLayoutKidney,3,1,1,1);
                KidneyLayout->addWidget(pushButtonKidneyBack,4,1,1,1);
                KidneyWidget->setLayout(KidneyLayout);
}

void MainWindow::CheckDiseaseProbability(){
    SwitchHealthTip();
    QPushButton *Pbutton = (QPushButton*)sender();

    if(Pbutton->text()=="CHECK for Brain"){

        int P=0; int M=0; int E=0; int A=0;
        double ResultP=0; double ResultM=0; double ResultE=0; double ResultA=0;

        if(QuestionBrain[0]->checked()){P+=2;}
        if(QuestionBrain[1]->checked()){P+=3;M+=1;E+=1;}
        if(QuestionBrain[2]->checked()){P+=1;A+=1;}
        if(QuestionBrain[3]->checked()){P+=1;}
        if(QuestionBrain[4]->checked()){E+=2;}
        if(QuestionBrain[5]->checked()){P+=3;}
        if(QuestionBrain[6]->checked()){M+=2;}
        if(QuestionBrain[7]->checked()){M+=1;E+=1;}
        if(QuestionBrain[8]->checked()){M+=1;E+=1;}
        if(QuestionBrain[9]->checked()){M+=1;E+=1;A+=2;}
        if(QuestionBrain[10]->checked()){M+=1;E+=1;}
        if(QuestionBrain[11]->checked()){A+=2;}
        if(QuestionBrain[12]->checked()){E+=2;}
        if(QuestionBrain[13]->checked()){A+=3;}
        if(QuestionBrain[14]->checked()){A+=3;}
        if(QuestionBrain[15]->checked()){A+=1;}
        if(QuestionBrain[16]->checked()){A+=1;}
        if(QuestionBrain[17]->checked()){A+=2;}

        ResultP=P*10;
        ResultM=M*100/7;
        ResultA=A*100/15;
        ResultE=E*100/9;

        Parkinsons->setText(QString::number(ResultP)+" %");
        Meningitis->setText(QString::number(ResultM)+" %");
        Encephalitis->setText(QString::number(ResultE)+" %");
        Alzeimer->setText(QString::number(ResultA)+" %");
    }
    if(Pbutton->text()=="CHECK for Head"){
        int C=0; int T=0; int M=0; int S=0;
                    double ResultC=0; double ResultT=0; double ResultM=0; double ResultS=0;

                    if(QuestionHead[0]->checked()){C+=3;}
                    if(QuestionHead[1]->checked()){C+=2;}
                    if(QuestionHead[2]->checked()){C+=1;}
                    if(QuestionHead[3]->checked()){C+=2;}
                    if(QuestionHead[4]->checked()){C+=1;}
                    if(QuestionHead[5]->checked()){T+=2;}
                    if(QuestionHead[6]->checked()){T+=2;}
                    if(QuestionHead[7]->checked()){T+=1;;}
                    if(QuestionHead[8]->checked()){T+=1;}
                    if(QuestionHead[9]->checked()){T+=1;}
                    if(QuestionHead[10]->checked()){M+=1;}
                    if(QuestionHead[11]->checked()){M+=2;}
                    if(QuestionHead[12]->checked()){M+=2;}
                    if(QuestionHead[13]->checked()){M+=2;}
                    if(QuestionHead[14]->checked()){S+=2;}
                    if(QuestionHead[15]->checked()){S+=2;}
                    if(QuestionHead[16]->checked()){S+=1;}
                    if(QuestionHead[17]->checked()){S+=2;}

                    ResultC=C*100/9;
                    ResultT=T*100/7;
                    ResultM=M*100/7;
                    ResultS=S*100/7;

                    Cluster->setText(QString::number(ResultC)+" %");
                    Tension->setText(QString::number(ResultT)+" %");
                    Migraine->setText(QString::number(ResultM)+" %");
                    Sinus->setText(QString::number(ResultS)+" %");
    }

    if(Pbutton->text()=="CHECK for Eyes"){
        int C=0; int Co=0; int D=0; int G=0;
                double ResultC=0; double ResultCo=0; double ResultD=0; double ResultG=0;

                if(QuestionEyes[0]->checked()){C+=2;Co+=1;D+=1;}
                if(QuestionEyes[1]->checked()){C+=2;}
                if(QuestionEyes[2]->checked()){C+=1;}
                if(QuestionEyes[3]->checked()){C+=1;}
                if(QuestionEyes[4]->checked()){C+=1;Co+=1;D+=1;G+=1;}
                if(QuestionEyes[5]->checked()){C+=1;}
                if(QuestionEyes[6]->checked()){C+=1;G+=1;}
                if(QuestionEyes[7]->checked()){Co+=2;D+=2;G+=2;}
                if(QuestionEyes[8]->checked()){Co+=2;D+=3;}
                if(QuestionEyes[9]->checked()){Co+=1;D+=3;G+=1;}
                if(QuestionEyes[10]->checked()){Co+=1;}
                if(QuestionEyes[11]->checked()){Co+=1;}
                if(QuestionEyes[12]->checked()){Co+=1;}
                if(QuestionEyes[13]->checked()){D+=1;}
                if(QuestionEyes[14]->checked()){D+=3;}
                if(QuestionEyes[15]->checked()){G+=3;}
                if(QuestionEyes[16]->checked()){G+=2;}
                if(QuestionEyes[17]->checked()){G+=1;}

                ResultC=C*100/9;
                ResultCo=Co*10;
                ResultD=D*100/14;
                ResultG=G*100/11;

                Cataract->setText(QString::number(ResultC)+" %");
                Conjunctivitis->setText(QString::number(ResultCo)+" %");
                DryEyeSyndrome->setText(QString::number(ResultD)+" %");
                Glaucoma->setText(QString::number(ResultG)+" %");
    }

    if(Pbutton->text()=="CHECK for Teeth and Gums"){
        int G=0; int TD=0; int P=0; int TS=0;
         double ResultG=0; double ResultTD=0; double ResultP=0; double ResultTS=0;

         if(QuestionTeethAndGums[0]->checked()){G+=2;P+=1;}
         if(QuestionTeethAndGums[1]->checked()){G+=2;}
         if(QuestionTeethAndGums[2]->checked()){G+=2;P+=1;}
         if(QuestionTeethAndGums[3]->checked()){G+=1;P+=1;}
         if(QuestionTeethAndGums[4]->checked()){G+=2;P+=1;TS+=2;}
         if(QuestionTeethAndGums[5]->checked()){G+=1;}
         if(QuestionTeethAndGums[6]->checked()){G+=1;}
         if(QuestionTeethAndGums[7]->checked()){TD+=2;}
         if(QuestionTeethAndGums[8]->checked()){TD+=2;}
         if(QuestionTeethAndGums[9]->checked()){TD+=1;P+=1;TS+=2;}
         if(QuestionTeethAndGums[10]->checked()){TD+=1;}
         if(QuestionTeethAndGums[11]->checked()){TD+=2;TS+=2;}
         if(QuestionTeethAndGums[12]->checked()){TD+=2;}
         if(QuestionTeethAndGums[13]->checked()){P+=2;}
         if(QuestionTeethAndGums[14]->checked()){P+=2;}
         if(QuestionTeethAndGums[15]->checked()){TS+=2;}
         if(QuestionTeethAndGums[16]->checked()){TS+=1;}
         if(QuestionTeethAndGums[17]->checked()){TS+=2;}

         ResultG=G*100/11;
         ResultTD=TD*10;
         ResultP=P*100/9;
         ResultTS=TS*100/11;

         Gingivitis->setText(QString::number(ResultG)+" %");
         Decay->setText(QString::number(ResultTD)+" %");
         Periodontal->setText(QString::number(ResultP)+" %");
         Sensitivity->setText(QString::number(ResultTS)+" %");
    }

    if(Pbutton->text()=="CHECK for Heart"){
        int C=0; int MI=0; int Cor=0; int Cog=0;
                        double ResultC=0; double ResultMI=0; double ResultCor=0; double ResultCog=0;

                        if(QuestionHeart[0]->checked()){C+=2;MI+=2;Cor+=3;Cog+=1;}
                        if(QuestionHeart[1]->checked()){C+=2;Cog+=1;}
                        if(QuestionHeart[2]->checked()){C+=1;}
                        if(QuestionHeart[3]->checked()){C+=1;}
                        if(QuestionHeart[4]->checked()){C+=2;MI+=1;Cor+=1;}
                        if(QuestionHeart[5]->checked()){C+=2;MI+=2;Cor+=1;}
                        if(QuestionHeart[6]->checked()){C+=2;Cor+=2;}
                        if(QuestionHeart[7]->checked()){MI+=1;Cor+=1;}
                        if(QuestionHeart[8]->checked()){MI+=2;Cor+=1;}
                        if(QuestionHeart[9]->checked()){MI+=2;Cor+=1;}
                        if(QuestionHeart[10]->checked()){Cor+=2;}
                        if(QuestionHeart[11]->checked()){Cog+=2;}
                        if(QuestionHeart[12]->checked()){Cog+=3;}
                        if(QuestionHeart[13]->checked()){Cog+=3;}
                        if(QuestionHeart[14]->checked()){C+=1;MI+=1;Cor+=1;Cog+=1;}
                        if(QuestionHeart[15]->checked()){C+=1;MI+=1;Cor+=1;Cog+=1;}
                        if(QuestionHeart[16]->checked()){C+=1;MI+=1;Cor+=1;Cog+=1;}
                        if(QuestionHeart[17]->checked()){C+=1;MI+=1;Cor+=1;Cog+=1;}

                        ResultC=C*100/16;
                        ResultMI=MI*100/14;
                        ResultCor=Cor*100/16;
                        ResultCog=Cog*100/14;

                        Cardiomypathy->setText(QString::number(ResultC)+" %");
                        MyI->setText(QString::number(ResultMI)+" %");
                        Coronary->setText(QString::number(ResultCor)+" %");
                        Congenital->setText(QString::number(ResultCog)+" %");

    }

    if(Pbutton->text()=="CHECK for Respiratory"){
        int T=0; int P=0; int C=0; int A=0;
            double ResultT=0; double ResultP=0; double ResultC=0; double ResultA=0;

            if(QuestionRespiratory[0]->checked()){T+=1;P+=1;}
            if(QuestionRespiratory[1]->checked()){T+=3;}
            if(QuestionRespiratory[2]->checked()){T+=3;}
            if(QuestionRespiratory[3]->checked()){T+=1;P+=1;C+=1;}
            if(QuestionRespiratory[4]->checked()){T+=1;}
            if(QuestionRespiratory[5]->checked()){T+=1;P+=1;}
            if(QuestionRespiratory[6]->checked()){T+=1;P+=1;C+=1;A+=1;}
            if(QuestionRespiratory[7]->checked()){P+=2;}
            if(QuestionRespiratory[8]->checked()){P+=2;}
            if(QuestionRespiratory[9]->checked()){P+=2;C+=2;A+=3;}
            if(QuestionRespiratory[10]->checked()){P+=2;}
            if(QuestionRespiratory[11]->checked()){C+=2;}
            if(QuestionRespiratory[12]->checked()){C+=1;A+=2;}
            if(QuestionRespiratory[13]->checked()){C+=1;}
            if(QuestionRespiratory[14]->checked()){C+=1;}
            if(QuestionRespiratory[15]->checked()){A+=1;}
            if(QuestionRespiratory[16]->checked()){A+=1;}
            if(QuestionRespiratory[17]->checked()){A+=2;}

            ResultT=T*100/11;
            ResultP=P*100/12;
            ResultC=C*100/9;
            ResultA=A*10;

            Tuberculosis->setText(QString::number(ResultT)+" %");
            Pneumonia->setText(QString::number(ResultP)+" %");
            COPD->setText(QString::number(ResultC)+" %");
            Asthma->setText(QString::number(ResultA)+" %");
    }

    if(Pbutton->text()=="CHECK for Digestive"){
        int A=0; int C=0; int J=0; int H=0;
            double ResultA=0; double ResultC=0; double ResultJ=0; double ResultH=0;

            if(QuestionDigestive[0]->checked()){A+=1;J+=1;H+=1;}
            if(QuestionDigestive[1]->checked()){A+=1;}
            if(QuestionDigestive[2]->checked()){A+=1;J+=1;H+=1;}
            if(QuestionDigestive[3]->checked()){A+=1;C+=1;}
            if(QuestionDigestive[4]->checked()){A+=1;C+=1;H+=1;}
            if(QuestionDigestive[5]->checked()){A+=1;C+=2;J+=1;H+=1;}
            if(QuestionDigestive[6]->checked()){A+=3;}
            if(QuestionDigestive[7]->checked()){C+=2;}
            if(QuestionDigestive[8]->checked()){C+=4;}
            if(QuestionDigestive[9]->checked()){J+=3;H+=1;}
            if(QuestionDigestive[10]->checked()){J+=2;H+=2;}
            if(QuestionDigestive[11]->checked()){J+=2;H+=2;}
            if(QuestionDigestive[12]->checked()){J+=1;}
            if(QuestionDigestive[13]->checked()){H+=1;}
            if(QuestionDigestive[14]->checked()){H+=1;}
            if(QuestionDigestive[15]->checked()){C+=1;}

            ResultA=A*100/9;
            ResultC=C*100/11;
            ResultJ=J*100/11;
            ResultH=H*100/11;

            Appendicitis->setText(QString::number(ResultA)+" %");
            Cholera->setText(QString::number(ResultC)+" %");
            Jaundice->setText(QString::number(ResultJ)+" %");
            HepatitisB->setText(QString::number(ResultH)+" %");
    }

    if(Pbutton->text()=="CHECK for Kidney"){
        int U=0; int S=0; int C=0; int I=0;
        double ResultU=0; double ResultS=0; double ResultC=0; double ResultI=0;

        if(QuestionKidney[0]->checked()){U+=3;C+=1;I+=2;}
        if(QuestionKidney[1]->checked()){U+=1;}
        if(QuestionKidney[2]->checked()){U+=1;C+=1;}
        if(QuestionKidney[3]->checked()){U+=1;}
        if(QuestionKidney[4]->checked()){U+=1;S+=1;I+=1;}
        if(QuestionKidney[5]->checked()){S+=2;C+=2;}
        if(QuestionKidney[6]->checked()){S+=3;}
        if(QuestionKidney[7]->checked()){S+=2;}
        if(QuestionKidney[8]->checked()){S+=2;I+=3;}
        if(QuestionKidney[9]->checked()){S+=1;}
        if(QuestionKidney[10]->checked()){S+=1;}
        if(QuestionKidney[11]->checked()){C+=2;}
        if(QuestionKidney[12]->checked()){C+=2;}
        if(QuestionKidney[13]->checked()){C+=2;}
        if(QuestionKidney[14]->checked()){I+=2;}
        if(QuestionKidney[15]->checked()){I+=2;}
        if(QuestionKidney[16]->checked()){I+=1;}
        if(QuestionKidney[17]->checked()){I+=1;}

        ResultU=U*100/7;
        ResultS=S*100/12;
        ResultC=C*10;
        ResultI=I*100/12;

        Uremia->setText(QString::number(ResultU)+" %");
        KidneyStone->setText(QString::number(ResultS)+" %");
        KidneyCancer->setText(QString::number(ResultC)+" %");
        KidneyInjury->setText(QString::number(ResultI)+" %");
    }
}

QGridLayout *MainWindow::getProbabilityLayout(QLabel *label, QString s) {
    QGridLayout *tempLayout = new QGridLayout;

    QLabel *tempLabel = new QLabel;
    tempLabel->setText("Probability of " + s + "  :   ");

    TipsBtn = new Button;
    TipsBtn->setFixedWidth(300);
    TipsBtn->setText("Health Tips for " + s);

    tempLayout->addWidget(tempLabel,0,0);
    tempLayout->setAlignment(label,Qt::AlignLeft);

    tempLayout->addWidget(label,0,1);
    tempLayout->setAlignment(label,Qt::AlignLeft);

    tempLayout->addWidget(TipsBtn,0,2);
    tempLayout->setAlignment(TipsBtn,Qt::AlignRight);

    connect(TipsBtn,SIGNAL(clicked()),this,SLOT(GetDiseaseTips()));
    return tempLayout;


}
void MainWindow::GetDiseaseTips(){
    SwitchHealthTip();
    QPushButton *Pbutton = (QPushButton*)sender();

    if(Pbutton->text()=="Health Tips for Parkinsons"){
        QMessageBox::information(this,"Health Tips for Parkinsons",ParkinsonsTips);
    }
    if(Pbutton->text()=="Health Tips for Meningitis"){
        QMessageBox::information(this,"Health Tips for Meningitis",MeningitisTips);
    }
    if(Pbutton->text()=="Health Tips for Encephalitis"){
        QMessageBox::information(this,"Health Tips for Encephalitis",EncephalitisTips);
    }
    if(Pbutton->text()=="Health Tips for Alzheimer"){
        QMessageBox::information(this,"Health Tips for Alzheimer",AlzeimerTips);
    }
    if(Pbutton->text()=="Health Tips for Cluster Headache"){
        QMessageBox::information(this,"Health Tips for Cluster Headache",ClusterHeadacheTips);
    }
    if(Pbutton->text()=="Health Tips for Tension Headache"){
        QMessageBox::information(this,"Health Tips for Tension Headache",TensionHeadacheTips);
    }
    if(Pbutton->text()=="Health Tips for Sinus Headache"){
        QMessageBox::information(this,"Health Tips for Sinus Headache",SinusHeadacheTips);
    }
    if(Pbutton->text()=="Health Tips for Migraine"){
        QMessageBox::information(this,"Health Tips for Migraine",MigraineTips);
    }
    if(Pbutton->text()=="Health Tips for Cataract"){
        QMessageBox::information(this,"Health Tips for Cataract",CataractTips);
    }
    if(Pbutton->text()=="Health Tips for Conjunctivitis"){
        QMessageBox::information(this,"Health Tips for Conjunctivitis",ConjunctivitisTips);
    }
    if(Pbutton->text()=="Health Tips for Dry Eye Syndrome"){
        QMessageBox::information(this,"Health Tips for Dry Eye Syndrome",DryEyeSyndromeTips);
    }
    if(Pbutton->text()=="Health Tips for Glaucoma"){
        QMessageBox::information(this,"Health Tips for Glaucoma",GlaucomaTips);
    }
    if(Pbutton->text()=="Health Tips for Gingivitis"){
        QMessageBox::information(this,"Health Tips for Gingivitis",GingivitisTips);
    }
    if(Pbutton->text()=="Health Tips for Decay"){
        QMessageBox::information(this,"Health Tips for Decay",DecayTips);
    }
    if(Pbutton->text()=="Health Tips for Periodontal Disease"){
        QMessageBox::information(this,"Health Tips for Periodontal Disease",PeriodontalTips);
    }
    if(Pbutton->text()=="Health Tips for Sensitivity"){
        QMessageBox::information(this,"Health Tips for Sensitivity",SensitivityTips);
    }
    if(Pbutton->text()=="Health Tips for Cardiomypathy"){
        QMessageBox::information(this,"Health Tips for Cardiomypathy",CardiomypathyTips);
    }
    if(Pbutton->text()=="Health Tips for Myocardial Infarction"){
        QMessageBox::information(this,"Health Tips for Myocardial Infarction",MyocardialInfarctionTips);
    }
    if(Pbutton->text()=="Health Tips for Coronary Heart Disease"){
        QMessageBox::information(this,"Health Tips for Coronary Heart Disease",CoronaryHeartDiseaseTips);
    }
    if(Pbutton->text()=="Health Tips for Congenital Heart Disease"){
        QMessageBox::information(this,"Health Tips for Coronary Heart Disease",CongenitalHeartDiseaseTips);
    }
    if(Pbutton->text()=="Health Tips for Tuberculosis"){
        QMessageBox::information(this,"Health Tips for Tuberculosis",TuberculosisTips);
    }
    if(Pbutton->text()=="Health Tips for Pneumonia"){
        QMessageBox::information(this,"Health Tips for Pneumonia",PneumoniaTips);
    }
    if(Pbutton->text()=="Health Tips for COPD"){
        QMessageBox::information(this,"Health Tips for COPD",COPDTips);
    }
    if(Pbutton->text()=="Health Tips for Asthma"){
        QMessageBox::information(this,"Health Tips for Asthma",AsthmaTips);
    }
    if(Pbutton->text()=="Health Tips for Appendicitis"){
        QMessageBox::information(this,"Health Tips for Appendicitis",AppendicitisTips);
    }
    if(Pbutton->text()=="Health Tips for Cholera"){
        QMessageBox::information(this,"Health Tips for Cholera",CholeraTips);
    }
    if(Pbutton->text()=="Health Tips for Jaundice"){
        QMessageBox::information(this,"Health Tips for Jaundice",JaundiceTips);
    }
    if(Pbutton->text()=="Health Tips for Hepatitis B"){
        QMessageBox::information(this,"Health Tips for Hepatitis B",HepatitisBTips);
    }
    if(Pbutton->text()=="Health Tips for Uremia"){
        QMessageBox::information(this,"Health Tips for Uremia",UremiaTips);
    }
    if(Pbutton->text()=="Health Tips for Kidney Stone"){
        QMessageBox::information(this,"Health Tips for Kidney Stone",KidneyStoneTips);
    }
    if(Pbutton->text()=="Health Tips for Kidney Cancer"){
        QMessageBox::information(this,"Health Tips for Kidney Cancer",KidneyCancerTips);
    }
    if(Pbutton->text()=="Health Tips for Kidney Injury"){
        QMessageBox::information(this,"Health Tips for Kidney Injury",KidneyInjuryTips);
    }

}

void MainWindow::CreateContactsWidget(){

    ContactsMainWidget = new QWidget;
    ContactsMainLayout = new QGridLayout;

    QWidget *ContactsBarWidget = new QWidget;    ContactsBarWidget->setStyleSheet("background:#B0B0B0;");
    ContactsBarWidget->setFixedWidth(250);

    QGridLayout *ContactsBarLayout = new QGridLayout;
    QWidget *CDoctor = new QWidget;
    CDoctor->setStyleSheet("border-image: url(://Images/Images/DoctorContacts.jpg) 0 0 0 0 stretch stretch;");

    QLabel *IconLabel[3];
    QGridLayout *IconLayout[3];

    for(int i=0; i<3; i++){
        IconLabel[i] = new QLabel;
        IconLayout[i] = new QGridLayout;
    }
    IconLabel[0]->setStyleSheet("border-image: url(://Images/Icons/Hospital.jpg) 0 0 0 0 stretch stretch;");
     IconLabel[1]->setStyleSheet("border-image: url(://Images/Icons/AMBULANCE.jpg) 0 0 0 0 stretch stretch;");
      IconLabel[2]->setStyleSheet("border-image: url(://Images/Icons/Blood bank.jpg) 0 0 0 0 stretch stretch;");
    for(int i=0; i<3; i++){
        IconLayout[i]->addWidget(IconLabel[i]);
    }

    Button *HospitalButton = new Button("HOSPITALS");
    HospitalButton->setFixedSize(170,150);
    HospitalButton->setStyleSheet("background: #95a5a6 ;");

    Button *AmbulancesButton = new Button("AMBULANCES");
    AmbulancesButton->setFixedSize(170,150);
    AmbulancesButton->setStyleSheet("background: #95a5a6  ;");

    Button *BloodBanksButton = new Button("BLOOD BANKS");
    BloodBanksButton->setFixedSize(170,150);
    BloodBanksButton->setStyleSheet("background: #95a5a6  ;");

    HospitalButton->setLayout(IconLayout[0]);
    AmbulancesButton->setLayout(IconLayout[1]);
    BloodBanksButton->setLayout(IconLayout[2]);

    ContactsBarLayout->addWidget(HospitalButton,0,0);
    ContactsBarLayout->addWidget(AmbulancesButton,1,0);
    ContactsBarLayout->addWidget(BloodBanksButton,2,0);
    ContactsBarWidget->setLayout(ContactsBarLayout);
    ContactsBarWidget->setStyleSheet("background: #d7dbdd ;");

    ContactsMainLayout->addWidget(CDoctor,0,0);
    ContactsMainLayout->addWidget(ContactsBarWidget,0,1);

    ContactsMainWidget->setLayout(ContactsMainLayout);
    ContactsMainWidget->setStyleSheet("background:#4B0082;");
  //  ContactsMainWidget->setStyleSheet("border-image: url(://Images/Images/Telephone.jpg) 0 0 0 0 stretch stretch;");


    connect(HospitalButton,SIGNAL(clicked()),this,SLOT(ShowHospital()));
    connect(AmbulancesButton,SIGNAL(clicked()),this,SLOT(ShowAmbulances()));
    connect(BloodBanksButton,SIGNAL(clicked()),this,SLOT(ShowBloodBanks()));
}
void MainWindow::CreateHospitalsWidget(){
    HospitalWidget = new QWidget;
    HospitalLayout = new QGridLayout;

    QLabel *HospitalHeaderLayout = new QLabel;
    HospitalHeaderLayout->setText("<h1>HOSPITALS</h1>");
    QLabel *EmptyLabel = new QLabel;
    EmptyLabel->setText("  ");
    EmptyLabel->setFixedHeight(50);

    labelHospitalContacts = new QLabel;
    labelHospitalContacts->setAlignment(Qt::AlignTop);
 //   labelHospitalContacts->setStyleSheet("border-image: url(://Images/Images/Contacts.jpg) 0 0 0 0 stretch stretch;");
    labelHospitalContacts->setMinimumSize(800,600);

    QWidget *sideBarWidget = new QWidget;
    QGridLayout *sideBarLayout = new QGridLayout;
    sideBarLayout->addWidget(HospitalHeaderLayout,0,0);
    sideBarLayout->setAlignment(HospitalHeaderLayout,Qt::AlignTop);

    Button *btnEye = new Button("EYE CARE HOSPITALS");btnEye->setFixedSize(200,40);
    Button *btnHeart = new Button("HEART CARE HOSPITALS");btnHeart->setFixedSize(200,40);
    Button *btnBone = new Button("BONE CARE HOSPITALS");btnBone->setFixedSize(200,40);
    Button *btnDental = new Button("DENTAL HOSPITALS");btnDental->setFixedSize(200,40);
    Button *btnSkin = new Button("SKIN CARE HOSPITALS");btnSkin->setFixedSize(200,40);
    Button *btnKidney = new Button("KIDNEY HOSPITALS");btnKidney->setFixedSize(200,40);
    Button *btnCancer = new Button("CANCER HOSPITALS");btnCancer->setFixedSize(200,40);
    Button *btnGeneral = new Button("GENERAL HOSPITALS");btnGeneral->setFixedSize(200,40);
    Button *pushButtonHospitalsBack = new Button("Back");pushButtonHospitalsBack->setFixedSize(150,30);


    sideBarLayout->addWidget(btnEye,1,0,1,1);  sideBarLayout->setAlignment(btnEye,Qt::AlignTop);
    sideBarLayout->addWidget(btnDental,2,0,1,1);  sideBarLayout->setAlignment(btnDental,Qt::AlignTop);
    sideBarLayout->addWidget(btnBone,3,0,1,1);  sideBarLayout->setAlignment(btnBone,Qt::AlignTop);
    sideBarLayout->addWidget(btnHeart,4,0,1,1);  sideBarLayout->setAlignment(btnHeart,Qt::AlignTop);
    sideBarLayout->addWidget(btnCancer,5,0,1,1);  sideBarLayout->setAlignment(btnCancer,Qt::AlignTop);
    sideBarLayout->addWidget(btnGeneral,6,0,1,1);  sideBarLayout->setAlignment(btnGeneral,Qt::AlignTop);
    sideBarLayout->addWidget(btnSkin,7,0,1,1);  sideBarLayout->setAlignment(btnSkin,Qt::AlignTop);
    sideBarLayout->addWidget(btnKidney,8,0,1,1);  sideBarLayout->setAlignment(btnKidney,Qt::AlignTop);
    sideBarLayout->addWidget(pushButtonHospitalsBack,10,0,1,1);
    sideBarLayout->setAlignment(pushButtonHospitalsBack,Qt::AlignBottom);
    sideBarWidget->setLayout(sideBarLayout);

    QWidget *ContactsDisplayWidget = new QWidget;
    QGridLayout *ContactsDisplayLayout = new QGridLayout;

    ContactsDisplayLayout->addWidget(labelHospitalContacts);
    ContactsDisplayWidget->setLayout(ContactsDisplayLayout);

    QScrollArea *displayScrollArea = new QScrollArea;
    displayScrollArea->setStyleSheet("background:#D3D3D3;");
    displayScrollArea->setWidget(ContactsDisplayWidget);

    HospitalLayout->addWidget(sideBarWidget,0,0,13,1);
    HospitalLayout->addWidget(EmptyLabel,0,1,1,1);
    HospitalLayout->addWidget(displayScrollArea,1,1,12,1);
    HospitalWidget->setLayout(HospitalLayout);
    HospitalWidget->setStyleSheet("background:#aed6f1;");

    connect (pushButtonHospitalsBack,SIGNAL(clicked()),this,SLOT(ShowContacts()));
    connect (btnEye,SIGNAL(clicked()),this,SLOT(ChangeHospitalContacts()));
    connect (btnBone,SIGNAL(clicked()),this,SLOT(ChangeHospitalContacts()));
    connect (btnHeart,SIGNAL(clicked()),this,SLOT(ChangeHospitalContacts()));
    connect (btnDental,SIGNAL(clicked()),this,SLOT(ChangeHospitalContacts()));
    connect (btnCancer,SIGNAL(clicked()),this,SLOT(ChangeHospitalContacts()));
    connect (btnSkin,SIGNAL(clicked()),this,SLOT(ChangeHospitalContacts()));
    connect (btnGeneral,SIGNAL(clicked()),this,SLOT(ChangeHospitalContacts()));
    connect (btnKidney,SIGNAL(clicked()),this,SLOT(ChangeHospitalContacts()));

}
void MainWindow::ChangeHospitalContacts(){
    SwitchHealthTip();
    QPushButton *Hbutton = (QPushButton*)sender();
    if(Hbutton->text()=="EYE CARE HOSPITALS"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\HospitalEyes.txt" );
        labelHospitalContacts->setText(lbl);
    }
    if(Hbutton->text()=="DENTAL HOSPITALS"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\HospitalDental.txt" );
        labelHospitalContacts->setText(lbl);
    }
    if(Hbutton->text()=="BONE CARE HOSPITALS"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\HospitalBone.txt" );
        labelHospitalContacts->setText(lbl);
    }
    if(Hbutton->text()=="HEART CARE HOSPITALS"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\HospitalHeart.txt" );
        labelHospitalContacts->setText(lbl);
    }
    if(Hbutton->text()=="CANCER HOSPITALS"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\HospitalCancer.txt" );
        labelHospitalContacts->setText(lbl);
    }
    if(Hbutton->text()=="GENERAL HOSPITALS"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\HospitalGeneral.txt" );
        labelHospitalContacts->setText(lbl);
    }
    if(Hbutton->text()=="SKIN CARE HOSPITALS"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\HospitalSkin.txt" );
        labelHospitalContacts->setText(lbl);
    }
    if(Hbutton->text()=="KIDNEY HOSPITALS"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\HospitalKidney.txt" );
        labelHospitalContacts->setText(lbl);
    }
}
void MainWindow::CreateAmbulancesWidget(){
    AmbulancesWidget = new QWidget;
    AmbulancesLayout = new QGridLayout;

    QLabel *AmbulanceHeaderLayout = new QLabel;
    AmbulanceHeaderLayout->setText("<h1>AMBULANCES</h1>");
    QLabel *EmptyLabel = new QLabel;
    EmptyLabel->setText("  ");
    EmptyLabel->setFixedHeight(50);

    labelAmbulancesContacts = new QLabel;
    labelAmbulancesContacts->setAlignment(Qt::AlignTop);
    labelAmbulancesContacts->setStyleSheet("background:#D3D3D3;");
    labelAmbulancesContacts->setMinimumSize(800,600);

    QWidget *sideBarWidget = new QWidget;
    QGridLayout *sideBarLayout = new QGridLayout;
    sideBarLayout->addWidget(AmbulanceHeaderLayout,0,0);
    sideBarLayout->setAlignment(AmbulanceHeaderLayout,Qt::AlignTop);

    Button *btnKathmandu = new Button("KATHMANDU");btnKathmandu->setFixedSize(200,40);
    Button *btnLalitpur = new Button("LALITPUR");btnLalitpur->setFixedSize(200,40);
    Button *btnBhaktapur = new Button("BHAKTAPUR");btnBhaktapur->setFixedSize(200,40);
    Button *btnKavre = new Button("KAVRE");btnKavre->setFixedSize(200,40);
    Button *pushButtonAmbulancesBack = new Button("Back");pushButtonAmbulancesBack->setFixedSize(150,30);


    sideBarLayout->addWidget(btnKathmandu,1,0,1,1);  sideBarLayout->setAlignment(btnKathmandu,Qt::AlignTop);
    sideBarLayout->addWidget(btnLalitpur,2,0,1,1);  sideBarLayout->setAlignment(btnLalitpur,Qt::AlignTop);
    sideBarLayout->addWidget(btnBhaktapur,3,0,1,1);  sideBarLayout->setAlignment(btnBhaktapur,Qt::AlignTop);
    sideBarLayout->addWidget(btnKavre,4,0,1,1);  sideBarLayout->setAlignment(btnKavre,Qt::AlignTop);
    sideBarLayout->addWidget(pushButtonAmbulancesBack,10,0,1,1);
    sideBarLayout->setAlignment(pushButtonAmbulancesBack,Qt::AlignBottom);
    sideBarWidget->setLayout(sideBarLayout);

    QWidget *ContactsDisplayWidget = new QWidget;
    QGridLayout *ContactsDisplayLayout = new QGridLayout;

    ContactsDisplayLayout->addWidget(labelAmbulancesContacts);
    ContactsDisplayWidget->setLayout(ContactsDisplayLayout);

    QScrollArea *displayScrollArea = new QScrollArea;
    displayScrollArea->setStyleSheet("background:#D3D3D3;");
    displayScrollArea->setWidget(ContactsDisplayWidget);

    AmbulancesLayout->addWidget(sideBarWidget,0,0,13,1);
    AmbulancesLayout->addWidget(EmptyLabel,0,1,1,1);
    AmbulancesLayout->addWidget(displayScrollArea,1,1,12,1);
    AmbulancesWidget->setLayout(AmbulancesLayout);
    AmbulancesWidget->setStyleSheet("background:#aed6f1;");

    connect (pushButtonAmbulancesBack,SIGNAL(clicked()),this,SLOT(ShowContacts()));
    connect (btnKathmandu,SIGNAL(clicked()),this,SLOT(ChangeAmbulancesContacts()));
    connect (btnLalitpur,SIGNAL(clicked()),this,SLOT(ChangeAmbulancesContacts()));
    connect (btnBhaktapur,SIGNAL(clicked()),this,SLOT(ChangeAmbulancesContacts()));
    connect (btnKavre,SIGNAL(clicked()),this,SLOT(ChangeAmbulancesContacts()));

}
void MainWindow::ChangeAmbulancesContacts(){
    SwitchHealthTip();
    QPushButton *Abutton = (QPushButton*)sender();
    if(Abutton->text()=="KATHMANDU"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\AmbulancesKathmandu.txt" );
        labelAmbulancesContacts->setText(lbl);
    }
    if(Abutton->text()=="LALITPUR"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\AmbulancesLalitpur.txt" );
        labelAmbulancesContacts->setText(lbl);
    }
    if(Abutton->text()=="BHAKTAPUR"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\AmbulancesBhaktapur.txt" );
        labelAmbulancesContacts->setText(lbl);
    }
    if(Abutton->text()=="KAVRE"){
        QString lbl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\AmbulancesKavre.txt" );
        labelAmbulancesContacts->setText(lbl);
    }

}
void MainWindow::CreateBloodBanksWidget(){
    BloodBanksWidget = new QWidget;
    BloodBanksLayout = new QGridLayout;
    QLabel *TitleBanks = new QLabel;

    TitleBanks->setText("<h1>BLOOD BANKS</h1>");
    QGridLayout *TheBloodBankLayout = new QGridLayout;
    QWidget *TheBloodBankWidget = new QWidget;
    QScrollArea *BloodBank = new QScrollArea;

    labelBloodBanksContacts = new QLabel;
    BloodBank->setStyleSheet("background:#D3D3D3;");
    QPushButton *pushButtonBloodBankBack = new QPushButton("Back");pushButtonBloodBankBack->setFixedSize(150,30);

    QString labl =FileHandler::fileReader( qApp->applicationDirPath(), "\\data\\BloodBanks.txt" );
    labelBloodBanksContacts->setText(labl );

    TheBloodBankLayout->addWidget(labelBloodBanksContacts);
    TheBloodBankWidget->setLayout(TheBloodBankLayout);
    BloodBank->setWidget(TheBloodBankWidget);
    BloodBanksLayout->addWidget(TitleBanks);
    BloodBanksLayout->addWidget(BloodBank);
    BloodBanksLayout->addWidget(pushButtonBloodBankBack);

    BloodBanksWidget->setLayout(BloodBanksLayout);
    BloodBanksWidget->setStyleSheet("background:#aed6f1;");
    connect (pushButtonBloodBankBack,SIGNAL(released()),this,SLOT(ShowContacts()));
}





void MainWindow::ShowHome() {
    SwitchHealthTip();
    delete theDisplayWidget;
    theDisplayWidget = new QWidget;
    theDisplayLayout = new QGridLayout;
    theDisplayWidget->setLayout(theDisplayLayout);

    theDisplayWidget->setStyleSheet("border-image: url(://Images/Images/Untitled.jpg) 0 0 0 0 stretch stretch;");

    displayLayout->addWidget(theDisplayWidget,0,0);
    displayLayout->addWidget(BottomBar,1,0);

    displayWidget->setLayout(displayLayout);
}

void MainWindow::ShowMedical() {
    SwitchHealthTip();
    delete theDisplayWidget;
    theDisplayWidget = new QWidget;
    theDisplayLayout = new QGridLayout;

    CreateMedicalWidget();
    theDisplayLayout->addWidget(MedicalWidget);
    theDisplayWidget->setLayout(theDisplayLayout);

    displayLayout->addWidget(theDisplayWidget,0,0);
    displayLayout->addWidget(BottomBar,1,0);

    displayWidget->setLayout(displayLayout);
}
void MainWindow::ShowBrain(){
    SwitchHealthTip();
    delete theDisplayWidget;
    theDisplayWidget = new QWidget;
    theDisplayLayout = new QGridLayout;

    CreateBrainWidget();
    theDisplayLayout->addWidget(BrainWidget);
    theDisplayWidget->setLayout(theDisplayLayout);

    displayLayout->addWidget(theDisplayWidget,0,0);
    displayLayout->addWidget(BottomBar,1,0);

    displayWidget->setLayout(displayLayout);
}
void MainWindow::ShowHead(){
    SwitchHealthTip();
    delete theDisplayWidget;
    theDisplayWidget = new QWidget;
    theDisplayLayout = new QGridLayout;

    CreateHeadWidget();
    theDisplayLayout->addWidget(HeadWidget);
    theDisplayWidget->setLayout(theDisplayLayout);

    displayLayout->addWidget(theDisplayWidget,0,0);
    displayLayout->addWidget(BottomBar,1,0);

    displayWidget->setLayout(displayLayout);
}
void MainWindow::ShowEyes(){
    SwitchHealthTip();
    delete theDisplayWidget;
    theDisplayWidget = new QWidget;
    theDisplayLayout = new QGridLayout;

    CreateEyesWidget();
    theDisplayLayout->addWidget(EyesWidget);
    theDisplayWidget->setLayout(theDisplayLayout);

    displayLayout->addWidget(theDisplayWidget,0,0);
    displayLayout->addWidget(BottomBar,1,0);

    displayWidget->setLayout(displayLayout);
}
void MainWindow::ShowTeethandGums(){
    SwitchHealthTip();
    delete theDisplayWidget;
    theDisplayWidget = new QWidget;
    theDisplayLayout = new QGridLayout;

    CreateTeethandGumsWidget();
    theDisplayLayout->addWidget(TeethAndGumsWidget);
    theDisplayWidget->setLayout(theDisplayLayout);

    displayLayout->addWidget(theDisplayWidget,0,0);
    displayLayout->addWidget(BottomBar,1,0);

    displayWidget->setLayout(displayLayout);

}
void MainWindow::ShowHeart(){
    SwitchHealthTip();
    delete theDisplayWidget;
    theDisplayWidget = new QWidget;
    theDisplayLayout = new QGridLayout;

    CreateHeartWidget();
    theDisplayLayout->addWidget(HeartWidget);
    theDisplayWidget->setLayout(theDisplayLayout);

    displayLayout->addWidget(theDisplayWidget,0,0);
    displayLayout->addWidget(BottomBar,1,0);

    displayWidget->setLayout(displayLayout);
}
void MainWindow::ShowRespiratory(){
    SwitchHealthTip();
    delete theDisplayWidget;
    theDisplayWidget = new QWidget;
    theDisplayLayout = new QGridLayout;

    CreateRespiratoryWidget();
    theDisplayLayout->addWidget(RespiratoryWidget);
    theDisplayWidget->setLayout(theDisplayLayout);

    displayLayout->addWidget(theDisplayWidget,0,0);
    displayLayout->addWidget(BottomBar,1,0);

    displayWidget->setLayout(displayLayout);
}
void MainWindow::ShowDigestive(){
    SwitchHealthTip();
    delete theDisplayWidget;
    theDisplayWidget = new QWidget;
    theDisplayLayout = new QGridLayout;

    CreateDigestiveWidget();
    theDisplayLayout->addWidget(DigestiveWidget);
    theDisplayWidget->setLayout(theDisplayLayout);

    displayLayout->addWidget(theDisplayWidget,0,0);
    displayLayout->addWidget(BottomBar,1,0);

    displayWidget->setLayout(displayLayout);
}
void MainWindow::ShowKidney(){
    SwitchHealthTip();
    delete theDisplayWidget;
    theDisplayWidget = new QWidget;
    theDisplayLayout = new QGridLayout;

    CreateKidneyWidget();
    theDisplayLayout->addWidget(KidneyWidget);
    theDisplayWidget->setLayout(theDisplayLayout);

    displayLayout->addWidget(theDisplayWidget,0,0);
    displayLayout->addWidget(BottomBar,1,0);

    displayWidget->setLayout(displayLayout);
}

void MainWindow::ShowFirstAid() {
    SwitchHealthTip();
    FirstAid *Firstaid = new FirstAid(this);
    QWidget *FirstAidWidget = Firstaid->getWidget();
    SpawnMode(FirstAidWidget);
}

void MainWindow::ShowContacts() {
    SwitchHealthTip();
    delete theDisplayWidget;
    theDisplayWidget = new QWidget;
    theDisplayLayout = new QGridLayout;

    CreateContactsWidget();
    theDisplayLayout->addWidget(ContactsMainWidget);
    theDisplayWidget->setLayout(theDisplayLayout);

    displayLayout->addWidget(theDisplayWidget,0,0);
    displayLayout->addWidget(BottomBar,1,0);

    displayWidget->setLayout(displayLayout);
}
void MainWindow::ShowHospital(){
    SwitchHealthTip();
    delete theDisplayWidget;
    theDisplayWidget = new QWidget;
    theDisplayLayout = new QGridLayout;

    CreateHospitalsWidget();
    theDisplayLayout->addWidget(HospitalWidget);
    theDisplayWidget->setLayout(theDisplayLayout);

    displayLayout->addWidget(theDisplayWidget,0,0);
    displayLayout->addWidget(BottomBar,1,0);

    displayWidget->setLayout(displayLayout);
}
void MainWindow::ShowAmbulances(){
    SwitchHealthTip();
    delete theDisplayWidget;
    theDisplayWidget = new QWidget;
    theDisplayLayout = new QGridLayout;

   CreateAmbulancesWidget();
    theDisplayLayout->addWidget(AmbulancesWidget);
    theDisplayWidget->setLayout(theDisplayLayout);

    displayLayout->addWidget(theDisplayWidget,0,0);
    displayLayout->addWidget(BottomBar,1,0);

    displayWidget->setLayout(displayLayout);
}
void MainWindow::ShowBloodBanks(){
    SwitchHealthTip();
    delete theDisplayWidget;
    theDisplayWidget = new QWidget;
    theDisplayLayout = new QGridLayout;

    CreateBloodBanksWidget();
    theDisplayLayout->addWidget(BloodBanksWidget);
    theDisplayWidget->setLayout(theDisplayLayout);

    displayLayout->addWidget(theDisplayWidget,0,0);
    displayLayout->addWidget(BottomBar,1,0);

    displayWidget->setLayout(displayLayout);
}

void MainWindow::ShowDiseases(){
    SwitchHealthTip();
    Diseases *Dis = new Diseases(this);
    QWidget *DiseasesWidget = Dis->getWidget();
    SpawnMode(DiseasesWidget);
}

void MainWindow::showFoodTips()
{
    SwitchHealthTip();
    FoodTips *Food = new FoodTips(this);
    QWidget *Foodwidget = Food->getWidget();
    SpawnMode(Foodwidget);
}

void MainWindow::ShowAbout(){
    SwitchHealthTip();
    QMessageBox::information(this,"About",AboutApp);
}
void MainWindow::SpawnMode(QWidget *widget) {
    delete mainLayout;
    delete theDisplayLayout;
    delete theDisplayWidget;


       theDisplayLayout = new QGridLayout;
       theDisplayLayout->addWidget(widget);

       theDisplayWidget = new QWidget;
       theDisplayWidget->setLayout(theDisplayLayout);

       displayLayout->addWidget(theDisplayWidget,0,0);
       displayLayout->addWidget(BottomBar,1,0);

       displayWidget->setLayout(displayLayout);

       mainLayout = new QGridLayout; //
       mainLayout->addWidget(headerWidget,      0,0,1,7);
       mainLayout->addWidget(SectionBarWidget,  1,0,10,1);
       mainLayout->addWidget(displayWidget,        1,1,10,6);

       mainWidget->setLayout(mainLayout);
}
void MainWindow::SwitchHealthTip(){
    for(int i=0; i<60; i++){ HT[i]= new QString; }

     *HT[0]=HealthTip1;
    *HT[1]=HealthTip2;
    *HT[2]=HealthTip3;
    *HT[3]=HealthTip4;
    *HT[4]=HealthTip5;
    *HT[5]=HealthTip6;
    *HT[6]=HealthTip7;
    *HT[7]=HealthTip8;
    *HT[8]=HealthTip9;
    *HT[9]=HealthTip10;
    *HT[10]=HealthTip11;
    *HT[11]=HealthTip12;
    *HT[12]=HealthTip13;
    *HT[13]=HealthTip14;
    *HT[14]=HealthTip15;
    *HT[15]=HealthTip16;
    *HT[16]=HealthTip17;
    *HT[17]=HealthTip18;
    *HT[18]=HealthTip19;
    *HT[19]=HealthTip20;
    *HT[20]=HealthTip21;
    *HT[21]=HealthTip22;
    *HT[22]=HealthTip23;
    *HT[23]=HealthTip24;
    *HT[24]=HealthTip25;
    *HT[25]=HealthTip26;
    *HT[26]=HealthTip27;
    *HT[27]=HealthTip28;
    *HT[28]=HealthTip29;
    *HT[29]=HealthTip30;
    *HT[30]=HealthTip31;
    *HT[31]=HealthTip32;
    *HT[32]=HealthTip33;
    *HT[33]=HealthTip34;
    *HT[34]=HealthTip35;
    *HT[35]=HealthTip36;
    *HT[36]=HealthTip37;
    *HT[37]=HealthTip38;
    *HT[38]=HealthTip39;
    *HT[39]=HealthTip40;
    *HT[40]=HealthTip41;
    *HT[41]=HealthTip42;
    *HT[42]=HealthTip43;
    *HT[43]=HealthTip44;
    *HT[44]=HealthTip45;
    *HT[45]=HealthTip46;
    *HT[46]=HealthTip47;
    *HT[47]=HealthTip48;
    *HT[48]=HealthTip49;
    *HT[49]=HealthTip50;
    *HT[50]=HealthTip51;
    *HT[51]=HealthTip52;
    *HT[52]=HealthTip53;
    *HT[53]=HealthTip54;
    *HT[54]=HealthTip55;
    *HT[55]=HealthTip56;
    *HT[56]=HealthTip57;
    *HT[57]=HealthTip58;
    *HT[58]=HealthTip59;
    *HT[59]=HealthTip60;
     int x= qrand() % 60;

    BottomBar->setText(*HT[x]);

}
MainWindow::~MainWindow()
{
    delete ui;
}
