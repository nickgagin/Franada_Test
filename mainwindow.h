#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QToolButton>
#include "syncprojectclass.h"
#include "projectdialog.h"
#include <QMdiSubWindow>
#include "videoform.h"
#include "webcam.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void signalSetProject(SyncProjectClass &);

private slots:
    void on_actionEditProject_triggered();

    void on_actionTest_triggered();

    void on_actionTileWindows_triggered();

    void on_actionCascadeWindows_triggered();

    void on_actionTryFFMPEG_triggered();

    void on_action_CloseProgram_triggered();

    void on_actionOpenProject_triggered();

    void on_actionWebCam_triggered();

private:
    Ui::MainWindow *ui;
    SyncProjectClass *projectInfo;
};

#endif // MAINWINDOW_H
