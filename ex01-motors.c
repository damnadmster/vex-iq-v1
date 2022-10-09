#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor6,          rightMotor,    tmotorVexIQ, openLoop, reversed, driveRight, encoder)
/*------------------------------------------------------------------------------------------------
Движение вперед
------------------------------------------------------------------------------------------------*/
int speed = 100;   // начальная скорость моторов

task main()
{
	while(true)
	{
		setMotorSpeed(leftMotor, speed);  // движение вперед - левый мотор
		setMotorSpeed(rightMotor, speed); // движение вперед - правый мотор
	}
}
