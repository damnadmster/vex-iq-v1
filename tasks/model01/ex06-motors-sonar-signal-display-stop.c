#pragma config(Motor,  motor1,          leftMotor,      tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor6,          rightMotor,     tmotorVexIQ, openLoop, reversed, driveRight, encoder)
#pragma config(Sensor, port9,  			distanceSensor, sensorVexIQ_Distance)
#pragma config(Sensor, port8,           led1,           sensorVexIQ_LED)
#pragma config(Sensor, port11,          led2,           sensorVexIQ_LED)
/*------------------------------------------------------------------------------------------------
Движение вперед, детектор препятствия, при приближении к препятствию звуковой сигнал, моргание индикаторами и стоп движения
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
			setMotorSpeed(leftMotor,  20);  // медленное движение вперед - левый мотор
			setMotorSpeed(rightMotor, 20); // медленное 	движение вперед - правый мотор	
			setTouchLEDColor(led1, colorRed);
			setTouchLEDColor(led2, colorRed);
			setTouchLEDBlinkTime(led1, 4, 1); // моргание, в десятых секунды 0,4 сек вкл; 0,1 сек. выкл
			setTouchLEDBlinkTime(led2, 4, 1);
			sleep(1000);
			setTouchLEDRGB(led1, 0, 0, 0);
			setTouchLEDRGB(led2, 0, 0, 0);
			displayTextLine(1, "Barrier Detected");
			displayTextLine(2, "distance Value: %d", getDistanceValue(distanceSensor));
			playSound(soundTada);
		
			setMotorSpeed(leftMotor, 0);  // движение вперед - левый мотор
			setMotorSpeed(rightMotor, 0); // движение вперед - правый мотор			
			move = false;
		}

		sleep(latency);

	}
}
