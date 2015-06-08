

#define WHEEL_RADIUS 2.16
#define WHEEL_DIAMETER 4.32
#define CAR_RADIUS 6.65


#define RIGHT -1
#define LEFT 1

#define FORWARD 1
#define BACKWARD -1

#define POWER_NORMAL 75
#define POWER_LOW 50
#define POWER_VERY_LOW 25
#define POWER_HIGH 100

#define COMPLETE_ROTATION 360
#define HALF_ROTATION 180



sub turn(int angle, int power, int direction ){
  int car_arc = ( angle * PI * CAR_RADIUS )/ HALF_ROTATION; // Measured in centimeter
  int amount_turns = (HALF_ROTATION * car_arc) /(PI * WHEEL_RADIUS); // Measured in centimeter

  RotateMotorExPID(OUT_BC, power, amount_turns, 100 * direction,
                    true, true, 40, 40, 90);
}
sub move(int distance, int power, int direction){
  int angle = (distance * COMPLETE_ROTATION * direction)/(PI * WHEEL_DIAMETER);
  RotateMotorEx(OUT_BC, power, angle, 0, true, true);
}

sub claw_control(int angle, int power, int direction){
  RotateMotor(OUT_A, power, angle * direction);
}
