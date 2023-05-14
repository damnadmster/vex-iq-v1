#pragma config(Motor,  motor1,          leftMotor,     tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor6,          rightMotor,    tmotorVexIQ, openLoop, reversed, driveRight, encoder)
#pragma config(Sensor, port9,  distanceSensor, sensorVexIQ_Distance)
/*------------------------------------------------------------------------------------------------
Движение вперед, детектор препятствия, изменение скорости при приближении к препятствию
model robot: images\model01.jpeg
- Движение вперед
- замеделение движения при наличии препятствия 
------------------------------------------------------------------------------------------------*/
int speed = 100;  // начальная скорость моторов
int latency = 1000;  // задержка перед проверкой
int distance = 100;  // дистанция сработки изменения движения

task main()
{
	while(true)
	{
		if (getDistanceValue(distanceSensor) > distance)  // если расстояние более переменной дистанции
		{
			speed = 100;  // держим скорость
			latency = 200; // периодичность измерения
			} else {
			speed = 10;  //замедляемся
			latency = 100; // чаще проверка
		}

		sleep(latency);
		setMotorSpeed(leftMotor, speed);  // движение вперед - левый мотор
		setMotorSpeed(rightMotor, speed); // движение вперед - правый мотор
	}
}
