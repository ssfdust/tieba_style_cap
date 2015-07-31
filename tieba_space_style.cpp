#include "tieba_space_style.h"
#include "ui_tieba_space_style.h"
#include <string.h>
#include <QStringList>
#include <QChar>
#include <QMessageBox>

tieba_space_style::tieba_space_style(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tieba_space_style)
{
    ui->setupUi(this);
    connect(ui->switch_button,SIGNAL(clicked()), this, SLOT(switch_button_clicked()));
    connect(ui->clear_button,SIGNAL(clicked()), this, SLOT(clear_button_clicked()));
}

tieba_space_style::~tieba_space_style()
{
    delete ui;
}

void tieba_space_style::switch_button_clicked(void)
{
    int base_space_count  = 2;
    int space_count       = 0;
    bool first_meet_space = 0;
    QString line;
    QString switch_text;
    QString text          = ui->textEdit->toPlainText();
    QStringList text_list = text.split(QRegExp("[\r\n]"));

    foreach(line, text_list)
    {
        if (line.startsWith('\t'))
            line.replace(QRegExp("\t"), QChar(0x3000));
        else if (line.startsWith(' ') && first_meet_space == 0)
        {
            first_meet_space = 1;
            while (space_count < line.size() && line.at(space_count) == QChar(0x20) )
                space_count++;
            base_space_count = space_count;
            line.replace(QRegExp(make_space_reg(space_count)), QChar(0x3000));
        }
        else if (line.startsWith(' ') && first_meet_space == 1)
            line.replace(QRegExp(make_space_reg(space_count)), QChar(0x3000));

        switch_text.append(line).append('\n');
    }
    ui->textEdit_2->setText(switch_text);
}

void tieba_space_style::clear_button_clicked(void)
{
    ui->textEdit->setText("");
}

char * tieba_space_style::make_space_reg(int space_num)
{
    char * space = NULL;
    int count;
    space = new char[space_num + 1];

    for(count = 0;count < space_num - 1; count++)
        space[count] = ' ';
    space[space_num-1] = '\0';

    return space;
}
