#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abstractshape.h"
#include "graphicssystem.h"
#include "circle.h"
#include "square.h"
#include "cmyobject.h"

#include <QStatusBar>


using namespace pashazz;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gr->setMouseTracking(true); //Следить за перемещениями мыши
    ui->gr->scale(1, -1); //Установить ось ординат вверх

    /* установить связь между GUI и кодом */
    connect(ui->action_Quit, &QAction::triggered, qApp, &QApplication::quit);

    /* нам нужен сигнал с аргументом double */
    /// https://isocpp.org/wiki/faq/pointers-to-members

    void (QDoubleSpinBox:: *valueChangedSignal)(double) = &QDoubleSpinBox::valueChanged;
    connect(ui->boxRad1, valueChangedSignal, this, &MainWindow::updateFirstRadius);
    connect(ui->boxRad2, valueChangedSignal, this, &MainWindow::updateSecondRadius);
    connect(ui->boxAngle, valueChangedSignal, this, &MainWindow::rotate);
    connect(ui->boxX, valueChangedSignal, this, &MainWindow::setX);
    connect(ui->boxY, valueChangedSignal, this, &MainWindow::setY);


    /* status bar */
    lCoords = new QLabel(this);
    statusBar()->addPermanentWidget(lCoords);

    /* создать объект CMyObject */



}

MainWindow::~MainWindow()
{
    delete ui;
    delete sys;
    delete circle1, circle2, circle3;
    delete scene;
    delete lCoords;
}

void MainWindow::updateFirstRadius(double r)
{
#ifndef NDEBUG
    std::cout << "Radius of the first circle has been updated to " << r << std::endl;
#endif
    circle1->setRadius(r);
    scene->update();
}

void MainWindow::updateSecondRadius(double r)
{
    circle2->setRadius(r);
    scene->update();
}

void MainWindow::updateLabel(double x, double y)
{
    Point2D rel = Point2D(ui->boxX->value(), ui->boxY->value()).translate(Point2D(x,y)).rotateAxis(ui->boxAngle->value());
    lCoords->setText(tr("abs: (%1, %2) rel: (%3, %4)").arg(x).arg(y).arg(rel.x).arg(rel.y));
}

void MainWindow::showIfInside(double x, double y)
{
    if (sys->isInside({x,y}))
    {
        statusBar()->showMessage(tr("Point (%1, %2) внутри объекта").arg(x).arg(y));
    }
    else
    {
        statusBar()->showMessage(tr("Point (%1, %2) снаружи объекта").arg(x).arg(y));
    }
}

void MainWindow::rotate(double angle)
{
    sys->setAngle(angle);
    scene->update();

}

void MainWindow::setX(double x)
{
    sys->setCentre({x, sys->centre().y});
}

void MainWindow::setY(double y)
{
    sys->setCentre({sys->centre().x, y});
}
