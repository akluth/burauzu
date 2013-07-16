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
    this->setGeometry(0, 0, 800, 600);

    main = new QVBoxLayout(this);

    header = new QHBoxLayout;

    menu = new QMenuBar(this);
    web = new QWebView(this);
    url = new QLineEdit(this);

    main->addLayout(header);
    main->addWidget(web);

    header->addWidget(menu);
    header->addWidget(url, 2);

    createActions();
    createMenu();
    this->setMenuBar(menu);

    web->load(QUrl("http://www.duckduckgo.com"));

    this->setContentsMargins(0, 0, 0, 0);
    main->setMargin(0);

    statusBar()->showMessage(tr("Loading done."));
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
    burauzuMenu = menu->addMenu(tr("&Burauzu"));
    burauzuMenu->addAction(exitAction);
    //menuBar()->addSeparator();

    url->setPlaceholderText("URL");
    //url->setMaximumWidth(200);
    url->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    url->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
}
