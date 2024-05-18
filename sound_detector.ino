  #include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C lcd(0x27, 16, 2);
  int ledPin = 9;
  int soundSensorPin = 13;
  int soundSensorState;
  bool isOn = false;

void setup() {
  //Serial.begin(9600);
  pinMode(soundSensorPin,INPUT);
  pinMode(ledPin,OUTPUT);
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.print("Create sounds");
}

void loop() {
  soundSensorState = digitalRead(soundSensorPin);
  if(soundSensorState == 1 && isOn == false){
  digitalWrite(ledPin,HIGH);
  lcd.clear();
  lcd.print(F("Switch is ON"));
  isOn = true;
  }
  else if(soundSensorState == 1 && isOn == true){
  digitalWrite(ledPin,LOW);
  lcd.clear();
  lcd.print(F("Switch is OFF"));
  isOn = false;
  }
}