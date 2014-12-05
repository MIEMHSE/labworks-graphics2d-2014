#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>


namespace pashazz
{
    class GraphicsScene : public QGraphicsScene
    {
    Q_OBJECT
    public:
        GraphicsScene(QObject *parent = 0) : QGraphicsScene(parent)
        {
        }

    signals:
        void mouseMoveSignal(double x, double y);
        void mouseClickSignal(double x, double y);

    protected:
        void mouseMoveEvent(QGraphicsSceneMouseEvent *e)
        {
            emit mouseMoveSignal(e->scenePos().x(), e->scenePos().y());
        }


        void mousePressEvent(QGraphicsSceneMouseEvent *e)
        {
            emit mouseClickSignal(e->scenePos().x(), e->scenePos().y());
        }



    };
}

#endif
