//CODE FOR THE RELATION BETWEEN A SENSOR AND AN ANALOGUE (VOLTAGE) OUTPUT

//int value (0, 256); //put the values you're getting from the sensor inside the brackets - lowest number, highest number

void setup() {
  // put your setup code here, to run once:
  TCCR0B = TCCR0B &0b11111000 | 0x01; //you need this line of code if you are using Analog write and you want to do audio with it. Be careful though, this messes with your timer 

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0); //the values coming in from the analog pin are always 10 bit (between 0 and 1023)

  // print out the value you read:
  Serial.println(value);


  value = constrain(map(value, 0, 1023, 0, 256), 0, 256); //this maps the 10 bit value range to the 8 bit value range, which is the range of the analogue output)
  //Serial.println(value);
  
  analogWrite(6, value); //these values are always 8 bit (between 0 and 256)


  delay(100);        // delay in between reads for stability
}
