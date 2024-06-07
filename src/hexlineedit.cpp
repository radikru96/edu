#include "hexlineedit.h"

HexLineEdit::HexLineEdit(QWidget *pwgt) : QLineEdit(pwgt) {
    QRegularExpression rxp("[0-9A-Fa-f]+");
    setValidator(new QRegularExpressionValidator(rxp, this));
}
