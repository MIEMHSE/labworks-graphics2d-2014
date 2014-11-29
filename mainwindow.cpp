#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abstractshape.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //quit action
    connect(ui->action_Quit, &QAction::triggered, qApp, &QApplication::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}
