#define PI 3.1416

float WHEEL_RADIUS = 1.75;
float WHEEL_DIAMETER = 3.5;
float CAR_RADIUS = 7.5;

#define COMPLETE_ROTATION 360
#define HALF_ROTATION 180



sub turn(int angle, int power, int direction ){
  int car_arc = ( angle * PI * CAR_RADIUS )/ HALF_ROTATION; // Measured in centimeter
  int amount_turns =
    ( angle * CAR_RADIUS)/( COMPLETE_ROTATION * WHEEL_RADIUS ) * COMPLETE_ROTATION; // Measured in centimeter

  RotateMotorExPID(OUT_BC, power, amount_turns, 100 * direction,
                    true, true, 40, 40, 90);
}
sub move(int power, int distance){
	int angle = (distance * COMPLETE_ROTATION)/(PI * WHEEL_DIAMETER);
    RotateMotor(OUT_BC, power, angle);
}

sub claw_control(int power){
    RotateMotor(OUT_A, power, 80);
}
