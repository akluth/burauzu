#ifndef BURAUZU_H
#define BURAUZU_H

#include "webview.h"
#include <QWidget>

class QMessageLogger;
class QTabWidget;
class QStatusBar;
class QLineEdit;
class QMenuBar;
class QWebView;
class QMenu;
class QUrl;

class Burauzu : public QWidget {
	Q_OBJECT
	
public:
	explicit Burauzu (QWidget *parent = 0);
	~Burauzu ();
	
public slots:
    void navigateToUserInput();
	
private:
    void createMenu();
    WebView* createWebViewTab(QUrl url);
    WebView* getCurrentWebViewTab();

    QList<WebView *> webViews;
	
	QMenuBar *m_menu;
	QMenu *m_burauzuMenu;
	QLineEdit *m_urlInput;
    QStatusBar *m_statusBar;
    QTabWidget *m_tabs;
};

#endif // BURAUZU_H
