/********************************************************************************
** Form generated from reading UI file 'main_window_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_WIDGET_H
#define UI_MAIN_WINDOW_WIDGET_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "gui/mygraphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowWidget
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tabCalculation;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_Time;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_ComputerName;
    QLineEdit *line_ComputerName;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_OS;
    QLineEdit *line_OS;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_Processor;
    QLineEdit *line_Processor;
    QTextEdit *textEdit;
    QWidget *tabGraph;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter;
    QTreeWidget *treeWidget;
    QTabWidget *tabGraphicsChoise;
    QWidget *tab_cpu;
    QGridLayout *gridLayout_3;
    MyGraphicsView *graphicsView_cpu;
    QWidget *tab_ram;
    QGridLayout *gridLayout_4;
    MyGraphicsView *graphicsView_ram;
    QWidget *tab_cpu_ram;
    QGridLayout *gridLayout_2;
    MyGraphicsView *graphicsView_all;
    QWidget *tabTest;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_2;
    QPushButton *buttonCheck;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowWidget)
    {
        if (MainWindowWidget->objectName().isEmpty())
            MainWindowWidget->setObjectName(QStringLiteral("MainWindowWidget"));
        MainWindowWidget->resize(777, 500);
        centralwidget = new QWidget(MainWindowWidget);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 581, 341));
        tabCalculation = new QWidget();
        tabCalculation->setObjectName(QStringLiteral("tabCalculation"));
        layoutWidget = new QWidget(tabCalculation);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 1, 791, 421));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        label_Time = new QLabel(layoutWidget);
        label_Time->setObjectName(QStringLiteral("label_Time"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(9);
        label_Time->setFont(font);
        label_Time->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_Time);

        dateTimeEdit = new QDateTimeEdit(layoutWidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(10);
        dateTimeEdit->setFont(font1);
        dateTimeEdit->setFrame(false);
        dateTimeEdit->setReadOnly(true);
        dateTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dateTimeEdit->setDateTime(QDateTime(QDate(2013, 1, 1), QTime(0, 0, 0)));
        dateTimeEdit->setDate(QDate(2013, 1, 1));
        dateTimeEdit->setMinimumDateTime(QDateTime(QDate(2012, 1, 1), QTime(0, 0, 0)));
        dateTimeEdit->setMaximumDate(QDate(3012, 12, 31));
        dateTimeEdit->setMinimumDate(QDate(2012, 1, 1));
        dateTimeEdit->setCalendarPopup(false);

        horizontalLayout_7->addWidget(dateTimeEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        label_ComputerName = new QLabel(layoutWidget);
        label_ComputerName->setObjectName(QStringLiteral("label_ComputerName"));
        label_ComputerName->setFont(font);
        label_ComputerName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_ComputerName);


        horizontalLayout_6->addLayout(horizontalLayout_5);

        line_ComputerName = new QLineEdit(layoutWidget);
        line_ComputerName->setObjectName(QStringLiteral("line_ComputerName"));
        line_ComputerName->setFont(font1);
        line_ComputerName->setFrame(false);
        line_ComputerName->setReadOnly(true);

        horizontalLayout_6->addWidget(line_ComputerName);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_OS = new QLabel(layoutWidget);
        label_OS->setObjectName(QStringLiteral("label_OS"));
        label_OS->setFont(font);
        label_OS->setFrameShape(QFrame::NoFrame);
        label_OS->setFrameShadow(QFrame::Plain);
        label_OS->setScaledContents(true);
        label_OS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_OS);


        horizontalLayout_3->addLayout(horizontalLayout);

        line_OS = new QLineEdit(layoutWidget);
        line_OS->setObjectName(QStringLiteral("line_OS"));
        line_OS->setFont(font1);
        line_OS->setFrame(false);
        line_OS->setReadOnly(true);

        horizontalLayout_3->addWidget(line_OS);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_Processor = new QLabel(layoutWidget);
        label_Processor->setObjectName(QStringLiteral("label_Processor"));
        label_Processor->setFont(font);
        label_Processor->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_Processor);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        line_Processor = new QLineEdit(layoutWidget);
        line_Processor->setObjectName(QStringLiteral("line_Processor"));
        line_Processor->setFont(font1);
        line_Processor->setFrame(false);
        line_Processor->setReadOnly(true);

        horizontalLayout_4->addWidget(line_Processor);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        textEdit = new QTextEdit(layoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(false);

        verticalLayout_2->addWidget(textEdit);


        verticalLayout_3->addLayout(verticalLayout_2);

        tabWidget->addTab(tabCalculation, QString());
        tabGraph = new QWidget();
        tabGraph->setObjectName(QStringLiteral("tabGraph"));
        verticalLayoutWidget = new QWidget(tabGraph);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 538, 239));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(verticalLayoutWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setLineWidth(0);
        splitter->setMidLineWidth(1);
        splitter->setOrientation(Qt::Horizontal);
        treeWidget = new QTreeWidget(splitter);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setEnabled(true);
        treeWidget->setMaximumSize(QSize(16777215, 16777215));
        treeWidget->setBaseSize(QSize(0, 0));
        treeWidget->setTextElideMode(Qt::ElideRight);
        splitter->addWidget(treeWidget);
        treeWidget->header()->setCascadingSectionResizes(false);
        treeWidget->header()->setDefaultSectionSize(100);
        treeWidget->header()->setMinimumSectionSize(30);
        tabGraphicsChoise = new QTabWidget(splitter);
        tabGraphicsChoise->setObjectName(QStringLiteral("tabGraphicsChoise"));
        tab_cpu = new QWidget();
        tab_cpu->setObjectName(QStringLiteral("tab_cpu"));
        gridLayout_3 = new QGridLayout(tab_cpu);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        graphicsView_cpu = new MyGraphicsView(tab_cpu);
        graphicsView_cpu->setObjectName(QStringLiteral("graphicsView_cpu"));

        gridLayout_3->addWidget(graphicsView_cpu, 0, 0, 1, 1);

        tabGraphicsChoise->addTab(tab_cpu, QString());
        tab_ram = new QWidget();
        tab_ram->setObjectName(QStringLiteral("tab_ram"));
        gridLayout_4 = new QGridLayout(tab_ram);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        graphicsView_ram = new MyGraphicsView(tab_ram);
        graphicsView_ram->setObjectName(QStringLiteral("graphicsView_ram"));

        gridLayout_4->addWidget(graphicsView_ram, 0, 0, 1, 1);

        tabGraphicsChoise->addTab(tab_ram, QString());
        tab_cpu_ram = new QWidget();
        tab_cpu_ram->setObjectName(QStringLiteral("tab_cpu_ram"));
        gridLayout_2 = new QGridLayout(tab_cpu_ram);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        graphicsView_all = new MyGraphicsView(tab_cpu_ram);
        graphicsView_all->setObjectName(QStringLiteral("graphicsView_all"));

        gridLayout_2->addWidget(graphicsView_all, 0, 0, 1, 1);

        tabGraphicsChoise->addTab(tab_cpu_ram, QString());
        splitter->addWidget(tabGraphicsChoise);

        verticalLayout_4->addWidget(splitter);

        tabWidget->addTab(tabGraph, QString());
        tabTest = new QWidget();
        tabTest->setObjectName(QStringLiteral("tabTest"));
        gridLayout = new QGridLayout(tabTest);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        buttonCheck = new QPushButton(tabTest);
        buttonCheck->setObjectName(QStringLiteral("buttonCheck"));
        buttonCheck->setMinimumSize(QSize(400, 400));
        QFont font2;
        font2.setFamily(QStringLiteral("Comic Sans MS"));
        font2.setPointSize(12);
        buttonCheck->setFont(font2);

        gridLayout->addWidget(buttonCheck, 1, 1, 1, 1);

        tabWidget->addTab(tabTest, QString());
        MainWindowWidget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowWidget);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 777, 21));
        MainWindowWidget->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowWidget);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindowWidget->setStatusBar(statusbar);

        retranslateUi(MainWindowWidget);

        tabWidget->setCurrentIndex(0);
        tabGraphicsChoise->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindowWidget);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowWidget)
    {
        MainWindowWidget->setWindowTitle(QApplication::translate("MainWindowWidget", "SystemStatusScaner", 0));
        label_Time->setText(QApplication::translate("MainWindowWidget", "Current Date/Time: ", 0));
        dateTimeEdit->setDisplayFormat(QApplication::translate("MainWindowWidget", "dd.MM.yyyy hh:mm:ss", 0));
        label_ComputerName->setText(QApplication::translate("MainWindowWidget", "Computer Name: ", 0));
        line_ComputerName->setText(QString());
        label_OS->setText(QApplication::translate("MainWindowWidget", "Operation System: ", 0));
        line_OS->setText(QString());
        label_Processor->setText(QApplication::translate("MainWindowWidget", "Processor: ", 0));
        line_Processor->setText(QString());
        textEdit->setHtml(QApplication::translate("MainWindowWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Made by student of NTU &quot;KhPI&quot; KIT-29m </span><span style=\" font-size:10pt; font-style:italic;\">Movchan Alexande</span><span style=\" font-size:10pt;\">r.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"><br /></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px"
                        ";\"><span style=\" font-size:8pt;\">\320\224\320\260\320\275\320\275\320\260\321\217 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \321\217\320\262\320\273\321\217\320\265\321\202\321\201\321\217 \320\274\320\275\320\276\320\263\320\276\320\277\320\276\321\202\320\276\321\207\320\275\321\213\320\274 \320\270 \320\274\320\275\320\276\320\263\320\276\321\204\321\203\320\275\320\272\321\206\320\270\320\276\320\275\320\260\320\273\321\214\320\275\321\213\320\274 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\320\265\320\274. \320\222 \321\202\320\265\320\272\321\203\321\211\320\265\320\274 \320\262\321\200\320\265\320\274\320\265\320\275\320\270 \320\277\320\276\320\273\321\203\321\207\320\260\320\265\321\202 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\270 \320\276\320\277\320\265\321\200\320\260\321\202\320\270\320\262\320\275\320\276\320\271 \320\277\320\260\320\274\321\217\321\202"
                        "\320\270 \320\270 \320\262\320\270\320\264\320\265\320\276\320\272\320\260\321\200\321\202\321\213 \320\270 \320\277\321\200\320\276\320\262\320\276\320\264\320\270\321\202 \320\260\320\275\320\260\320\273\320\270\320\267 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\321\213\321\205 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271.</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabCalculation), QApplication::translate("MainWindowWidget", "Calculation", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(3, QApplication::translate("MainWindowWidget", "RAM", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("MainWindowWidget", "CPU", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("MainWindowWidget", "Time", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindowWidget", "Number", 0));
        tabGraphicsChoise->setTabText(tabGraphicsChoise->indexOf(tab_cpu), QApplication::translate("MainWindowWidget", "CPU", 0));
        tabGraphicsChoise->setTabText(tabGraphicsChoise->indexOf(tab_ram), QApplication::translate("MainWindowWidget", "RAM", 0));
        tabGraphicsChoise->setTabText(tabGraphicsChoise->indexOf(tab_cpu_ram), QApplication::translate("MainWindowWidget", "CPU / RAM", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabGraph), QApplication::translate("MainWindowWidget", "Graphic", 0));
        buttonCheck->setText(QApplication::translate("MainWindowWidget", "CHECK", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabTest), QApplication::translate("MainWindowWidget", "Test", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindowWidget: public Ui_MainWindowWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_WIDGET_H
