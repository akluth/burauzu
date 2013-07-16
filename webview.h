#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QWidget>

class QWebView;
class QTabWidget;

class WebView : public QWidget
{
    Q_OBJECT
public:
    explicit WebView(QUrl url, QWidget *parent = 0);
    void navigateToUrl(const QUrl &url);
    
signals:
    
public slots:

private:
    QWebView *m_web;
};

#endif // WEBVIEW_H
