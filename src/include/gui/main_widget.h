#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <qmainwindow.h>
#include "ui_main_window_widget.h"

//test core classes for working
#include "core\data_storage.h"
#include "core/checker.h"
#include <qtimer.h>

class CMainWindowWidget : public QMainWindow
{
	Q_OBJECT
public:
	CMainWindowWidget( QWidget *parent = 0 );
	~CMainWindowWidget();

private:
	Ui::MainWindowWidget ui;

   CDataStorage* m_pDataStorage;
	QPointer<CChecker> m_pChecker;


// QTimer* m_pDataTimer;
};

#endif