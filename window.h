#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QLabel>
#include <QRadioButton>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <ctime>

class Window : public QDialog
{
    Q_OBJECT

public:
    Window(QWidget *parent = 0);
    ~Window();
private:
        int player_choice;
private:
        QLabel *player, *result;
        QPushButton *button;
        QRadioButton *rock, *scissors, *paper;
        QColor color;
        QPalette background;

        void Labels();
        void Radio();
        void Layouts();

        void Computer();

private slots:
                void ButtonClicked();

};

#endif // WINDOW_H
