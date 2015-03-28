sub turn(){
    RotateMotorEx(OUT_BC, 75, 360, 100, true, true);
}

sub move(int power, long angle){
    RotateMotor(OUT_BC, power, angle);
}

sub claw_control(int power){
    RotateMotor(OUT_A, power, 80);
}
