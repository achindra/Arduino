
//
// Detect motion and generate trigger
//

int pirPin = 13;
int ledPin = 4;

void setup()
{
	pinMode(pirPin, INPUT);
	pinMode(ledPin, OUTPUT);

	Serial.begin(9600);
}

void loop()
{
	if (digitalRead(pirPin) == HIGH)
	{
		digitalWrite(ledPin, HIGH);
		Serial.write("Motion Detected");
	}
	else
	{
		digitalWrite(ledPin, LOW);
	}
	delay(1000);
}
