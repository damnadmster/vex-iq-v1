#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor6,          rightMotor,    tmotorVexIQ, openLoop, reversed, driveRight, encoder)
#pragma config(Sensor, port7,  distanceSensor, sensorVexIQ_Distance)
#pragma config(Sensor, port2,  bumpSwitch,     sensorVexIQ_Touch)
/*------------------------------------------------------------------------------------------------
Движение вперед , остановка при столкновении с препятствием
------------------------------------------------------------------------------------------------*/
int speed = 100;  // начальная скорость моторов
int latency = 1000;  // задержка перед проверкой
int distance = 100;  // дистанция сработки изменения движения
int must_stop  = false;
task main()
{
	while(!must_stop)
	{
		if (getDistanceValue(distanceSensor) > distance)
		{
			speed = 100;
			latency = 1000;
			} else {
			speed = 10;
			latency = 200;
		}

		sleep(latency);
		setMotorSpeed(leftMotor, speed);  // движение вперед - левый мотор
		setMotorSpeed(rightMotor, speed); // движение вперед - правый мотор

		if (getBumperValue(bumpSwitch) == 1) must_stop = true; // наткнулись на препятствие - СТОП
	}
}
