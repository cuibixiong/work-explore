
#include "action.h"

QAction *createAction(QObject *parent, QString name, QString desc, QIcon icon, QString shortkey)
{
    QAction *action = new QAction(parent);
    action->setText(name);
    action->setStatusTip(desc);
    action->setToolTip(name);

    if (!icon.isNull())
    {
        action->setIcon(icon);
        action->setIconVisibleInMenu(true);
    }

    if (shortkey != QObject::tr(""))
        action->setShortcut(QKeySequence(shortkey));

    return action;
}
