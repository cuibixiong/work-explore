#include <QtWidgets>

#include "workspace.h"
#include "action.h"

#include <QContextMenuEvent>

WorkSpace::WorkSpace(QWidget *parent)
    : QWidget(parent)
{
    setupUI();
}

WorkSpace::~WorkSpace()
{}

void WorkSpace::setupUI()
{
    QGridLayout *mainLayout = new QGridLayout();

    mainLayout->setSpacing(1);
    mainLayout->setContentsMargins(5,5,5,5);

    m_workspace = new QTreeWidget();
    m_workspace->setHeaderLabels(QStringList() << "File Name" << "Size" << "Type");
    m_workspace->setSelectionMode(QAbstractItemView::ExtendedSelection);
    m_workspace->setContextMenuPolicy(Qt::CustomContextMenu);

    mainLayout->addWidget(m_workspace);
    this->setLayout(mainLayout);
}
