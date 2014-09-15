#ifndef ProjectDialog_H
#define ProjectDialog_H

#include <QDialog>
#include "syncprojectclass.h"

namespace Ui {
class ProjectDialog;
}

class ProjectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProjectDialog(QWidget *parent = 0);
    ~ProjectDialog();

public slots:
    void slotSetProject(SyncProjectClass &);

private:
    Ui::ProjectDialog *ui;
    SyncProjectClass *project;
};

#endif // ProjectDialog_H
