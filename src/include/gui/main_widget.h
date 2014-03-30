#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <qmainwindow.h>
#include "ui_main_window_widget.h"

#include "core\data_storage.h"
#include "core/checker.h"

class CMainWindowWidget : public QMainWindow
{
	Q_OBJECT
public:
	CMainWindowWidget( QWidget *parent = 0 );
	~CMainWindowWidget();

   public slots:
      void checkerGreen();
      void checkerYellow();
      void checkerRed();

private:
	Ui::MainWindowWidget ui;

   CDataStorage* m_pDataStorage;
	CChecker* m_pChecker;

};

#endif