#include "mainwindow.h"

#include "dptaskcheckfile.h"
#include "dptaskoutput.h"
#include "dptaskparam.h"
#include "dptaskexecutor.h"

#include <QAction>
#include <QCheckBox>
#include <QComboBox>
#include <QCoreApplication>
#include <QCloseEvent>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QPushButton>
#include <QSpinBox>
#include <QTableView>
#include <QTableWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QHeaderView>
#include <QTimer>

#include <QDebug>

MainWindow::MainWindow() : taskList(QList<DPTask> ()), taskExecutorList(QList<DPTaskExecutor*> ())
{
    //

    DPTaskOutput T1("Task1", 10);
    T1.addParam("TestString");
    DPTaskCheckFile T2("Task2", 30);
    T2.addParam("/esempio.txt");

    this->taskList.append(T1);
    this->taskList.append(T2);

    DPTaskExecutor *TE1 = new DPTaskExecutor(this);
    TE1->task = &T1;
    TE1->taskTimer = new QTimer(this);
    this->taskExecutorList.append(TE1);

    DPTaskExecutor *TE2 = new DPTaskExecutor(this);
    TE2->task = &T2;
    TE2->taskTimer = new QTimer(this);
    this->taskExecutorList.append(TE2);

    qDebug("Task List has been inited as hardcoded values");

    //

    createActions();
    createTrayIcon();
    createTaskTable();

    //
    initTimers();



/*
    connect(showMessageButton, &QAbstractButton::clicked, this, &Window::showMessage);
    connect(showIconCheckBox, &QAbstractButton::toggled, trayIcon, &QSystemTrayIcon::setVisible);
    connect(iconComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::setIcon);
    connect(trayIcon, &QSystemTrayIcon::messageClicked, this, &Window::messageClicked);
    connect(trayIcon, &QSystemTrayIcon::activated, this, &Window::iconActivated);

*/
;
    trayIcon->show();

    setWindowTitle(tr("QSystemTrayIcon Exercise"));
    resize(600, 300);
}

MainWindow::~MainWindow()
{
    qDeleteAll(taskExecutorList);
    taskExecutorList.clear();
}

void MainWindow::createTaskTable()
{
    QTableWidget *taskTable = new QTableWidget(2,4);
    QStringList labels;
    labels << tr("Task#") << tr("Task name") << tr("Periodicity") << tr("Parameters");
    taskTable->setHorizontalHeaderLabels(labels);
    taskTable->verticalHeader()->hide();
    taskTable->setShowGrid(true);

    // initialize tasks from task List
    // note that task list for this exercise
    for( int i=0; i<this->taskList.count(); ++i )
    {
        // taskTable->insertRow(i);
        QTableWidgetItem *itm0 = new QTableWidgetItem;
        itm0->setText(QString::number(i));
        itm0->setFlags(itm0->flags() ^ Qt::ItemIsEditable);
        taskTable->setItem(i, 0, itm0);

        QTableWidgetItem *itm1 = new QTableWidgetItem;
        itm1->setText(this->taskList[i].getTaskName());
        itm1->setFlags(itm1->flags() ^ Qt::ItemIsEditable);
        taskTable->setItem(i, 1, itm1);

        QTableWidgetItem *itm2 = new QTableWidgetItem;
        itm2->setText(this->taskList[i].getTaskPeriodAsString());
        itm2->setFlags(itm2->flags() ^ Qt::ItemIsEditable);
        taskTable->setItem(i, 2, itm2);

        QTableWidgetItem *itm3 = new QTableWidgetItem;
        itm3->setText(this->taskList[i].getTaskParametersAsString());
        taskTable->setItem(i, 3, itm3);

    }


    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->setStretch(0, 1);
    mainLayout->addWidget(taskTable);
    setLayout(mainLayout);
}


void MainWindow::createActions()
{
    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, &QAction::triggered, this, &QWidget::hide);

    maximizeAction = new QAction(tr("Ma&ximize"), this);
    connect(maximizeAction, &QAction::triggered, this, &QWidget::showMaximized);

    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, &QAction::triggered, this, &QWidget::showNormal);

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
}

void MainWindow::createTrayIcon()
{
    trayIconMenu = new QMenu(this);

    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(maximizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/images/taskicon.png"));
    trayIcon->setContextMenu(trayIconMenu);
}

void MainWindow::initTimers()
{
    for( int i=0; i<this->taskExecutorList.count(); ++i ) {
        QObject::connect(this->taskExecutorList[i]->taskTimer, SIGNAL(timeout()), this->taskExecutorList[i], SLOT(execute()));
        this->taskExecutorList[i]->taskTimer->start(10*this->taskList[i].getTaskPeriod());
    }
}
