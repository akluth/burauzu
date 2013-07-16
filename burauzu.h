#ifndef BURAUZU_H
#define BURAUZU_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QWidgetAction>
#include <QLineEdit>
#include <QWebView>
#include <QUrl>

namespace Ui {
class Burauzu;
}

class Burauzu : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Burauzu(QWidget *parent = 0);
    ~Burauzu();

private slots:
    void exitBurauzu();

private:
    void createActions();
    void createMenu();

private:
    QHBoxLayout *layout;
    QWebView *webView;

private:
    QMenu *burauzuMenu;
    QAction *exitAction;
    QLineEdit *url;
    QWidgetAction *urlBar;
};

#endif // BURAUZU_H
