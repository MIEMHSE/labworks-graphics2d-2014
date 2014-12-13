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
    connect(ui->boxRad3, valueChangedSignal, this, &MainWindow::updateThirdRadius);
    connect(ui->boxAngle, valueChangedSignal, this, &MainWindow::updateAngle);
    connect(ui->boxX, valueChangedSignal, this, &MainWindow::setX);
    connect(ui->boxY, valueChangedSignal, this, &MainWindow::setY);
    connect(ui->boxSquare, valueChangedSignal, this, &MainWindow::updateEdge);


    /* status bar */
    lCoords = new QLabel(this);
    statusBar()->addPermanentWidget(lCoords);

    /* создать объект CMyObject */
    obj = new CMy2DObjectA2(Point2D(ui->boxX->value(), ui->boxY->value()), ui->boxSquare->value(),
                            ui->boxRad1->value(), ui->boxRad2->value(), ui->boxRad3->value(), ui->boxAngle->value(), ui->gr->backgroundBrush(), Qt::magenta);

    /* отрисовать */
    ui->gr->setScene(obj->GetScene());

    /* Соединить сцену и форму */
    connect(obj->GetScene(), &GraphicsScene::mouseMoveSignal, this, &MainWindow::updateLabel);
    connect(obj->GetScene(), &GraphicsScene::mouseClickSignal, this, &MainWindow::showIfInside);

    /* оживить кнопку вращения */
    rotator.setInterval(100);
    connect(&rotator, &QTimer::timeout, this, &MainWindow::rotateBySmallRad);
    connect(ui->cmdRotate, &QPushButton::clicked, this, &MainWindow::switchRotation);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete lCoords;
    delete obj;
}

void MainWindow::updateFirstRadius(double r)
{
#ifndef NDEBUG
    std::cout << "Radius of the first circle has been updated to " << r << std::endl;
#endif
    obj->SetRadius1(r);
    obj->GetScene()->update();
}

void MainWindow::updateSecondRadius(double r)
{
    obj->SetRadius2(r);
    obj->GetScene()->update();
}

void MainWindow::updateThirdRadius(double r)
{
    obj->SetRadius3(r);
    obj->GetScene()->update();
}

void MainWindow::updateAngle(double a)
{
    obj->SetAngle(a);
    obj->GetScene()->update();
}

void MainWindow::updateLabel(double x, double y)
{
    Point2D rel = Point2D(ui->boxX->value(), ui->boxY->value()).translate(Point2D(x,y)).rotateAxis(ui->boxAngle->value());
    lCoords->setText(tr("abs: (%1, %2) rel: (%3, %4)").arg(x).arg(y).arg(rel.x).arg(rel.y));
}

void MainWindow::updateEdge(double e)
{
    obj->SetEdge(e);
    obj->GetScene()->update();
}

void MainWindow::showIfInside(double x, double y)
{
    if (obj->IsInside({x,y}))
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
    obj->Rotate(angle);
    ui->boxAngle->setValue(obj->GetAngle());
    obj->GetScene()->update();

}

void MainWindow::setX(double x)
{
    obj->SetCentre(Point2D(x, obj->GetCentre().y));
}

void MainWindow::setY(double y)
{
    obj->SetCentre(Point2D(obj->GetCentre().x, y));
}

void MainWindow::switchRotation()
{
    if (rotate_enabled)
    {
     rotator.stop();
     ui->cmdRotate->setText("Вращать");
     rotate_enabled = false;
    }
    else
    {
        rotator.start();
        ui->cmdRotate->setText("Остановить");
        rotate_enabled =  true;
    }

}

void MainWindow::rotateBySmallRad()
{
    rotate(0.01);
}
