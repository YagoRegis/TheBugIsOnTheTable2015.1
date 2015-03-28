#define PI 3.1416

#define WHEEL_DIAMETER 4.32


sub turn(){
    RotateMotorEx(OUT_BC, 75, 360, 100, true, true);
}

sub move(int power, int distance){
	int angle = (distance/(PI*WHEEL_DIAMETER))*360;
    RotateMotor(OUT_BC, power, angle);
}

sub claw_control(int power){
    RotateMotor(OUT_A, power, 80);
}
