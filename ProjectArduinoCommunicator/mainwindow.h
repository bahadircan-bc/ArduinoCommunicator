#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "serialcommunicator.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    SerialCommunicator* serialCommunicator;
    QThread* serialThread;

signals:
    void tryConnection(QString);
    void sendMsg(QString);

public slots:
    void sendButtonClicked();
    void scanButtonClicked();
    void connectButtonClicked();
    void test1ButtonClicked();
    void test2ButtonClicked();

private:
    Ui::MainWindow *ui;

    void setBindings();

};
#endif // MAINWINDOW_H
