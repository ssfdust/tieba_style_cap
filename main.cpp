#include "tieba_space_style.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication tieba_style(argc, argv);
    tieba_space_style window;
    window.show();

    return tieba_style.exec();
}
