#include "mainwindow.h"

#include "dptasktablemodel.h"

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

#include <QDebug>

MainWindow::MainWindow() : taskList(QList<DPTask> ())
{
    //

    DPTask T1("Task1", 10);
    DPTask T2("Task2", 30);

    this->taskList.append(T1);
    this->taskList.append(T2);

    qDebug("Task List has been inited as hardcoded values");

    //

    createActions();
    createTrayIcon();
    createTaskTable();





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
    resize(400, 300);
}

MainWindow::~MainWindow()
{
    // fixed tasks, for the sake of exercise

}

void MainWindow::createTaskTable()
{
    QTableWidget *taskTable = new QTableWidget(2,3);
    QStringList labels;
    labels << tr("Task#") << tr("Task name") << tr("Parameters");
    taskTable->setHorizontalHeaderLabels(labels);
    taskTable->verticalHeader()->hide();
    taskTable->setShowGrid(true);

    // initialize tasks from task List
    // note that task list for this exercise
    for( int i=0; i<this->taskList.count(); ++i )
    {
        // taskTable->insertRow(i);
        QTableWidgetItem *itm = new QTableWidgetItem;
        itm->setText(this->taskList[i].getTaskName());
        taskTable->setItem(i, 1, itm);
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
