#include "window.h"


Window::Window(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle("RSP game");
    this->setFixedSize(350, 150);

    color.setRgb(30, 80, 60);
    background.setColor(backgroundRole(), color);
    this->setPalette(background);

    button = new QPushButton("Choice");
    button->setEnabled(false);

    Labels();
    Radio();
    Layouts();

    connect(button, SIGNAL(clicked(bool)), this, SLOT(ButtonClicked()));

}

Window::~Window()
{

}

void Window::Labels()
{
  QFont *font = new QFont();
  font->setUnderline(true);
  font->setBold(true);

  player = new QLabel();
  player->setText("<font color=red>Player #1</font>");
  player->setFont(*font);

  result = new QLabel("Result: ");
  result->setFrameStyle(QFrame::Box | QFrame::Raised);
  font->setUnderline(false);
  result->setFont(*font);
}

void Window::Radio()
{
    rock = new QRadioButton("Rock");
    scissors = new QRadioButton("Scissors");
    paper = new QRadioButton("Paper");

    connect(rock, SIGNAL(clicked(bool)), button, SLOT(setEnabled(bool)));
    connect(scissors, SIGNAL(clicked(bool)), button, SLOT(setEnabled(bool)));
    connect(paper, SIGNAL(clicked(bool)), button, SLOT(setEnabled(bool)));
}

void Window::Layouts()
{
    QHBoxLayout *titles = new QHBoxLayout;
    QHBoxLayout *content = new QHBoxLayout;
    QVBoxLayout *main_layout = new QVBoxLayout;

    titles->addSpacing(130);
    titles->addWidget(player);

    content->addSpacing(25);
    content->addWidget(rock);
    content->addWidget(scissors);
    content->addWidget(paper);

    main_layout->addLayout(titles);
    main_layout->addLayout(content);
    main_layout->addWidget(button);
    main_layout->addWidget(result);

    this->setLayout(main_layout);
}

void Window::Computer()
{
   srand(std::time(NULL));

   int computer_choice = rand() % 3 + 1;

   switch (computer_choice)
   {
        case 1: {
                    if(computer_choice == player_choice)
                        result->setText(result->text() + "Remise. ");
                    else if(computer_choice && player_choice == 2)
                        result->setText(result->text() + "Lose. ");
                    else if(computer_choice && player_choice == 3)
                        result->setText(result->text() + "Win! ");

                    result->setText(result->text() + "Computer: Rock");
                    break;
                }
        case 2: {
                   if(computer_choice == player_choice)
                       result->setText(result->text() + "Remise. ");
                   else if(computer_choice && player_choice == 3)
                       result->setText(result->text() + "Lose. ");
                   else if(computer_choice && player_choice == 1)
                       result->setText(result->text() + "Win! ");

                   result->setText(result->text() + "Computer: Scissors");
                   break;
               }
       case 3: {
                   if(computer_choice == player_choice)
                       result->setText(result->text() + "Remise. ");
                   else if(computer_choice && player_choice == 1)
                       result->setText(result->text() + "Lose. ");
                   else if(computer_choice && player_choice == 2)
                       result->setText(result->text() + "Win! ");

                   result->setText(result->text() + "Computer: Paper");
                   break;
               }

   }
}

void Window::ButtonClicked()
{
      result->clear();
      if(rock->isChecked()) player_choice = 1;
      else if(scissors->isChecked()) player_choice = 2;
      else if(paper->isChecked()) player_choice = 3;

      Computer();

      color.setRgb(rand() % 250, rand() % 250, rand() % 250);
      background.setColor(this->backgroundRole(), color);
      this->setPalette(background);

}




