#include <QtWidgets>
#include <QTest>

class Test_QLineEdit : public QObject {
    Q_OBJECT
private slots:
    void min();
};

void Test_QLineEdit::min()
{
    QLineEdit txt;
    QTest::keyClicks( &txt, "ABCDEFGH" );
    QCOMPARE( txt.text(), QString( "ABCDEFGH." ) );
    QVERIFY( txt.isModified() );
}

QTEST_MAIN(Test_QLineEdit)
#include "main.moc"
