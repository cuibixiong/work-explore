#include <QtGui>
#include <QTreeWidget>

class WorkSpace : public QWidget
{
    Q_OBJECT

    public:
        explicit WorkSpace(QWidget *parent = 0);
        virtual ~WorkSpace();

    public slots:

    private:
        QTreeWidget *m_workspace;
        void setupUI();
};
