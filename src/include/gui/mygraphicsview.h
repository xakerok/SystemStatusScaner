#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>

#include <QList>
#include <core\data_storage.h>

class MyGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    MyGraphicsView( QWidget *parent = 0 );
    void painting( QList <SDataValue*> value, int painterType );

    enum TypePainter {
       CPUTypePainter = 0,
       RAMTypePainter,
       ALLTypePainter
    };


protected:

    void setCenter(const QPointF& centerPoint);

    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void wheelEvent(QWheelEvent* event);
    virtual void resizeEvent(QResizeEvent* event);

private:
    QGraphicsScene* scene;

    QPointF center;
    QPoint fixedPoint;
	 QList<QPoint>points;

};

#endif
