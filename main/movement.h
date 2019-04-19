#include <L298N.h>
L298N motorDx(ENA, IN1, IN2);
L298N motorSx(ENB, IN3, IN4);
void move_robot(unsigned short dx, unsigned short sx) { //speed value from 0 to 100
  dx=map(dx, 0, 100, 0, 255);
  sx=map(sx, 0, 100, 0, 255);
  //dx
  if(dx>0){
    motorDx.setSpeed(dx);
    motorDx.forward();
  } else if(dx==0){
    motorDx.stop();
  } else if(dx<0){
    motorDx.setSpeed((dx*-1));
    motorDx.backward();
  }
  //sx
  if(sx>0){
    motorSx.setSpeed(sx);
    motorSx.forward();
  } else if(sx==0){
    motorSx.stop();
  } else if(sx<0){
    motorSx.setSpeed((sx*-1));
    motorSx.backward();
  }
}
