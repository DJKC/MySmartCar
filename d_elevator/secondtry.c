#pragma config(Sensor, dgtl6,  SE,             sensorQuadEncoder)
#pragma config(Sensor, dgtl10, F1,             sensorTouch)
#pragma config(Sensor, dgtl11, F2,             sensorTouch)
#pragma config(Sensor, dgtl12, F3,             sensorTouch)
#pragma config(Sensor, dgtl5,  FF,         sensorTouch)
#pragma config(Sensor, dgtl4,  FU2,         sensorTouch)
#pragma config(Sensor, dgtl3,  FD2,         sensorTouch)
#pragma config(Sensor, dgtl2,  TF,         sensorTouch)
#pragma config(Motor,  port9,           rMotor,        tmotorServoContinuousRotation, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void down(int distance);
void up(int distance);
//void queue(int qu, int qd);
task queue(){
	int f1=0, f2=720, f3=1440;
	//int qu[10], qd[10];
	int cFloor=0;
	int distance=0;
	do{
			SensorValue(SE)=0;
		if(SensorValue(F1)==1){
			distance=f1-cFloor;
	    down(distance);
	    cFloor=f1;
		}
		if(SensorValue(F2)==1){
			distance=f2-cFloor;
			if(distance<0)
				down(distance);
			else
				up(distance);
			cFloor=f2;
		}
		if(SensorValue(F3)==1){
			distance=f3-cFloor;
			up(distance);
			cFloor=f3;
		}
		if(SensorValue(FF)==1){
			distance=f1-cFloor;
	    down(distance);
	    cFloor=f1;
		}
		if(SensorValue(FU2)==1||SensorValue(FD2)==1){
			distance=f2-cFloor;
			if(distance<0)
				down(distance);
			else
				up(distance);
			cFloor=f2;
		}
		if(SensorValue(TF)==1){
			distance=f3-cFloor;
			up(distance);
			cFloor=f3;
		}
	}while(true);

}

task main()
{
	int f1=0, f2=720, f3=1440;
	//int qu[10], qd[10];
	int cFloor=0;
	int distance=0;
	do{
			SensorValue(SE)=0;
		if(SensorValue(F1)==1){
			distance=f1-cFloor;
	    down(distance);
	    cFloor=f1;
		}
		if(SensorValue(F2)==1){
			distance=f2-cFloor;
			if(distance<0)
				down(distance);
			else
				up(distance);
			cFloor=f2;
		}
		if(SensorValue(F3)==1){
			distance=f3-cFloor;
			up(distance);
			cFloor=f3;
		}
		if(SensorValue(FF)==1){
			distance=f1-cFloor;
	    down(distance);
	    cFloor=f1;
		}
		if(SensorValue(FU2)==1||SensorValue(FD2)==1){
			distance=f2-cFloor;
			if(distance<0)
				down(distance);
			else
				up(distance);
			cFloor=f2;
		}
		if(SensorValue(TF)==1){
			distance=f3-cFloor;
			up(distance);
			cFloor=f3;
		}
	}while(true);
}



void up(int distance){
	while(-SensorValue(SE)<distance){
		motor[rMotor]=-63;
		//queue(qu, qd);
	}
	motor[rMotor]=0;
}

void down(int distance){
	while(-SensorValue(SE)>distance){
		motor[rMotor]=63;
		//queue(qu,qd);
	}
	motor[rMotor]=0;
}