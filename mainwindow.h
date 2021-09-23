#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QSystemTrayIcon>
#include <QDialog>

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
QT_END_NAMESPACE

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    void createActions();
    void createTrayIcon();

    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;

    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;


};
#endif // MAINWINDOW_H
