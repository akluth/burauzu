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
#include "webview.h"

WebView::WebView(QString url, QWidget *parent) :
    QWidget(parent)
{
    this->m_web = new QWebView;
    this->m_web->load(url);
}


void WebView::navigateToUrl(const QUrl &url)
{


    this->m_web->load(url);
}
