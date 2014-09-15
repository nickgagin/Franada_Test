#include "ProjectDialog.h"
#include "ui_ProjectDialog.h"

ProjectDialog::ProjectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProjectDialog)
{
    ui->setupUi(this);

    QStringList labels;
    labels << tr("Канал") << tr("Описание");
    ui->treeWidget->setHeaderLabels(labels);
    ui->treeWidget->clear();
}

ProjectDialog::~ProjectDialog()
{
    delete ui;
}

void ProjectDialog::slotSetProject(SyncProjectClass &pA)
{
   project = &pA;

   ui->lineEdit_location->setText(project->getLocation().toLocal8Bit());
   ui->lineEdit_date->setText(project->getProjectDate().toString("yyyy.MM.dd").toLocal8Bit());
   ui->lineEdit_navigation->setText(project->getNavigationFilePath().toLocal8Bit());
   ui->plainTextEdit_description->appendPlainText(project->getProjDescription().toLocal8Bit());

   for(int i = 0; i < project->channelList.size(); i++)
   {
       QTreeWidgetItem *channelItem = new QTreeWidgetItem(ui->treeWidget);
       channelItem->setText(0,project->channelList[i].name);

       QTreeWidgetItem *child_filename = new QTreeWidgetItem(channelItem);
       child_filename->setText(1,project->channelList[i].filePath);
       child_filename->setText(0,"Имя файла");
       QTreeWidgetItem *child_frame = new QTreeWidgetItem(channelItem);
       child_frame->setText(1,QString::number(project->channelList[i].frame,10));
       child_frame->setText(0,"Синхронизированный кадр");
       QTreeWidgetItem *child_flash = new QTreeWidgetItem(channelItem);
       child_flash->setText(1,QString::number(project->channelList[i].flash,10));
       child_flash->setText(0,"Вспышка в кадре");

       QTreeWidgetItem *child_geometry = new QTreeWidgetItem(channelItem);
       child_geometry->setText(0,"Геометрия кадра");
       QTreeWidgetItem *child_geom_rotX = new QTreeWidgetItem(child_geometry);
       child_geom_rotX->setText(1,QString::number(project->channelList[i].geometryInfo.rotX,'f',4));
       child_geom_rotX->setText(0,"Поворот вокруг оси Х");
       QTreeWidgetItem *child_geom_rotY = new QTreeWidgetItem(child_geometry);
       child_geom_rotY->setText(1,QString::number(project->channelList[i].geometryInfo.rotY,'f',4));
       child_geom_rotY->setText(0,"Поворот вокрут оси Y");
       QTreeWidgetItem *child_geom_rotZ = new QTreeWidgetItem(child_geometry);
       child_geom_rotZ->setText(1,QString::number(project->channelList[i].geometryInfo.rotZ,'f',4));
       child_geom_rotZ->setText(0,"Поворот вокруг оси Z");
       QTreeWidgetItem *child_geom_transX = new QTreeWidgetItem(child_geometry);
       child_geom_transX->setText(1,QString::number(project->channelList[i].geometryInfo.transX,'f',4));
       child_geom_transX->setText(0,"Смещение по оси X");
       QTreeWidgetItem *child_geom_transY = new QTreeWidgetItem(child_geometry);
       child_geom_transY->setText(1,QString::number(project->channelList[i].geometryInfo.transY,'f',4));
       child_geom_transY->setText(0,"Смещение по оси Y");
       QTreeWidgetItem *child_geom_transZ = new QTreeWidgetItem(child_geometry);
       child_geom_transZ->setText(1,QString::number(project->channelList[i].geometryInfo.transZ,'f',4));
       child_geom_transZ->setText(0,"Смещение по оси Z");
   }
}

