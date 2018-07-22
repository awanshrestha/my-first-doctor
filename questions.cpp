#include "questions.hpp"

Question::Question() {
   QuestionLabel = new QLabel();
    Yes = new QRadioButton("Yes");
    No = new QRadioButton("No");
    QuestionLayout = new QGridLayout;
    QuestionLayout->addWidget(QuestionLabel,0,0,2,2);
    QuestionLayout->addWidget(Yes,2,0,2,2);
    QuestionLayout->addWidget(No,2,1,2,2);
    QuestionWidget = new QWidget;
    QuestionWidget->setLayout(QuestionLayout);
}

Question::Question(QString questionname)
{
    QuestionLabel = new QLabel();
    QuestionLabel->setText(questionname);
    Yes = new QRadioButton("Yes");
    No = new QRadioButton("No");
    QuestionLayout = new QGridLayout;

    QuestionLayout->addWidget(QuestionLabel,0,0,2,2);
    QuestionLayout->addWidget(Yes,2,0,2,2);
    QuestionLayout->addWidget(No,2,1,2,2);

    QuestionWidget = new QWidget;
    QuestionWidget->setLayout(QuestionLayout);
}

void Question::setQuestion(QString questionname) {
    QuestionLabel->setText(questionname);
}
QWidget* Question::getWidget() {
    return this->QuestionWidget;
}
bool Question::checked(){
    if(Yes->isChecked()) {
        return true;
    } else {
        return false;
    }
}
