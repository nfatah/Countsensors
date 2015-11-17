/*
This arduino code is for a project tha won an intel Buildathon 
challenge held in Mombasa city on 5-6/11/2015.

Its a simple ardduino project that counts the number of sears 
occupied out of a total number and light an LED when the seats 
are full.
It also outputs the count as number of occupied / total number
on the serial monitor

because of availability of parts and the short time provided 
by the judges we used:
--2 pushbutton in place of pressure sensors
--Serial monitor instead of LCD display
That simple...we pitched the business concept and WON. Small,
but we are proud!

 created 6 nov 2015 
 by Fatah and groupX team members
 modified 17 Nov 2015
 by Fatah Nur

 This example code is in the public domain.
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
