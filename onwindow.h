/*
  onwindow.h
  
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

#ifndef ONWINDOW_H
#define ONWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <ctime>

#include "onwidget.h"

class QAction;
class QLabel;
class QIcon;
class QMenu;
class QCloseEvent;
class QSettings;
class QTimer;

class ONWindow : public QMainWindow {
    Q_OBJECT;

public:
    ONWindow();
    ~ONWindow();

private slots:
    void about();
    void startTimer();

    void update();
  
protected:
    // Initialization functions
    void createActions();
    void createMenus();
    void closeEvent(QCloseEvent *event);

private:
    QAction *aboutAction;
    QAction *aboutQtAction;
    QAction *quitAction;
  
    QAction *timeAction;
  
    QMenu *fileMenu;
    QMenu *optionsMenu;
    QMenu *helpMenu;
    QSettings *qset;

    std::time_t start_time;

    QTimer *theTimer;

    ONWidget *onwid;
};

#endif
