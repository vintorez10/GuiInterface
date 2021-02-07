#ifndef WINDSENSOR_H
#define WINDSENSOR_H

#include <QObject>
#include <QTimer>
#include <QDateTime>

class WindSensor : public QObject
{
    Q_OBJECT
public:
    explicit WindSensor(QObject *parent = nullptr);

private:
    uint64_t m_windValue;
    QTimer m_time;

signals:
    void setWindValue(const uint64_t windVal);

};

#endif // WINDSENSOR_H
