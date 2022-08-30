#ifndef SERIALCOMMUNICATOR_H
#define SERIALCOMMUNICATOR_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialCommunicator : public QObject
{
    Q_OBJECT
public:
    explicit SerialCommunicator(QObject *parent = nullptr);

public slots:
    void configurePort(QString);
    void tryConnection(QString);
    //void formMsg();
    void sendMsg(QString);
    //void tryDisconnection();

signals:
    void sendLog(QString);

private:
    QSerialPort* serialPort;

};

#endif // SERIALCOMMUNICATOR_H
