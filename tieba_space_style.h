#ifndef TIEBA_SPACE_STYLE_H
#define TIEBA_SPACE_STYLE_H

#include <QMainWindow>

namespace Ui {
class tieba_space_style;
}

class tieba_space_style : public QMainWindow
{
    Q_OBJECT

public:
    explicit tieba_space_style(QWidget *parent = 0);
    ~tieba_space_style();
    char * make_space_reg(int space_num);

private slots:
    void switch_button_clicked(void);
    void clear_button_clicked(void);

private:
    Ui::tieba_space_style *ui;
};

#endif // TIEBA_SPACE_STYLE_H
