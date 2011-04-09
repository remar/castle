#ifndef OBJECT_H
#define OBJECT_H

// An object in the game

class Object
{
 public:
  Object(int sprite);
  virtual ~Object();
  virtual void update();
  void moveAbs(int x, int y);
  void moveRel(int x, int y);
  void setAnimation(int anim);
  void setScroll(int scrollX, int scrollY);
  void setVisible(bool show);
  bool destroy();

  int getX();
  int getY();

 protected:
  int x, y;
  int destroyTimer;
  bool destroyMe;
  int smallSpriteInst;
  int largeSpriteInst;

 private:
  int scrollX, scrollY;

  bool show;
};

#endif
