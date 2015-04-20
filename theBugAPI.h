#define PI 3.1416

#define WHEEL_RADIUS 2.16
#define WHEEL_DIAMETER 4.32
#define CAR_RADIUS 6.65


#define RIGHT -1
#define LEFT 1

#define FOWARD 1
#define BACKWARD -1

#define POWER_NORMAL 75
#define POWER_LOW 50
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
    RotateMotor(OUT_BC, power, angle);
}

sub claw_control(int angle, int power, int direction){
  int car_arc = ( angle * PI * CAR_RADIUS )/ HALF_ROTATION; // Measured in centimeter
  int amount_turns = (HALF_ROTATION * car_arc) /(PI * WHEEL_RADIUS); // Measured in centimeter

  RotateMotorExPID(OUT_B, power, amount_turns, 100 * direction,
                    true, true, 40, 40, 90);
}
