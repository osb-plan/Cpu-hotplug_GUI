#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>


#define MAXCPU  16

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionConfigure_triggered();

    void on_actionExit_triggered();

    void on_btnCPU0on_clicked();
    void on_btnCPU1on_clicked();
    void on_btnCPU2on_clicked();
    void on_btnCPU3on_clicked();
    void on_btnCPU4on_clicked();
    void on_btnCPU5on_clicked();
    void on_btnCPU6on_clicked();
    void on_btnCPU7on_clicked();
    void on_btnCPU8on_clicked();
    void on_btnCPU9on_clicked();
    void on_btnCPU10on_clicked();
    void on_btnCPU11on_clicked();
    void on_btnCPU12on_clicked();
    void on_btnCPU13on_clicked();
    void on_btnCPU14on_clicked();
    void on_btnCPU15on_clicked();

    void on_btnCPU0off_clicked();
    void on_btnCPU1off_clicked();
    void on_btnCPU2off_clicked();
    void on_btnCPU3off_clicked();
    void on_btnCPU4off_clicked();
    void on_btnCPU5off_clicked();
    void on_btnCPU6off_clicked();
    void on_btnCPU7off_clicked();
    void on_btnCPU8off_clicked();
    void on_btnCPU9off_clicked();
    void on_btnCPU10off_clicked();
    void on_btnCPU11off_clicked();
    void on_btnCPU12off_clicked();
    void on_btnCPU13off_clicked();
    void on_btnCPU14off_clicked();
    void on_btnCPU15off_clicked();

    void on_actionAbout_Hot_Plug_GUI_triggered();

private:
    Ui::MainWindow *ui;
    QVector<QString> LabelsCPU;
    QVector<qint8> MappingActiveCPU;
    QVector<QPushButton*> ptrPushOn_;
    QVector<QPushButton*> ptrPushOff_;
    QVector<QLabel*> ptrLabelon_;
    QVector<QLabel*> ptrLabeloff_;
    QVector<QLabel*> ptrLabelGeneralView_;

    void MapComponents();
    void EnableComponents(QStringList list);

};

#endif // MAINWINDOW_H

