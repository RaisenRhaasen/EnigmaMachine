#ifndef POSITION_H
#define POSITION_H
class Position
{
      public:
             Position(char a[]);
             void Step();
             int Pos1();
             int Pos2();
             int Pos3();
             
      private:
              int position1;
              int position2;
              int position3;
};
#endif
