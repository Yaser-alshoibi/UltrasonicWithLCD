#include<LiquidCrystal.h>


const int trigpin=8;
const int echopin=9;
float duration;
float distance;
int red_light_pin= 12;
int green_light_pin = 10;
int blue_light_pin = 11;
LiquidCrystal lcd(3,2,4,5,7,6);
  
void setup()
{
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  lcd.begin(16,2);
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  Serial.begin(9600);
   
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}

void loop()
{
 
    
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
      
  duration = pulseIn(echopin, HIGH);
  distance = (duration*.0343)/2; //Sound travel in speed of 340m/s so speed multiplied with time gives distance
  //Duration is devided by 2 becuase the sensor measure the time for travelling to object and back to sensor again
  
 lcd.setCursor(0,0); 

  Serial.print("Distance: ");
  Serial.println(distance);
  if ( distance > 100 && distance < 250){
    
  delay(3000);
  if ( distance > 100 && distance < 250 )
  {
    
  lcd.print("Hello");
  RGB_color(0, 255, 0); // Green Color
    delay(2000);
    
    }
  }
  
  else if ( distance <= 100 && distance>1 )
  {
    lcd.println("STOP");
    RGB_color(255, 255, 0); // Yellow Color
  }
  
  else {
    lcd.clear();
    RGB_color(0, 0, 0); // Turn OFF

  }
 
    }
  
