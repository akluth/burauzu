/**
 *   This file is part of Burauzu (ブラウズ).
 *
 *   Burauzu is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   Burauzu is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Burauzu.  If not, see <http://www.gnu.org/licenses/>.
**/
#include "burauzu.h"

Burauzu::Burauzu(QWidget *parent) :
    QMainWindow(parent)
{
    createActions();
    createMenu();
    this->setGeometry(0, 0, 800, 600);

    webView = new QWebView(this);
    webView->setGeometry(0, 20, 800, 530);
    webView->load(QUrl("http://www.google.de"));

    this->setCentralWidget(webView);
}


Burauzu::~Burauzu()
{
}


void Burauzu::exitBurauzu()
{
    qApp->exit();
}


void Burauzu::createActions()
{
    exitAction = new QAction(tr("Exit"), this);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(exitBurauzu()));
}


void Burauzu::createMenu()
{
    url = new QLineEdit(this);
    urlBar = new QWidgetAction(this);
    urlBar->setDefaultWidget(url);

    burauzuMenu = menuBar()->addMenu(tr("&Burauzu"));
    burauzuMenu->addAction(exitAction);
    menuBar()->addAction(urlBar);
}
