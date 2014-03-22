#include "gui\main_widget.h"
#include <QtWidgets/QApplication>

//enable console for debug
#ifdef _DEBUG
#pragma comment ( linker, "/subsystem:console" )
#endif

int main( int argc, char **argv )
{
	QApplication app( argc, argv );
	//CMainWindowWidget w;
	//w.show();
	return app.exec();
}
