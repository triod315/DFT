/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_function_plot;
    QAction *actionSave_amplitude_plot;
    QAction *actionExit;
    QWidget *centralWidget;
    QWidget *widget;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButton;
    QCustomPlot *function_plot;
    QCustomPlot *amplitude_plot;
    QCustomPlot *phase_plot;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuPlots;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(883, 547);
        actionSave_function_plot = new QAction(MainWindow);
        actionSave_function_plot->setObjectName(QStringLiteral("actionSave_function_plot"));
        actionSave_amplitude_plot = new QAction(MainWindow);
        actionSave_amplitude_plot->setObjectName(QStringLiteral("actionSave_amplitude_plot"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(490, 10, 381, 181));
        doubleSpinBox = new QDoubleSpinBox(widget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(80, 40, 62, 22));
        doubleSpinBox->setSingleStep(0.5);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 50, 75, 23));
        function_plot = new QCustomPlot(centralWidget);
        function_plot->setObjectName(QStringLiteral("function_plot"));
        function_plot->setGeometry(QRect(10, 10, 421, 221));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(function_plot->sizePolicy().hasHeightForWidth());
        function_plot->setSizePolicy(sizePolicy);
        function_plot->setLayoutDirection(Qt::LeftToRight);
        amplitude_plot = new QCustomPlot(centralWidget);
        amplitude_plot->setObjectName(QStringLiteral("amplitude_plot"));
        amplitude_plot->setGeometry(QRect(10, 250, 421, 231));
        sizePolicy.setHeightForWidth(amplitude_plot->sizePolicy().hasHeightForWidth());
        amplitude_plot->setSizePolicy(sizePolicy);
        amplitude_plot->setLayoutDirection(Qt::LeftToRight);
        phase_plot = new QCustomPlot(centralWidget);
        phase_plot->setObjectName(QStringLiteral("phase_plot"));
        phase_plot->setGeometry(QRect(440, 250, 411, 231));
        sizePolicy.setHeightForWidth(phase_plot->sizePolicy().hasHeightForWidth());
        phase_plot->setSizePolicy(sizePolicy);
        phase_plot->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 883, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuPlots = new QMenu(menuBar);
        menuPlots->setObjectName(QStringLiteral("menuPlots"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuPlots->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuPlots->addAction(actionSave_function_plot);
        menuPlots->addAction(actionSave_amplitude_plot);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionSave_function_plot->setText(QApplication::translate("MainWindow", "Save function plot", Q_NULLPTR));
        actionSave_amplitude_plot->setText(QApplication::translate("MainWindow", "Save amplitude plot", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", Q_NULLPTR));
        actionExit->setShortcut(QApplication::translate("MainWindow", "F4", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "do it", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuPlots->setTitle(QApplication::translate("MainWindow", "Plots", Q_NULLPTR));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
