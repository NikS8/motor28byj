/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
                                                                motor28byj.ino
                                              Copyright © 2019, Zigfred & Nik.S
05.03.2019 v1
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*****************************************************************************\
Motor 28BYJ-48 5v driver ULM2003A
/*****************************************************************************/
#include <CustomStepper.h>            // Подключаем библиотеку CustomStepper
CustomStepper stepper(2, 3, 4, 5);    // Подключен драйвер шагового двигателя
boolean rotate1 = false;              // Переменная для смены режимов
boolean rotatedeg = false;            // Переменная для смены режимов
boolean crotate = false;              // Переменная для смены режимов                 

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            setup
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void setup()
{
  stepper.setRPM(8);   // Устанавливаем количество оборотов в минуту
  stepper.setSPR(4075); // Устанавливаем колочество шагов на полный оборот. 
                        // Максимальное значение 4075.7728395
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            loop
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
void loop()
{
  if (stepper.isDone() &&  rotate1 == false)  
  {
    stepper.setDirection(CCW);  // Направление вращения (по часовой)
    stepper.rotate(5);          // Вращение на заданное количество оборотов
    rotate1 = true;
  }
  if (stepper.isDone() && rotate1 == true && rotatedeg == false)
  {
    stepper.setDirection(CW);   // Направление вращения (против часовой)
    stepper.rotateDegrees(180); // Поворачивает вал на заданное кол-во градусов
    rotatedeg = true;
  }
  if (stepper.isDone() && rotatedeg == true && crotate == false)
  {
    stepper.setDirection(CCW);  // Направление вращения (по часовой)
    stepper.rotate();           // Будет вращать пока не получит команду 
                                //  о смене направления или STOP
    crotate = true;
  }
  stepper.run();  //  Этот метод обязателен в блоке loop. 
                  //  Он инициирует работу двигателя, когда это необходимо
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*\
            end
\*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/