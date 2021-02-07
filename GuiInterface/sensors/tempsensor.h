#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

class TempSensor : public QObject
{
    Q_OBJECT
public:
    explicit TempSensor(QObject *parent = nullptr);

private:
    double m_tempFromSensor;
    QTimer m_time;

signals:
    void setTemperature(const double temperature);

};

#endif // TEMPSENSOR_H
