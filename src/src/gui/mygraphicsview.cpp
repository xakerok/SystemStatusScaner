#include "gui/mygraphicsview.h"

#include <QMessageBox>
#include <QList>

#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QPoint>
#include <QGraphicsProxyWidget>
#include <QMessageBox>

MyGraphicsView::MyGraphicsView( QWidget* parent ): QGraphicsView( parent )
{
	scene = new QGraphicsScene( this );
	setScene( scene );

    scene->setSceneRect( 0, 0, 100, 100 );
    setCenter( QPointF( 50,50 ) );
}


void MyGraphicsView::painting( QList <SDataValue*> & lst, int painterType )
{
	points.clear();
	scene->clear();
	QPen pen;
	pen.setColor( QColor::fromRgb( 200, 200, 50 ) );
	scene->addLine( 0, 0, 100, 0, pen );
	scene->addLine( 100, 0, 100, 100, pen );
	scene->addLine( 100, 100, 0, 100, pen );
	scene->addLine( 0, 100, 0, 0, pen );

	if( lst.size() < 2 )return;

	switch( painterType )
	{
	case 0: // cpu-1 by cpu
		{    
			for( int i=1; i<lst.size(); i++ )
			{
            QPoint p( lst.at( i-1 )->usCPU, lst.at( i )->usCPU );
				points.append( p );
			}
         break;
		}
	case 1: // ram-1 by ram
		{    
			for( int i=1; i<lst.size(); i++ )
			{
				QPoint p( lst.at( i-1 )->usRAM, lst.at( i )->usRAM );
				points.append( p );
			}
         break;
		}
	case 2: // cpu by ram
		{    
			for( int i=0; i<lst.size(); i++ )
			{
            QPoint p( lst.at( i )->usCPU, lst.at( i )->usRAM );
				points.append( p );
			}
			break;
		}
	default: { break; }

	}
   
   QPen linePen;
   linePen.setWidthF( 0.5 );
	for( int i=1; i<points.size(); i++)
	{
		scene->addLine( QLine( points[i-1], points[i] ), linePen );
	}
}


void MyGraphicsView::wheelEvent(QWheelEvent* event)
{
	QPointF pointBeforeScale(mapToScene(event->pos()));
	QPointF visibleCenter = center;
	double scaleFactor = 1.1;
	if(event->delta() > 0)
		scale(scaleFactor, scaleFactor);    //  +
	else
		scale(1.0 / scaleFactor, 1.0 / scaleFactor);    //  -
	QPointF pointAfterScale(mapToScene(event->pos()));
	QPointF offset = pointBeforeScale - pointAfterScale;
	QPointF newCenter = visibleCenter + offset;
	setCenter(newCenter);
}

void MyGraphicsView::setCenter(const QPointF &centerPoint)
{
    //Get the rectangle of the visible area in scene coords
    QRectF visibleArea = mapToScene(rect()).boundingRect();
 
    //Get the scene area
    QRectF sceneBounds = sceneRect();
 
    double boundX = visibleArea.width() / 2.0;
    double boundY = visibleArea.height() / 2.0;
    double boundWidth = sceneBounds.width() - 2.0 * boundX;
    double boundHeight = sceneBounds.height() - 2.0 * boundY;
 
    //The max boundary that the centerPoint can be to
    QRectF bounds(boundX, boundY, boundWidth, boundHeight);
 
    if(bounds.contains(centerPoint)) {
        //We are within the bounds
        center = centerPoint;
    } else {
        //We need to clamp or use the center of the screen
        if(visibleArea.contains(sceneBounds)) {
            //Use the center of scene ie. we can see the whole scene
            center = sceneBounds.center();
        } else {
 
            center = centerPoint;
 
            //We need to clamp the center. The centerPoint is too large
            if(centerPoint.x() > bounds.x() + bounds.width()) {
                center.setX(bounds.x() + bounds.width());
            } else if(centerPoint.x() < bounds.x()) {
                center.setX(bounds.x());
            }
 
            if(centerPoint.y() > bounds.y() + bounds.height()) {
                center.setY(bounds.y() + bounds.height());
            } else if(centerPoint.y() < bounds.y()) {
                center.setY(bounds.y());
            }
 
        }
    }
 
    //Update the scrollbars
    centerOn(center);
}

void MyGraphicsView::mousePressEvent(QMouseEvent* event)
{
	fixedPoint = event->pos();
}

void MyGraphicsView::mouseReleaseEvent(QMouseEvent* event)
{
	fixedPoint = event->pos();
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent* event)
{
	if(!fixedPoint.isNull()) {
		QPointF offset = mapToScene(fixedPoint) - mapToScene(event->pos());
		fixedPoint = event->pos();
        setCenter(center + offset);
	}
}

void MyGraphicsView::resizeEvent(QResizeEvent* event)
{
	QRectF visibleArea = mapToScene(rect()).boundingRect();
	setCenter(visibleArea.center());

	QGraphicsView::resizeEvent(event);
}

