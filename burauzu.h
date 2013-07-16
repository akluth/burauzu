#ifndef BURAUZU_H
#define BURAUZU_H

#include <QWidget>

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
    void navigateToUrl(const QUrl &url);
	
private:
	void createMenu ();

	QWebView *m_web;
	
	QMenuBar *m_menu;
	QMenu *m_burauzuMenu;
	QLineEdit *m_urlInput;
	QStatusBar *m_statusBar;	
};

#endif // BURAUZU_H
