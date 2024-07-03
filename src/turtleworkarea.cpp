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
        << "Koch Snowflake"
        << "Hello Turtle";
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
    case 4:
        strCode =   "turtle.fract = function( length, n ) {\n"
                    "    if (n>1) {\n"
                    "        this.fract( length/3 < 1 ? 1 : length/3, n-1 );\n"
                    "        this.left(60);\n"
                    "        this.fract( length/3 < 1 ? 1 : length/3, n-1 );\n"
                    "        this.right(120);\n"
                    "        this.fract( length/3 < 1 ? 1 : length/3, n-1 );\n"
                    "        this.left(60);\n"
                    "        this.fract( length/3 < 1 ? 1 : length/3, n-1 );\n"
                    "    } else {\n"
                    "        this.forward( length );\n"
                    "    }\n"
                    "}\n"
                    "turtle.reset();\n"
                    "turtle.left(60);\n"
                    "turtle.forward(200);\n"
                    "turtle.right(150);\n"
                    "for ( i = 0; i <3; ++i ) {\n"
                    "    turtle.fract( 400, 5 );\n"
                    "    turtle.right(120);\n"
                    "}";
        break;
    default:
        strCode = "charHeight = 72;\n"
                  "charWidth = 32;\n"
                  "charSpace = 10;\n"
                  "turtle.wh = function() {\n"
                  "    this.left( 90 );\n"
                  "    this.forward( charHeight );\n"
                  "    this.back( charHeight/2 );\n"
                  "    this.right( 90 );\n"
                  "    this.forward( charWidth );\n"
                  "    this.left( 90 );\n"
                  "    this.back( charHeight/2 );\n"
                  "    this.right( 90 );}\n"
                  "turtle.we = function() {\n"
                  "    this.left( 90 );\n"
                  "    this.forward( charHeight/2 );\n"
                  "    this.right( 90 );\n"
                  "    this.forward( charWidth );\n"
                  "    for ( i = 0; i < 2; ++i ) {\n"
                  "        this.back( charWidth );\n"
                  "        this.right( 90 );\n"
                  "        this.forward( charHeight/4 );\n"
                  "        this.left( 90 );\n"
                  "        this.forward( charWidth );}}\n"
                  "turtle.wl = function() {\n"
                  "    this.left( 90 );\n"
                  "    this.forward( charHeight );\n"
                  "    this.back( charHeight );\n"
                  "    this.right( 90 );}\n"
                  "turtle.wo = function() {\n"
                  "    for ( i = 0; i < 2; ++i ) {\n"
                  "        this.forward( charWidth );\n"
                  "        this.left( 90 );\n"
                  "        this.forward( charHeight/2 );\n"
                  "        this.left( 90 );}\n"
                  "    this.forward( charWidth );}\n"
                  "turtle.ww = function() {\n"
                  "    var lineSize = Math.sqrt( Math.pow(charHeight/2,2)+Math.pow(charHeight/4,2) );\n"
                  "    this.forward( charWidth/2 );\n"
                  "    this.right( 60 );\n"
                  "    this.back( lineSize );\n"
                  "    for ( i = 0; i < 2; ++i ) {\n"
                  "        this.forward( lineSize );\n"
                  "        this.left( 120 );\n"
                  "        this.forward( lineSize );\n"
                  "        if (i==0) this.right( 120 );}\n"
                  "    this.back( lineSize );\n"
                  "    this.right( 60 );\n"
                  "    this.forward( charWidth/2 );}\n"
                  "turtle.wr = function() {\n"
                  "    this.left( 90 );\n"
                  "    this.forward( charHeight/2 );\n"
                  "    this.right( 90 );\n"
                  "    this.forward( charWidth );\n"
                  "    this.back( charWidth );\n"
                  "    this.right( 90 );\n"
                  "    this.forward( charHeight/2 );\n"
                  "    this.left( 90 );\n"
                  "    this.forward( charWidth );}\n"
                  "turtle.wd = function() {\n"
                  "    this.wo();\n"
                  "    this.wl();}\n"
                  "turtle.reset();\n"
                  "turtle.left(90);\n"
                  "turtle.forward(190);\n"
                  "turtle.left(180);\n"
                  "turtle.wh();\n"
                  "turtle.forward(charSpace);\n"
                  "turtle.we();\n"
                  "turtle.forward(charSpace);\n"
                  "turtle.wl();\n"
                  "turtle.forward(charSpace);\n"
                  "turtle.wl();\n"
                  "turtle.forward(charSpace);\n"
                  "turtle.wo();\n"
                  "turtle.forward(charWidth);\n"
                  "turtle.ww();\n"
                  "turtle.forward(charSpace);\n"
                  "turtle.wo();\n"
                  "turtle.forward(charSpace);\n"
                  "turtle.wr();\n"
                  "turtle.forward(charSpace);\n"
                  "turtle.wl();\n"
                  "turtle.forward(charSpace);\n"
                  "turtle.wd();\n";
    }
    m_ptxt->setPlainText(strCode);
}
