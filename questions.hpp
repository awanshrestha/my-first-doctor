#ifndef QUESTION_HPP
#define QUESTION_HPP

#include <QMainWindow>
#include <QLabel>
#include <QLayout>
#include <QGridLayout>
#include <QWidget>
#include <QRadioButton>

class Question
{
public:
    Question(QString);
    Question();
    QWidget* getWidget();
    void setQuestion(QString);
    bool checked();
private:
    QWidget *QuestionWidget;
    QLabel *QuestionLabel;
    QGridLayout *QuestionLayout;
    QRadioButton *Yes,*No;
};

#endif // QUESTION_HPP
