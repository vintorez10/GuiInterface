#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QIcon>
#include <QSizePolicy>
#include <QPalette>
#include <QGraphicsScene>
#include <QLCDNumber>
#include <QPalette>
#include <QPixmap>
#include <QLabel>
#include <QLineEdit>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include "tempsensor.h"
#include "humiditysensor.h"
#include "windsensor.h"


class UserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr);
    ~UserWindow();

private:
    void setTempLayout();
    void setHumidityLayout();
    void setWindLayout();
    void setVideoLayout();
    void setBackColor();

private:

    QGridLayout *m_mainLayout;
    QPalette m_dark;
    QGroupBox *m_tempGroup, *m_humidityGroup,
              *m_windGroup, *m_videoGroup;

    TempSensor *m_tempSensor;    
    HumiditySensor *m_humiditySensor;
    WindSensor *m_windSensor;

    //QTimer m_newTimer;
    QLCDNumber *m_tempDigitNumber, *m_humidityDigital,
               *m_windDigital;

public slots:
    void updateTempValue(const double tempVal);
    void updateHumidityValue(const uint64_t humVal);
    void updateWindValue(const uint64_t windVal);


};
#endif // USERWINDOW_H
