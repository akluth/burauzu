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

    header = new QWidget(this);
    header->setMinimumSize(200, 50);
    header->setSizePolicy(QSizePolicy::Expanding,
                                 QSizePolicy::Expanding);

    layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    menuBarLayout = new QHBoxLayout;
    menuBarLayout->setSpacing(5);
    header->setLayout(menuBarLayout);

    createActions();
    createMenu();

    layout->addWidget(header);

    webView = new QWebView(this);
    webView->setGeometry(0, 30, 800, 530);
    webView->load(QUrl("http://www.duckduckgo.com"));

    //this->setCentralWidget(webView);
    layout->addWidget(webView);

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
    burauzuMenu = menuBar()->addMenu(tr("&Burauzu"));
    burauzuMenu->addAction(exitAction);
    //menuBar()->addSeparator();

    url = new QLineEdit(this);
    url->setPlaceholderText("URL");
    url->setMaximumWidth(200);
    url->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    url->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);

    menuBarLayout->addWidget(menuBar());
    menuBarLayout->addWidget(url);
}
