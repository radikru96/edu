#ifndef CALCULATION_H
#define CALCULATION_H

#include <QObject>

class Calculation : public QObject
{
    Q_OBJECT
private:
    Q_PROPERTY( qulonglong input WRITE setInputValue READ inputValue NOTIFY inputValueChanged )
    Q_PROPERTY( qulonglong result READ resultValue NOTIFY resultValueChanged )
    qulonglong m_nInput;
    qulonglong m_nResult;
public:
    Calculation( QObject *parent = nullptr );
    Q_INVOKABLE qulonglong factorial( const qulonglong &n );

    qulonglong inputValue() const;
    qulonglong resultValue() const;
    void setInputValue( const qulonglong & );
signals:
    void inputValueChanged(qulonglong);
    void resultValueChanged(qulonglong);
};

#endif // CALCULATION_H
