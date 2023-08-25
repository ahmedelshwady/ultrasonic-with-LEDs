const int echo=3,trig=4;
int time,distance;
float a,b,c,d;
void setup()
{
  for(int i=5;i<=10;i++){
  pinMode(i,OUTPUT);
  }
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  time=pulseIn(echo,HIGH);
  distance = time * 0.034 / 2;
  a=map(distance,0,82,0,255);
  b=map(distance,82,164,0,255);
  c=map(distance,164,246,0,255);
  d=map(distance,246,328,0,255);
  if(distance<82){
   analogWrite(5,a);
   digitalWrite(6,0);
   digitalWrite(9,0);
   digitalWrite(10,0);
  }
  else if(distance>82&&distance<=164){
  analogWrite(6,b);
  digitalWrite(5,1);
  digitalWrite(9,0);
  digitalWrite(10,0);  
  }
 else if(distance>164&&distance<=246){
   analogWrite(9,c);
   digitalWrite(5,1);
   digitalWrite(6,1);
   digitalWrite(10,0);
  }
  else{
  analogWrite(10,d);
  digitalWrite(5,1);
  digitalWrite(6,1);
  digitalWrite(9,1);
  }

}