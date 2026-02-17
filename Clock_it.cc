#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

const int onButton = 4; //On & Off button :)

unsigned long startTime = 0; //Time at 0 is 0 :D

bool state = false; //Starts off off

void setup() {
  lcd.init();
  lcd.noBacklight(); //Tell the Arduino to "clock it!"

  pinMode(onButton, INPUT_PULLUP); //Defines one pin :)) 
}

void loop() {

  if(digitalRead(onButton) == LOW){
    state = !state; //Flips the state
    lcd.clear(); //Clears the screen

    
    if(state){ //Checks if state is true(1)
      startTime = millis(); //If on, the time will be recorded
      lcd.backlight();
    } else {
      lcd.noBacklight(); //If off, the screen will be off
    }
    delay(500); //Prevents Arduino from going crazy when I press it longer than 1ms :))
  }  

  

  if (state == 1){

    
      //Math logic to calculate seconds, minutes, and hours using modulo
    
      unsigned long currentTime = (millis() - startTime)/1000; //Calculates in seconds, not milliseconds
  
      unsigned long seconds = currentTime % 60; //Remainder after dividing by 60 seconds(1 minute) to see # of seconds
  
      unsigned long minutes = (currentTime % 3600)/60; //Remainder after dividing 3600 seconds(1 hour) to see # of minutes
  
      unsigned long hours = currentTime/3600; //Number of hours (Rounds down)

      //Shows the time itself with the display


    
      //Top row display
      lcd.setCursor(0,0);
      lcd.print(F("Time since set:  "));


      //Bottom row display
      lcd.setCursor(0,1);
      lcd.print(F("H:"));
        if(hours < 10){ //Adds the leading 0 to make the transition from 9 to 10 be improved to 09 to 10
        lcd.print(F("0"));
      }
      lcd.print(hours);
  
      lcd.print(F(" M:"));
        if(minutes < 10){ //Adds leading 0
            lcd.print(F("0"));
          }
      lcd.print(minutes);
  
      lcd.print(F(" S:"));
        if(seconds < 10){ //Adds leading 0
          lcd.print(F("0"));
        }
      lcd.print(seconds);
      lcd.print(F("     ")); //Clears the rest of screen
  }
}

//February 17th, 2026
//This is my first time using the millis function :))
