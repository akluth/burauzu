#ifndef BURAUZU_H
#define BURAUZU_H

#include <QMainWindow>

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
    void on_actionQuit_triggered();

private:
    Ui::Burauzu *ui;
};

#endif // BURAUZU_H
