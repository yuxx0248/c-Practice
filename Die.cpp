#include <stdlib.h>
#include "Die.h"

// 创建一个骰子，默认有6面， 1 - 6
Die::Die() {
  mSides = 6;
}

// 扔骰子，设置返回值为 1-6 中随机一个
void Die::roll() {
  mValue = rand() % 6 + 1;
}

// 返回上一次扔骰子的返回值
int Die::getValue() {
  return mValue;
}
