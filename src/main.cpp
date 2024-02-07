#include <QtWidgets>
#include <QApplication>

QLabel *lbl(QGraphicsEffect *pge) {
    QLabel *plbl = new QLabel;
    plbl->setPixmap(QPixmap(":/images/OS2.png").scaled(150,150,Qt::KeepAspectRatio));
    if (pge)
        plbl->setGraphicsEffect(pge);
    return plbl;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;
    QGraphicsBlurEffect *pBlur = new QGraphicsBlurEffect;
    QGraphicsDropShadowEffect *pShadow = new QGraphicsDropShadowEffect;
    QGraphicsColorizeEffect *pColorize = new QGraphicsColorizeEffect;

    QFormLayout *pform = new QFormLayout;
    pform->addRow("No Effects", lbl(0));
    pform->addRow("Blur", lbl(pBlur));
    pform->addRow("Drop Shadow", lbl(pShadow));
    pform->addRow("Colorize", lbl(pColorize));
    wgt.setLayout(pform);
    wgt.show();
    return a.exec();
}
