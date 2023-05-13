#pragma config(Motor,  motor1,          leftMotor,      tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor6,          rightMotor,     tmotorVexIQ, openLoop, reversed, driveRight, encoder)
#pragma config(Sensor, port9,  			distanceSensor, sensorVexIQ_Distance)
/*------------------------------------------------------------------------------------------------
Движение вперед, детектор препятствия, при приближении к препятствию звуковой сигнал и стоп движения
model robot: images\model01.jpeg
------------------------------------------------------------------------------------------------*/
int speed = 100;  // начальная скорость моторов
int latency = 200;  // задержка перед проверкой
int distance = 150;  // дистанция сработки изменения движения мм.
int move = true; 

task main()
{
	while(move)
	{
		if (getDistanceValue(distanceSensor) > distance)  // если расстояние более переменной дистанции
		{
			setMotorSpeed(leftMotor, speed);  // движение вперед - левый мотор
			setMotorSpeed(rightMotor, speed); // движение вперед - правый мотор
		} else {
			playSound(soundTada);
			setMotorSpeed(leftMotor, 0);  // движение вперед - левый мотор
			setMotorSpeed(rightMotor, 0); // движение вперед - правый мотор			
			move = false;
		}

		sleep(latency);

	}
}
