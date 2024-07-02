#include <QJSEngine>
#include "turtleworkarea.h"
#include "turtle.h"

TurtleWorkArea::TurtleWorkArea(QWidget *parent)
    : QWidget{parent}
{
    m_pTurtle = new Turtle;
    m_pTurtle->setFixedSize( 400, 400 );
    m_ptxt = new QTextEdit;
    QComboBox *pcbo = new QComboBox;
    QStringList lst;
    lst << "Haus vom Nikolaus"
        << "Curly"
        << "Circle"
        << "Fantasy"
        << "Golden ratio";
    pcbo->addItems(lst);
    connect( pcbo, SIGNAL(activated(int)), SLOT(slotApplyCode(int)) );
    slotApplyCode(0);
    QJSValue scriptTurtle = m_scriptEngine.newQObject( m_pTurtle );
    m_scriptEngine.globalObject().setProperty( "turtle", scriptTurtle );
    QPushButton *pcmd = new QPushButton( "&Evaluate");
    connect( pcmd, SIGNAL(clicked(bool)), SLOT(slotEvaluate()) );
    QGridLayout *pgrdLayout = new QGridLayout;
    pgrdLayout->addWidget( pcbo, 0, 0);
    pgrdLayout->addWidget( m_ptxt, 1, 0);
    pgrdLayout->addWidget( m_pTurtle, 0, 1, 2, 1 );
    pgrdLayout->addWidget( pcmd, 2, 0, 1, 2 );
    setLayout( pgrdLayout );
}

void TurtleWorkArea::slotEvaluate()
{
    QJSValue result = m_scriptEngine.evaluate( m_ptxt->toPlainText() );
    if ( result.isError() )
        QMessageBox::critical( 0, "Evaluating error", result.toString(), QMessageBox::Yes );
}

void TurtleWorkArea::slotApplyCode(int n)
{
    QString strCode;
    switch (n) {
    case 0:
        strCode = "var k = 100;\n"
                  "turtle.reset();\n"
                  "turtle.right(90);\n"
                  "turtle.back(-k);\n"
                  "turtle.left(90);\n"
                  "turtle.forward(k);\n"
                  "turtle.left(30);\n"
                  "turtle.forward(k);\n"
                  "turtle.left(120);\n"
                  "turtle.forward(k);\n"
                  "turtle.left(30);\n"
                  "turtle.forward(k);\n"
                  "turtle.left(135);\n"
                  "turtle.forward(Math.sqrt(2)*k);\n"
                  "turtle.left(135);\n"
                  "turtle.forward(k);\n"
                  "turtle.left(135);\n"
                  "turtle.forward(Math.sqrt(2)*k);\n";
        break;
    case 1:
        strCode = "turtle.reset();\n"
                  "for ( i = 0; i < 2; ++i ) {\n"
                  "    for ( j = 0; j < 100; ++j ) {\n"
                  "        turtle.forward(15);\n"
                  "        turtle.left(100-j);\n"
                  "    }\n"
                  "    turtle.right(180);\n"
                  "}";
        break;
    case 2:
        strCode = "turtle.circle = function() {\n"
                  "    for ( var i = 0; i < 360; ++i ) {\n"
                  "        this.forward(1);\n"
                  "        this.left(1);}}\n"
                  "turtle.reset();\n"
                  "turtle.circle();\n";
        break;
    case 3:
        strCode = "turtle.reset();\n"
                  "for ( i = 0; i < 200; ++i ) {\n"
                  "    turtle.forward(i*2);\n"
                  "    turtle.left(91);}";
        break;
    default:
        strCode = "turtle.reset();\n"
                  "turtle.left(50);\n"
                  "turtle.forward(190);\n"
                  "turtle.left(155);\n"
                  "for ( i = 1; i < 300; ++i ) {\n"
                  "    turtle.forward(i*1.6180339887/15);\n"
                  "    turtle.left(i*1.6180339887);}";
    }
    m_ptxt->setPlainText(strCode);
}
