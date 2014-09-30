#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->mdiArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionEditProject_triggered()
{
    ProjectDialog* pD = new ProjectDialog();
    connect(this,SIGNAL(signalSetProject(SyncProjectClass &)),pD,SLOT(slotSetProject(SyncProjectClass &)));
    pD->showNormal();

    emit signalSetProject(*projectInfo);
}


void MainWindow::on_actionTest_triggered()
{
    VideoForm* vfWindow = new VideoForm();
    ui->mdiArea->addSubWindow(vfWindow);
    vfWindow->show();
}

void MainWindow::on_actionTileWindows_triggered()
{
    ui->mdiArea->tileSubWindows();
}

void MainWindow::on_actionCascadeWindows_triggered()
{
    ui->mdiArea->cascadeSubWindows();
}

void MainWindow::on_actionTryFFMPEG_triggered()
{
    SyncProjectClass *nProject = new SyncProjectClass();
    nProject->setDescription("Последний полёт с HD камерой");
    nProject->setLocation("Рязанская область, Спасский район, с.Панино");
    nProject->setDateTime(QDateTime::fromString("2014.08.04","yyyy.MM.dd"));
    nProject->setNavigationFilePath("D:\\noExistingPath\\file.bin");
    Channel_Info testChannel;
    testChannel.name = "TV";
    testChannel.flash = 450;
    testChannel.geometryInfo.rotX = 5;
    testChannel.frame = 808;
    nProject->addChannelToList(testChannel);
    nProject->saveToXmlProjectFile();
}

void MainWindow::on_action_CloseProgram_triggered()
{
    this->close();
}

void MainWindow::on_actionOpenProject_triggered()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this,
        tr("Открыть файл проекта"), "", tr("Image Files (*.xml)"));
    projectInfo = new SyncProjectClass(fileName);
    this->on_actionEditProject_triggered();
}

void MainWindow::on_actionWebCam_triggered()
{
    WebCam* wcForm = new WebCam();
    ui->mdiArea->addSubWindow(wcForm);
    wcForm->show();
}
