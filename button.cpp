#include "button.hpp"

void Button::mouseReleaseEvent(QMouseEvent*)
{
    emit clicked();
}

Button::Button(QString text, QWidget *parent) : QPushButton(parent)
{
    this->setText(text);
}

