int poten = A0;
int Led1, Led2, Led3, Led4;
int potencia;
int Led[4];
String slider;
int sliderNivel = 3;


void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 4; i++) {
    Led[i] = 5 - i;
    pinMode(Led[i], OUTPUT);
  }
}

void loop() {

  delay(10);
  potencia = analogRead(poten);
  Serial.println(potencia);


  //leds apagados
  for (int i = 0; i < 4; i++) {
    digitalWrite(Led[i], LOW  );
  }

  //leds encendido
  for (int i = 0; i < sliderNivel; i++) {
    digitalWrite(Led[i], HIGH  );
  }
}

void serialEvent() {

  slider = Serial.read();
  sliderNivel = slider.toInt();


}
