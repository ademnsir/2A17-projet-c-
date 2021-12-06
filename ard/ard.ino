
const int buzzer = 8; //buzzer to arduino pin 8
char data;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 8 as an outpu
}

void loop() {
  // put your main code here, to run repeatedly:

if (Serial.available() )
{
data=Serial.read();
  
  if(data=='1')
  {
     
     tone(buzzer, 1000); // Send 1KHz sound signal...
   delay(500);        // ...for 1 sec
     noTone(buzzer);
  
   }
   else if (data=='0')
  {  
    noTone(buzzer);     // Stop sound...

  }

}}
