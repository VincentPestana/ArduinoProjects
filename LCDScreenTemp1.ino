#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int temperaturePin = A0;

void setup() 
{
    lcd.begin(16, 2);
    lcd.clear();
    float tempCentigrade = convertToCentigrade(getTempVoltage(temperaturePin));
    lcd.print("Start : ");
    lcd.print(tempCentigrade);
    lcd.print("c");
}

void loop()
{
    lcd.setCursor(0, 1);
    float tempCentigrade = convertToCentigrade(getTempVoltage(temperaturePin));
    lcd.print(tempCentigrade);
    lcd.print("c");

    delay(1000);
}

// Function to read and return
//  floating-point value (true voltage)
//  on analog pin 
float getTempVoltage(int pin)
{
	return (analogRead(pin) * 0.004882814);	
	// This equation converts the 0 to 1023 value that analogRead()
	// returns, into a 0.0 to 5.0 value that is the true voltage
	// being read at that pin.
}

float convertToCentigrade(float tempVoltage)
{
    return (tempVoltage - 0.5) * 100.0;
}