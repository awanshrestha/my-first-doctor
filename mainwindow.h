#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "definitions.hpp"
#include "firstaid.hpp"
#include "diseases.hpp"
#include "filehandler.hpp"
#include "questions.hpp"
#include "tab.hpp"
#include "foodtips.hpp"

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QTextLayout>
#include <QLabel>
#include <QScrollArea>
#include <QMessageBox>
#include <QPixmap>
#include <cstdlib>
#include <ctime>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QWidget *mainWidget;
    QGridLayout *mainLayout;

    QWidget *headerWidget;
    QGridLayout *headerLayout;

    QWidget *SectionBarWidget;
    QGridLayout *SectionbarLayout;

    QWidget *displayWidget;
    QGridLayout *displayLayout;

    QWidget *theDisplayWidget;
    QGridLayout *theDisplayLayout;

    QLabel *BottomBar;
    QString *HT[60];


    QWidget *MedicalWidget;
    QGridLayout *MedicalLayout;
    QWidget *BrainWidget,*HeadWidget,*EyesWidget,*TeethAndGumsWidget,
            *KidneyWidget,*HeartWidget,*RespiratoryWidget,*DigestiveWidget;

    Button *TipsBtn;

    QLabel *Parkinsons,*Meningitis,*Encephalitis,*Alzeimer,
           *Appendicitis,*Cholera,*Jaundice,*HepatitisB,
           *Tuberculosis,*Pneumonia,*COPD,*Asthma,
           *Cataract,*Conjunctivitis,*DryEyeSyndrome,*Glaucoma,
           *Cluster,*Tension,*Sinus,*Migraine,
           *Cardiomypathy,*MyI,*Coronary,*Congenital,
           *Gingivitis,*Decay,*Periodontal,*Sensitivity,
           *Uremia,*KidneyStone,*KidneyCancer,*KidneyInjury;

    QGridLayout *ParkinsonsLayout,*MeningitisLayout,*EncephalitisLayout,*AlzeimerLayout,
           *AppendicitisLayout,*CholeraLayout,*JaundiceLayout,*HepatitisBLayout,
           *TuberculosisLayout,*PneumoniaLayout,*COPDLayout,*AsthmaLayout,
           *CataractLayout,*ConjunctivitisLayout,*DryEyeSyndromeLayout,*GlaucomaLayout,
           *ClusterLayout,*TensionLayout,*SinusLayout,*MigraineLayout,
           *CardiomypathyLayout,*MyILayout,*CoronaryLayout,*CongenitalLayout,
           *GingivitisLayout,*DecayLayout,*PeriodontalLayout,*SensitivityLayout,
           *UremiaLayout,*KidneyStoneLayout,*KidneyCancerLayout,*KidneyInjuryLayout;

    Question *QuestionBrain[18];
    Question *QuestionDigestive[16];
    Question *QuestionRespiratory[18];
    Question *QuestionEyes[18];
    Question *QuestionHead[18];
    Question *QuestionHeart[18];
    Question *QuestionTeethAndGums[18];
    Question *QuestionKidney[18];

    QWidget *ContactsMainWidget;
    QGridLayout *ContactsMainLayout;
    QWidget *HospitalWidget;
    QGridLayout *HospitalLayout;
    QLabel *labelHospitalContacts;
    QWidget *AmbulancesWidget;
    QGridLayout *AmbulancesLayout;
    QLabel *labelAmbulancesContacts;
    QWidget *BloodBanksWidget;
    QGridLayout *BloodBanksLayout;
    QLabel *labelBloodBanksContacts;

private:
    Ui::MainWindow *ui;

    void CreateHomeWidget();
    void CreateExceptDisplay();

    void CreateMedicalWidget();
    void CreateBrainWidget();
    void CreateHeadWidget();
    void CreateEyesWidget();
    void CreateTeethandGumsWidget();
    void CreateHeartWidget();
    void CreateRespiratoryWidget();
    void CreateDigestiveWidget();
    void CreateKidneyWidget();


    QGridLayout *getProbabilityLayout(QLabel *label, QString s);

    void CreateContactsWidget();
    void CreateHospitalsWidget();
    void CreateAmbulancesWidget();
    void CreateBloodBanksWidget();

    void SwitchHealthTip();
    void SpawnMode(QWidget*);

private slots:
    void ShowAbout();
    void ShowMedical();
    void ShowHome();
    void ShowFirstAid();

    void ShowBrain();
    void ShowHead();
    void ShowEyes();
    void ShowTeethandGums();
    void ShowHeart();
    void ShowRespiratory();
    void ShowDigestive();
    void ShowKidney();
    void CheckDiseaseProbability();
    void GetDiseaseTips();

    void ShowContacts();
    void ShowHospital();
    void ShowAmbulances();
    void ShowBloodBanks();
    void ChangeHospitalContacts();
    void ChangeAmbulancesContacts();
    void ShowDiseases();

    void showFoodTips();
};

#endif // MAINWINDOW_H
