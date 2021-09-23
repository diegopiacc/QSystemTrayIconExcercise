#include "mainwindow.h"

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
#include <QTextEdit>
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow()
{
    createActions();
    createTrayIcon();
/*
    connect(showMessageButton, &QAbstractButton::clicked, this, &Window::showMessage);
    connect(showIconCheckBox, &QAbstractButton::toggled, trayIcon, &QSystemTrayIcon::setVisible);
    connect(iconComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &Window::setIcon);
    connect(trayIcon, &QSystemTrayIcon::messageClicked, this, &Window::messageClicked);
    connect(trayIcon, &QSystemTrayIcon::activated, this, &Window::iconActivated);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(iconGroupBox);
    mainLayout->addWidget(messageGroupBox);
    setLayout(mainLayout); */
;
    trayIcon->show();

    setWindowTitle(tr("QSystemTrayIcon Exercise"));
    resize(400, 300);
}

MainWindow::~MainWindow()
{
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
    trayIcon->setContextMenu(trayIconMenu);
}
