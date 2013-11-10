#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <qmainwindow.h>
#include "ui_main_window_widget.h"

class CMainWindowWidget : public QMainWindow
{
	Q_OBJECT
public:
	CMainWindowWidget(QWidget *parent = 0);
	~CMainWindowWidget();

private:
	Ui::MainWindowWidget ui;
};

#endif // MAIN_WIDGET_H
