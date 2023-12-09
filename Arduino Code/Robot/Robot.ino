int onepin = A0; 
int twopin = A1; 
int threepin = A2; 
int fourpin = A3; 
int fivepin = A4; 
int oneout = 7; 
int twoout = 8; 
int threeout = 9; 
int fourout = 10; 
int signal = 13; 
const int threshold = 200;
const int minimum = 800;
const int rl = 500;
 
void setup() 
{ 
 Serial.begin(9600); 
pinMode(signal, OUTPUT);pinMode(oneout, OUTPUT);
pinMode(twoout, OUTPUT); pinMode(threeout, OUTPUT); 
pinMode(fourout, OUTPUT); 
digitalWrite(signal, LOW);digitalWrite(oneout, LOW); 
digitalWrite(twoout, LOW);digitalWrite(threeout, LOW); 
digitalWrite(fourout, LOW);delay(1000); 
digitalWrite(signal, HIGH); delay(1000);digitalWrite(signal, LOW);
delay(1000); digitalWrite(signal, HIGH);
} 
 
void loop() { 
if(analogRead(onepin) >= threshold || analogRead(fivepin) >= threshold) forward(); 
else if(analogRead(onepin) == minimum || analogRead(fivepin) == minimum) stop(); delay(50); 



if(analogRead(twopin) >= rl){ 
while(analogRead(twopin) >= rl) right(); 
while(analogRead(onepin) < minimum && analogRead(fivepin) < minimum); stop();delay(1000);} 


if(analogRead(threepin) >= rl){ 
while(analogRead(threepin) >= rl) right();
while(analogRead(onepin) < minimum && analogRead(fivepin) < minimum); stop();delay(1000);} 


if(analogRead(fourpin) >= rl){ 
while(analogRead(fourpin) >= rl) left();
while(analogRead(onepin) < minimum && analogRead(fivepin) < minimum); stop();delay(1000);} 
} 
 
void forward(void) 
{digitalWrite(oneout, HIGH);digitalWrite(twoout,LOW); 
digitalWrite(threeout, HIGH);digitalWrite(fourout, LOW);} 
void rev(void) 
{digitalWrite(oneout, LOW);digitalWrite(twoout,HIGH); 
digitalWrite(threeout, LOW);digitalWrite(fourout, HIGH);} 
void stop(void) 
{digitalWrite(oneout, LOW);digitalWrite(twoout,LOW); 
digitalWrite(threeout, LOW);digitalWrite(fourout, LOW);} 
void left(void) 
{digitalWrite(oneout, LOW);digitalWrite(twoout,HIGH); 
digitalWrite(threeout, HIGH);digitalWrite(fourout, LOW);} 
void right(void) 
{digitalWrite(oneout, HIGH);digitalWrite(twoout,LOW); 
digitalWrite(threeout, LOW);digitalWrite(fourout, HIGH);} 


