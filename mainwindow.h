#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "workspace.h"

class QAction;
class QMenu;

class WorkSpace;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow();

private:
    void setupUI();
    void createBar();
    void createActions();
    void createMenuBar();
    void createToolBar();
    void createStatusBar();


private slots:
    void OpenFile() {} 
    void Exit() {}
    void About() {}

private:
    QMap<QString, QAction *> actions;
    QMenuBar *menuBar;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    WorkSpace *localWorkSpace;
    WorkSpace *remoteWorkSpace;
};

#endif // MAINWINDOW_H
