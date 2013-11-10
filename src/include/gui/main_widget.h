#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <qmainwindow.h>
#include "ui_main_window_widget.h"

//test core classes for working
#include "core\calculator_cpu.h"
#include "core\calculator_ram.h"
#include <qtimer.h>

class CMainWindowWidget : public QMainWindow
{
	Q_OBJECT
public:
	CMainWindowWidget(QWidget *parent = 0);
	~CMainWindowWidget();

private:
	Ui::MainWindowWidget ui;

   CCalculatorCPU* m_pCPUcalc;
   CCalculatorRAM* m_pRAMcalc;
   QTimer* m_pDataTimer;
   Q_SLOT void GetCurrDataValue();
};

#endif // MAIN_WIDGET_H
