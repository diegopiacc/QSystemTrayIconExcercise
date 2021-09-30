#include "mainwindow.h"

#include "dptaskcheckfile.h"
#include "dptaskoutput.h"
#include "dptaskparam.h"

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

MainWindow::MainWindow() : taskList(QList<DPTask*> ()), timerList(QList<QTimer*> ()) // , taskExecutorList(QList<DPTaskExecutor*> ())
{
    //

    DPTaskOutput *T1 = new DPTaskOutput("Task1", 10);
    T1->addParam("TestString");
    DPTaskCheckFile *T2 = new DPTaskCheckFile("Task2", 30);
    T2->addParam("/esempio.txt");

    this->taskList.append(T1);
    this->taskList.append(T2);

    QTimer* taskTimer1 = new QTimer(this);
    QTimer* taskTimer2 = new QTimer(this);

    this->timerList.append(taskTimer1);
    this->timerList.append(taskTimer2);


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
    /*
    qDeleteAll(taskExecutorList);
    taskExecutorList.clear();
    */
}

void MainWindow::createTaskTable()
{
    taskTable = new QTableWidget(2,4);
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
        itm1->setText(this->taskList[i]->getTaskName());
        itm1->setFlags(itm1->flags() ^ Qt::ItemIsEditable);
        taskTable->setItem(i, 1, itm1);

        QTableWidgetItem *itm2 = new QTableWidgetItem;
        itm2->setText(this->taskList[i]->getTaskPeriodAsString());
        itm2->setFlags(itm2->flags() ^ Qt::ItemIsEditable);
        taskTable->setItem(i, 2, itm2);

        QTableWidgetItem *itm3 = new QTableWidgetItem;
        itm3->setText(this->taskList[i]->getTaskParametersAsString());
        taskTable->setItem(i, 3, itm3);

    }

    QObject::connect(taskTable, SIGNAL(cellChanged(int, int)), this, SLOT(cellChanged(int, int)));



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

/**
 * @brief MainWindow::initTimers
 * Initialize a list of Timers for the tasks managed by this object; could be improved
 * by creating a TaskExecutor object/TaskExecutors QList
 *
 */
void MainWindow::initTimers()
{

    QObject::connect(this->timerList[0], SIGNAL(timeout()), this, SLOT(executeTimer1()));
    QObject::connect(this->timerList[1], SIGNAL(timeout()), this, SLOT(executeTimer2()));

    this->timerList[0]->start(1000*this->taskList[0]->getTaskPeriod());
    this->timerList[1]->start(1000*this->taskList[1]->getTaskPeriod());

    /*
    for( int i=0; i<this->taskExecutorList.count(); ++i ) {
        QObject::connect(this->taskExecutorList[i]->taskTimer, SIGNAL(timeout()), this->taskExecutorList[i], SLOT(execute()));
        this->taskExecutorList[i]->taskTimer->start(10*this->taskList[i].getTaskPeriod());
    }
    */
}

void MainWindow::executeTimer1()
{
    DPTaskOutput* t = (DPTaskOutput*)this->taskList[0];
    t->execute();
}

void MainWindow::executeTimer2()
{
    DPTaskCheckFile* t = (DPTaskCheckFile*)this->taskList[1];
    t->execute();
}

void MainWindow::cellChanged(int r, int c)
{
    QString newval = taskTable->item(r, c)->text();
    if(c==3) {
        this->taskList[r]->resetParam(newval);
    } else {
        qDebug() << "How did you manage to edit THIS?" << r << c;
    }
}

