#include "tempsensor.h"

TempSensor::TempSensor(QObject *parent) : QObject(parent)
{
    m_tempFromSensor = 20.0;
    m_time.setInterval(4000);
    m_time.setSingleShot(false);

    connect(&m_time, &QTimer::timeout, this, [this](){

        QDateTime timeNow = QDateTime::currentDateTime();
        double changeValue = static_cast<double>(timeNow.time().second() % 10 - 5);

        m_tempFromSensor += changeValue;

        emit setTemperature(m_tempFromSensor);

    });

    m_time.start();

}
