#pragma config(Motor,  motor1,          leftMotor,      tmotorVexIQ, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motor6,          rightMotor,     tmotorVexIQ, openLoop, reversed, driveRight, encoder)
#pragma config(Sensor, port9,  			distanceSensor, sensorVexIQ_Distance)
#pragma config(Sensor, port8,           led1,           sensorVexIQ_LED)
#pragma config(Sensor, port11,          led2,           sensorVexIQ_LED)
#pragma config(Sensor, port2,           gyroSensor,     sensorVexIQ_Gyro)
/*------------------------------------------------------------------------------------------------
model robot: images\model01.jpeg
Движение вперед, детектор препятствия, 
	при приближении к препятствию звуковой сигнал, 
	моргание индикаторами и стоп движения
	сообщение на дисплее о препятствии
- перенос индикации в функции
- перенос движения прямо в функции
- поворот на 180 градусов с отображением угла поворота на дисплее, индикация повотрота
- сообщение о завершении поворота на дисплее, выключение индикации
- возвращение обратно до препятствия 
------------------------------------------------------------------------------------------------*/
int speed = 100;  // начальная скорость моторов
int low_speed = 20;
int latency = 200;  // задержка перед проверкой
int distance = 150;  // дистанция сработки изменения движения мм.
int move = true;  // признак движения прямо
int length = 0; // длина движения
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
// движение прямо
void moving ()
{
	while(move)
	{
		if (getDistanceValue(distanceSensor) > distance)  // если расстояние более переменной дистанции
		{
			motorset(speed,speed); // left, right
			sleep(latency);
			displayTextLine(1, "Move forward");
			displayTextLine(3, "Left Motor: %d", getMotorEncoder(leftMotor));
			displayTextLine(4, "Right Motor: %d", getMotorEncoder(rightMotor));
		} else {
			motorset(low_speed,low_speed);
			blinkled(1000, 255,0,0); // вызов функции
			displayTextLine(1, "Barrier Detected");
			displayTextLine(2, "distance Value: %d", getDistanceValue(distanceSensor));
			displayTextLine(3, "Left Motor: %d", getMotorEncoder(leftMotor));
			displayTextLine(4, "Right Motor: %d", getMotorEncoder(rightMotor));
			motorset(0,0);	
			move = false; // global variable
			blinkled(1000,0,255,0); // снова вызов функции
		}
	}
}
//#####################################################################################
// движение обратно
void movingback (int length)
{
	while(move)
	{
		if (getMotorEncoder(rightMotor) < length)  // 
		{
			motorset(speed,speed); // left, right
			sleep(20);
			displayTextLine(1, "Move forward");
			displayTextLine(2, "");
			displayTextLine(3, "Left Motor: %d", getMotorEncoder(leftMotor));
			displayTextLine(4, "Right Motor: %d", getMotorEncoder(rightMotor));
		} else {
			displayTextLine(1, "start point reached");
			displayTextLine(2, "");
			displayTextLine(3, "Left Motor: %d", getMotorEncoder(leftMotor));
			displayTextLine(4, "Right Motor: %d", getMotorEncoder(rightMotor));
			blinkled(1000, 255,0,0); // вызов функции

			motorset(0,0);	
			move = false; // global variable
			blinkled(1000,0,255,0); // снова вызов функции
		}
	}
}
//#####################################################################################

task main()
{
	resetMotorEncoder(leftMotor);	// сброс позиции энкодера в 0
	resetMotorEncoder(rightMotor);	//
	resetGyro(gyroSensor);
	moving();
	playSound(soundTada);
	sleep(1000);
	length = getMotorEncoder(rightMotor); // запонили сколько проехал модуль
	// этап 2 : поворот на 180 
	while(getGyroDegrees(gyroSensor) < 180)
	{
		setTouchLEDColor(led1, colorRed);
		setTouchLEDColor(led2, colorBlue);
		displayTextLine(1, "Rotating");
		displayTextLine(2, "degree Value: %d", getGyroDegrees(gyroSensor));	
		displayTextLine(3, "");
		displayTextLine(4, "");
		motorset(-25,25);
		setTouchLEDRGB(led1, 0, 0, 0);
		setTouchLEDRGB(led2, 0, 0, 0);
	}
	move = true;  // поворот завершен ,можно двигаться прямо
	// поворот завершен
	displayTextLine(1, "done!"); // 
	displayTextLine(2, "");
	setTouchLEDRGB(led1, 0, 0, 0);
	setTouchLEDRGB(led2, 0, 0, 0);
	sleep(1000);
	
	resetMotorEncoder(leftMotor);	// сброс позиции энкодера в 0
	resetMotorEncoder(rightMotor);	//
	movingback(length);
	playSound(soundPowerOff2);
}
