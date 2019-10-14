int acelerador = A2;
int rotacion = A0;
int boton = 2;
int feedback = 0;
int led = 13;


void setup() {

  Serial.begin(9600);
  Serial.println("0,0,0");
  pinMode(boton, INPUT);
  pinMode(led, OUTPUT);
}


void loop() {


  if (Serial.available() > 0) {
    feedback = Serial.read();


    if (feedback == 1) {
      digitalWrite(led, HIGH);
    }

    else if (feedback == 0) {
      digitalWrite(led, LOW);

    }


    int trigger = digitalRead(boton);
    int acel = (1023 - analogRead(acelerador)) ;
    int rot = 1023 - analogRead(rotacion);


    Serial.print(acel);
    Serial.print(",");
    delay(1);
    Serial.print(rot);
    Serial.print(",");
    delay(1);
    Serial.println(trigger);
    if (trigger == 1) {

      delay(500);
    }
  }

}
