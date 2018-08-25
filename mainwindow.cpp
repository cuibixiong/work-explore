#include <QtWidgets>

#include "mainwindow.h"
#include "action.h"

#define GET_ACTION_NAME(x) QString(x).split(".", QString::SkipEmptyParts).last()

#define M_FILE "&File"
#define FILE_OPEN "File.Open"
#define FILE_EXIT "File.Exit"

#define M_HELP "&Help"
#define HELP_ABOUT "Help.About"

MainWindow::MainWindow()
{
    setupUI();
    createBar();
}

void MainWindow::createBar()
{
    menuBar = new QMenuBar(this);
    this->setMenuBar(menuBar);

    toolBar = new QToolBar(this);
    this->addToolBar(toolBar);

    statusBar = new QStatusBar(this);
    this->setStatusBar(statusBar);

    createActions();
    createMenuBar();
    createToolBar();
}

void MainWindow::createActions()
{
    actions.insert(tr(FILE_OPEN), createAction(this, GET_ACTION_NAME(FILE_OPEN), tr("open"), QIcon(""), tr("")));
    connect(actions[FILE_OPEN], SIGNAL(triggered()), this, SLOT(OpenFile()));

    actions.insert(tr(FILE_EXIT), createAction(this, GET_ACTION_NAME(FILE_EXIT), tr("exit"), QIcon(""), tr("")));
    connect(actions[FILE_OPEN], SIGNAL(triggered()), this, SLOT(Exit()));

    actions.insert(tr(HELP_ABOUT), createAction(this, GET_ACTION_NAME(HELP_ABOUT), tr("about"), QIcon(""), tr("")));
    connect(actions[FILE_OPEN], SIGNAL(triggered()), this, SLOT(About()));
}

void MainWindow::createMenuBar()
{
    QMenu *lv1 ;

    lv1 = menuBar->addMenu(M_FILE);
    lv1->addAction(actions[FILE_OPEN]);
    lv1->addAction(actions[FILE_EXIT]);

    lv1 = menuBar->addMenu(M_HELP);
    lv1->addAction(actions[HELP_ABOUT]);
}

void MainWindow::createToolBar()
{
    toolBar->addAction(actions[FILE_OPEN]);
    toolBar->addAction(actions[FILE_EXIT]);
}

void MainWindow::setupUI()
{
    setMinimumSize(800, 600);
    setWindowTitle("Oh! WorkExplore");

    QHBoxLayout *mainLayout = new QHBoxLayout();
    QWidget *mainWidget = new QWidget();
    this->setCentralWidget(mainWidget);

#define LAYOUT(x) \
    QGridLayout *x = new QGridLayout(); \
    x->setSpacing(1);                   \
    x->setContentsMargins(5,5,5,5);

    LAYOUT(localWorkSpaceLayout);
    LAYOUT(remoteWorkSpaceLayout);
#undef LAYOUT

    QGroupBox *localWorkSpaceGroupBox = new QGroupBox("Local WorkSpace");
    QGroupBox *remoteWorkSpaceGroupBox = new QGroupBox("Remote WorkSpace");

    mainLayout->addWidget(localWorkSpaceGroupBox, 0);
    mainLayout->addWidget(remoteWorkSpaceGroupBox, 1);

    localWorkSpaceGroupBox->setLayout(localWorkSpaceLayout);
    localWorkSpace = new WorkSpace();
    localWorkSpaceLayout->addWidget(localWorkSpace);

    remoteWorkSpaceGroupBox->setLayout(remoteWorkSpaceLayout);
    remoteWorkSpace = new WorkSpace();
    remoteWorkSpaceLayout->addWidget(remoteWorkSpace);

    mainWidget->setLayout(mainLayout);
}
