#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QLabel>
#include "square.h"
#include "circle.h"
#include "graphicssystem.h"
#include "scene.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
private:
    Ui::MainWindow *ui;
    pashazz::GraphicsSystem *sys;
    /* фигуры */
    pashazz::Square *square, *minisquare;
    pashazz::Circle *circle1, *circle2, *circle3;
    pashazz::GraphicsScene *scene;
    QLabel *lCoords;

private slots:
    void updateFirstRadius(double);
    void updateSecondRadius(double);
    void updateThirdRadius(double) {}
    void updateEdge(double) {}
    void updateLabel(double x, double y);
    void showIfInside(double x, double y);
    void rotate(double);

    void setX(double);
    void setY(double);
};

#endif // MAINWINDOW_H
