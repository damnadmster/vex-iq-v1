#pragma config(Motor,  motor1,          leftMotor,      tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor6,          rightMotor,     tmotorVexIQ, openLoop, reversed, driveRight, encoder)
#pragma config(Sensor, port9,  			distanceSensor, sensorVexIQ_Distance)
#pragma config(Sensor, port8,           led1,           sensorVexIQ_LED)
#pragma config(Sensor, port11,          led2,           sensorVexIQ_LED)
/*------------------------------------------------------------------------------------------------
Движение вперед, детектор препятствия, при приближении к препятствию звуковой сигнал, моргание индикаторами и стоп движения
model robot: images\model01.jpeg
Движение вперед, детектор препятствия, 
	при приближении к препятствию звуковой сигнал, 
	моргание индикаторами и стоп движения
	сообщение на дисплее о препятствии
- перенос индикации в функции
- перенос движения прямо в функции
------------------------------------------------------------------------------------------------*/
int speed = 100;  // начальная скорость моторов
int low_speed = 20;
int latency = 200;  // задержка перед проверкой
int distance = 150;  // дистанция сработки изменения движения мм.
int move = true;  // признак движения прямо
//#####################################################################################
// моргание диодами
void blinkled( int sleeptime, int r, int g, int b)
{
	setTouchLEDRGB(led1, r, g, b);
	setTouchLEDRGB(led2, r, g, b);
	setTouchLEDBlinkTime(led1, 4, 1); // моргание, в десятых секунды 0,4 сек вкл; 0,1 сек. выкл
	setTouchLEDBlinkTime(led2, 4, 1);
	sleep(sleeptime);
	setTouchLEDRGB(led1, 0, 0, 0);
	setTouchLEDRGB(led2, 0, 0, 0);
}
//#####################################################################################
// вращение моторов
void motorset ( int lmotor, int rmotor)
{
	setMotorSpeed(leftMotor, lmotor);  // движение вперед - левый мотор
	setMotorSpeed(rightMotor, rmotor); // движение вперед - правый мотор
}

//#####################################################################################

task main()
{
	while(move)
	{
		if (getDistanceValue(distanceSensor) > distance)  // если расстояние более переменной дистанции
		{
			motorset(speed,speed);
		} else {
			motorset(low_speed,low_speed);
			blinkled(1000, 255,0,0); // вызов функции
			displayTextLine(1, "Barrier Detected");
			displayTextLine(2, "distance Value: %d", getDistanceValue(distanceSensor));
			playSound(soundTada);
			motorset(0,0);	
			move = false;
			blinkled(1000,0,255,0); // снова вызов функции
		}

		sleep(latency);

	}
}
