#ifndef BURAUZU_H
#define BURAUZU_H

#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStatusBar>
#include <QMenuBar>
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
    QHBoxLayout *header;
    QVBoxLayout *main;
    QWebView *web;

private:
    QMenuBar *menu;
    QMenu *burauzuMenu;
    QAction *exitAction;
    QLineEdit *url;
    QWidgetAction *urlBar;
};

#endif // BURAUZU_H
