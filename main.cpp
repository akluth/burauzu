#include "burauzu.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Burauzu w;
    w.show();
    
    return a.exec();
}
