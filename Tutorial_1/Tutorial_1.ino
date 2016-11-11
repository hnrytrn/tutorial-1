
const int pinPotentiometer = 5;
const int pinLed = 13;
const int threshold = 512;

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
	Serial.println("Hello from Tutorial 1!  Lets blink some LEDs");
}

/*
Read over the the following code, and try and figure out what it does.
Put comments beside each piece of logic explaining what it does.
Try to infer the meaning of a particular function from its name.
* Hint: There is only one function called in the main loop: analogRead *

See if you can print out 'potentiometerReading' to your computer screen using
Serial communication.  Look at the line 'Serial.println("Hello..." above for an
example of how to use it.

If you are having trouble, try building the circuit and seeing what it does.
*/
void loop()
{
	int potentiometerReading = analogRead(pinPotentiometer);

	if (potentiometerReading > threshold) {
		digitalWrite(pinLed, HIGH);
	}
	else {
		digitalWrite(pinLed, LOW);
	}
}
