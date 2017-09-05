#ifndef ROTOR_H
#define ROTOR_H

class Rotor
{
      public:
             Rotor(char a[26]);
             int Substitute(int code, int rotorchange);
             int BackSubstitute(int code, int rotorchange);
             int getChange(int i);
             int getBackChange(int i);
      private:
             int change[26];
             int backchange[26];
};
#endif
