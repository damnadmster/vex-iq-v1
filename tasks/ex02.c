#pragma config(StandardModel, "Clawbot IQ With Sensors")
//*push - stop - backward a bitly - return - move        !!*//

task main()
{
while (getTouchLEDValue(touchLED) == 0)
	{}
playSound(soundAirWrench);
repeat (forever)
{
	if(getBumperValue(bumpSwitch) == 0)
	{
		setMotorSpeed(leftMotor, 127);
		setMotorSpeed(rightMotor, 127);
		sleep(20);
	} else
	{
		setMotorSpeed(leftMotor, -127);
		setMotorSpeed(rightMotor, -127);
		sleep(500);
		setMotorSpeed(leftMotor, 127);
		setMotorSpeed(rightMotor, 0);
		sleep(1500);
		}
	}
}
