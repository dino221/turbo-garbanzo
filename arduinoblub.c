#include <math.h>
int pinOut = 10;

double Thermistor(int RawADC) {
	double Temp;
	Temp = log(10000.0*((1024.0/RawADC-1))); //Ako se koristi 100 Kohm thermistor, potrebno je izmjeniti liniju 7 u kodu,
						// Temp = log(100000.0*((1024.0/RawADC-1)));
	Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp )) * Temp );
	Temp = Temp - 273.15;
	return Temp;
}

void setup() {
	Serial.begin(9600);
	pinMode(10, OUTPUT),
}

void loop() {
	int val;
	double temp;
	val = analogRead(0);
	temp = Thermistor(val);
	Serial.print("Temperature= ");
	Serial.print(temp);
	Serial.println(" *C");

		if (temp >= 60) {
			digitalWrite(pinOut, LOW);
		}
		else {
			digitalWrite(pinOut, HIGH);
		}
	delay(500);
}
