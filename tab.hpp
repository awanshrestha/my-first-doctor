#ifndef TAB_H
#define TAB_H

#include <QDialog>
#include <QMainWindow>
#include <QLabel>
#include <QLayout>
#include <QGridLayout>
#include <QWidget>
#include <QRadioButton>
#include <QCheckBox>

class TAB
{
public:
   TAB();
   void setAnotherText(QString);
   QWidget* getwidgeter();
   void setMarkYES();
   void setMarkNo();
   void setMarkMaybe(QString);

   /*only for top*/
   void setTEXTforyes(QString);
   void setTEXTforNo(QString);
   void setTEXTforMaybe(QString);

    void SetDefault();

private:
   QLabel *FOOD_Label;
   QLabel *Yess,*Noo,*Maybe;
   QWidget *widgetofTable;
   QGridLayout *gridforTable;

};

#endif // TAB_H
