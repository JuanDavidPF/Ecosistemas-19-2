///////////////////////UNIVERSIDAD ICESI/////////////////////////////////
/////////////////DISEÑO DE MEDIOS INTERACTIVOS///////////////////////////
//////////////////ECOSÍSTEMAS DE PROGRAMACIÓN////////////////////////////
///////////////////////////2019 - 2 /////////////////////////////////////
/////JUAN DAVID PAYÁN---JESSICA PARDEY---ANGIE RAMIREZ---JOSE BARRIOS////
///////////////////////LABORATORIO SEMANA 1//////////////////////////////


////////////////////////////////////////////

///////Variables globales

int LED[6];
const int perilla = 0;
const int sensorLuz = 1;
int potencia = 0;
int luz = 0;
const int boton = 7;
boolean botonPressed;
boolean botonWasPressed;
int patron = 0;
int ledActual = 0;


////////////////////////////////////////////

void setup() {

  Serial.begin(9600);


  /////asigna el puerto de los leds

  for (int i = 0; i < 6 ; i++) {
    LED[i] = i + 8;
    pinMode(LED[i], OUTPUT);
  }


  /////asigna el puerto del botón
  pinMode(boton, INPUT);


}//cierra el metodo setup




////////////////////////////////////////////

void loop() {


  //////asigna la potencia del potenciometro con una resta para cambiar el sentido del giro
  potencia = 1023 - analogRead(perilla);

  /////el sensor determina la luminosidad del ambiente
  luz = analogRead(sensorLuz);

  ///////determina si el boton está presionado o no
  botonPressed = digitalRead(boton);


  //determina los estados que ha tenido el boton y cambia de fase.
  if (botonPressed == true && botonWasPressed == false) {
    patron++;
    if (patron > 5)patron = 0;

    //el led actual pasa a ser 0 cada vez se pulsa el boton
    ledActual = 0;
  }


  //determina que el boton ya fue presionado
  botonWasPressed = botonPressed;


  ///////patrones de las luces

  switch (patron) {

    case 0:


      //los leds se encienden dependiendo de la cantidad encendida
      for (int i = 0; i < potencia / 170 ; i++) {
        ledActual = i;
        digitalWrite(LED[ledActual], HIGH);
      }

      delay(100);

      //todos los leds están apagados
      for (int i = 0; i < 6 ; i++) {
        digitalWrite(LED[i], LOW);
      }


      break;// cierra la fase 0


    case 1:

      //los leds se encienden dependiendo de la cantidad de luz

      for (int i = 0; i < luz / 50 ; i++) {
        digitalWrite(LED[i], HIGH);
      }

      delay(100);

      //todos los leds están apagados
      for (int i = 0; i < 6 ; i++) {
        digitalWrite(LED[i], LOW);
      }

      break;// cierra la fase 1

    case 2:

      //enciende el led actual y el que le sigue
      digitalWrite(LED[ledActual], HIGH);
      if (ledActual + 1 <= 5)digitalWrite(LED[ledActual + 1], HIGH);


      //si el led que le sigue al actual es mayor al ultimo led disponible, enciende el primero
      if (ledActual + 1 > 5 )digitalWrite(LED[0], HIGH);


      delay(100);

      //el led actual incrementa en uno
      ledActual ++;

      //si el led actual llega al ultimo, se reinicia
      if (ledActual == 6) ledActual = 0;


      //todos los leds se apagan en cada iteración.
      for (int i = 0; i < 6 ; i++) {
        digitalWrite(LED[i], LOW);
      }

      break;// break que cierra el primer patron


    case 3:

      //enciende el led actual y el anterior
      digitalWrite(LED[ledActual], HIGH);
      if (ledActual - 1 >= 0 )digitalWrite(LED[ledActual - 1], HIGH);


      //si el led anterior actual es menor al primer led disponible, enciende el ultimo
      if (ledActual - 1 < 0 )digitalWrite(LED[5], HIGH);


      delay(100);

      //el led actual se reduce en uno
      ledActual --;

      //si el led actual llega al primero, se reinicia
      if (ledActual == -1) ledActual = 5;



      //todos los leds se apagan en cada iteración.
      for (int i = 0; i < 6 ; i++) {
        digitalWrite(LED[i], LOW);
      }

      break;//break que cierra el segundo patron


    case 4:

      //enciende el led actual y su reflejo
      digitalWrite(LED[ledActual], HIGH);
      digitalWrite(LED[5 - ledActual], HIGH);

      delay(90);

      //si el led actual llega al ultimo , se reinicia
      if (ledActual == 5) ledActual = 0;

      //el led actual incrementa en uno
      ledActual ++;

      //todos los leds se apagan en cada iteración.
      for (int i = 0; i < 6 ; i++) {
        digitalWrite(LED[i], LOW);
      }


      break;//break que cierra el tercer patron


    case 5:

      //enciende el led actual si este está apagado
      if (digitalRead(LED[ledActual]) == LOW) {
        digitalWrite(LED[ledActual], HIGH);
      } /*apaga el led actual si este está encendido*/
      else if (digitalRead(LED[ledActual]) == HIGH) {
        digitalWrite(LED[ledActual], LOW);
      }

      //apaga el led actual si este está encendido


      delay(90);

      //si el led actual llega al ultimo, se reinicia
      if (ledActual == 5) ledActual = -1;


      //el led actual incrementa en uno
      ledActual ++;

      break;//break que cierra el cuarto patron

  }//cierra el switch de patron
}//cierra el metodo loop
