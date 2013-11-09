#include "gui\main_widget.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CMainWindowWidget w;
	w.show();
	return a.exec();
}
