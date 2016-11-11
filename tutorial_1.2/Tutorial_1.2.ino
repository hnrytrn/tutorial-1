
// here we use pre-defined values to set the value to each variable.
// On the Arduino Uno and Nano, A5 matches analog pin 5.
const int pinPotentiometer = A5;

const int pinLed = 11;

const int threshold = 512;

const int printPeriod = 500;

unsigned long timeNow = 0;
unsigned long timePrev = 0;

/* Every sketch must start with a call to 'setup()' and 'loop()'*/
void setup()
{
	// Before using the Serial stream from the Arduino, we must set
	// a baud rate for it.  The baud rate is the number is bits per second
	// sent to and from the arduino.  The device or computer on the other end
	// must also be set to using the same baud rate.
	// Think of it as having different internet speeds -- setting a higher baud rate will give
	// you faster transmission of data.
	Serial.begin(9600);

	// In order to drive an LED with a pin, we must set that pin to "output" mode.
	// This allows up to 40mA of current to flow either in or out of the pin
	// (acting as source, or ground, respectively)
	// A typical LED will use at most 20mA of current when fully lit, so we are safe.
	// In a later tutorial we will talk about how to drive high current loads, like a 
	// light bulb, or a toaster.
	pinMode(pinLed, OUTPUT);

	// To turn the pin 'on' and 'off', we set it to HIGH or LOW, respectively.
	// This will turn on or off the LED.
	// Note this is dependent on how you wire the LED.
	digitalWrite(pinLed, LOW);

	// This is how we can print a line to the PC Serial window.  Use '.print()'
	// to print on the same line.
	Serial.println("Hello from Tutorial 1.2!  Lets dim an LED!");
}

/*
Build the circuit for Tutorial 1.2 and test out the code.
We will talk about how the led fades in and out with relation to how far you
turn the potentiometer on another tutorial.

How do you think 'analogWrite' is changing the brightness of the LED?
Feel free to throw out random guesses at this point.
*/
void loop()
{
	int potentiometerReading = analogRead(pinPotentiometer);

	analogWrite(pinLed, potentiometerReading);

	timeNow = millis();
	if (timeNow - timePrev > printPeriod) {
		Serial.print("Potentimeter reading: ");
		Serial.println(potentiometerReading);
		timePrev = timeNow;
	}
}
