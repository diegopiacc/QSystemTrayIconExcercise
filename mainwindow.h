#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSystemTrayIcon>
#include <QDialog>
#include <QList>
#include "dptask.h"

QT_BEGIN_NAMESPACE
class QAction;
class QCheckBox;
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QMenu;
class QPushButton;
class QSpinBox;
class QTextEdit;
class QTimer;
class QTableWidget;
QT_END_NAMESPACE

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:

    void createActions();
    void createTaskTable();
    void createTrayIcon();

    void initTimers();

    QList<DPTask*> taskList;
    QList<QTimer*> timerList;
    // QList<DPTaskExecutor*> taskExecutorList;


    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;

    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;

private:
    QTableWidget *taskTable;

private slots:
    void executeTimer1();
    void executeTimer2();

    void cellChanged(int r, int c);

};
#endif // MAINWINDOW_H
