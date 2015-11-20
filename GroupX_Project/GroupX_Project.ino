/*
Its a simple ardduino project that counts the number of sears 
occupied out of a total number and light an LED when the seats 
are full. Outputs this count as number of occupied / total number
on the serial monitor

--2 pushbutton on pin 2 & 4 in place of pressure sensors
--Serial monitor instead of LCD display

 created 6 nov 2015 
 by Fatah and groupX team members
 modified 17 Nov 2015
 by Fatah Nur

 This code is public.
 */

// set pin numbers:
//pushbutton pins
const int buttonPin1 = 2; 
const int buttonPin2 = 4;     
//LED pin 
const int ledPin =  13;   
  
// variable for reading the pushbutton status
int x = 0;         
int y = 0;         

void setup() {
  // initialize the LED pin as OUTPUT
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pins as INPUT
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  //initialize communication through Serial monitor
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  x = digitalRead(buttonPin1);
  y = digitalRead(buttonPin2);
  
  //if no pushbuttons are pressed
  if(x == 0 && y == 0)
  {
   //Display 'EMPTY' 
   Serial.println("EMPTY");
  //Don't light the LED
   digitalWrite(ledPin, LOW);  
  }
  //if all pushbuttons are pressed
  if(x == 1 && y == 1)
  {
   //Display 'FULL' 
   Serial.println("FULL");
   //Light the LED
   digitalWrite(ledPin, HIGH); 
  }
  if(x == 1 && y == 0 || x == 0 && y == 1)
  {
   //Display number of pins pressed out of total
   Serial.println("1 / 2");
   //Don't light LED
   digitalWrite(ledPin, LOW);   
  }
}
