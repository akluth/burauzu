/*
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
 */
#include "burauzu.h"
#include "webview.h"

#include <QApplication>
#include <QDebug>
#include <QBoxLayout>
#include <QTableWidget>
#include <QStatusBar>
#include <QLineEdit>
#include <QMenuBar>
#include <QWebView>
#include <QUrl>


Burauzu::Burauzu (QWidget *parent)
	: QWidget (parent)
{
	resize (800, 600);

	QVBoxLayout *main = new QVBoxLayout (this);
	QHBoxLayout *header = new QHBoxLayout;

	this->m_menu = new QMenuBar;
	this->m_urlInput = new QLineEdit;
	this->m_statusBar = new QStatusBar;
    this->m_tabs = new QTabWidget;

    this->m_tabs->addTab(createWebViewTab(QUrl("http://blog.fefe.de")), tr("blog.fefe.de"));
    this->m_tabs->show();

    main->addLayout(header);
    main->addWidget(this->m_tabs);
    main->addWidget(this->m_statusBar);
	
    header->addWidget(this->m_menu);
    header->addWidget(this->m_urlInput, 2);

    createMenu();
	 
    setContentsMargins(0, 0, 0, 0);
    main->setMargin(0);
	
    this->m_statusBar->showMessage(tr("Loading done."));
}


Burauzu::~Burauzu()
{
	
}


WebView* Burauzu::createWebViewTab(QUrl url)
{
    webViews.append(new WebView(url));
    return webViews.last();
}


WebView* Burauzu::getCurrentWebViewTab()
{
    qDebug() << "Current tab: " << this->m_tabs->currentIndex();
    return webViews.value(this->m_tabs->currentIndex());
}

void Burauzu::navigateToUserInput()
{
    QString url = this->m_urlInput->text();

    this->m_urlInput->setText(url);

    qDebug() << getCurrentWebViewTab();
    qDebug() << url;

    this->m_statusBar->showMessage("Loading...");
    getCurrentWebViewTab()->navigateToUrl(QUrl::fromUserInput(url));
}


void Burauzu::createMenu()
{
    m_burauzuMenu = m_menu->addMenu(tr("&Burauzu"));
    m_burauzuMenu->addAction(tr("&Exit"), qApp, SLOT(quit()));
	
    m_urlInput->setPlaceholderText(tr("URL"));
	m_urlInput->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
	
    connect(this->m_urlInput, SIGNAL(returnPressed()), SLOT(navigateToUserInput()));
}
