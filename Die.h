#ifndef DIE_H
#define DIE_H

class Die {
  private:
    int mSides;
    int mValue;

  public:
    Die();
    void roll();
    int getValue();
};


#endif
