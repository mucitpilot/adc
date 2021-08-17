#ifdef ESP32
 const int potPin = 27;
 const int ledPin = 25;
 int bolen=4; //nodemcu veya esp32 kartta 1024 aralığını kullanmak için.
#else
  const int potPin = A0;
  const int ledPin = D7;
  int bolen=1; //nodemcu veya esp32 kartta 1024 aralığını kullanmak için.
#endif


// potanstan okuyacağımız veriyi saklayacağımız değişken
int potDeger = 0;


void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  delay(500);
}

void loop() {
  // pottan değeri okuyalım
  potDeger = analogRead(potPin);
  Serial.println(potDeger);
  digitalWrite(ledPin, HIGH);
  delay(potDeger/bolen);
  digitalWrite(ledPin, LOW);
  delay(potDeger/bolen);
  
}
