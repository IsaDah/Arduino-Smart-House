#include <Servo.h> //Includes servo motor library
char data = 0; //Variable data of type char we will recieve these characters from android device


Servo myservo; //declaring a servo motor
int pos; //default position of lock
int led = 13; //attaching red led for locked position on pin 13
int led2 = 12; //attaching green led for unlocked position on pin 12

int led3 = 7; //attaching lighting of room1 to digital pin 7
int led4 = 4; //attaching lighting of room2 to digital pin 4
int led5 = 8; //attaching lighting of room3 to digital pin 8
int led6 = 2; //attaching lighting of room4 to digital pin 2


void setup() 
{
myservo.attach(9); //attaching servo motor to pin 9
Serial.begin(9600); //Sets the data rate in bits per second (baud) for serial data transmission.
pinMode(led, OUTPUT); //The code makes the digital pin 13 OUTPUT and Togles it HIGH and LOW.
pinMode(led2, OUTPUT); //The code makes the digital pin 12 OUTPUT and Togles it HIGH and LOW.
pinMode(led3, OUTPUT); //The code makes the digital pin 7 OUTPUT and Togles it HIGH and LOW.
pinMode(led4, OUTPUT); //The code makes the digital pin 4 OUTPUT and Togles it HIGH and LOW.
pinMode(led5, OUTPUT); //The code makes the digital pin 8 OUTPUT and Togles it HIGH and LOW.
pinMode(led6, OUTPUT); //The code makes the digital pin 2 OUTPUT and Togles it HIGH and LOW.
}

void loop() 
{
 
 if (Serial.available() > 0) // Get the number of bytes (characters) available for reading from the serial port. 
 {
  data = Serial.read(); //Reads incoming serial data
  Serial.print(data); //Prints data to the serial port as human-readable ASCII text.
  Serial.print("\n"); //new line
  if (data == '1') 
  {
    myservo.write(45);
    digitalWrite(led, HIGH); //When data = 1 rotate the motor and turn off green light and turn on red light (LOCK the door)
    digitalWrite(led2, LOW);
    pos = 1;
  }
  if (data == '0') 
  {
    myservo.write(90);
    digitalWrite(led, LOW); //When data = 0 rotate the motor and turn on green light and turn off red light (UNLOCK the door)
    digitalWrite(led2, HIGH);
    pos = 0;
  }
  if (data == 'G')
    digitalWrite(led3, HIGH); //When data = G turn on lighting for room 1 
  else  if (data == 'R')
    digitalWrite(led3, LOW); //When data = R turn off lighting for room 1

    if (data == 'K')
    digitalWrite(led4, HIGH); //When data = K turn on lighting for room 2
  else if (data == 'L')
    digitalWrite(led4, LOW);  //When data = L turn off lighting for room 2

    if (data == 'M')
    digitalWrite(led5, HIGH); //When data = M turn on lighting for room 3
  else if (data == 'N')
    digitalWrite(led5, LOW); //When data = N turn off lighting for room 3

     if (data == 'O')
    digitalWrite(led6, HIGH); //When data = O turn on lighting for room 4
  else if (data == 'P')
    digitalWrite(led6, LOW);  //When data = P turn off lighting for room 4
  
 }
}
