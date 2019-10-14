int led1 = 4;
int led2 = 5;
int led3 = 6;
int led4 = 7;
String valores;
int valor;


void setup() {

  Serial.begin(9600);

  pinMode(led1, OUTPUT   );
  pinMode(led2, OUTPUT   );
  pinMode(led3, OUTPUT   );
  pinMode(led4, OUTPUT   );

}

void loop() {



  if (Serial.available() > 0) { // Si existe una conexion
    valores = Serial.readStringUntil('\n');


  }


  if (valores == "1000" || valores == "1100" || valores == "1010" || valores == "1110"  || valores == "1001" || valores == "1011"  || valores == "1101") digitalWrite(led1, HIGH  );
  else digitalWrite(led1, LOW);

  if (valores == "0100" || valores == "1100" || valores == "0101" || valores == "1101"  || valores == "0111"  || valores == "1110"  || valores == "0110") digitalWrite(led2, HIGH  );
  else digitalWrite(led2, LOW);

  if (valores == "0010" || valores == "1010" || valores == "0011" || valores == "1101"  || valores == "1011" || valores == "0111"   || valores == "0110") digitalWrite(led3, HIGH  );
  else digitalWrite(led3, LOW);

  if (valores == "0001" || valores == "0101" || valores == "0011" || valores == "1101"  || valores == "1001"  || valores == "0111"  || valores == "1011") digitalWrite(led4, HIGH  );
  else digitalWrite(led4, LOW);

  if (valores == "1111") {

    delay(100);
    digitalWrite(led1, HIGH  );
    digitalWrite(led2, HIGH  );
    digitalWrite(led3, HIGH  );
    digitalWrite(led4, HIGH  );

    delay(100);

    digitalWrite(led1, LOW );
    digitalWrite(led2, LOW  );
    digitalWrite(led3, LOW  );
    digitalWrite(led4, LOW  );

  }
}
