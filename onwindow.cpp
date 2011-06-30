/*
  onwindow.cpp
  
  Copyright (c) 2011, Jeremiah LaRocco jeremiah.larocco@gmail.com

  Permission to use, copy, modify, and/or distribute this software for any
  purpose with or without fee is hereby granted, provided that the above 
  copyright notice and this permission notice appear in all copies. 

  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES 
  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR 
  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES 
  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN 
  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF 
  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/

#include <QtGui>
#include <QSettings>

#include <sstream>
#include <cstdlib>

#include "onwindow.h"

ONWindow::ONWindow() : QMainWindow(), onwid(0) {
  
    std::srand(std::time(0));

    qset = new QSettings(QSettings::IniFormat, QSettings::UserScope,
                         "ONView", "ONView");

    // // Make the QMinefield the central widget
    onwid = new ONWidget(this);
    setCentralWidget(onwid);

    // Initialize GUI stuff
    setWindowTitle(tr("Open Nurbs Viewer"));
    setWindowIcon(QIcon(":/images/icon.png"));

    createActions();
    createMenus();
    
    start_time = 0;
  
    theTimer = new QTimer(this);

    connect(theTimer, SIGNAL(timeout()), this, SLOT(update()));
}

ONWindow::~ONWindow() {
    if (onwid) {
        delete onwid;
    }

    // Delete everything
    delete aboutAction;
    delete aboutQtAction;
    delete quitAction;

    delete fileMenu;
    delete optionsMenu;
    delete helpMenu;
}

/*!
  Initializes all of the QActions used by the game
*/
void ONWindow::createActions() {
    // About
    aboutAction = new QAction(tr("About"), this);
    aboutAction->setIcon(QIcon(":/images/about.png"));
    aboutAction->setShortcut(tr("Ctrl+A"));
    aboutAction->setStatusTip(tr("About On"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));

    // About QT
    aboutQtAction = new QAction(tr("About QT"), this);
    aboutQtAction->setIcon(QIcon(":/images/about.png"));
    aboutQtAction->setStatusTip(tr("About On"));
    connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));

    // Exit
    quitAction = new QAction(tr("Exit"), this);
    quitAction->setIcon(QIcon(":/images/quit.png"));
    quitAction->setShortcut(tr("Ctrl+Q"));
    quitAction->setStatusTip(tr("Quit"));
    connect(quitAction, SIGNAL(triggered()), this, SLOT(close()));//quit()));

    timeAction = new QAction(tr("0"), this);
    timeAction->setStatusTip(tr("Time"));
}

/*!
  Initialize menus
*/
void ONWindow::createMenus() {
    // File menu
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(quitAction);

    // Help menu
    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addSeparator();
    helpMenu->addAction(aboutQtAction);
}

/*!
  Display the about box
*/
void ONWindow::about() {
    QMessageBox::about(this, tr("About On"),
                       tr("<h2>Open Nurbs Viewer</h2>"
                          "<p>Copyright &copy; 2011 Jeremiah LaRocco</p>"
                          "<p>View Rhino .3dm files.</p>"));
}

/*!
  Prompt before closing
*/
void ONWindow::closeEvent(QCloseEvent *event) {
    // if (QMessageBox::warning(this, tr("On"),
    //                          tr("Really quit?"),
    //                          QMessageBox::Yes | QMessageBox::Default,
    //                          QMessageBox::No, QMessageBox::Cancel | QMessageBox::Escape)==QMessageBox::Yes) {
    //     // delete qmf;
    event->accept();
    // } else {
    //     event->ignore();
    // }
}


/*!
  Set the game start time.
*/
void ONWindow::startTimer() {
    start_time = std::time(0);
    theTimer->start(1000);
}

/*!
  Update the timer
*/
void ONWindow::update() {
    // if (start_time) {
    //     std::time_t end_time = std::time(0);
    //     double elapsed = difftime(end_time, start_time);
    
    //     // timeAction->setText(tr("%1").arg(elapsed));
    // } else {
    //     timeAction->setText(tr("0"));
    // }
}
