#pragma config(Sensor, port2,  bumpSwitch,     sensorVexIQ_Touch)
#pragma config(Sensor, port7,  distanceSensor, sensorVexIQ_Distance)
#pragma config(Sensor, port8,  gyroSensor,     sensorVexIQ_Gyro)
#pragma config(Sensor, port10, led1,           sensorVexIQ_LED)
#pragma config(Sensor, port11, led2,           sensorVexIQ_LED)
#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor6,          rightMotor,    tmotorVexIQ, openLoop, reversed, driveRight, encoder)

/*------------------------------------------------------------------------------------------------

движение вперед - препятствие - разворот 180 - движение назад - препятствие - стоп

------------------------------------------------------------------------------------------------*/
int speed = 100;
int returns  = false;
int latency = 1000;
task main()
{
	resetGyro(gyroSensor);
	//While distance sensor is more than 100mm (10cm) away
	while (!returns )
	{
		if (getDistanceValue(distanceSensor) > 100)
		{
			speed = 100;
			setTouchLEDColor(led1, colorGreen);
			setTouchLEDColor(led2, colorGreen);
			latency = 1000;
			} else {
			setTouchLEDColor(led1, colorBlueGreen);
			setTouchLEDColor(led2, colorBlueGreen);
			speed = 10;
			latency = 200;
		}

		setMotorSpeed(leftMotor, speed);
		setMotorSpeed(rightMotor, speed);

		sleep(latency);
		if (getBumperValue(bumpSwitch) == 1) returns = true;
	}

	while(getGyroDegrees(gyroSensor) < 180)
	{
		setTouchLEDColor(led1, colorRed);
		setTouchLEDColor(led2, colorBlue);

		setMotorSpeed(leftMotor, -25);
		setMotorSpeed(rightMotor, 25);
	}
	while(true)
	{
		if (getDistanceValue(distanceSensor) > 100)
		{  speed = 100;
			setTouchLEDColor(led1, colorGreen);
			setTouchLEDColor(led2, colorGreen);
			latency = 1000; }
		else {
			setTouchLEDColor(led1, colorBlueGreen);
			setTouchLEDColor(led2, colorBlueGreen);
			speed = 10;
			latency = 200; }

		setMotorSpeed(leftMotor, speed);
		setMotorSpeed(rightMotor, speed);
		if (getBumperValue(bumpSwitch) == 1)
		{
			setTouchLEDColor(led1, colorYellow);
			setTouchLEDBlinkTime(led1, 40, 2);
			setTouchLEDRGB(led2, 0, 0, 0);
			sleep(1000);
			break;
		}
	}
}
