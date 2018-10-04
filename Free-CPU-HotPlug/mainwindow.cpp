#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QProcess>
#include <QDebug>
#include <QPushButton>
#include <QFile>
#include <dialog.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->setVisible(false);

    MapComponents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MapComponents()
{
    /* Label ON */
    ptrLabelon_.push_back(ui->lblCPU0on);
    ptrLabelon_.push_back(ui->lblCPU1on);
    ptrLabelon_.push_back(ui->lblCPU2on);
    ptrLabelon_.push_back(ui->lblCPU3on);
    ptrLabelon_.push_back(ui->lblCPU4on);
    ptrLabelon_.push_back(ui->lblCPU5on);
    ptrLabelon_.push_back(ui->lblCPU6on);
    ptrLabelon_.push_back(ui->lblCPU7on);
    ptrLabelon_.push_back(ui->lblCPU8on);
    ptrLabelon_.push_back(ui->lblCPU9on);
    ptrLabelon_.push_back(ui->lblCPU10on);
    ptrLabelon_.push_back(ui->lblCPU11on);
    ptrLabelon_.push_back(ui->lblCPU12on);
    ptrLabelon_.push_back(ui->lblCPU13on);
    ptrLabelon_.push_back(ui->lblCPU14on);
    ptrLabelon_.push_back(ui->lblCPU15on);


    /* Label ON */
    ptrLabeloff_.push_back(ui->lblCPU0off);
    ptrLabeloff_.push_back(ui->lblCPU1off);
    ptrLabeloff_.push_back(ui->lblCPU2off);
    ptrLabeloff_.push_back(ui->lblCPU3off);
    ptrLabeloff_.push_back(ui->lblCPU4off);
    ptrLabeloff_.push_back(ui->lblCPU5off);
    ptrLabeloff_.push_back(ui->lblCPU6off);
    ptrLabeloff_.push_back(ui->lblCPU7off);
    ptrLabeloff_.push_back(ui->lblCPU8off);
    ptrLabeloff_.push_back(ui->lblCPU9off);
    ptrLabeloff_.push_back(ui->lblCPU10off);
    ptrLabeloff_.push_back(ui->lblCPU11off);
    ptrLabeloff_.push_back(ui->lblCPU12off);
    ptrLabeloff_.push_back(ui->lblCPU13off);
    ptrLabeloff_.push_back(ui->lblCPU14off);
    ptrLabeloff_.push_back(ui->lblCPU15off);

    /* PushButton ON */

    ptrPushOn_.push_back(ui->btnCPU0on);
    ptrPushOn_.push_back(ui->btnCPU1on);
    ptrPushOn_.push_back(ui->btnCPU2on);
    ptrPushOn_.push_back(ui->btnCPU3on);

    ptrPushOn_.push_back(ui->btnCPU4on);
    ptrPushOn_.push_back(ui->btnCPU5on);
    ptrPushOn_.push_back(ui->btnCPU6on);
    ptrPushOn_.push_back(ui->btnCPU7on);

    ptrPushOn_.push_back(ui->btnCPU8on);
    ptrPushOn_.push_back(ui->btnCPU9on);
    ptrPushOn_.push_back(ui->btnCPU10on);
    ptrPushOn_.push_back(ui->btnCPU11on);

    ptrPushOn_.push_back(ui->btnCPU12on);
    ptrPushOn_.push_back(ui->btnCPU13on);
    ptrPushOn_.push_back(ui->btnCPU14on);
    ptrPushOn_.push_back(ui->btnCPU15on);

    /* PushButton ON */

    ptrPushOff_.push_back(ui->btnCPU0off);
    ptrPushOff_.push_back(ui->btnCPU1off);
    ptrPushOff_.push_back(ui->btnCPU2off);
    ptrPushOff_.push_back(ui->btnCPU3off);

    ptrPushOff_.push_back(ui->btnCPU4off);
    ptrPushOff_.push_back(ui->btnCPU5off);
    ptrPushOff_.push_back(ui->btnCPU6off);
    ptrPushOff_.push_back(ui->btnCPU7off);

    ptrPushOff_.push_back(ui->btnCPU8off);
    ptrPushOff_.push_back(ui->btnCPU9off);
    ptrPushOff_.push_back(ui->btnCPU10off);
    ptrPushOff_.push_back(ui->btnCPU11off);

    ptrPushOff_.push_back(ui->btnCPU12off);
    ptrPushOff_.push_back(ui->btnCPU13off);
    ptrPushOff_.push_back(ui->btnCPU14off);
    ptrPushOff_.push_back(ui->btnCPU15off);


    for(int i = 0; i < MAXCPU; i++ )
    {
        ptrLabelon_.at(i)->setStyleSheet("QLabel { background-color : grey;}");
        ptrLabeloff_.at(i)->setStyleSheet("QLabel { background-color : grey;}");
        ptrPushOn_.at(i)->setEnabled(false);
        ptrPushOff_.at(i)->setEnabled(false);
    }

}

void MainWindow::EnableComponents(QStringList list)
{
    ptrLabelon_.at(0)->setStyleSheet("QLabel { background-color : green;}");

    for(int i = 1; i < MappingActiveCPU.length(); i++ )
    {
        if(MappingActiveCPU.at(i) == 1)
        {
            ptrLabelon_.at(i)->setStyleSheet("QLabel { background-color : green;}");
            ptrLabeloff_.at(i)->setStyleSheet("QLabel { background-color : grey;}");
            ptrPushOn_.at(i)->setEnabled(false);
            ptrPushOff_.at(i)->setEnabled(true);
        }else
        {
            ptrLabelon_.at(i)->setStyleSheet("QLabel { background-color : grey;}");
            ptrLabeloff_.at(i)->setStyleSheet("QLabel { background-color : red;}");
            ptrPushOn_.at(i)->setEnabled(true);
            ptrPushOff_.at(i)->setEnabled(false);
        }
    }
}

void MainWindow::on_actionConfigure_triggered()
{




    QProcess process;
    process.start("lscpu -e");
    process.waitForFinished(-1); // will wait forever until finished

    QString _stdout = process.readAllStandardOutput();
    QString _stderr = process.readAllStandardError();

    QRegExp rx("[\n]");
    QStringList list = _stdout.split(rx, QString::SkipEmptyParts);

    for(auto i = 0; i < list.length(); i++)
    {
        //qDebug() << list.at(i);
        if(i  > 0)
        {
            QString onoff;
            qint16 cpu;
            QString str = list.at(i);

            if(str.contains("yes"))
            {
                MappingActiveCPU.push_back(1);
            }else{
                MappingActiveCPU.push_back(0);
            }
            LabelsCPU.push_back(str);
            //qDebug() << str.contains("no");
        }
    }
    for(auto i = 0; i < MappingActiveCPU.length(); i++)
    {
        qDebug() << MappingActiveCPU.at(i);
    }
    EnableComponents(list);

    if(MappingActiveCPU.length() <= 3 )
    {

        qint8 idx = ui->tabWidget->indexOf(ui->tabCpu4);
        ui->tabWidget->removeTab(idx);
        idx = ui->tabWidget->indexOf(ui->tabCpu8);
        ui->tabWidget->removeTab(idx);
        idx = ui->tabWidget->indexOf(ui->tabCpu12);
        ui->tabWidget->removeTab(idx);

    }else if (MappingActiveCPU.length() <= 8 )
    {
        qint8 idx = ui->tabWidget->indexOf(ui->tabCpu8);
        ui->tabWidget->removeTab(idx);
        idx = ui->tabWidget->indexOf(ui->tabCpu12);
        ui->tabWidget->removeTab(idx);

    }else if (MappingActiveCPU.length() <= 12 )
    {
        qint8 idx = ui->tabWidget->indexOf(ui->tabCpu12);
        ui->tabWidget->removeTab(idx);
    }

    ui->tabWidget->setVisible(true);
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_btnCPU0on_clicked()
{
    ui->btnCPU0on->setEnabled(false);
    ui->btnCPU0off->setEnabled(true);

    ui->lblCPU0on->setStyleSheet("QLabel { background-color : green;}");
    ui->lblCPU0off->setStyleSheet("QLabel { background-color : grey;}");

    QString filename = "/sys/devices/system/cpu/cpu0/online";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << "1";
    }

    file.close();
}

void MainWindow::on_btnCPU0off_clicked()
{
    ui->btnCPU0on->setEnabled(true);
    ui->btnCPU0off->setEnabled(false);

    ui->lblCPU0on->setStyleSheet("QLabel { background-color : grey;}");
    ui->lblCPU0off->setStyleSheet("QLabel { background-color : red;}");
    QString filename = "/sys/devices/system/cpu/cpu0/online";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << "0";
    }
    file.close();
}


void MainWindow::on_btnCPU1on_clicked()
{
    ui->btnCPU1on->setEnabled(false);
    ui->btnCPU1off->setEnabled(true);

    ui->lblCPU1on->setStyleSheet("QLabel { background-color : green;}");
    ui->lblCPU1off->setStyleSheet("QLabel { background-color : grey;}");

    QString filename = "/sys/devices/system/cpu/cpu1/online";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << "1";
    }else{

    }

    file.close();
}

void MainWindow::on_btnCPU1off_clicked()
{
    ui->btnCPU1on->setEnabled(true);
    ui->btnCPU1off->setEnabled(false);

    ui->lblCPU1on->setStyleSheet("QLabel { background-color : grey;}");
    ui->lblCPU1off->setStyleSheet("QLabel { background-color : red;}");
    QString filename = "/sys/devices/system/cpu/cpu1/online";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << "0";
    }
    file.close();
}

void MainWindow::on_actionAbout_Hot_Plug_GUI_triggered()
{
    Dialog *dialog = new Dialog;
    dialog->setWindowTitle("Dialog");
    dialog->show();
}