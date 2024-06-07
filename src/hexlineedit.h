#ifndef HEXLINEEDIT_H
#define HEXLINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QRegularExpressionValidator>

class HexLineEdit : public QLineEdit
{
public:
    HexLineEdit(QWidget *pwgt = 0);
};

#endif // HEXLINEEDIT_H
