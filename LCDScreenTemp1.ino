#include <LiquidCrystal.h>

const int temperaturePin = A0;

float tempMin, tempAverage, tempMax;

int uptime = 0;

// Initialize the display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
    lcd.begin(16, 2);
    lcd.clear();

    lcd.print("Temperature Avg's");
    float startingTemp = convertToCentigrade(getTempVoltage(temperaturePin));
    tempMin = startingTemp;
    tempAverage = startingTemp;
    tempMax = startingTemp;
}

void loop()
{
    // Temperature display
    for (int i = 0; i < 20; i++)
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        float tempCurrent = convertToCentigrade(getTempVoltage(temperaturePin));

        if (tempCurrent < tempMin)
        {
            tempMin = tempCurrent;
        }
        
        if (tempCurrent > tempMax)
        {
            tempMax = tempCurrent;
        }

        tempAverage = (tempAverage + tempCurrent) / 2;
        
        lcd.print(tempMin, 1);
        lcd.print(" ");
        lcd.print(tempAverage, 1);
        lcd.print(" ");
        lcd.print(tempMax, 1);

        lcd.setCursor(0, 1);
        lcd.print("Min   Avg   Max");

        delay(1000);
    }
    
    // Info display
    lcd.clear();
    lcd.print(millis() / 1000);
    lcd.print("s");
    lcd.setCursor(0, 1);
    lcd.print("Uptime");
    delay(2000);
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