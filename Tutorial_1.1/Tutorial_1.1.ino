
const int pinPotentiometer = 5;
const int pinLed = 13;
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
	Serial.println("Hello from Tutorial 1!  Lets blink some LEDs");
}

/*
You noticed with the last tutorial that when we printed to the screen, there were hundreds of values being printed to the screen per second!
We don't want to print all of those values!

What if we printed them at a fixed interval?

Experiment with the code below to print potentiometerReading at:
0.5Hz, 1Hz, 5Hz, 10Hz, 50Hz.

What are the associated periods with these frequencies?
*/
void loop()
{
	int potentiometerReading = analogRead(pinPotentiometer); //creates variable which stores value returned by analogRead function which...you guessed it... reads the analog

	if (potentiometerReading > threshold) { //compares the current analog reading to the threshold defined at the top of the program, insuring that it is greater then said threshold
		digitalWrite(pinLed, HIGH);
	}
	else {
		digitalWrite(pinLed, LOW); 
	}

  Serial.println(potentiometerReading);

	// comment on the lines below explaining what they do.
	timeNow = millis();                       //Time is given in milliseconds
	if (timeNow - timePrev > printPeriod){   //if it has been over 500 milliseconds, then print the result
		if (potentiometerReading==0.5 || potentiometerReading==1 || potentiometerReading== 5 || potentiometerReading==10 || potentiometerReading== 50){
		Serial.print("Potentimeter reading: ");   
		Serial.println(potentiometerReading);  
		
		timePrev = timeNow;  
		}
	}

}
