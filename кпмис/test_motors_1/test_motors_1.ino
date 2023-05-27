#define M1_dir 45
#define M1_speed 44

#define M2_dir 47
#define M2_speed 46

 
void setup() {
pinMode(M1_dir,OUTPUT);
pinMode(M1_speed,OUTPUT);

pinMode(M2_dir,OUTPUT);
pinMode(M2_speed,OUTPUT);


}

void loop() {
  digitalWrite(M1_dir, LOW);
  analogWrite(M1_speed,150);
  digitalWrite(M2_dir, LOW);
  analogWrite(M2_speed,150);
  delay(2000);
  digitalWrite(M1_dir, HIGH);
  analogWrite(M1_speed,150);
  digitalWrite(M2_dir, HIGH);
  analogWrite(M2_speed,150);
  delay(2000);
  analogWrite(M1_speed,0);
  analogWrite(M2_speed,0);
  delay(2000);

}
