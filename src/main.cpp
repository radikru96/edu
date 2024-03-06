#include <QtSvgWidgets/QSvgWidget>
#include <QtSvg>
#include <QtWidgets>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSvgWidget svg(":/images/motion.svg");
    svg.show();
    QObject::connect(svg.renderer(), SIGNAL(repaintNeeded()), &svg, SLOT(repaint()));
    return a.exec();
}
